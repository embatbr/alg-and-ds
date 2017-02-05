/*
 * Implementation
 */


#include <stdio.h>
#include <stdlib.h>

#include "hashes.h"


/*
 * Functions for type HashObject
 */


int hash_code(int key, int size, int offset) {
    int code = (key + offset) % size;
    return code;
}

HashObject* create_hash_object(const int key, const int value, const char* types, const int code) {
    HashObject* hash_object = (HashObject*) malloc(sizeof(HashObject));

    if(hash_object != NULL) {
        hash_object->key = key;
        hash_object->key_type = *types;
        hash_object->value = value;
        hash_object->value_type = *(types + 1);
        hash_object->code = code;
        hash_object->valid = 1;
    }

    return hash_object;
}

void show_hash_object(const HashObject* hash_object) {
    if((hash_object == NULL) || !hash_object->valid) {
        printf("%p\n", NULL);
    }
    else {
        printf("[%d] -> ", hash_object->code);

        if(hash_object->key_type == 'i') {
            printf("%d: ", hash_object->key);
        }
        else if(hash_object->key_type == 'c') {
            printf("%c: ", hash_object->key);
        }

        if(hash_object->value_type == 'i') {
            printf("%d\n", hash_object->value);
        }
        else if(hash_object->value_type == 'c') {
            printf("%c\n", hash_object->value);
        }
    }
}


/*
 * Functions for type HashTable
 */


HashTable* create_hash_table(const int size) {
    HashTable* hash_table = (HashTable*) malloc(sizeof(HashTable));

    if((hash_table == NULL) || (size <= 0)) {
        return NULL;
    }

    hash_table->size = size;
    hash_table->buckets = (HashObject**) malloc(size * sizeof(HashObject*));

    return hash_table;
}

void show_hash_table(const HashTable* hash_table) {
    if(hash_table == NULL) {
        printf("%p\n", NULL);
    }
    else {
        printf("size: %d\n", hash_table->size);
        printf("buckets:\n");
        int i;
        for(i = 0; i < hash_table->size; i++) {
            HashObject* bucket = *(hash_table->buckets + i);
            show_hash_object(bucket);
        }
    }
}

int put(const HashTable* hash_table, const int key, const int value, const char* types) {
    int num_attempts = 0;

    HashObject* hash_object = NULL;

    while(num_attempts < hash_table->size) {
        int code = hash_code(key, hash_table->size, num_attempts);
        hash_object = *(hash_table->buckets + code);

        if((hash_object == NULL) || !hash_object->valid || (hash_object->key == key)) {
            if((hash_object != NULL) && !hash_object->valid) {
                show_hash_object(hash_object);
            }

            HashObject* hash_object = create_hash_object(key, value, types, code);
            *(hash_table->buckets + code) = hash_object;

            return code;
        }

        num_attempts++;
    }

    return -1;
}

HashObject* get(const HashTable* hash_table, const int key) {
    int num_attempts = 0;

    while(num_attempts < hash_table->size) {
        int code = hash_code(key, hash_table->size, num_attempts);

        HashObject* hash_object = *(hash_table->buckets + code);
        if(hash_object == NULL) {
            return NULL;
        }
        else if(hash_object->key == key) {
            if(!hash_object->valid) {
                return NULL;
            }

            return hash_object;
        }

        num_attempts++;
    }

    return NULL;
}

HashObject* pop(const HashTable* hash_table, const int key) {
    HashObject* hash_object = get(hash_table, key);

    if((hash_object != NULL) && (hash_object->key == key) && hash_object->valid) {
        hash_object->valid = 0;
    }

    return hash_object;
}
