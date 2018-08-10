TARGET = unittest

INCDIR = -I../..
LIBS = -lboost_unit_test_framework -lboost_system -lboost_filesystem -ltmtable -ltmxsd -lxerces-c
LIBDIR = -L.. -L../../tmUtil -L../../tmXsd

CXX = c++
RM = rm -f

.PHONY: all test clean dist-clean

all: $(TARGET)

$(TARGET): unittest.cc
	$(CXX) -o $@ $< $(INCDIR) $(LIBDIR) $(LIBS)

test: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(TARGET)

dist-clean: clean
