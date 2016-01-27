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
#include <iostream>
#include "Cut.hh"


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int
main()
{
  std::cout << "/////////////////////////////////////////////////////////\n\n";
  std::cout << "\t\tA cut parser for Spirit...\n\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";

  std::cout
    << "Give me a cut of the form :\n"
    << "  MU-ETA_CUT1,EG-PHI_CUT1\n";
  std::cout << "Type [q or Q] to quit\n\n";

  std::string str;
  while (getline(std::cin, str))
  {

    if (str.empty() || str[0] == 'q' || str[0] == 'Q') break;

    Cut::Item item;
    bool rc = Cut::parser(str, item);
    if (rc) item.print();
  }

  std::cout << "nCut = " <<  Cut::cutName.size() << std::endl;

  std::cout << "Bye... :-) \n\n";
  return 0;
}
/* eof */
