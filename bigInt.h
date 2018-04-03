/**
 *  BIG INTEGER IMPLEMENTATION. Implementation of a Big Integer where its value is represented as a list. 
 */
#ifndef BIGINT_H
#define BIGINT_H
#include <stdlib.h>
#include "list.h"

/*
 * Struct:  bigInt 
 * --------------------
 * struct that represents a Big Integer
 *
 *  list: the digits list of the integer number
 *
 */
typedef struct bigInt
{
    list digits;
} * bigInt;

/*
 * Function:  newBigInt 
 * --------------------
 * Big Integer constructor
 *
 *  digits: a list of digits to be used in the new Big Integer
 * 
 *  returns: a new Big Integer with the list of digits provided
 */
bigInt newBigInt(list digits);


/*
 * Function:  printBigInt 
 * --------------------
 * prints a Big Integer as a list of integers:
 *      3 -> 2 -> 1 -> NULL
 *
 *  x: the Big Integer to be printed
 */
void printBigInt(bigInt x);


/*
 * Function:  addBig 
 * --------------------
 * does the sum of two Big Integers as we normally do
 * on primary school using a carry-one. It uses the addList
 * from list.h
 *
 *  x: the leftmost Big Integer to be used in the sum
 *  y: the rightmost Big Integer to be used in the sum
 *
 *  returns: a Big Integer as the result of th sum of two Big Integers
 */
bigInt addBig(bigInt x, bigInt y);

/*
 * Function:  bigIntAsString 
 * --------------------
 * returns a string from the Big Integer's list of digits
 *
 *  x: the Big Integer from which the string will be returned
 *
 *  returns: a string
 */
char* bigIntAsString(bigInt x);

/*
 * Function:  getDigits 
 * --------------------
 * gets the list of digits from a Big Integer
 *
 *  x: the Big Integer from which the list will be retrieved
 *
 *  returns: a list of digits
 */
list getDigits(bigInt x);

#endif