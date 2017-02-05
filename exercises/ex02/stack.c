/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42; // Sets every value to 42
    }
    return array; // Returns a pointer
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array); // This points to the address of the previous array

    for (i=0; i<SIZE; i++) {
    array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo(); // array is assigned to a pointer referencing the array
    // inside the function, which is destroyed after foo() is finished.
    bar();

    for (i=0; i<SIZE; i++) {
    printf("%d\n", array[i]);
    }

    return 0;
}
