#ifndef BIGINT_H
#define BIGINT_H
#include "stdlib.h"
#include "list.h"

typedef struct bigInt
{
    list digits;
} * bigInt;

typedef list bigNum;

list addList(list l, list r, int carry);

bigInt newBigInt(list digits);

void printBigInt(bigInt x);

bigInt addBig(bigInt x, bigInt y);

bigInt subBig(bigInt x, bigInt y);

char* bigIntAsString(bigInt x);

list getDigits(bigInt x);

#endif