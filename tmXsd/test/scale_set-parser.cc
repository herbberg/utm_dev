#include "reader.hh"

#include <iostream>
#include <fstream>

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "usage: " << argv[0] << " file.xml" << std::endl;
    return 1;
  }

  std::ifstream ifs(argv[1]);
  tmxsd::Reader<tmxsd::scale_set> reader;
  reader.read(ifs);
  if (not reader.success())
  {
    std::cout << reader.message() << std::endl;
  }
}

