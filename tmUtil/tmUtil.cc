/**
 * @author      Takashi Matsushita
 * Created:     14 Feb 2005
 */

/** @todo */
/** @warnings */

/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include "tmUtil/tmUtil.hh"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>

#include <unistd.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>


/*====================================================================*
 * implementation
 *====================================================================*/
// ---------------------------------------------------------------------
// functions
// ---------------------------------------------------------------------
namespace tmutil
{

// removes extra whites
std::string
trim(std::string const& source,
     char const* whites)
{
  std::string result(source);
  std::string::size_type index = result.find_last_not_of(whites);
  if (index != std::string::npos) result.erase(++index);

  index = result.find_first_not_of(whites);
  if (index != std::string::npos)
  {
    result.erase(0, index);
  }
  else
  {
    result.erase();
  } 
 
  return result;
}



void
tokenise(const std::string& str,
         std::vector<std::string>& tokens,
         const std::string& delimiters)
{
  std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  std::string::size_type pos = str.find_first_of(delimiters, lastPos);

  while (std::string::npos != pos || std::string::npos != lastPos)
  {
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    lastPos = str.find_first_not_of(delimiters, pos);
    pos = str.find_first_of(delimiters, lastPos);
  }
}


int
regex_compile(regex_t* regex,
              const std::string& expression)
{
  TM_LOG_DBG("regex_compile: " << expression);
  int rc = regcomp(regex, expression.c_str(), REG_EXTENDED|REG_NEWLINE);
  if (rc)
  {
    char message[BUFSIZ];
    regerror(rc, regex, message, BUFSIZ);
    std::cout << "Regex compilation error '" << expression << "'"
              << message << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}


int
regex_match(regex_t* regex,
            const std::string& text,
            std::vector<std::string>& tokens)
{
  const char* address = text.c_str();
  const char* pointer = address;
  const size_t n_matches = 10;
  regmatch_t match[n_matches];

  while (true)
  {
    if (regexec(regex, pointer, n_matches, match, 0)) break;

    for (size_t ii = 0; ii < n_matches; ii++)
    {
      if (match[ii].rm_so == -1) break;
      if (ii == 0) continue;

      int start = match[ii].rm_so + (pointer - address);
      int length = match[ii].rm_eo - match[ii].rm_so;

      TM_LOG_DBG("s " << start << " " << length << " : "
                      << text.substr(start, length));
      tokens.push_back(text.substr(start, length));
    }
    pointer += match[0].rm_eo;
  }

  return EXIT_SUCCESS;
}


template<typename T> T
convert(const std::string& ss)
{
  T data;
  std::istringstream(ss) >> data;
  return data;
}


template<typename T> std::string toString(const T d)
{
  return static_cast<std::ostringstream*>(&(std::ostringstream() << d))->str();
}


template<typename T> std::string toString(const std::vector<T>& d)
{
  std::string rc;
  for (size_t ii = 0; ii < d.size(); ii++)
  {
    std::ostringstream oss;
    oss << d.at(ii);
    rc += oss.str() + " ";
  }
  return rc;
}


void
toLower(std::string& str)
{
  std::transform(str.begin(), str.end(), str.begin(), tolower);
}


void
unquote(std::string& str)
{
  str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
}


void
join(const std::vector<std::string>& array,
     std::string& result,
     const std::string& delimiter)
{
  for (size_t ii = 0; ii < array.size(); ii++)
  {
    if (not result.empty())
    {
      result += delimiter + array.at(ii);
    }
    else
    {
      result += array.at(ii);
    }
  }
}


bool
replace(std::string& text,
        const std::string& from,
        const std::string& to,
        const bool exactMatch)
{
  size_t p = 0;
  while ((p = text.find(from, p)) != std::string::npos)
  {
    bool replace = true;
    const size_t index = p + from.length();
    if (exactMatch)
    {
      if (index < text.size())
      {
        if (text.at(index) != ' ') replace = false;
      }
    }
    if (replace) text.replace(p, from.length(), to);
    p += to.length();
    if (p >= text.size()) break;
  }
  return true;
}


std::string
getHash(const std::string& text)
{
  std::locale loc;
  const std::collate<char>& coll = std::use_facet<std::collate<char> >(loc);
  size_t hash = coll.hash(text.data(), text.data() + text.length());
  std::ostringstream oss;
  oss << hash;
  return oss.str();
}


std::string
getcwd()
{
  std::string cwd;

  char buf[FILENAME_MAX];
  if (::getcwd(buf, sizeof(buf)) != NULL)
  {
    cwd = buf;
  }
  else
  {
    ::perror("tmutil::getcwd: ");
  }

  return cwd;
}


std::pair<std::string, std::string>
splitpath(const std::string& path)
{
  char buf[FILENAME_MAX];

  strncpy(buf, path.c_str(), sizeof(buf));
  const char* p = ::dirname(buf);
  std::string before(p);

  strncpy(buf, path.c_str(), sizeof(buf));
  p = ::basename(buf);
  std::string after(p);

  return std::make_pair(before, after);
}


void
chdir(const std::string& path)
{
  std::string dir(path);
  struct stat st;
  lstat(path.c_str(), &st);
  if(not S_ISDIR(st.st_mode))
  {
    size_t found = path.find_last_of("/\\");
    dir = path.substr(0, found);
  }

  TM_LOG_DBG("dir = " << dir);

  if (::chdir(dir.c_str()))
  {
    ::perror("tmutil::chdir: ");
    TM_LOG_ERR(getcwd() << " -> " << dir);
  }
}


/*--------------------------------------------------------------------*
 * template instantiations
 *--------------------------------------------------------------------*/
template int convert<int>(const std::string& s);
template unsigned int convert<unsigned int>(const std::string& s);
template bool convert<bool>(const std::string& s);
template double convert<double>(const std::string& s);

template std::string toString<int>(const int d);
template std::string toString<bool>(const bool d);
template std::string toString<long>(const long d);
template std::string toString<size_t>(const size_t d);
template std::string toString<unsigned int>(const unsigned int d);
template std::string toString<double>(const double d);
template std::string toString(const std::vector<int>& d);
template std::string toString(const std::vector<bool>& d);
template std::string toString(const std::vector<std::string>& d);

} // namespace tmutil

/* eof */
