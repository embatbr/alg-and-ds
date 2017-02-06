/*
 * Testing
 */


#include <stdio.h>
#include <stdlib.h>

#include "../utils.h"
#include "sorting.h"


void main() {
    printf("### Tests for Algorithms ###\n\n");
    printf("##### Mergesort #####\n");

    int input[] = {6, 5, 3, 1, 8, 7, 2, 4};
    show_array_int(input, 8);
    mergesort_int(input, 8);
    show_array_int(input, 8);

    printf("\n");

    int input2[] = {5, 1, 4, 0, 7, 8, 9, 8, 2};
    show_array_int(input2, 9);
    mergesort_int(input2, 9);
    show_array_int(input2, 9);

    printf("\n");

    char input3[] = "aifasoid";
    printf("%s\n", input3);
    mergesort_char(input3, 8);
    printf("%s\n", input3);
}
