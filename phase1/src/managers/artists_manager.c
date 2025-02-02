#include "managers/artists_manager.h"
#include "data_structures/hash_table.h"
#include "entities/artist.h"
#include <stdlib.h>

typedef struct artists_manager {
    Hash_Table *table; // TO BE CHANGED
} Artists_Manager;


Artists_Manager *create_artists_manager(void) {
    Artists_Manager *new = (Artists_Manager *)calloc(1, sizeof(Artists_Manager));
    if (new == NULL)
        return NULL;

    new->table = create_ht(&fnv_hash);
    if (new->table == NULL) {
        free(new);
        return NULL;
    }

    return new;
}

void destroy_artists_manager(Artists_Manager *manager) {
    if (manager != NULL) {
        if (manager->table != NULL)
            destroy_ht(manager->table, &destroy_artist);

        free(manager);
    }
}

int add_artist_AM(Artists_Manager *manager, char **tokens, unsigned n_tokens) {
    if (manager == NULL || tokens == NULL || n_tokens == 0)
        return 1;

    Artist *new_artist = create_artist(tokens, n_tokens);
    if (new_artist == NULL)
        return 2;

    if (ht_insert(manager->table, new_artist, get_artist_id(new_artist)) != 0)
        return 2;
    
    return 0;
}

bool check_artist_AM(const Artists_Manager *manager, const char *identifier) {
    if (manager == NULL || identifier == NULL)
        return false;

    return ht_check(manager->table, identifier);
}
