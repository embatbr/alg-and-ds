/*
 * Testing
 */


#include <stdio.h>
#include <stdlib.h>

#include "lists.h"


void main() {
    int value = 0;
    Node* node = create_node(value);
    printf("Creating node with value %d:\n", value);
    show_node(node);

    int length = 10;
    int i;
    int* values = (int*) malloc(sizeof(int) * length);
    for (i = 0; i < length; i++) {
        *(values + i) = i + 11;
    }
    LinkedList* list = create_linked_list(values, length);
    printf("\nCreating list of length %d\n", length);
    show_list(list);

    value = 21;
    append(list, value);
    printf("\nAppend %d to list\n", value);
    show_list(list);

    value = 0;
    Node* found = find(list, value);
    printf("\nSearching a node with value %d\n", value);
    show_node(found);

    value = 12;
    found = find(list, value);
    printf("\nSearching a node with value %d\n", value);
    show_node(found);

    printf("\nCurrent list:\n");
    show_list(list);

    Node* head = list->head;
    printf("\nRemoving the head\n");
    remove_node(list, head);
    show_list(list);

    Node* tail = list->tail;
    printf("\nRemoving the tail\n");
    remove_node(list, tail);
    show_list(list);

    node = list->head->next->next->next;
    printf("\nRemoving the node ");
    show_node(node);
    remove_node(list, node);
    show_list(list);
}
