#ifndef tmutil_macros_hh
#define tmutil_tmUtil_hh

#include <iostream>
#include <sstream>
#include <stdexcept>

// ----------------------------------------------------------------------------
//  macros
// ----------------------------------------------------------------------------

/** helper macro for pretty function signatures, to be used in output streams. */
#define TM_FUNCTION_REF __PRETTY_FUNCTION__ << ": "

/** helper macro for pretty filename/line number signatures, to be used in output streams. */
#define TM_FILE_LINE_REF " [" << __FILE__ << ":" << std::dec << __LINE__ << "]"

/** helper macro for pretty log messages, to be used in output streams. */
#define TM_LOG_MSG(OSS, LVL, MSG) (OSS << LVL << "> " << TM_FUNCTION_REF << MSG << TM_FILE_LINE_REF << std::endl)

/** a macro that displays run-time debug message, can be disabled by defining NDEBUG macro */
#ifndef NDEBUG
#define TM_LOG_DBG(MSG) TM_LOG_MSG(std::cout, "dbg", MSG)
#else
#define TM_LOG_DBG(MSG) ;
#endif

/** a macro that displays run-time information message */
#define TM_LOG_INF(MSG) TM_LOG_MSG(std::cout, "inf", MSG)

/** a macro that displays run-time warning message */
#define TM_LOG_WAR(MSG) TM_LOG_MSG(std::cerr, "war", MSG)

/** a macro that displays run-time error message */
#define TM_LOG_ERR(MSG) TM_LOG_MSG(std::cerr, "err", MSG)

/** a macro that displays run-time fatal error message */
#define TM_LOG_FAT(MSG) TM_LOG_MSG(std::cerr, "fat", MSG)

/** a macro that displays message then exits a program */
#define TM_FATAL_ERROR(MSG) (TM_LOG_FAT(MSG), \
  throw std::runtime_error(static_cast<std::ostringstream&>(std::ostringstream().flush() << "run time error: " << MSG).str()))

/** a macro for pretty quotes, to be used in output streams. */
#define TM_QUOTE(MSG) "'" << MSG << "'"

/** a macro for pretty double quotes, to be used in output streams. */
#define TM_DQUOTE(MSG) "\"" << MSG << "\""

/** a macro for pretty key='value' debug signatures, to be used in output streams. */
#define TM_VALUE_DBG(VAL) #VAL << "=" << TM_QUOTE(VAL)

#endif // tmutil_macros_hh
