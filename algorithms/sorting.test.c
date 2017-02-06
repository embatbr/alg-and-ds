/*
 * Testing
 */


#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"


void main() {
    printf("### Tests for Algorithms ###\n\n");
    printf("##### Mergesort #####\n");

    int input[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int* output = (int*) malloc(8 * sizeof(int));
    show_array(input, 8);
    mergesort(input, 8);
    show_array(input, 8);

    printf("\n");

    int input2[] = {5, 1, 4, 0, 7, 8, 9, 8, 2};
    int* output2 = (int*) malloc(9 * sizeof(int));
    show_array(input2, 9);
    mergesort(input2, 9);
    show_array(input2, 9);
}
