/**
 * @author      Takashi Matsushita
 * Created:     03 Jul 2014
 */

/** @todo */

/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <iostream>

#include "boost/version.hpp"
#include "Function.hh"
#include "Cut.hh"
#include "Object.hh"


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int
main()
{
  const std::string indent = "  ";

  std::cout << "Boost version: " << BOOST_VERSION << "\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";
  std::cout << "\t\tA function parser for Spirit...\n\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";

  std::cout
    << "Give me a function of the form :\n"
    << "  dist{MU10[MU-ETA_CUT1,MU-PHI_CUT1],EG.gt.20p5+2}[DETA_1,DETA_2]\n";
  std::cout << "Type [q or Q] to quit\n\n";

  std::string str;
  while (getline(std::cin, str))
  {
    if (str.empty() || str[0] == 'q' || str[0] == 'Q') break;

    Function::Item function;
    bool rc = Function::parser(str, function);
    if (not rc) continue;
    function.print();
  }

  std::cout << "nFnc = " <<  Function::functionName.size() << std::endl;

  std::cout << "Bye... :-) \n\n";
  return 0;
}
/* eof */
