#ifndef MUSIC_H
#define MUSIC_H

typedef struct music Music;

/**
 * @brief Create a Music 
 * 
 * @param tokens Array with the content to create this entity
 * @param len Number of elements on the array
 * @return void* Music (NULL on failure)
 */
void *create_music(const char **tokens, unsigned len);

/**
 * @brief Frees the allocated space for a Music
 * 
 * @param data Music
 */
void destroy_music(void *data);

// SETTERS

/**
 * @brief Set the music id
 * 
 * @param music Music
 * @param id New Id
 */
void set_music_id(Music *music, const char *id);

/**
 * @brief Set the music genre
 * 
 * @param music Music
 * @param genre New Genre
 */
void set_music_genre(Music *music, const char *genre);

/**
 * @brief Set the music duration
 * 
 * @param music Music
 * @param value New duration
 */
void set_music_duration(Music *music, unsigned value);


// GETTERS

/**
 * @brief Get the music id
 * 
 * @param music Music
 * @return const char* Music Id (NULL on failure)
 */
const char *get_music_id(const Music *music);

/**
 * @brief Get the music genre
 * 
 * @param music Music
 * @return const char* Music Genre (NULLon failure)
 */
const char *get_music_genre(const Music *music);

/**
 * @brief Get the music duration
 * 
 * @param music Music
 * @return unsigned Music duration (0 on failure)
 */
unsigned get_music_duration(const Music *music);

/**
 * @brief Get the music authors
 * 
 * @param music Music
 * @return const char** Music Authors (NULL on failure)
 */
const char **get_music_authors(const Music *music);

/**
 * @brief Get the number of authors of the music
 * 
 * @param music Music
 * @return unsigned Number of authors (0 on failure)
 */
unsigned get_music_num_authors(const Music *music);



#endif