/*
 * Defines hashes
 */


typedef struct _hash_item {
    int key;
    int value;
    char* types;    // i = int, c = char
    int code;

    struct _hash_item* prev;
    struct _hash_item* next;
    int length;                 // used only by the list head
    struct _hash_item* tail;    // used only by the list head
} HashItem;

// time: O(1); space: O(1)
int hash_code(int key, int size);

// time: O(1); space: O(1)
HashItem* create_hash_item(const int key, const int value, char* types, const int code);

// time: O(1); space: O(1)
void show_hash_item(const HashItem* hash_item, const int is_linked);

void show_linked_hash_items(HashItem* hash_item);


/*
 * In case of collision, rehashes the key to another array position. This table
 * can store int or char keys and values in the same array.
 */
typedef struct {
    int size;
    HashItem** buckets;
} HashTable;

// time: O(1); space: O(1)
HashTable* create_hash_table(const int size);

// time O(N) (amortized O(Nk), where k is the average list length); space: O(1)
void show_hash_table(const HashTable* hash_table);

// time: O(1) (amortized O(Nk), k = average list length); space: O(1) (amortized O(k))
HashItem* put(const HashTable* hash_table, const int key, const int value, char* types);

// // time: O(1) (amortized O(k)); space O(1)
HashItem* get(const HashTable* hash_table, const int key, const char key_type);

HashItem* pop(const HashTable* hash_table, const int key, const char key_type);
