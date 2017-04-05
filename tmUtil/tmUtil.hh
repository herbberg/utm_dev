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
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <regex.h>


/*--------------------------------------------------------------------*
 * macros
 *--------------------------------------------------------------------*/
/** @file tmUtil.hh
    collection of macros */

/** a macro that displays message then exits a program */
#define TM_FATAL_ERROR(x) (std::cerr << "fat> " << x << " [" \
                                     << __FILE__ << ":" \
                                     << std::dec << __LINE__ << "]" \
                                     << std::endl, \
                           throw std::runtime_error(static_cast<std::ostringstream&>(std::ostringstream().flush() << "run time error: " << x).str()))

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


} // namespace tmutil

#endif // tmUtil_hh
/* eof */
