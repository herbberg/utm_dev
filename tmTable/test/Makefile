TARGET = unittest

INCDIR = -I../..
LIBS = -lboost_unit_test_framework -lboost_system -lboost_filesystem -ltmtable -ltmxsd -lxerces-c
LIBDIR = -L.. -L../../tmUtil -L../../tmXsd

all: $(TARGET)

$(TARGET): unittest.cc
	g++ -o $@ $< $(INCDIR) $(LIBDIR) $(LIBS)

test: $(TARGET)
	./$(TARGET)

clean:
	rm $(TARGET)
