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

int soma(int a, int b)
{
    return a + b;
}

int subtracao(int a, int b)
{
    return a - b;
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

list addList(list l, list r, int carry)
{
    if (r == NULL && l == NULL)
    {
        if (carry == 1)
        {
            return newlist(carry, NULL);
        }

        return NULL;
    }

    if (r == NULL)
    {
        return newlist(head(l) + carry, tail(l));
    }

    int sum = head(l) + head(r) + carry;

    int car = 0;

    if (sum > 9)
    {
        car = 1;
        sum = sum % 10;
    }

    return newlist(sum, addList(tail(l), tail(r), car));
}


char* bigIntAsString(bigInt x){
    list l = revert(getDigits(x));
    return listToString(l);
}
