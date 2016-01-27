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
  tmxsd::Reader<tmxsd::ext_signal_set> reader;
  reader.read(ifs);
}

