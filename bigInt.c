#include "bigInt.h"
#include "stdlib.h"
#include "stdio.h"

bigInt newBigInt(list digits)
{
    bigInt b = malloc(sizeof(struct bigInt));
    b->digits = digits;
    return b;
}

void printBigInt(bigInt x)
{
    list digits = getDigits(x);
    printList(digits);
}

list getDigits(bigInt x)
{
    return x->digits;
}

bigInt addBig(bigInt x, bigInt y)
{

    list lx = getDigits(x);
    list ly = getDigits(y);

    int lengthx = length(lx);
    int lengthy = length(ly);

    list l = ly;
    list r = lx;

    if (lengthx >= lengthy)
    {
        l = lx;
        r = ly;
    }

    list result = addList(l, r, 0);

    return newBigInt(result);
}


char* bigIntAsString(bigInt x){
    list l = revert(getDigits(x));
    return listToString(l);
}
