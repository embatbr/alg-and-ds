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


char* int2str(const int num_param) {
    int num = num_param;
    int digit, num_digits = 0;

    // count string size
    do {
        double num_d = (double) num;
        digit = (int) ((num_d/10 - num/10) * 10);
        num_digits++;
        num = num / 10;
    }
    while(num != 0);

    // allocate string
    char* digits = (char*) malloc(num_digits * sizeof(char));

    int i;
    num = num_param;

    // parse
    for(i = num_digits - 1; i >= 0; i--) {
        double num_d = (double) num;
        digit = (int) ((num_d/10 - num/10 + 0.01) * 10); // 0.01 is to correct the decimal imprecision

        *(digits + i) = digit + 48;

        num = num / 10;
    }

    return digits;
}

void int2str2(const int num_param, char* output) {
    int num = num_param;
    int digit, num_digits = 0;

    // count string size
    do {
        double num_d = (double) num;
        digit = (int) ((num_d/10 - num/10) * 10);
        num_digits++;
        num = num / 10;
    }
    while(num != 0);

    int i;
    num = num_param;

    // parse
    for(i = num_digits - 1; i >= 0; i--) {
        double num_d = (double) num;
        digit = (int) ((num_d/10 - num/10 + 0.01) * 10); // 0.01 is to correct the decimal imprecision

        *(output + i) = digit + 48;

        num = num / 10;
    }
}


void show_square_matrix(const int* matrix, const int size) {
    show_matrix(matrix, size, size);
}

void show_matrix(const int* matrix, const int M, const int N) {
    int i;
    for(i = 0; i < M; i++) {
        int j;
        for(j = 0; j < N; j++) {
            int position = i*N + (j % N);
            int element = matrix[position];
            char sep = ((j + 1) % N) == 0 ? '\n' : ' ';

            printf("%4d%c", element, sep);
        }
    }
}
