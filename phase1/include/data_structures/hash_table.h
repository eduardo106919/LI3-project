#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct hash_table Hash_Table;

Hash_Table *create_ht(size_t (*hash)(const char *));
void destroy_ht(Hash_Table *ht, void (*destroy)(void *));

int ht_insert(Hash_Table *ht, void *data, const char *key);

const void *ht_lookup(const Hash_Table *ht, const char *key);
bool ht_check(const Hash_Table *ht, const char *key);

size_t ht_size(const Hash_Table *ht);



size_t fnv_hash(const char *key);


#endif