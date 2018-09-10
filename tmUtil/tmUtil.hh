/**
 * @author Bernhard Arnold
 * @author Takashi Matsushita
 * @date: 14 Feb 2005
 */

#ifndef tmUtil_hh
#define tmUtil_hh
/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include "tmUtil/macros.hh"

#include <regex.h>

#include <string>
#include <vector>

/*--------------------------------------------------------------------*
 * constants
 *--------------------------------------------------------------------*/
/* nope */

/*--------------------------------------------------------------------*
 * function
 *--------------------------------------------------------------------*/
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

  typedef std::vector<unsigned> data_t;
  data_t data;
};

/* Version number comparision. */
bool operator==(const Version& lhs, const Version& rhs);
bool operator!=(const Version& lhs, const Version& rhs);
bool operator<(const Version& lhs, const Version& rhs);
bool operator>(const Version& lhs, const Version& rhs);
bool operator<=(const Version& lhs, const Version& rhs);
bool operator>=(const Version& lhs, const Version& rhs);

} // namespace tmutil

#endif // tmUtil_hh
/* eof */
