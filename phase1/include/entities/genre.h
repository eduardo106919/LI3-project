/**
 * @file genre.h
 * @author Eduardo Freitas Fernandes
 * @brief Hearder file that contains the functions to manipulate a Music Genre
 */

#ifndef GENRE_H
#define GENRE_H

/**
 * @brief Struct that defines a Music genre
 */
typedef struct genre Genre;

/**
 * @brief Creates a Music Genre
 * 
 * @param name Name of the Genre
 * @return void* Music Genre
 */
void *create_genre(const char *name);

/**
 * @brief Frees the allocated space for a Music Genre
 * 
 * @param data 
 */
void destroy_genre(void *data);

// SETTERS

/**
 * @brief Set the genre name
 * 
 * @param genre Music Genre
 * @param name New Name
 */
void set_genre_name(Genre *genre, const char *name);

/**
 * @brief Set the genre likes
 * 
 * @param genre Genre
 * @param value New likes
 */
void set_genre_likes(Genre *genre, unsigned value);

// GETTERS

/**
 * @brief Get the genre name
 * 
 * @param genre Genre
 * @return const char* Genre Name
 */
const char *get_genre_name(const Genre *genre);

/**
 * @brief Get the genre likes
 * 
 * @param genre Genre
 * @return unsigned Genre Likes
 */
unsigned get_genre_likes(const Genre *genre);



#endif