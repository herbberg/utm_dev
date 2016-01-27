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

#include "Object.hh"
#include "Cut.hh"


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------

int
main()
{
  std::cout << "/////////////////////////////////////////////////////////\n\n";
  std::cout << "\t\tAn object parser for Spirit...\n\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";

  std::cout
    << "Give me an object of the form :\n"
    << "  MU.gt.20p5+1[MU-ETA_CUT1,MU-PHI_CUT1]\n";
  std::cout << "Type [q or Q] to quit\n\n";

  std::string str;
  while (getline(std::cin, str))
  {

    if (str.empty() || str[0] == 'q' || str[0] == 'Q') break;

    Object::Item object;
    if (not Object::parser(str, object)) continue;
    object.print();
  }

  std::cout << "Bye... :-) \n\n";
  return 0;
}
/* eof */
