/*
 * Defines lists of all types
 */


/*
 * LINKED LISTS
 */


typedef struct _node {
    int value;
    struct _node* next;
} Node;

Node* create_node(const int value);

void show_node(const Node* A);


typedef struct {
    Node* head;
    Node* tail;
    int length;
} LinkedList;

// time: O(N), space: O(N)
LinkedList* create_linked_list(const int* values, const int length);

// time: O(N), space: O(1)
void show_list(const LinkedList* list);

// time: O(1), space: O(1)
void append(LinkedList* list, const int value);

// time: O(N), space: O(1)
Node* insert_value(LinkedList* list, const int value, const int index);

// time: O(N), space: O(1)
Node* find(const LinkedList* list, const int value);

// time: O(N), space: O(N)
Node** find_all(const LinkedList* list, const int value);

// time: O(N), space: O(1)
Node* remove_by_index(LinkedList* list, const int index);

// time: O(N), space: O(1)
Node* remove_value(LinkedList* list, const int value);

// time: O(N), space: O(1)
Node** remove_all_values(LinkedList* list, const int value);


/*
 * DOUBLY LINKED LISTS
 */


// TODO
