/**
 *  LIST IMPLEMENTATION. Implementation of a list data structure and its useful functions. 
 */

#ifndef LIST_H
#define LIST_H

/*
 * Enum:  bool 
 * --------------------
 * since C does not have a boolean type, this enum
 * acts like it. To be used on filter function
 */
typedef enum Bool {
    FALSE,
    TRUE,
} bool;

/*
 * Struct:  list 
 * --------------------
 * struct that represents list data structure for integers
 *
 *  value: the actual integer value stored in the list
 *  rest: a pointer to the remaining list. (NULL if it's the last item of the list)
 *
 */
typedef struct intlist
{
    int value;
    struct intlist *rest;
} * list;

/*
 * Function:  newlist 
 * --------------------
 * constructor of a list
 *
 *  x: integer value to be stored in the list
 *  r: the remaining list
 *
 *  returns: a list with the head (x) and tail (r)
 */
list newlist(int x, list r);

/*
 * Function:  head 
 * --------------------
 * gets the head (i.e first element) of a list
 *
 *  l: list which the head will be retrieved
 *
 *  returns: an integer value corresponding to the head of the list
 */
int head(list l);

/*
 * Function:  tail 
 * --------------------
 * gets the tail (i.e remaining elements) of a list
 *
 *  l: list which the tail will be retrieved
 *
 *  returns: another list corresponding to the tail of the list l
 */
list tail(list l);

/*
 * Function:  printList 
 * --------------------
 * prints a list in the following format:
 *          1 -> 2 -> 3 -> NULL
 *
 *  l: list to be printed
 */
void printList(list l);

/*
 * Function:  elem 
 * --------------------
 * retrieves an element in a given position of a list
 *
 *  n: position of the element on the list
 *  l: list where the element is
 *
 *  returns: the value of the element in the given position or
 *            or -1 if the position is invalid
 */
int elem(int n, list l);

/*
 * Function:  lenght 
 * --------------------
 * calculates the lenght of a given list
 *
 *  l: list to have the lenght calculated
 *
 *  returns: an integer corresponding to
 *           the number of elements on a given list
 */
int length(list l);

/*
 * Function:  append 
 * --------------------
 * appends two list together
 *
 *  l1: first list to be appended
 *  l2: second list to be appended
 *
 *  returns: a third list with the result of appending
 *           the beggining of l2 in l1 (i.e l1+l2)
 */
list append(list l1, list l2);

/*
 * Function:  add 
 * --------------------
 * adds an element in a given list on a given position
 *
 *  x: the element to be added
 *  l: the list where the element will be added
 *  pos: the position to add the element
 *
 *  returns: a list with the new element added on the given position
 */
list add(int x, list l, int pos);

/*
 * Function:  map 
 * --------------------
 * applies a given function to all elements in a list
 *
 *  f: the function to be applied
 *  l: the list where the function will be applied
 *
 *  returns: a list with the elements modified
 *           by the given function
 */
list map(int (*f)(int), list l);

/*
 * Function:  zipWith 
 * --------------------
 * applies a given function using elements from 2 lists.
 * It will take an element from each list and apply the function
 * and store in a third function.
 *
 *  f: a function that takes two integers and returns an integer
 *  l: the left list from which the elements will be taken
 *  r: the right list from which the elements will be taken
 * 
 *  returns: a list with the result of the function applied to
 *           the elements of both lists. If one list is bigger
 *           than the other, the remaining elements from the bigger will be intact
 */
list zipWith(int (*f)(int, int), list l, list r);

/*
 * Function:  filter 
 * --------------------
 * removes elements of the list according to a given boolean function
 *
 *  f: a boolean function to be used as a filter
 *  l: the list where the function will be applied
 * 
 *  returns: a list with the elements that returned True when
 *           applied to the f function
 */
list filter(bool (*f)(int), list l);

/*
 * Function:  revert 
 * --------------------
 * reverts a list
 *
 *  l: the list to be reverted
 * 
 *  returns: a list reverted
 */
list revert(list l);

/*
 * Function:  recursivelistToString 
 * --------------------
 * the actual function that takes an list and returns all 
 * its integer elements as a string recursivelly
 *
 *  l: the list to converted
 * 
 *  returns: a string with all elements of the list
 */
char *recursivelistToString(list l, char *buffer, int i);

/*
 * Function:  listToString 
 * --------------------
 * wrapper function for recursivelistToString function.
 * It allocates the buffer and starts the iterator
 *
 *  l: the list to converted
 * 
 *  returns: a string with all elements of the list
 */
char *listToString(list l);

/*
 * Function:  addList 
 * --------------------
 * a function that sums the elements from two lists
 * using decimal notation
 *
 *  l: the leftmost list to be used in the sum
 *  r: the rightmost list to be used in the sum
 *
 *  returns: a list as the result of th sum of two lists
 */
list addList(list l, list r, int carry);

#endif