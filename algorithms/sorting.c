/*
 * Implementation
 */


#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"


void show_array(const int* input, const int length) {
    int i;
    for(i = 0; i < length; i++) {
        printf("%d%c", input[i], i == (length - 1) ? '\n' : ' ');
    }
}


void _mergesort(int* input, const int begin, const int end, int* output) {
    int middle = (begin + end) / 2;

    if(end - begin > 2) { // O(logN)
        _mergesort(input, begin, middle, output);
        _mergesort(input, middle, end, output);
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

void mergesort(int* input, const int length) {
    int* output = (int*) malloc(length * sizeof(int));
    _mergesort(input, 0, length, output);
}
