#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "bitset.h"

#define NUM_BITS 64
int main(int argc, char **argv){
    BitSet_p bitset = allocBitSet(NUM_BITS);
    for (int i = 0; i<NUM_BITS; i++){
        setBit(bitset, i);
    }
    setBit(bitset,5);
    assert(clearBit(bitset,5) == 0);
    setBit(bitset,5);
    assert(getBit(bitset,NUM_BITS-1) == 1);

    assert(allocItem(bitset) < 0);
    assert(getBit(bitset, 10) == 1);
    assert(freeItem(bitset, 10) == 0);
    assert(getBit(bitset, 10) == 0);
    assert(freeItem(bitset, 10) < 0);

    // testing file stuff
    writeBitSet("written.bin", bitset);
    FILE *fptr; 
    fptr = fopen("written.bin","rb");
    fseek(fptr, 0, SEEK_END); // seek to end of file
    int size = ftell(fptr); // size of file in bytes 
    fseek(fptr, 0, SEEK_SET);
    BitSet_p bitset2 = allocBitSet(size*8);
    readBitSet("written.bin", bitset2);

    for (int i = 0; i<NUM_BITS; i++){
        if (getBit(bitset,i) != getBit(bitset2,i)){  // if mismatch, print index and values
            printf("mismatch at %d\n", i);
            printf("bitset: %d\n", getBit(bitset,i));
            printf("bitset2: %d\n", getBit(bitset2,i));
        }
    }

    printf("sizeof bitset:  %ld\n", sizeof(bitset));
    printf("sizeof bitset buffer:  %ld\n", sizeof(bitset->buffer));
    return 0;



}


