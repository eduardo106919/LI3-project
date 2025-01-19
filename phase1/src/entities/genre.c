#include "entities/genre.h"
#include <stdlib.h>
#include <string.h>


typedef struct genre {
    char *name;
    unsigned likes;
} Genre;


void *create_genre(const char *name) {
    if (name == NULL)
        return NULL;

    Genre *new_genre = (Genre *)calloc(1, sizeof(Genre));
    if (new_genre == NULL)
        return NULL;
    
    new_genre->name = strdup(name);
    new_genre->likes = 1;

    return new_genre;
}

void destroy_genre(void *data) {
    if (data != NULL) {
        Genre *temp = (Genre *)data;

        if (temp->name != NULL)
            free(temp->name);

        free(temp);
    }
}

// SETTERS

void set_genre_name(Genre *genre, const char *name) {
    if (genre != NULL && name != NULL) {
        if (genre->name != NULL)
            free(genre->name);

        genre->name = strdup(name);
    }
}

void set_genre_likes(Genre *genre, unsigned value) {
    if (genre != NULL)
        genre->likes = value;
}

// GETTERS

const char *get_genre_name(const Genre *genre) {
    if (genre != NULL)
        return genre->name;

    return NULL;
}

unsigned get_genre_likes(const Genre *genre) {
    if (genre != NULL)
        return genre->likes;

    return 0;
}