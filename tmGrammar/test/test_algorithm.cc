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
#include "Algorithm.hh"


// ---------------------------------------------------------------------
// main
// ---------------------------------------------------------------------
int
main()
{
  std::cout << "/////////////////////////////////////////////////////////\n\n";
  std::cout << "\t\tAn algorithm parser for Spirit...\n\n";
  std::cout << "/////////////////////////////////////////////////////////\n\n";

  std::cout
    << "Give me an algorithm of the form :\n"
    << "  NOT (A AND B) OR ((NOT C AND D) AND (E AND NOT F) AND (G XOR H))\n";
  std::cout << "Type [q or Q] to quit\n\n";

  std::string str;
  while (getline(std::cin, str))
  {
    Algorithm::Logic::clear();

    if (str.empty() || str[0] == 'q' || str[0] == 'Q') break;

    bool rc = Algorithm::parser(str);
    if (rc) Algorithm::Logic::print();
  }

  std::cout << "nGate = " <<  Algorithm::gateName.size() << std::endl;

  std::cout << "Bye... :-) \n\n";
  return 0;
}
/* eof */
