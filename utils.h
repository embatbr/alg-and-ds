/*
 * Defines utils
 */


#define BOOL(x) (x ? "TRUE" : "FALSE")


void show_array_int(const int* input, const int length);


int* copy_array_int(const int* array, const int length);

char* copy_array_char(const char* array, const int length);


int strequal(const char* str_a, const char* str_b);


int call_question(const char* question, const char* desired);


char* int2str(const int num_param);

void int2str2(const int num_param, char* output);


void show_square_matrix(const int* matrix, const int size);

void show_matrix(const int* matrix, const int M, const int N);
