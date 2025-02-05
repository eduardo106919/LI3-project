#include "managers/catalog.h"
#include "managers/artists_manager.h"
#include "managers/musics_manager.h"
#include "managers/users_manager.h"
#include "parsers/sintatic_validation.h"
#include "utils/utils_str.h"
#include <stdlib.h>
#include <string.h>

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

/**
 * @brief Checks if the Ids in the CSV list are valid
 * 
 * Assumes input is not NULL
 * 
 * @param manager Catalog
 * @param list Csv list with the ids
 * @param to_check Type of entity of the identifiers
 * @return true List is valid
 * @return false List is not valid
 */
static bool catalog_validate_id_list(const Catalog *manager, const char *list, Entity to_check) {
    bool result = true;

    unsigned len = 0;
    char *delim = ", ";
    size_t total_len = 8; // an identifier has 8 characters

    char **tokens = parse_string_list(list, &len, total_len,delim);

    if (tokens != NULL) {
        for (unsigned i = 0; i < len && result == true; i++)
            result = catalog_check_entity(manager, tokens[i], to_check);
        
        free(tokens);
    } else
        result = false;

    return result;
}

bool catalog_validate_entity(const Catalog *manager, char **tokens, unsigned n_tokens, Entity type) {
    if (manager != NULL && tokens != NULL) {
        bool result = true;
        switch (type) {
            case Artist:
                result = validate_csv_list(tokens[4]);
                /* list is either empty and it's the artist is individual
                   or it's a group and the list is not empty */
                result = result && 
                         ((strcmp(tokens[6], "individual") && csv_list_is_empty(tokens[4])) || 
                         (strcmp(tokens[6], "group") && csv_list_is_empty(tokens[4]) == false));

                break;
            case Music:
                result = validate_csv_list(tokens[2]);
                result = result && catalog_validate_id_list(manager, tokens[2], Artist);
                result = result && validate_duration(tokens[3]);

                break;
            case User:
                result = validate_email(tokens[1]);
                result = result && validate_date(tokens[4]);
                result = result && validate_subscription(tokens[6]);
                result = result && validate_csv_list(tokens[7]);
                result = result && catalog_validate_id_list(manager, tokens[7], Music);

                break;
            default:
                break;
        }

        return result;
    }

    return false;
}