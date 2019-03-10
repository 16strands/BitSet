typedef struct BitSet{
    int count;
    char *buffer;
} BitSet, *BitSet_p;


BitSet* allocBitSet(int num_bits);

void freeBitSet(BitSet* b);

void setBit(BitSet* b, int i);

int clearBit(BitSet* b, int i);

bool getBit(BitSet* b, int i);

int allocItem(BitSet* b);

int freeItem(BitSet* b, int i);

void readBitSet(char* filename, BitSet* b);

void writeBitSet(char* filename, BitSet *b);






