/*
 * Defines hashes
 */


/*
 * key_type and value_type: i - int, c - char
 */
typedef struct _hash_object {
    int key;
    int value;
    char* types;
    int code;

    struct _hash_object* prev;
    struct _hash_object* next;
    int length;                 // used only by the list head
    struct _hash_object* tail;  // used only by the list head
} HashObject;

// time: O(1); space: O(1)
int hash_code(int key, int size);

// time: O(1); space: O(1)
HashObject* create_hash_object(const int key, const int value, char* types, const int code);

// time: O(1); space: O(1)
void show_hash_object(const HashObject* hash_object, const int is_linked);

void show_linked_hash_objects(HashObject* hash_object);


/*
 * In case of collision, rehashes the key to another array position. This table
 * can store int or char keys and values in the same array.
 */
typedef struct {
    int size;
    HashObject** buckets;
} HashTable;

// time: O(1); space: O(1)
HashTable* create_hash_table(const int size);

// time O(N) (amortized O(Nk), where k is the average list length); space: O(1)
void show_hash_table(const HashTable* hash_table);

// time: O(1) (amortized O(Nk), k = average list length); space: O(1) (amortized O(k))
HashObject* put(const HashTable* hash_table, const int key, const int value, char* types);

// // time: O(1) (amortized O(N)); space ?
// HashObject* get(const HashTable* hash_table, const int key);

// HashObject* pop(const HashTable* hash_table, const int key);
