#ifndef tmutil_tmUtil_hh
#define tmutil_tmUtil_hh

#include "tmUtil/macros.hh"

#include <regex.h>

#include <sstream>
#include <string>
#include <vector>

namespace tmutil {

/**
  *  fast power of base 10 for integral exponents up to 308
  *
  *  @param regex [in/out] regex_t
  *  @param expression [in] posix regular expression
  *  @return base 10 raised to the power exponent
  *  @throws a std exception on exceeding exponent range
  */
double pow10(unsigned int exponent);

  /** MurmurHashNeutral2 by Austin Appleby (public domain)
   *  https://github.com/aappleby/smhasher/
   *
   *  @param s [in] text
   */
unsigned long MurmurHashNeutral2(const void* key, int len, unsigned int seed);

/**
  *  compile posix regular expression
  *
  *  @param regex [in/out] regex_t
  *  @param expression [in] posix regular expression
  *  @return non-zero if error detected
  */
int regex_compile(regex_t* regex,
                  const std::string& expression);

/**
  *  compile posix regular expression
  *
  *  @param regex [in/out] regex_t
  *  @param expression [in] text to match
  *  @param tokens [out] matched strings
  *  @return non-zero if error detected
  */
int regex_match(regex_t* regex,
                const std::string& text,
                std::vector<std::string>& tokens);

/** Returns environment variable.
  * Returns empty string if environment variable is not set.
  */
std::string getEnviron(const std::string& name);

/** Returns environment variable.
  * Returns fallback value if environment variable is not set.
  */
std::string getEnviron(const std::string& name, const std::string& fallback);

// PROTOTYPE
template<typename T>
std::string quote(const T& literal)
{
  constexpr char quote = '\'';
  std::ostringstream oss;
  oss << quote << literal << quote;
  return oss.str();
}

// PROTOTYPE
template<typename T>
std::string join(const T& iterable, const std::string& delim)
{
  std::ostringstream oss;
  for (const auto& value : iterable)
    oss << (oss.tellp() ? delim : std::string()) << value;
  return oss.str();
}

// PROTOTYPE
template<typename T>
std::string join_quoted(const T& iterable, const std::string& delim)
{
  std::ostringstream oss;
  for (const auto& value : iterable)
    oss << (oss.tellp() ? delim : std::string()) << quote(value);
  return oss.str();
}

// PROTOTYPE
template<typename T>
std::string format_parser_error(const T& begin, const T& end, const T& pos)
{
  std::ostringstream oss;
  size_t n = std::distance(begin, pos);
  oss << std::string(begin, end) << std::endl;
  oss << std::string(n, ' ') << '^' << std::endl;
  return oss.str();
}

/** Version number container.
  *
  * Version v("1.2.3");
  * Version("2.4") < Version("2.12"); // true
  */
struct Version
{
  Version(const std::string& version);

  void str(const std::string& version);
  std::string str() const;

  typedef std::vector<unsigned> value_type;
  value_type values;
};

/* Version number comparision. */
bool operator==(const Version& lhs, const Version& rhs);
bool operator!=(const Version& lhs, const Version& rhs);
bool operator<(const Version& lhs, const Version& rhs);
bool operator>(const Version& lhs, const Version& rhs);
bool operator<=(const Version& lhs, const Version& rhs);
bool operator>=(const Version& lhs, const Version& rhs);

} // namespace tmutil

#endif // tmutil_tmUtil_hh
