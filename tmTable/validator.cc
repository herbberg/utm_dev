#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "tmTable/tmTable.hh"
#include "tmXsd/reader.hh"
#include "tmXsd/writer.hh"
#include "tmTable/validator.hh"

bool
tmtable::isBin(const tmtable::Row& row)
{
#if 0 // TMP_FILE_BASE
  char path[] = "/tmp/xmlXXXXXX";
  int fd = mkstemp(path);
  close(fd);
  std::cout << path << std::endl;

  if (not tmxsd::writeBin(row, path)) return false;
  std::ifstream ifs(path);
#endif

  std::stringstream ss;
  if (not tmxsd::writeBin(row, ss)) return false;
  tmxsd::Reader<tmxsd::bin> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}


bool
tmtable::isScale(const tmtable::Row& row)
{
  std::stringstream ss;
  if (not tmxsd::writeScale(row, ss)) return false;
  tmxsd::Reader<tmxsd::scale> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}


bool
tmtable::isScaleSet(const tmtable::Row& row)
{
  std::stringstream ss;
  if (not tmxsd::writeScaleSet(row, ss)) return false;
  tmxsd::Reader<tmxsd::scale_set> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}


bool
tmtable::isExtSignal(const tmtable::Row& row)
{
  std::stringstream ss;
  if (not tmxsd::writeExtSignal(row, ss)) return false;
  tmxsd::Reader<tmxsd::ext_signal> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}


bool
tmtable::isExtSignalSet(const tmtable::Row& row)
{
  std::stringstream ss;
  if (not tmxsd::writeExtSignalSet(row, ss)) return false;
  tmxsd::Reader<tmxsd::ext_signal_set> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}

bool
tmtable::isCut(const tmtable::Row& row)
{
  std::stringstream ss;
  if (not tmxsd::writeCut(row, ss)) return false;
  tmxsd::Reader<tmxsd::cut> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}

bool
tmtable::isObjectRequirement(const tmtable::Row& row)
{
  std::stringstream ss;
  if (not tmxsd::writeObjectRequirement(row, ss)) return false;
  tmxsd::Reader<tmxsd::object_requirement> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}

bool
tmtable::isExternalRequirement(const tmtable::Row& row)
{
  std::stringstream ss;
  if (not tmxsd::writeExternalRequirement(row, ss)) return false;
  tmxsd::Reader<tmxsd::external_requirement> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}

bool
tmtable::isAlgorithm(const tmtable::Row& row)
{
  std::stringstream ss;
  if (not tmxsd::writeAlgorithm(row, ss)) return false;
  tmxsd::Reader<tmxsd::algorithm> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}


bool
tmtable::isMenu(const tmtable::Row& row)
{
  std::stringstream ss;
  if (not tmxsd::writeMenu(row, ss)) return false;
  tmxsd::Reader<tmxsd::menu> reader;
  reader.read(ss);
  bool rc = reader.success();
  if (not rc)
  {
    std::cerr << reader.message() << std::endl;
    std::cout << ss.str() << std::endl;
  }
  return rc;
}
/* eof */
