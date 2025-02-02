#include "managers/musics_manager.h"
#include "data_structures/hash_table.h"
#include "entities/music.h"
#include <stdlib.h>

typedef struct musics_manager {
    Hash_Table *table;
} Musics_Manager;

Musics_Manager *create_musics_manager(void) {
    Musics_Manager *new = (Musics_Manager *)calloc(1, sizeof(Musics_Manager));
    if (new == NULL)
        return NULL;

    new->table = create_ht(&fnv_hash);
    if (new->table == NULL) {
        free(new);
        return NULL;
    }

    return new;
}

void destroy_musics_manager(Musics_Manager *manager) {
    if (manager != NULL) {
        if (manager->table != NULL)
            destroy_ht(manager->table, &destroy_music);

        free(manager);
    }
}

int add_music_MM(Musics_Manager *manager, const char **tokens, unsigned n_tokens) {
    if (manager == NULL || tokens == NULL || n_tokens == 0)
        return 1;

    Music *new_song = create_music(tokens, n_tokens);
    if (new_song == NULL)
        return 2;

    if (ht_insert(manager->table, new_song, get_music_id(new_song)) != 0)
        return 2;

    return 0;
}

bool check_music_MM(const Musics_Manager *manager, const char *identifier) {
    if (manager == NULL || identifier == NULL)
        return false;

    return ht_check(manager->table, identifier);
}

