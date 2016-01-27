#include "tmTable/tmTable.hh"
#include "tree2table.hh"
#include "table2tree.hh"

int
main()
{
  std::string message;

  tmxsd::menu menu = tmxsd::xml2menu("menu.xml", message);
  std::cout << message << std::endl;
  tmtable::Menu table_menu;
  tmtable::Scale table_scale;
  tmtable::ExtSignal table_ext_signal;
  tmxsd::tree2menu(menu, table_menu, table_scale, table_ext_signal);
  tmxsdtree::menu2xml(table_menu, table_scale, table_ext_signal, "foo.xml");
}
