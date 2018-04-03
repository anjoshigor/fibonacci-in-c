#include "fibo.h"
#include "bigInt.h"
#include <stdio.h> /* to use sprintf*/

/*
 * Wrapper function
 */
char *recursiveFibo(int n)
{
    int result = recursiveFiboCalc(n);

    char *str = malloc(sizeof(char) * 12); /* enough space to store integers */
    sprintf(str, "%d", result);
    return str;
}

/*
 * Actual recursive function
 */
int recursiveFiboCalc(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return recursiveFiboCalc(n - 2) + recursiveFiboCalc(n - 1);
} 

char *dpFibo(int n)
{
    int *fib = malloc(sizeof(int) * (n + 1));

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    char *str = malloc(sizeof(char) * 12);
    sprintf(str, "%d", fib[n]);
    return str;
}

char *bigFibo(int n)
{

    bigInt *fib = malloc(sizeof(struct bigInt) * (n + 1)); /* allocating vector*/

    fib[0] = newBigInt(newlist(0, NULL)); /* storing bigInts instead of regular ints */
    fib[1] = newBigInt(newlist(1, NULL));

    for (int i = 2; i < n + 1; i++)
    {
        fib[i] = addBig(fib[i - 1], fib[i - 2]); /* using add function from bigInts*/
    }

    return bigIntAsString(fib[n]); /* using auxiliar function to convert bigInt to string*/
}