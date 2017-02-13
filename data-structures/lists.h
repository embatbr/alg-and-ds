/*
 * Defines lists of all types
 */


/*
 * (DOUBLY) LINKED LISTS
 */


typedef struct _node {
    int value;
    struct _node* prev;
    struct _node* next;
} Node;

Node* create_node(const int value);

void show_node_sufix(const Node* A, const char* sufix);

void show_node(const Node* A);


typedef struct {
    Node* head;
    Node* tail;
    int length;
} LinkedList;

// time: O(1); space: O(1)
LinkedList* create_empty_linked_list();

// time: O(N); space: O(N)
LinkedList* create_linked_list(const int* values, const int length);

// time: O(N); space: O(1)
void show_list(const LinkedList* list);

// time: O(1); space: O(1)
void append_node(LinkedList* list, Node* node);

// time: O(1); space: O(1)
void append(LinkedList* list, const int value);

// time: O(N); space: O(1)
Node* find(const LinkedList* list, const int value);

// time: O(1); space O(1)
void remove_node(LinkedList* list, Node* node);


typedef struct {
    int size;
    Node** buckets;
} NodeHashTable;

// time: O(1); space O(1)
int node_hash_code(int key, int size);

// time: O(1); space: O(1)
NodeHashTable* create_node_hash_table(const int size);

// time: O(1); space: O(1) (amortized O(k))
void put_node(const NodeHashTable* node_hash_table, const int key, Node* node);

// time: O(1); space: O(1) (amortized O(k))
Node* get_node(const NodeHashTable* node_hash_table, const int key);
