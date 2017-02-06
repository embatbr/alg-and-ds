/*
 * Implementation
 */


#include <stdio.h>
#include <stdlib.h>

#include "hashes.h"


/*
 * Functions for type HashObject
 */


int hash_code(int key, int size) {
    return key % size;
}

HashObject* create_hash_object(const int key, const int value, char* types, const int code) {
    HashObject* hash_object = (HashObject*) malloc(sizeof(HashObject));

    if(hash_object != NULL) {
        hash_object->key = key;
        hash_object->value = value;
        hash_object->types = types;
        hash_object->code = code;

        hash_object->prev = hash_object->next = hash_object->tail = NULL;
        hash_object->length = 0;
    }

    return hash_object;
}

void show_hash_object(const HashObject* hash_object, const int is_linked) {
    if(hash_object == NULL) {
        printf("%p\n", NULL);
    }
    else {
        if(!is_linked || hash_object->tail != NULL) {
            printf("(%d) ", hash_object->code);
        }

        if(*hash_object->types == 'i') {
            printf("[%d: ", hash_object->key);
        }
        else if(*hash_object->types == 'c') {
            printf("[%c: ", hash_object->key);
        }

        if(*(hash_object->types + 1) == 'i') {
            printf("%d]", hash_object->value);
        }
        else if(*(hash_object->types + 1) == 'c') {
            printf("%c]", hash_object->value);
        }

        if(is_linked) {
            printf("->");
        }
        else {
            printf("\n");
        }
    }
}

void show_linked_hash_objects(HashObject* hash_object) {
    HashObject* cur_hash_object;
    for(cur_hash_object = hash_object; cur_hash_object != NULL; cur_hash_object = cur_hash_object->next) {
        show_hash_object(cur_hash_object, 1);
    }
    show_hash_object(cur_hash_object, 1);
}


/*
 * Functions for type HashTable
 */


HashTable* create_hash_table(const int size) {
    if(size <= 0) {
        return NULL;
    }

    HashTable* hash_table = (HashTable*) malloc(sizeof(HashTable));

    if(hash_table != NULL) {
        hash_table->size = size;
        hash_table->buckets = (HashObject**) malloc(size * sizeof(HashObject*));
    }

    return hash_table;
}

void show_hash_table(const HashTable* hash_table) {
    if(hash_table == NULL) {
        printf("%p\n", NULL);
    }
    else {
        printf("size: %d\n", hash_table->size);
        printf("buckets:\n");

        int i, empty = 1;
        for(i = 0; i < hash_table->size; i++) {
            HashObject* bucket = *(hash_table->buckets + i);
            if(bucket != NULL) {
                empty = 0;
                show_linked_hash_objects(bucket);
            }
        }

        if(empty) {
            printf("EMPTY\n");
        }
    }
}

HashObject* put(const HashTable* hash_table, const int key, const int value, char* types) {
    HashObject* hash_object = NULL;

    int code = hash_code(key, hash_table->size);
    hash_object = *(hash_table->buckets + code);

    if(hash_object == NULL) {
        HashObject* new_hash_object = create_hash_object(key, value, types, code);
        new_hash_object->length = 1;
        new_hash_object->tail = new_hash_object;

        *(hash_table->buckets + code) = new_hash_object;

        return new_hash_object;
    }
    else {
        // TODO extract it to function get
        char key_type = *types;
        for(; hash_object != NULL; hash_object = hash_object->next) {
            if(hash_object->key == key && *hash_object->types == key_type) {
                break;
            }
        }

        HashObject* new_hash_object = hash_object;
        if(new_hash_object != NULL) {
            new_hash_object->value = value;
            new_hash_object->types = types;
        }
        else {
            new_hash_object = create_hash_object(key, value, types, code);

            HashObject* tail = (*(hash_table->buckets + code))->tail;
            tail->next = new_hash_object;
            new_hash_object->prev = tail;

            (*(hash_table->buckets + code))->length++;
            (*(hash_table->buckets + code))->tail = new_hash_object;
        }

        return new_hash_object;
    }

    return NULL;
}

// HashObject* get(const HashTable* hash_table, const int key) {
//     int num_attempts = 0;

//     while(num_attempts < hash_table->size) {
//         int code = hash_code(key, hash_table->size, num_attempts);

//         HashObject* hash_object = *(hash_table->buckets + code);
//         if(hash_object == NULL) {
//             return NULL;
//         }
//         else if(hash_object->key == key) {
//             if(!hash_object->valid) {
//                 return NULL;
//             }

//             return hash_object;
//         }

//         num_attempts++;
//     }

//     return NULL;
// }

// HashObject* pop(const HashTable* hash_table, const int key) {
//     HashObject* hash_object = get(hash_table, key);

//     if((hash_object != NULL) && (hash_object->key == key) && hash_object->valid) {
//         hash_object->valid = 0;
//     }

//     return hash_object;
// }
