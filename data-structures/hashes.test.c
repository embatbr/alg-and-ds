/*
 * Testing
 */


#include <stdio.h>
#include <stdlib.h>

#include "hashes.h"


void main() {
    printf("### Tests for Data Structures ###\n\n");
    printf("##### HashObject #####\n");

    printf("\nCreating hash_object with key 1, value 120 and types \"ii\"\n");
    HashObject* hash_object = create_hash_object(1, 120, "ii", hash_code(1, 9));
    show_hash_object(hash_object, 0);

    printf("\nCreating hash_object with key 1, value 'x' and types \"ic\"\n");
    hash_object = create_hash_object(1, 'x', "ic", hash_code(1, 9));
    show_hash_object(hash_object, 0);

    printf("\nCreating hash_object with key 1, value 120 and types \"ic\"\n");
    hash_object = create_hash_object(1, 120, "ic", hash_code(1, 9));
    show_hash_object(hash_object, 0);

    printf("\nCreating hash_object with key 'a', value 'x' and types \"cc\"\n");
    hash_object = create_hash_object('a', 'x', "cc", hash_code('a', 9));
    show_hash_object(hash_object, 0);

    printf("\nCreating hash_object with key 97, value 120 and types \"cc\"\n");
    hash_object = create_hash_object(97, 120, "cc", hash_code(97, 9));
    show_hash_object(hash_object, 0);

    printf("\nCreating hash_object with key 79, value 145 and types \"ii\", and appending to list\n");
    hash_object->next = create_hash_object(79, 145, "ii", hash_code(79, 9));
    hash_object->length = 1;
    hash_object->tail = hash_object->next;
    show_linked_hash_objects(hash_object);


    printf("\n\n##### HashTable #####\n");

    printf("\nCreating hash_table with size 0\n");
    HashTable* hash_table = create_hash_table(0);
    show_hash_table(hash_table);

    printf("\nCreating hash_table with size 9\n");
    hash_table = create_hash_table(9);
    show_hash_table(hash_table);

    printf("\nInserting (1, 120, \"ii\") into hash_table\n");
    HashObject* new_hash_object = put(hash_table, 1, 120, "ii");
    show_hash_object(new_hash_object, 0);
    show_hash_table(hash_table);

    printf("\nInserting (1, 'x', \"ic\") into hash_table\n");
    new_hash_object = put(hash_table, 1, 'x', "ic");
    show_hash_object(new_hash_object, 0);
    show_hash_table(hash_table);

    printf("\nInserting (100, 145, \"ci\") into hash_table\n");
    new_hash_object = put(hash_table, 100, 145, "ci");
    show_hash_object(new_hash_object, 0);
    show_hash_table(hash_table);

    printf("\nInserting ('a', 'x', \"cc\") into hash_table\n");
    new_hash_object = put(hash_table, 'a', 'x', "cc");
    show_hash_object(new_hash_object, 0);
    show_hash_table(hash_table);

    printf("\nInserting (97, 103, \"cc\") into hash_table\n");
    new_hash_object = put(hash_table, 97, 103, "cc");
    show_hash_object(new_hash_object, 0);
    show_hash_table(hash_table);

    printf("\nInserting (10, 'x', \"ic\") into hash_table\n");
    new_hash_object = put(hash_table, 10, 'x', "ic");
    show_hash_object(new_hash_object, 0);
    show_hash_table(hash_table);

    // printf("\nGet element with key 123\n");
    // hash_object = get(hash_table, 123);
    // show_hash_object(hash_object);

    // printf("\nGet element with key 'a'\n");
    // hash_object = get(hash_table, 'a');
    // show_hash_object(hash_object);

    // printf("\nGet element with key 10\n");
    // hash_object = get(hash_table, 10);
    // show_hash_object(hash_object);

    // printf("\nRemoving element with key 123\n");
    // hash_object = pop(hash_table, 123);
    // show_hash_object(hash_object);
    // show_hash_table(hash_table);

    // printf("\nRemoving element with key 10\n");
    // hash_object = pop(hash_table, 10);
    // show_hash_object(hash_object);
    // show_hash_table(hash_table);

    // printf("\nGet removed element (key = 10)\n");
    // hash_object = get(hash_table, 10);
    // show_hash_object(hash_object);

    // printf("\nGet element with same initial hash code (key = 19)\n");
    // hash_object = get(hash_table, 19);
    // show_hash_object(hash_object);

    // // FUDEU
    // printf("\nInserting (19, 'Z', \"ic\") into hash_table\n");
    // code = put(hash_table, 19, 'Z', "ic");
    // printf("code: %d\n", code);
    // show_hash_table(hash_table);
}
