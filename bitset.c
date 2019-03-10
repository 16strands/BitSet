#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#include "bitset.h"


BitSet* allocBitSet(int num_bits){ // allocates and returns a pointer to a BitSet
    int size = ceil(num_bits/8);
    BitSet_p bitset = malloc(sizeof(BitSet));
    bitset->buffer = malloc(size);
    bitset->count = num_bits;
    return bitset;
}

void freeBitSet(BitSet* b){ // frees a BitSet
    free(b->buffer); 
    free(b);
}

void setBit(BitSet* b, int i){ // sets bit i of the BitSet
    int byte = (i/8);
    b->buffer[byte] |= (1 << i%8);
}

int clearBit(BitSet* b, int i){ // clears bit i of the BitSet
    int byte = (i/8);
    b->buffer[byte] &= ~(1 << i%8);
    return 0;
}

bool getBit(BitSet* b, int i){ // returns the bit (boolean) value of the ith bit of the BitSet
    int byte = (i/8);
    return (b->buffer[byte] & ( 1 << i%8 ));
}

// This kind of data structure can be used to track, for example, the free status of an array of items. 
// Therefore, given a Bit Set implementation, you could easily build on top of it an allocate/free interface like this one:

int allocItem(BitSet* b){ // returns the index of an item that was free, but is now allocated. 
// If there are no more free items, returns a negative number
    for (int i=0; i < b->count; i++){
        if (getBit(b, i) == 0){
            setBit(b, i);
            return i;
        }
    }
    return -1;
}


int freeItem(BitSet* b, int i){ // frees the item at location i, first checking that it wasn't already free. 
// Returns 0 on success, <0 if there was an error
    if (getBit(b,i) == 1){
        clearBit(b,i);
        return 0;
    }
    return -1;
}

// Since we want this Bit Set implementation to be persistent, we have read and write functions:
void readBitSet(char* filename, BitSet* b){ // reads, from file f, a Bit Set into the memory pointed to by b.
    freeBitSet(b);
    FILE *fptr; 
    fptr = fopen(filename,"rb");
    assert(fptr != NULL && "File unable to be opened.");
    fseek(fptr, 0, SEEK_END); // seek to end of file
    int size = ftell(fptr); // size of file in bytes 
    fseek(fptr, 0, SEEK_SET); // seek back to beginning of file
    fread(b->buffer,8,ceil(size/8),fptr); 
    b->count = size*8;
    fclose(fptr);
}

void writeBitSet(char* filename, BitSet *b){ // writes Bit Set b to file f
    FILE *fptr;
    fptr = fopen(filename,"wb");
    assert(fptr != NULL && "File unable to be opened.");
    int size = ceil(b->count/8);
    fwrite(b->buffer,8,ceil(size/8),fptr);
    fclose(fptr);
}







