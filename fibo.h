/**
 *  FIBONACCI FUNCTIONS. A set of fuctions to handle fibonacci calculations. 
 */

#ifndef FIBO_H
#define FIBO_H
#include "bigInt.h"

/*
 * Function:  recursiveFibo 
 * --------------------
 * wrappers the fibonacci's computation of a number using recursion
 *
 *  n: number to be used on fibonacci calculation
 *
 *  returns: a string from the decimal number
 *           calculated using the recursiveFiboCal
 *           it could take a long time to process big numbers
 */
char *recursiveFibo(int n);

/*
 * Function:  recursiveFiboCalc 
 * --------------------
 * the actual fibonacci's computation of a number using recursion
 *
 *  n: number to be used on fibonacci calculation
 *
 *  returns: an integer value as the result of fibonacci calculation
 *           it could take a long time to process big numbers
 */
int recursiveFiboCalc(int n);

/*
 * Function:  dpFibo 
 * --------------------
 * fibonacci's computation using dynamic programming
 *
 *  n: number to be used on fibonacci calculation
 *
 *  returns: a string from the decimal number
 *           calculated using the fibonacci calculation
 *           it could return negative numbers with big n due to int overflow
 */
char *dpFibo(int n);

/*
 * Function:  bigFibo 
 * --------------------
 * fibonacci's computation using dynamic programming and Big Integer
 *
 *  n: number to be used on fibonacci calculation
 *
 *  returns: a string from the decimal number
 *           calculated using the fibonacci calculation
 *           @see bigInt.h for more details about Big Integers
 */
char *bigFibo(int n);

#endif