/*
 * Defines hashes
 */


/*
 * key_type and value_type: i - int, c - char
 */
typedef struct {
    int key;
    char key_type;
    int value;
    char value_type;
    int code;
    char valid;
} HashObject;

// time: O(1); space: O(1)
int hash_code(int key, int size, int offset);

// time: O(1); space: O(1)
HashObject* create_hash_object(const int key, const int value, const char* types, const int code);

// time: O(1); space: O(1)
void show_hash_object(const HashObject* hash_object);


/*
 * In case of collision, rehashes the key to another array position. This table
 * can store int or char keys and values in the same array.
 */
typedef struct {
    int size;
    HashObject** buckets;
} HashTable;

// time: O(1); space: ?
HashTable* create_hash_table(const int size);

// time O(N), where N is the table size; space: ?
void show_hash_table(const HashTable* hash_table);

// time: O(1) (amortized O(N)); space: ?
int put(const HashTable* hash_table, const int key, const int value, const char* types);

// time: O(1) (amortized O(N)); space ?
HashObject* get(const HashTable* hash_table, const int key);

HashObject* pop(const HashTable* hash_table, const int key);

// TODO how to delete without affect the get?
// Maybe with a flag "is_dead" or "idle object", being replaced only when a new key is hashed to the same position
