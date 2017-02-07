/*
 * Implementation
 */


#include <stdio.h>
#include <stdlib.h>

#include "hashes.h"


/*
 * Functions for type HashItem
 */


int hash_code(int key, int size) {
    return key % size;
}

HashItem* create_hash_item(const int key, const int value, char* types, const int code) {
    HashItem* hash_item = (HashItem*) malloc(sizeof(HashItem));

    if(hash_item != NULL) {
        hash_item->key = key;
        hash_item->value = value;
        hash_item->types = types;
        hash_item->code = code;

        hash_item->prev = hash_item->next = hash_item->tail = NULL;
        hash_item->length = 0;
    }

    return hash_item;
}

void show_hash_item(const HashItem* hash_item, const int is_linked) {
    if(hash_item == NULL) {
        printf("%p\n", NULL);
    }
    else {
        if(is_linked && hash_item->tail != NULL) { // is the 1st element in list
            printf("(%d,%d) ", hash_item->code, hash_item->length);
        }
        else if(!is_linked) {
            printf("(%d) ", hash_item->code);
        }

        if(*hash_item->types == 'i') {
            printf("[%d: ", hash_item->key);
        }
        else if(*hash_item->types == 'c') {
            printf("[%c: ", hash_item->key);
        }

        if(*(hash_item->types + 1) == 'i') {
            printf("%d]", hash_item->value);
        }
        else if(*(hash_item->types + 1) == 'c') {
            printf("%c]", hash_item->value);
        }

        if(is_linked) {
            printf("->");
        }
        else {
            printf("\n");
        }
    }
}

void show_linked_hash_items(HashItem* hash_item) {
    HashItem* cur_hash_item;
    for(cur_hash_item = hash_item; cur_hash_item != NULL; cur_hash_item = cur_hash_item->next) {
        show_hash_item(cur_hash_item, 1);
    }
    show_hash_item(cur_hash_item, 1);
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
        hash_table->buckets = (HashItem**) malloc(size * sizeof(HashItem*));
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
            HashItem* bucket = *(hash_table->buckets + i);
            if(bucket != NULL) {
                empty = 0;
                show_linked_hash_items(bucket);
            }
        }

        if(empty) {
            printf("EMPTY\n");
        }
    }
}

HashItem* put(const HashTable* hash_table, const int key, const int value, char* types) {
    HashItem* hash_item = NULL;

    hash_item = get(hash_table, key, *types);

    if(hash_item != NULL) {         // replace the value
        hash_item->value = value;
        hash_item->types = types;
    }
    else {
        int code = hash_code(key, hash_table->size);
        hash_item = create_hash_item(key, value, types, code);

        HashItem* head = *(hash_table->buckets + code);
        if(head == NULL) {
            head = hash_item;
            *(hash_table->buckets + code) = head;
            head->tail = head;
        }
        else {
            head->tail->next = hash_item;
            hash_item->prev = head->tail;

            head->tail = head->tail->next;
        }

        head->length++;
    }

    return hash_item;
}

HashItem* get(const HashTable* hash_table, const int key, const char key_type) {
    int code = hash_code(key, hash_table->size);
    HashItem* hash_item = *(hash_table->buckets + code);

    while(hash_item != NULL && (hash_item->key != key || *hash_item->types != key_type)) {
        hash_item = hash_item->next;
    }

    return hash_item;
}

HashItem* pop(const HashTable* hash_table, const int key, const char key_type) {
    HashItem* hash_item = get(hash_table, key, key_type);

    if(hash_item != NULL) {
        int code = hash_item->code;
        HashItem* head = *(hash_table->buckets + code);

        if(hash_item == head) {
            HashItem* new_head = head->next;
            if(head->next != NULL) {
                head->next->prev = NULL;
                head->next->length = head->length - 1;
                head->next->tail = head->tail;
            }

            *(hash_table->buckets + code) = head->next;
        }
        else {
            HashItem* prev = hash_item->prev;
            HashItem* next = hash_item->next;
            hash_item->prev = hash_item->next = NULL;

            prev->next = next;
            if(hash_item == head->tail) {      // hash_item is tail
                head->tail = prev;
            }
            else {
                next->prev = prev;
            }

            head->length--;
        }
    }

    return hash_item;
}
