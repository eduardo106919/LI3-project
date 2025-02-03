#include "managers/catalog.h"
#include "managers/artists_manager.h"
#include "managers/musics_manager.h"
#include "managers/users_manager.h"
#include <stdlib.h>

typedef struct catalog {
    Artists_Manager *artists;
    Musics_Manager *songs;
    Users_Manager *users;
} Catalog;

Catalog *create_catalog(void) {
    Catalog *new = (Catalog *)calloc(1, sizeof(Catalog));
    if (new == NULL)
        return NULL;

    new->artists = create_artists_manager();
    if (new->artists == NULL) {
        free(new);
        return NULL;
    }

    new->songs = create_musics_manager();
    if (new->songs == NULL) {
        destroy_artists_manager(new->artists);
        free(new);
        return NULL;
    }

    new->users = create_users_manager();
    if (new->users == NULL) {
        destroy_artists_manager(new->artists);
        destroy_musics_manager(new->songs);
        free(new);
        return NULL;
    }

    return new;
}

void destroy_catalog(Catalog *manager) {
    if (manager != NULL) {
        if (manager->artists != NULL)
            destroy_artists_manager(manager->artists);

        if (manager->songs != NULL)
            destroy_musics_manager(manager->songs);

        if (manager->users != NULL)
            destroy_users_manager(manager->users);

        free(manager);
    }
}

int catalog_add_entity(Catalog *manager, char **tokens, unsigned n_tokens, Entity type) {
    if (manager == NULL || tokens == NULL || n_tokens == 0 || type == None)
        return 1;

    int result = 0;
    switch (type) {
        case Artist:
            result = add_artist_AM(manager->artists, tokens, n_tokens);
            break;
        case Music:
            result = add_music_MM(manager->songs, tokens, n_tokens);
            break;
        case User:
            result = add_user_UM(manager->users, tokens, n_tokens);
            break;

        default:
            break;
    }

    return result;
}

bool catalog_check_entity(const Catalog *manager, const char *identifier, Entity to_find) {
    if (manager == NULL || identifier == NULL || to_find == None)
        return false;

    bool result = false;
    switch (to_find) {
        case Artist:
            result = check_artist_AM(manager->artists, identifier);
            break;
        case Music:
            result = check_music_MM(manager->songs, identifier);
            break;
        case User:
            result = check_user_UM(manager->users, identifier);
            break;
       
        default:
            break;
    }

    return result;
}

bool catalog_validate_entity(const Catalog *manager, char **tokens, unsigned n_tokens, Entity type) {


    return false;
}