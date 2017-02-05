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
    node->next = NULL;

    return node;
}

void show_node(const Node* node) {
    if(node == NULL) {
        printf("%p\n", NULL);
    }
    else {
        printf("%p: (%d, %p)\n", node, node->value, node->next);
    }
}


LinkedList* create_linked_list(const int* values, const int length) {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
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
            list->tail = list->tail->next;
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
        printf("head: %p\n", list->head);
        printf("tail: %p\n", list->tail);

        Node* cur = list->head;
        while(cur != NULL) {
            show_node(cur);
            cur = cur->next;
        }
    }
}

void append(LinkedList* list, const int value) {
    list->tail->next = create_node(value);
    list->tail = list->tail->next;
    list->length++;
}

Node* insert_value(LinkedList* list, const int value, const int index) {
    if((index < 0) || (index > list->length)) {
        return NULL;
    }

    Node* new_node = create_node(value);

    if(index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    }
    else if(index == list->length) {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    else {
        Node* prev_node = NULL;
        Node* cur_node = list->head;
        int cur_index = 0;

        while(cur_index < index) {
            prev_node = cur_node;
            cur_node = cur_node->next;
            cur_index++;
        }

        new_node->next = cur_node;
        prev_node->next = new_node;
    }

    list->length++;
    return new_node;
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

Node** find_all(const LinkedList* list, const int value) {
    Node** nodes = (Node**) malloc(list->length * sizeof(Node*));

    Node* cur_node;
    int i = 0;

    for(cur_node = list->head; cur_node != NULL; cur_node = cur_node->next) {
        if(cur_node->value == value) {
            *(nodes + i) = cur_node;
            i++;
        }
    }

    return nodes;
}

Node* remove_by_index(LinkedList* list, const int index) {
    if((index < 0) || (index > list->length)) {
        return NULL;
    }

    Node* prev_node = NULL;
    Node* cur_node = list->head;
    int cur_index = 0;

    while(cur_index < index) {
        prev_node = cur_node;
        cur_node = cur_node->next;
        cur_index++;
    }

    if(index == 0) {
        list->head = list->head->next;
    }
    else {
        prev_node->next = cur_node->next;

        if(cur_index == list->length - 1) {
            list->tail = prev_node;
        }
    }

    list->length--;

    return cur_node;
}

Node* remove_value(LinkedList* list, const int value) {
    Node* prev_node = NULL;
    Node* cur_node;

    for(cur_node = list->head; cur_node != NULL; cur_node = cur_node->next) {
        if(cur_node->value == value) {
            if(prev_node == NULL) {
                list->head = cur_node->next;
            }
            else {
                prev_node->next = cur_node->next;

                if(list->tail == cur_node) {
                    list->tail = prev_node;
                }
            }

            list->length--;
            break;
        }
        else {
            prev_node = cur_node;
        }
    }

    return cur_node;
}

Node** remove_all_values(LinkedList* list, const int value) {
    Node** nodes = (Node**) malloc(list->length * sizeof(Node*));

    Node* prev_node = NULL;
    Node* cur_node;
    int i = 0;

    for(cur_node = list->head; cur_node != NULL; cur_node = cur_node->next) {
        if(cur_node->value == value) {
            *(nodes + i) = cur_node;
            i++;

            if(prev_node == NULL) {
                list->head = cur_node->next;
            }
            else {
                prev_node->next = cur_node->next;

                if(list->tail == cur_node) {
                    list->tail = prev_node;
                }
            }

            list->length--;
        }
        else {
            prev_node = cur_node;
        }
    }

    return nodes;
}
