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

    value = 13;
    int index = -1;
    printf("\nInsert %d into list at position %d\n", value, index);
    Node* new_node = insert_value(list, value, index);
    show_node(new_node);

    value = 13;
    index = list->length + 1;
    printf("\nInsert %d into list at position %d\n", value, index);
    new_node = insert_value(list, value, index);
    show_node(new_node);

    value = 13;
    index = 5;
    printf("\nInsert %d into list at position %d\n", value, index);
    new_node = insert_value(list, value, index);
    show_node(new_node);
    printf("List:\n");
    show_list(list);

    value = 80;
    index = 0;
    printf("\nInsert %d into list at position %d\n", value, index);
    new_node = insert_value(list, value, index);
    show_node(new_node);
    printf("List:\n");
    show_list(list);

    value = -200;
    index = list->length;
    printf("\nInsert %d into list at position %d\n", value, index);
    new_node = insert_value(list, value, index);
    show_node(new_node);
    printf("List:\n");
    show_list(list);

    value = 0;
    Node* found = find(list, value);
    printf("\nSearching a node with value %d\n", value);
    show_node(found);

    value = 12;
    found = find(list, value);
    printf("\nSearching a node with value %d\n", value);
    show_node(found);

    value = 0;
    Node** nodes = find_all(list, value);
    printf("\nSearching all nodes with value %d\n", value);
    for(i = 0; i < list->length; i++) {
        Node* n = *(nodes + i);
        show_node(n);
    }

    value = 13;
    nodes = find_all(list, value);
    printf("\nSearching all nodes with value %d\n", value);
    for(i = 0; i < list->length; i++) {
        Node* n = *(nodes + i);
        show_node(n);
    }

    printf("\nCurrent list:\n");
    show_list(list);

    index = 0;
    printf("\nRemoving the head (index %d)\n", index);
    Node* removed_node = remove_by_index(list, index);
    show_node(removed_node);
    show_list(list);

    index = 4;
    printf("\nRemoving the element at index %d\n", index);
    removed_node = remove_by_index(list, index);
    show_node(removed_node);
    show_list(list);

    index = list->length - 1;
    printf("\nRemoving the tail (index %d)\n", index);
    removed_node = remove_by_index(list, index);
    show_node(removed_node);
    show_list(list);

    value = -1;
    printf("\nRemoving element of value %d\n", value);
    removed_node = remove_value(list, value);
    show_node(removed_node);
    show_list(list);

    value = 11;
    printf("\nRemoving element of value %d\n", value);
    removed_node = remove_value(list, value);
    show_node(removed_node);
    show_list(list);

    value = 17;
    printf("\nRemoving element of value %d\n", value);
    removed_node = remove_value(list, value);
    show_node(removed_node);
    show_list(list);

    value = 13;
    append(list, value);
    printf("\nRemoving element with value %d\n", value);
    removed_node = remove_value(list, value);
    show_node(removed_node);
    show_list(list);

    value = 0;
    nodes = remove_all_values(list, value);
    printf("\nRemoving all nodes with value %d\n", value);
    for(i = 0; i < list->length; i++) {
        Node* n = *(nodes + i);
        show_node(n);
    }
    show_list(list);

    value = 13;
    nodes = remove_all_values(list, value);
    printf("\nRemoving all nodes with value %d\n", value);
    for(i = 0; i < list->length; i++) {
        Node* n = *(nodes + i);
        show_node(n);
    }
    show_list(list);

    value = 12;
    nodes = remove_all_values(list, value);
    printf("\nRemoving all nodes with value %d\n", value);
    for(i = 0; i < list->length; i++) {
        Node* n = *(nodes + i);
        show_node(n);
    }
    show_list(list);
}
