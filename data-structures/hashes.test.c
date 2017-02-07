/*
 * Testing
 */


#include <stdio.h>
#include <stdlib.h>

#include "hashes.h"


void main() {
    printf("### Tests for Data Structures ###\n\n");
    printf("##### HashItem #####\n");

    printf("\nCreating hash_item with key 1, value 120 and types \"ii\"\n");
    HashItem* hash_item = create_hash_item(1, 120, "ii", hash_code(1, 9));
    show_hash_item(hash_item, 0);

    printf("\nCreating hash_item with key 1, value 'x' and types \"ic\"\n");
    hash_item = create_hash_item(1, 'x', "ic", hash_code(1, 9));
    show_hash_item(hash_item, 0);

    printf("\nCreating hash_item with key 1, value 120 and types \"ic\"\n");
    hash_item = create_hash_item(1, 120, "ic", hash_code(1, 9));
    show_hash_item(hash_item, 0);

    printf("\nCreating hash_item with key 'a', value 'x' and types \"cc\"\n");
    hash_item = create_hash_item('a', 'x', "cc", hash_code('a', 9));
    show_hash_item(hash_item, 0);

    printf("\nCreating hash_item with key 97, value 120 and types \"cc\"\n");
    hash_item = create_hash_item(97, 120, "cc", hash_code(97, 9));
    show_hash_item(hash_item, 0);

    printf("\nCreating hash_item with key 79, value 145 and types \"ii\", and appending to list\n");
    hash_item->next = create_hash_item(79, 145, "ii", hash_code(79, 9));
    hash_item->tail = hash_item->next;
    hash_item->length = 2;
    show_linked_hash_items(hash_item);


    printf("\n\n##### HashTable #####\n");

    printf("\nCreating hash_table with size 0\n");
    HashTable* hash_table = create_hash_table(0);
    show_hash_table(hash_table);

    printf("\nCreating hash_table with size 9\n");
    hash_table = create_hash_table(9);
    show_hash_table(hash_table);

    printf("\nInserting (1, 120, \"ii\") into hash_table\n");
    HashItem* new_hash_item = put(hash_table, 1, 120, "ii");
    show_hash_item(new_hash_item, 0);
    show_hash_table(hash_table);

    printf("\nInserting (1, 'x', \"ic\") into hash_table\n");
    new_hash_item = put(hash_table, 1, 'x', "ic");
    show_hash_item(new_hash_item, 0);
    show_hash_table(hash_table);

    printf("\nInserting (100, 145, \"ci\") into hash_table\n");
    new_hash_item = put(hash_table, 100, 145, "ci");
    show_hash_item(new_hash_item, 0);
    show_hash_table(hash_table);

    printf("\nInserting (100, 'H', \"ic\") into hash_table\n");
    new_hash_item = put(hash_table, 100, 'H', "ic");
    show_hash_item(new_hash_item, 0);
    show_hash_table(hash_table);

    printf("\nInserting ('a', 'x', \"cc\") into hash_table\n");
    new_hash_item = put(hash_table, 'a', 'x', "cc");
    show_hash_item(new_hash_item, 0);
    show_hash_table(hash_table);

    printf("\nInserting (97, 103, \"cc\") into hash_table\n");
    new_hash_item = put(hash_table, 97, 103, "cc");
    show_hash_item(new_hash_item, 0);
    show_hash_table(hash_table);

    printf("\nInserting (10, 'x', \"ic\") into hash_table\n");
    new_hash_item = put(hash_table, 10, 'x', "ic");
    show_hash_item(new_hash_item, 0);
    show_hash_table(hash_table);

    printf("\nInserting (19, 'B', \"ic\") into hash_table\n");
    new_hash_item = put(hash_table, 19, 'B', "ic");
    show_hash_item(new_hash_item, 0);
    show_hash_table(hash_table);

    printf("\nGet element with key 123\n");
    hash_item = get(hash_table, 123, 'i');
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nGet element with key 'a'\n");
    hash_item = get(hash_table, 'a', 'c');
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nGet element with key 97\n");
    hash_item = get(hash_table, 97, 'i');
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nGet element with key 10\n");
    hash_item = get(hash_table, 10, 'i');
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nRemoving element with key 123\n");
    hash_item = pop(hash_table, 123, 'i');
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nRemoving element with key 'a'\n");
    hash_item = pop(hash_table, 'a', 'c');
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nRemoving element with key 1 (head)\n");
    hash_item = pop(hash_table, 1, 'i');
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nRemoving element with key 19 (tail)\n");
    hash_item = pop(hash_table, 19, 'i');
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nRemoving element with key 100 (tail)\n");
    hash_item = pop(hash_table, 100, 'i');
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nInserting (100, 'Z', \"ic\") into hash_table\n");
    hash_item = put(hash_table, 100, 'Z', "ic");
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);

    printf("\nInserting (102, 1, \"ii\") into hash_table\n");
    hash_item = put(hash_table, 102, 1, "ii");
    show_hash_item(hash_item, 0);
    show_hash_table(hash_table);
}
