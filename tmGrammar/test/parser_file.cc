/**
 * @author      Takashi Matsushita
 * Created:     09 Jul 2014
 */

/** @todo */

/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <fstream>

#include "tmUtil/tmUtil.hh"
#include "Algorithm.hh"
#include "Function.hh"
#include "Object.hh"


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int
main(int argc, char *argv[])
{
  int opt;
  char* fileName = 0;
  bool debug = 0;

  while ((opt = getopt(argc, argv, "df:")) != -1)
  {
    switch (opt)
    {
      case 'f':
        fileName = optarg;
        break;

      case 'd':
        debug = 1;
        break;

      default:
        std::cerr << "Usage: " << argv[0] << " -f <input file>" << std::endl;
        return 1;
    }
  }

  std::ifstream file;
  file.open(fileName);
  if (not file.is_open())
  {
    TM_LOG_ERR("couldn't open file: '" << (fileName ? fileName : " ") << "'");
    file.close();
    return 1;
  }

  const std::string indent = "  ";
  std::string line;
  while (getline(file, line))
  {
    Algorithm::Logic::clear();

    bool rc = Algorithm::parser(line);
    if (not rc) continue;

    // analyse each token
    for (size_t ii = 0; ii < Algorithm::Logic::tokens.size(); ii++)
    {
      const std::string& token = Algorithm::Logic::tokens.at(ii);
      bool matched = false;

      // logical operator
      if (Algorithm::gateName.find(token) != Algorithm::gateName.end())
      {
        if (debug) std::cout << token <<  " is a GATE" << std::endl;
        matched = true;
        continue;
      }

      // function
      for (Function::reserved::const_iterator cit = Function::functionName.begin();
           cit != Function::functionName.end(); cit++)
      {
        if (token.compare(0, cit->first.length(), cit->first) == 0)
        {
          if (debug) std::cout << token <<  " is a function" << std::endl;

          Function::Item function;
          if (not Function::parser(token, function)) continue;
          if (debug) std::cout << indent;
          if (debug) function.print();
          matched = true;

          break;
        }
      }

      // object
      for (Object::reserved::const_iterator cit = Object::objectName.begin();
           cit != Object::objectName.end(); cit++)
      {
        if (token.compare(0, cit->first.length(), cit->first) == 0)
        {
          if (debug) std::cout << token <<  " is an object" << std::endl;

          Object::Item object;
          if (not Object::parser(token, object)) continue;
          if (debug) std::cout << indent;
          if (debug) object.print();
          matched = true;

          break;
        }
      }

      if (matched) continue;
      TM_LOG_ERR("failed to parse '" << token << "'");
    }
  }

  std::cout << "Bye... :-) \n\n";
  file.close();
  return 0;
}
/* eof */
