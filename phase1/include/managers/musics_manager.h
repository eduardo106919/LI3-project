/**
 * @file musics_manager.h
 * @author Eduardo Freitas Fernandes (ef05238@gmail.com)
 * @brief Header file for the Musics Manager
 */

#ifndef MUSICS_MANAGER_H
#define MUSICS_MANAGER_H

#include <stdbool.h>

/**
 * @brief Manager for all the stored Songs
 */
typedef struct musics_manager Musics_Manager;

/**
 * @brief Create a Musics Manager
 * 
 * @return Musics Manager (NULL on failure)
 * @note The return value must be freed with @ref destroy_musics_manager
 */
Musics_Manager *create_musics_manager(void);

/**
 * @brief Frees the allocated space for the Musics Manager
 * 
 * @param manager Musics Manager
 */
void destroy_musics_manager(Musics_Manager *manager);

/**
 * @brief Adds a song to the Musics Manager
 * 
 * This function creates the music object, so it only needs to receive the tokens to create it
 * 
 * @param manager Musics Manager
 * @param tokens Information to create a Song
 * @param n_tokens Number of tokens
 * @return 0 on sucess, 1 input is NULL, 2 allocation problems
 */
int add_music_MM(Musics_Manager *manager, char **tokens, unsigned n_tokens);

/**
 * @brief Checks if a song exists
 * 
 * @param manager Musics Manager
 * @param identifier Song identifier
 * @return true Song exists
 * @return false Song does not exist
 */
bool check_music_MM(const Musics_Manager *manager, const char *identifier);

#endif