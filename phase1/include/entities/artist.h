/**
 * @file artist.h
 * @author Eduardo Freitas Fernandes
 * @brief Module to represent the Artist entity, containing various functions to manipulate this entity
 */

#ifndef ARTIST_H
#define ARTIST_H

#include <stdbool.h>

/**
 * @brief Struct for an Artist, this entity can only 
 * be created or destroyed with the functions presented in this header file
 */
typedef struct artist Artist;

/**
 * @brief Create an Artist
 * 
 * @param tokens Array with the content to create this entity
 * @param len Number of elements on the array
 * @return void* Artist (NULL on failure)
 */
void *create_artist(const char **tokens, unsigned len);

/**
 * @brief Frees the space allocated for an Artist
 * 
 * @param data Artist
 */
void destroy_artist(void *data);

// SETTERS

/**
 * @brief Change the artist id
 * 
 * @param artist Artist
 * @param id New Id
 */
void set_artist_id(Artist *artist, const char *id);

/**
 * @brief Change the artist name 
 * 
 * @param artist Artist
 * @param name New Name
 */
void set_artist_name(Artist *artist, const char *name);

/**
 * @brief Change the artist country
 * 
 * @param artist Artist
 * @param country New Country
 */
void set_artist_country(Artist *artist, const char *country);

/**
 * @brief Change the artist recipe per stream
 * 
 * @param artist Artist
 * @param value New recipe per stream
 */
void set_artist_recipe_stream(Artist *artist, unsigned double value);

/**
 * @brief Change the artist total recipe
 * 
 * @param artist Artist
 * @param value New total recipe
 */
void set_artist_total_recipe(Artist *artist, unsigned double value);

/**
 * @brief Change the artist discography
 * 
 * @param artist Artist
 * @param value New discography
 */
void set_artist_discography(Artist *artist, unsigned value);

// GETTERS

/**
 * @brief Get the artist id
 * 
 * @param artist Artist
 * @return const char* Artist Id (NULL on error)
 */
const char *get_artist_id(const Artist *artist);

/**
 * @brief Get the artist name
 * 
 * @param artist Artist
 * @return const char* Artist Name (NULL on error)
 */
const char *get_artist_name(const Artist *artist);

/**
 * @brief Get the artist country
 * 
 * @param artist Artist
 * @return const char* Artist Country (NULL on error)
 */
const char *get_artist_country(const Artist *artist);

/**
 * @brief Get the artist recipe per stream
 * 
 * @param artist Artist
 * @return unsigned double Artist recipe stream (0 on error)
 */
unsigned double get_artist_recipe_stream(const Artist *artist);

/**
 * @brief Get the artist total recipe
 * 
 * @param artist Artist
 * @return unsigned double Artist total recipe (0 on error)
 */
unsigned double get_artist_total_recipe(const Artist *artist);

/**
 * @brief Get the artist discography
 * 
 * @param artist Artist
 * @return unsigned Artist Discography (0 on error)
 */
unsigned get_artist_discography(const Artist *artist);

/**
 * @brief Get the artists constituents
 * 
 * @param artist Artist
 * @return const char** Artists constituents ids (NULL on error)
 */
const char **get_artists_constituent(const Artist *artist);

/**
 * @brief Get the number of constituents artists
 * 
 * @param artist Artist
 * @return unsigned Number of constituents artists (0 on error)
 */
unsigned get_artist_num_const(const Artist *artist);

/**
 * @brief Check if artist is a group
 * 
 * @param artist Artist
 * @return true Artist is group
 * @return false Artist is individual (artist == NULL)
 */
bool get_artist_is_group(const Artist *artist);




#endif