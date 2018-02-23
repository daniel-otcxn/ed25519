SRC := $(wildcard *.c)
CXXSRC := $(wildcard *.cc)
OBJS := $(patsubst %.c, %.o, $(SRC))
CXXOBJS := $(patsubst %.cc, %.o, $(CXXSRC))
CC := gcc-7
CXX := g++-7

.PHONY: all clean run lines

-include Makefile.local

BIN := test

run: $(BIN)
	./$<;

all: $(BIN)

$(BIN): $(CXXOBJS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@;

$(OBJS) : %.o : %.c
	$(CC) $(CXXFLAGS) -c $< -o $@;

$(CXXOBJS) : %.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@;

-include *.d

lines:
	wc -l *.cc *.h;

clean:
	@rm -fv *.o *.d $(BIN)
