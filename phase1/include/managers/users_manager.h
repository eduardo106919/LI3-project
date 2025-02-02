/**
 * @file users_manager.h
 * @author Eduardo Freitas Fernandes (ef05238@gmail.com)
 * @brief Header file for the Users Manager
 */

#ifndef USERS_MANAGER_H
#define USERS_MANAGER_H

#include <stdbool.h>

/**
 * @brief Users Manager
 */
typedef struct users_manager Users_Manager;

/**
 * @brief Create a Users Manager
 * 
 * @return Users Manager (NULL on failure)
 * @note The return value must be freed with @ref destroy_users_manager
 */
Users_Manager *create_users_manager(void);

/**
 * @brief Frees the allocated space for Users Manager
 * 
 * @param manager Users Manager
 */
void destroy_users_manager(Users_Manager *manager);

/**
 * @brief Adds an User to the Users Manager
 * 
 * This function creates the User object, reason for this function receive the tokens to create it
 * 
 * @param manager Users Manager
 * @param tokens Information to create the User
 * @param n_tokens Number of tokens
 * @return 0 on sucess, 1 input is NULL, 2 allocation problems
 */
int add_user_UM(Users_Manager *manager, char **tokens, unsigned n_tokens);

/**
 * @brief Checks if a User exists
 * 
 * @param manager Users Manager
 * @param identifier User Identifier
 * @return true User exists
 * @return false User does not exist
 */
bool check_user_UM(const Users_Manager *manager, const char *identifier);



#endif