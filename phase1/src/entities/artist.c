#include "entities/artist.h"
#include "utils/utils_str.h"
#include <stdlib.h>
#include <string.h>

#define TOTAL_TOKENS 7
#define ID_LEN 9 // 7 characters for the string, 2 for the ' on the ends

typedef struct artist {
    char *id;
    char *name;
    unsigned double recipe_per_stream;
    unsigned double total_recipe;
    unsigned discography;
    char **id_constituent;
    // == 0 -> individual, != 0 -> group
    unsigned num_artists;
    char *country;
} Artist;

void *create_artist(const char **tokens, unsigned len) {
    if (tokens == NULL || len != TOTAL_TOKENS)
        return NULL;

    Artist * new_artist = (Artist *)calloc(1, sizeof(Artist));
    if (new_artist == NULL)
        return NULL;

    new_artist->id = strdup(tokens[0]);
    new_artist->name = strdup(tokens[1]);
    // no need for description
    new_artist->recipe_per_stream = strtod(tokens[3], NULL);
    new_artist->id_constituent = parse_string_list(tokens[4], &(new_artist->num_artists), ID_LEN, ", ");
    new_artist->country = strdup(tokens[5]);

    return new_artist;
}

void destroy_artist(void *data) {
    if (data == NULL)
        return;

    Artist * artist = (Artist *)data;
    if (artist->id != NULL)
        free(artist->id);

    if (artist->name != NULL)
        free(artist->name);

    if (artist->country != NULL)
        free(artist->country);

    if (artist->id_constituent != NULL) {
        for (unsigned i = 0; i < artist->num_artists; i++) {
            if (artist->id_constituent[i] != NULL)
                free(artist->id_constituent[i]);
        }

        free(artist->id_constituent);
    }

    free(artist);
}

// SETTERS

void set_artist_id(Artist *artist, const char *id) {
    if (artist != NULL && id != NULL) {
        if (artist->id != NULL)
            free(artist->id);

        artist->id = strdup(id);
    }
}

void set_artist_name(Artist *artist, const char *name) {
    if (artist != NULL && name != NULL) {
        if (artist->name != NULL)
            free(artist->name);

        artist->name = strdup(name);
    }
}

void set_artist_country(Artist *artist, const char *country) {
    if (artist != NULL && country != NULL) {
        if (artist->country != NULL)
            free(artist->country);

        artist->country = strdup(country);
    }
}

void set_artist_recipe_stream(Artist *artist, unsigned double value) {
    if (artist != NULL)
        artist->recipe_per_stream = value;
}

void set_artist_total_recipe(Artist *artist, unsigned double value) {
    if (artist != NULL)
        artist->total_recipe = value;
}

void set_artist_discography(Artist *artist, unsigned value) {
    if (artist != NULL)
        artist->discography = value;
}

// GETTERS

const char *get_artist_id(const Artist *artist) {
    if (artist != NULL && artist->id != NULL)
        return artist->id;

    return NULL;
}

const char *get_artist_name(const Artist *artist) {
    if (artist != NULL && artist->name != NULL)
        return artist->name;

    return NULL;
}

const char *get_artist_country(const Artist *artist) {
    if (artist != NULL && artist->country != NULL)
        return artist->country;

    return NULL;
}

unsigned double get_artist_recipe_stream(const Artist *artist) {
    if (artist != NULL)
        return artist->recipe_per_stream;

    return 0;
}

unsigned double get_artist_total_recipe(const Artist *artist) {
    if (artist != NULL)
        return artist->total_recipe;

    return 0;
}

unsigned get_artist_discography(const Artist *artist) {
    if (artist != NULL)
        return artist->discography;

    return 0;
}

const char **get_artists_constituent(const Artist *artist) {
    if (artist == NULL || artist->id_constituent == NULL)
        return NULL;
    
    return artist->id_constituent;
}

unsigned get_artist_num_const(const Artist *artist) {
    if (artist != NULL)
        return artist->num_artists;

    return 0;
}

bool get_artist_is_group(const Artist *artist) {
    if (artist != NULL)
        return artist->num_artists != 0;

    return false;
}