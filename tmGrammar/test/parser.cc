/**
 * @author      Takashi Matsushita
 * Created:     04 Jul 2014
 */

/** @todo */

/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include "tmUtil/tmUtil.hh"
#include "Algorithm.hh"
#include "Function.hh"
#include "Object.hh"


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int
main()
{
  const std::string indent = "  ";

  std::cout << "/////////////////////////////////////////////////////////\n\n";
  std::cout << "\t\tA logic parser ...\n\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";

  std::cout
    << "Give me a logic of the form :\n"
    << "  NOT (MU10 AND EG.gt.10p5+1) OR ((NOT TAU15[TAU-ISO_1] AND JET100[JET-ETA_1,JET-ETA_2]) AND (comb{MU10,MU20} AND NOT mass{MU10[MU-PHI_1,MU-ETA_1],EG10}[MASS_1,MASS_2]))\n";
  std::cout << "Type [q or Q] to quit\n\n";

  std::string str;
  while (getline(std::cin, str))
  {
    Algorithm::Logic::clear();

    if (str.empty() || str[0] == 'q' || str[0] == 'Q') break;

    bool rc = Algorithm::parser(str);
    if (not rc) continue;

    // analyse each token
    for (size_t ii = 0; ii < Algorithm::Logic::tokens.size(); ii++)
    {
      const std::string& token = Algorithm::Logic::tokens.at(ii);
      bool matched = false;

      // logical operator
      if (Algorithm::gateName.find(token) != Algorithm::gateName.end())
      {
        std::cout << token <<  " is a GATE" << std::endl;
        matched = true;
        continue;
      }

      // function
      for (Function::reserved::const_iterator cit = Function::functionName.begin();
           cit != Function::functionName.end(); cit++)
      {
        if (token.compare(0, cit->first.length(), cit->first) == 0)
        {
          std::cout << token <<  " is a function" << std::endl;

          Function::Item function;
          if (not Function::parser(token, function)) continue;
          std::cout << indent;
          function.print();
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
          std::cout << token <<  " is an object" << std::endl;

          Object::Item object;
          if (not Object::parser(token, object)) continue;
          std::cout << indent;
          object.print();
          matched = true;

          break;
        }
      }

      if (matched) continue;
      TM_LOG_ERR("failed to parse '" << token << "'");
    }
  }

  std::cout << "Bye... :-) \n\n";
  return 0;
}
/* eof */
