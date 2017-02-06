/*
 * Implementation
 */


#include <stdio.h>
#include <stdlib.h>

#include "utils.h"


void show_array_int(const int* input, const int length) {
    int i;
    for(i = 0; i < length; i++) {
        printf("%d%c", input[i], i == (length - 1) ? '\n' : ' ');
    }
}


int* copy_array_int(const int* array, const int length) {
    int* copy = (int*) malloc(length * sizeof(int));

    if(copy != NULL) {
        int i;
        for(i = 0; i < length; i++) {
            copy[i] = array[i];
        }
    }

    return copy;
}

char* copy_array_char(const char* array, const int length) {
    char* copy = (char*) malloc(length * sizeof(char));

    if(copy != NULL) {
        int i;
        for(i = 0; i < length; i++) {
            copy[i] = array[i];
        }
    }

    return copy;
}


int strequal(const char* str_a, const char* str_b) {
    return strcmp(str_a, str_b) == 0;
}


int call_question(const char* question, const char* desired) {
    return strequal(question, "all") || strequal(question, desired);
}
