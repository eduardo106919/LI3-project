/**
 * @file artists_manager.h
 * @author Eduardo Freitas Fernandes (ef05238@gmail.com)
 * @brief Header file for the Artists Manager
 */

#ifndef ARTISTS_MANAGER_H
#define ARTISTS_MANAGER_H

#include <stdbool.h>

/**
 * @brief Artists Manager
 */
typedef struct artists_manager Artists_Manager;

/**
 * @brief Create a Artists Manager
 * 
 * @return Artists Manager (NULL on failure)
 * @note The return value must be freed with @ref destroy_artists_manager
 */
Artists_Manager *create_artists_manager(void);

/**
 * @brief Frees the allocated space for the Artists Manager
 * 
 * @param manager Artists Manager
 */
void destroy_artists_manager(Artists_Manager *manager);

/**
 * @brief Adds an Artist to the Artists Manager
 * 
 * @param manager Artists Manager
 * @param tokens Information to create an Artist
 * @param n_tokens Number of tokens
 * @return 0 on sucess, 1 input is NULL, 2 allocation problems
 */
int add_artist_AM(Artists_Manager *manager, char **tokens, unsigned n_tokens);

/**
 * @brief Checks if an Artist exists
 * 
 * @param manager Artists Manager
 * @param identifier Artist identifier
 * @return true Artist exists
 * @return false Artist does not exists
 */
bool check_artist_AM(const Artists_Manager *manager, const char *identifier);


#endif