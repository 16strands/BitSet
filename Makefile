CXX=gcc
CXXFLAGS=-Wall -Wextra -pedantic -g 
LDFLAGS=$(CXXFLAGS)
# OBJ=$(SRC:.cc=.o)

all: test_bitset 

test_bitset: bitset.c test_bitset.c
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.c test_bitset 
