/*
 * Implementation
 */


#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"


void _mergesort_int(int* input, const int begin, const int end, int* output) {
    int middle = (begin + end) / 2;

    if(end - begin > 2) { // O(logN)
        _mergesort_int(input, begin, middle, output);
        _mergesort_int(input, middle, end, output);
    }

    int left = begin, right = middle;
    int i = begin;

    while(left < middle && right < end) {
        if(input[left] <= input[right]) {
            output[i] = input[left];
            left++;
        }
        else {
            output[i] = input[right];
            right++;
        }

        i++;
    }

    while(left < middle) {
        output[i] = input[left];
        i++;
        left++;
    }

    while(right < end) {
        output[i] = input[right];
        i++;
        right++;
    }

    i = begin;
    while(i < end) {
        input[i] = output[i];
        i++;
    }
}

void mergesort_int(int* input, const int length) {
    int* output = (int*) malloc(length * sizeof(int));
    _mergesort_int(input, 0, length, output);
}


void _mergesort_char(char* input, const int begin, const int end, char* output) {
    int middle = (begin + end) / 2;

    if(end - begin > 2) { // O(logN)
        _mergesort_char(input, begin, middle, output);
        _mergesort_char(input, middle, end, output);
    }

    int left = begin, right = middle;
    int i = begin;

    while(left < middle && right < end) {
        if(input[left] <= input[right]) {
            output[i] = input[left];
            left++;
        }
        else {
            output[i] = input[right];
            right++;
        }

        i++;
    }

    while(left < middle) {
        output[i] = input[left];
        i++;
        left++;
    }

    while(right < end) {
        output[i] = input[right];
        i++;
        right++;
    }

    i = begin;
    while(i < end) {
        input[i] = output[i];
        i++;
    }
}

void mergesort_char(char* input, const int length) {
    char* output = (char*) malloc(length * sizeof(char));
    _mergesort_char(input, 0, length, output);
}
