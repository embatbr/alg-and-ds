/*
 * Implementation
 */


#include <stdio.h>
#include <stdlib.h>

#include "lists.h"


Node* create_node(const int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    if(node == NULL) {
        exit(-1);
    }

    node->value = value;
    node->prev = node->next = NULL;

    return node;
}

void show_node_sufix(const Node* node, const char* sufix) {
    if(node == NULL) {
        printf("%p\n", NULL);
    }
    else {
        printf("%p: (%p, %d, %p)%s\n", node, node->prev, node->value, node->next, sufix);
    }
}

void show_node(const Node* node) {
    show_node_sufix(node, "");
}


LinkedList* create_empty_linked_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->length = 0;
    list->head = list->tail = NULL;
}

LinkedList* create_linked_list(const int* values, const int length) {
    LinkedList* list = create_empty_linked_list();
    list->length = length;

    int i;
    for (i = 0; i < length; i++) {
        int value = *(values + i);
        Node *node = create_node(value);

        if(list->head == NULL) {
            list->head = list->tail = node;
        }
        else {
            list->tail->next = node;
            node->prev = list->tail;
            list->tail = node;
        }
    }

    return list;
}

void show_list(const LinkedList* list) {
    if(list == NULL) {
        printf("%p\n", NULL);
    }
    else {
        printf("length: %d\n", list->length);

        Node* cur_node = list->head;
        while(cur_node != NULL) {
            if(cur_node == list->head) {
                show_node_sufix(cur_node, " [head]");
            }
            else if(cur_node == list->tail) {
                show_node_sufix(cur_node, " [tail]");
            }
            else {
                show_node(cur_node);
            }
            cur_node = cur_node->next;
        }
    }
}

void append_node(LinkedList* list, Node* node) {
    if(list->length > 0) {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    else {
        list->head = list->tail = node;
    }

    list->length++;
}

void append(LinkedList* list, const int value) {
    Node* node = create_node(value);
    append_node(list, node);
}

Node* find(const LinkedList* list, const int value) {
    Node* cur_node;

    for(cur_node = list->head; cur_node != NULL; cur_node = cur_node->next) {
        if(cur_node->value == value) {
            break;
        }
    }

    return cur_node;
}

/*
 * Assuming node is in the list
 */
void remove_node(LinkedList* list, Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;

    // node->prev = node->next = NULL;

    if(prev != NULL) {
        prev->next = next;
    }
    if(next != NULL) {
        next->prev = prev;
    }
    if(node == list->head) {
        list->head = next;
    }
    if(node == list->tail) {
        list->tail = prev;
    }

    list->length--;
}


/*
 * Functions for type NodeHashTable
 */


int node_hash_code(int key, int size) {
    return key % size;
}

NodeHashTable* create_node_hash_table(const int size) {
    if(size <= 0) {
        return NULL;
    }

    NodeHashTable* node_hash_table = (NodeHashTable*) malloc(sizeof(NodeHashTable));

    if(node_hash_table != NULL) {
        node_hash_table->size = size;
        node_hash_table->buckets = (Node**) malloc(size * sizeof(Node*));
    }

    return node_hash_table;
}

void put_node(const NodeHashTable* node_hash_table, const int key, Node* node) {
    int code = node_hash_code(key, node_hash_table->size);

    *(node_hash_table->buckets + code) = node;
}

Node* get_node(const NodeHashTable* node_hash_table, const int key) {
    int code = node_hash_code(key, node_hash_table->size);

    return *(node_hash_table->buckets + code);
}
