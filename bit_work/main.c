#include <stdio.h>
#include <stdbool.h>

#define INT_SIZE 32

// A collection of Bit manipulation functions

// Set the bit in the pointer value
void setBit(int bit, int *value)
{
    int temp = 1 << bit;
    *value |= temp;
}

// Clear the bit in the referenced value
void clearBit(int bit, int *value)
{
    int temp = 1 << bit;
    temp = ~temp;
    *value &= temp;
}

// Take an 32-bit integer and turn it into an array
void getBoolArray(int value, bool *bool_array[INT_SIZE])
{
    for (int i = 0; i < INT_SIZE; i++)
    {
        *bool_array[i] = (value >> i & 1);
    }
}

// Human read print of the boolean array
void printBoolArray(bool *bool_array[INT_SIZE])
{

    printf("Printing bool array %x", bool_array);
}

// Convert the bool array back into a 32 bit int
int getIntFromBoolArray(bool *bool_array[INT_SIZE])
{

    int value = 0;
    for (int i = 0; i < INT_SIZE; i++)
    {

        if (*bool_array[i])
            setBit(i, &value);
    }

    return value;
}

int main()
{

    for (int i = 0; i < INT_SIZE; i++)
    {

        int v = 0x00000000;
        setBit(i, &v);
        printf("Set Bit %d \t: 0x%08x\n", i, v);
    }

    for (int i = 0; i < INT_SIZE; i++)
    {
        int v =0xffffffff;
        clearBit(i, &v);
        printf("Set Bit %d \t: 0x%x\n", i, v);
    }

    bool *boolArray[INT_SIZE];

    getBoolArray(0x5555aaaa, boolArray);

    printBoolArray(boolArray);

    int bees = getIntFromBoolArray(boolArray);
    printf("Set Bit 0x%x\n", bees);
    return 0;
}