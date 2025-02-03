#include "entities/music.h"
#include "utils/utils_str.h"
#include <stdlib.h>
#include <string.h>


#define TOTAL_TOKENS 7
#define ID_LEN 9


typedef struct music {
    char *id;
    char **authors;
    unsigned num_authors;
    unsigned duration;
    char *genre;
} Music;


void *create_music(char **tokens, unsigned len) {
    if (tokens == NULL || len != TOTAL_TOKENS)
        return NULL;

    Music *new_music = (Music *)calloc(1, sizeof(Music));
    if (new_music == NULL)
        return NULL;

    new_music->id = strdup(tokens[0]);
    new_music->authors = parse_string_list(tokens[2], &(new_music->num_authors), ID_LEN, ", ");
    new_music->duration = strtoul(tokens[3], NULL, 10);
    new_music->genre = strdup(tokens[4]);

    return new_music;
}

void destroy_music(void *data) {
    if (data != NULL) {
        Music *music = (Music *)data;

        if (music->id != NULL)
            free(music->id);

        if (music->genre != NULL)
            free(music->genre);

        if (music->authors != NULL) {
            for (unsigned i = 0; i < music->num_authors; i++) {
                if (music->authors[i] != NULL)
                    free(music->authors[i]);
            }
                
            free(music->authors);
        }

        free(music);
    }
}

// SETTERS

void set_music_id(Music *music, const char *id) {
    if (music != NULL && id != NULL) {
        if (music->id != NULL)
            free(music->id);

        music->id = strdup(id);
    }
}

void set_music_genre(Music *music, const char *genre) {
    if (music != NULL && genre != NULL) {
        if (music->genre != NULL)
            free(music->genre);

        music->genre = strdup(genre);
    }
}

void set_music_duration(Music *music, unsigned value) {
    if (music != NULL)
        music->duration = value;
}

// GETTERS

const char *get_music_id(const Music *music) {
    if (music != NULL)
        return music->id;

    return NULL;
}

const char *get_music_genre(const Music *music) {
    if (music != NULL)
        return music->genre;

    return NULL;
}

unsigned get_music_duration(const Music *music) {
    if (music != NULL)
        return music->duration;

    return 0;
}

char **get_music_authors(const Music *music) {
    if (music == NULL || music->authors == NULL || music->num_authors == 0)
        return NULL;

    char **result = (char **)calloc(music->num_authors, sizeof(char *));
    if (result == NULL)
        return NULL;

    for (unsigned i = 0; i < music->num_authors; i++)
        result[i] = strdup(music->authors[i]);

    return result;
}

unsigned get_music_num_authors(const Music *music) {
    if (music != NULL)
        return music->num_authors;

    return 0;
}