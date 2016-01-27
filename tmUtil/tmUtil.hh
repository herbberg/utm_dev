/**
 * @author      Takashi Matsushita
 * Created:     14 Feb 2005
 */

/** @todo */
/** @warnings */

#ifndef tmUtil_hh
#define tmUtil_hh
/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <regex.h>


/*--------------------------------------------------------------------*
 * macros
 *--------------------------------------------------------------------*/
/** @file tmUtil.hpp
    collection of macros */

/** a stringize macro; private use */
#define TM_STR_(x) #x

/** a stringize macro; public use */
#define TM_STR(x) TM_STR_(x)

/** a macro that displays error meesage of system call */
#define TM_SYS_ERR(func) (fprintf(stderr, "err> %s: %s [%s:%d]\n", func, strerror(errno), __FILE__, __LINE__))

/** a macro that displays message then exits a program */
#define TM_FATAL_ERROR(x) (std::cerr << "fat> " << x << " [" \
                                     << __FILE__ << ":" \
                                     << std::dec << __LINE__ << "]" \
                                     << std::endl, \
                           throw std::runtime_error("run time error"))

/** a macro to be used for incomplete implementation */
#define TM_NOT_IMPLEMENTED_ERROR() TM_FATAL_ERROR("not implemented")

/** a macro that displays run-time information message */
#define TM_LOG_INF(x) (std::cout << "inf> " << x << " [" << __FILE__ << ":" << std::dec << __LINE__ << "]\n")

/** a macro that displays run-time warning message */
#define TM_LOG_WAR(x) (std::cerr << "war> " << x << " [" << __FILE__ << ":" << std::dec << __LINE__ << "]\n")

/** a macro that displays run-time error message */
#define TM_LOG_ERR(x) (std::cerr << "err> " << x << " [" << __FILE__ << ":" << std::dec << __LINE__ << "]" << std::endl)


/** a macro that displays run-time debug message,
    can be disabled by defining NDEBUG macro */
#ifndef NDEBUG
#define TM_LOG_DBG(x) (std::cout << "dbg> " << x  << " [" << __FILE__ \
                                 << ":" << std::dec << __LINE__ << "]\n")
#else
#define TM_LOG_DBG(x) ;
#endif

/*--------------------------------------------------------------------*
 * constants
 *--------------------------------------------------------------------*/
/* nope */

/*--------------------------------------------------------------------*
 * function
 *--------------------------------------------------------------------*/
namespace tmutil {
/**
 *  remove leading and trailing white characters from string
 *
 *  @param source [in] input string
 *  @param whites [in] white characters
 *  @return trimmed string
 */
std::string trim(std::string const& source,
                 char const *whites = " \t\r\n");

/**
 *  tokenise a string with delimiters
 *
 *  @param source [in] input string
 *  @param tokens [out] array of tokens
 *  @param delimiters [in] delimiters
 */
void tokenise(const std::string& source,
              std::vector<std::string>& tokens,
              const std::string& delimiters = " ");


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

/**
  *  string to T conversion
  *
  *  @param string [in] string
  *  @return T
  */
template<typename T>
T convert(const std::string& string);


/**
  *  T to string conversion
  *
  *  @param data [in] data of type T
  *  @return string expression of data
  */
template<typename T>
std::string toString(const T data);

template<typename T>
std::string toString(const std::vector<T>& data);


/**
  *  convert to lowercase strings
  *
  *  @param string [in/out] string
  */
void toLower(std::string& string);


/**
 *  remove quotes
 *
 *  @param string [in/out] string
 */
void unquote(std::string& string);


/**
 *  join string in an array with delimiter
 *
 *  @param array [in] array of string to be joined
 *  @param result [in/out] string to hold the result
 *  @param delimiter [in] delimiter for joining array of string
 */
void join(const std::vector<std::string>& array,
          std::string& result,
          const std::string& delimiter = ",");


/**
 *  replace all occurences of text with another string
 *
 *  @param text [in/out] target string
 *  @param from [in] string to be replaced
 *  @param to [in] string to replace
 *  @param exactMatch [in] don't perform replace for partially matched pattern
 */
bool replace(std::string& text,
             const std::string& from,
             const std::string& to,
             const bool exactMatch = true);


/**
 *  get hash value from the given string
 *
 *  @param text [in] input string
 *  @param exactMatch [in] don't perform replace for partially matched pattern
 *  @return hash value in string
 */
std::string getHash(const std::string& text);


/**
 *  get the current working directory
 *
 *  @return current working directory
 */
std::string getcwd();


/**
 *  get the path component before/after the filnal '/'
 *
 *  @param path [in] path name
 *  @return path component before/after the final '/'
 */
std::pair<std::string, std::string> splitpath(const std::string& path);


/**
 *  change working directory
 *
 *  @param path [in] path name. Change the cwd to path. If path is a file, change the cwd to the directory which contains the file.
 */
void chdir(const std::string& path);

} // namespace tmutil

#endif // tmUtil_hh
/* eof */
