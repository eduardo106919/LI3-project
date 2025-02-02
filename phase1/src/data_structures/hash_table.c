#include "data_structures/hash_table.h"
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 101

typedef struct bucket {
    void *data;
    char *key;
    struct bucket *next;
} Bucket;

typedef struct hash_table {
    size_t size, count;
    size_t (*hash)(const char *);
    Bucket **buckets;
} Hash_Table;

/**
 * @brief Creates a bucket
 * 
 * Assumes data and key are not NULL
 * 
 * @param data Data to store
 * @param key Key to identify data
 * @return Bucket* New bucket
 */
static Bucket *create_bucket(void *data, const char *key) {
    Bucket *new_bucket = (Bucket *)calloc(1, sizeof(Bucket));
    if (new_bucket == NULL)
        return NULL;

    new_bucket->data = data;
    new_bucket->key = strdup(key);
    new_bucket->next = NULL;

    return new_bucket;
}

Hash_Table *create_ht(size_t (*hash)(const char *)) {
    if (hash == NULL)
        return NULL;

    Hash_Table *new_table = (Hash_Table *)calloc(1, sizeof(Hash_Table));
    if (new_table == NULL)
        return NULL;

    new_table->buckets = (Bucket **)calloc(INIT_SIZE, sizeof(Bucket *));
    if (new_table->buckets == NULL) {
        free(new_table);
        return NULL;
    }
    new_table->size = INIT_SIZE;
    new_table->count = 0;
    new_table->hash = hash;

    return new_table;
}

void destroy_ht(Hash_Table *ht, void (*destroy)(void *)) {
    if (ht != NULL && destroy != NULL) {
        if (ht->buckets != NULL) {
            Bucket *temp = NULL, *aux = NULL;
            for (size_t i = 0; i < ht->size; i++) {
                temp = ht->buckets[i];
                while (temp != NULL) {
                    aux = temp->next;
                    if (temp->data != NULL)
                        destroy(temp->data);

                    if (temp->key != NULL)
                        free(temp->key);

                    free(temp);
                    temp = aux;
                }
            }
        }

        free(ht);
    }
}

/**
 * @brief Calculates the load factor of the Hash table
 * 
 * Assumes ht is not NULL
 * 
 * @param ht Hash Table
 * @return float Load Factor
 */
static float ht_load_factor(const Hash_Table *ht) {
    return (float) ht->count / (float) ht->size;
}

static int ht_resize(Hash_Table *ht) {
    return 0;
}

int ht_insert(Hash_Table *ht, void *data, const char *key) {
    // input is NULL
    if (ht == NULL || key == NULL || data == NULL || ht->buckets == NULL)
        return 1;

    size_t index = ht->hash(key) % ht->size;
    // there are no replicates in the table
    Bucket * new_bucket = create_bucket(data, key);
    // preppend the bucket
    new_bucket->next = ht->buckets[index];
    ht->buckets[index] = new_bucket;
    ht->count++;

    if (ht_load_factor(ht) > 0.8) {
        if (ht_resize(ht) != 0)
            return 2;
    }

    return 0;
}

const void *ht_lookup(const Hash_Table *ht, const char *key) {
    if (ht == NULL || key == NULL)
        return NULL;

    size_t index = ht->hash(key) % ht->size;
    Bucket *temp = ht->buckets[index];
    while (temp != NULL && strcmp(temp->key, key) != 0)
        temp = temp->next;

    // found the key
    if (temp != NULL)
        return temp->data;

    return NULL;
}

bool ht_check(const Hash_Table *ht, const char *key) {
    if (ht == NULL || key == NULL)
        return NULL;

    size_t index = ht->hash(key) % ht->size;
    Bucket *temp = ht->buckets[index];
    while (temp != NULL && strcmp(temp->key, key) != 0)
        temp = temp->next;

    return temp != NULL ? true : false;
}

size_t ht_size(const Hash_Table *ht) {
    if (ht != NULL)
        return ht->count;
    return 0;
}

#define FNV_PRIME 0x01000193
#define FNV_OFFSET 0x811c9dc5

size_t fnv_hash(const char *key) {
    if (key == NULL)
        return 0;

    size_t hash = FNV_OFFSET;
    for (size_t i = 0; key[i] != '\0'; i++) {
        hash = hash ^ key[i];
        hash *= FNV_PRIME;
    }

    return hash;
}