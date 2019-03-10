# Bit Set

A Bit Set is a simple, low-level data structure that allows allocating, setting, freeing, and reading bits. This structure is good for tracking the free status of an array of items. In future editions of the project I will use this code as a Block Map structure. 

## Getting Started

Use the makefile provided to create the executable if you wish to test the functions, otherwise the meat of the project is in bitset.c and bitset.h, which don't have a main function of their own. 

## Testing

All tests are located in the main function in test_bitset.c. The tests create a bitset and manipulate it using the functions defined in bitset.c, asserting along the way. Then the bitset is written to a file, and read into another chunk of memory as bitset2. The two are compared, and if all goes well, the only terminal output is sizeof information. 

## Future Improvements

I believe that the memory stuff is handled properly, but I wasn't sure how to write tests for this. If I were to write more in my test files, I would write some to test memory management and some to test BitSets of varying lengths. 

## Acknowledgments

* Thanks to Dylan McNamee for writing and assisting with the assignment 
