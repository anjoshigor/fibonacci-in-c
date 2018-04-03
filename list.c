#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#define RED "\033[31m" /* Red */
#define RESET "\033[0m"
#define GREEN "\033[32m" /* Green */

list newlist(int x, list r)
{
    list l = malloc(sizeof(struct intlist));
    l->value = x;
    l->rest = r;
    return l;
}

int head(list l)
{
    return l->value;
}

list tail(list l)
{
    return l->rest;
}

void printList(list l)
{
    if (l == NULL)
    {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", head(l));
    printList(tail(l));
}

int elem(int n, list l)
{

    if (n == 0)
        return l->value;

    int i = 1;
    list elem = l->rest;
    while (elem->rest && i != n)
    {
        elem = elem->rest;
        i++;
    }

    if (i != n)
    {
        printf(RED "\nNo element in position: %d! Returning -1 \n" RESET, n);
        return -1;
    }

    return elem->value;
}

int length(list l)
{
    if (l == NULL)
    {
        return 0;
    }

    return 1 + length(tail(l));
}

list append(list l1, list l2)
{
    if (l1 == NULL)
        return l2;

    return newlist(head(l1), append(tail(l1), l2));
}

list add(int x, list l, int pos)
{
    if (pos == 0)
        return newlist(x, l);
    else
        return newlist(head(l), add(x, tail(l), --pos));
}

list zipWith(int (*f)(int, int), list l, list r)
{

    if (l == NULL && r == NULL)
        return NULL;

    if (l == NULL && r != NULL)
        return newlist(head(r), tail(r));

    if (l != NULL && r == NULL)
        return newlist(head(l), tail(l));

    l->value = f(head(l), head(r));

    return newlist(head(l), zipWith(f, tail(l), tail(r)));
}

list map(int (*f)(int), list l)
{
    if (l == NULL)
        return NULL;

    l->value = f(head(l));

    return newlist(head(l), map(f, tail(l)));
}

list filter(bool (*f)(int), list l)
{

    if (l == NULL)
        return NULL;

    if (f(head(l)) == TRUE)
        return newlist(head(l), filter(f, tail(l)));

    return NULL;
}

list revert(list l)
{
    list a = l;
    list result = newlist(head(a), NULL);
    a = a->rest;

    while (a != NULL)
    {
        result = add(head(a), result, 0);
        a = a->rest;
    }

    return result;
}

char *recursivelistToString(list l, char *buffer, int i)
{
    if (l == NULL)
    {
        return '\0';
    }

    char aux = '0' + head(l);

    buffer[i] = aux;

    recursivelistToString(tail(l),buffer,++i);
}

char *listToString(list l)
{
    int size = length(l);
    char *result = malloc(sizeof(char) * size);

    recursivelistToString(l,result,0);

    return result;
}