/**
 * @file catalog.h
 * @author Eduardo Freitas Fernandes (ef05238@gmail.com)
 * @brief Header file for the Catalog
 * 
 * This file contains the API for the Catalog, this struct is the acess point to every operation that involves entities.
 */

#ifndef CATALOG_H
#define CATALOG_H

/**
 * @brief Enum to identify an Entity
 */
typedef enum {None, Artist, Music, User} Entity;

/**
 * @brief Catalog
 */
typedef struct catalog Catalog;

/**
 * @brief Create a Catalog
 * 
 * @return Catalog (NULL on failure)
 * @note The return value must be freed with @ref destroy_catalog
 */
Catalog *create_catalog(void);

/**
 * @brief Frees the allocated space for a Catalog
 * 
 * @param manager Catalog
 */
void destroy_catalog(Catalog *manager);

/**
 * @brief Adds an entity to the Catalog
 * 
 * @param manager Catalog
 * @param tokens Information to create an entity
 * @param n_tokens Number of tokens
 * @param type Entity to add
 * @return 0 on sucess, 1 input is NULL, 2 allocation problems
 */
int catalog_add_entity(Catalog *manager, char **tokens, unsigned n_tokens, Entity type);

/**
 * @brief Checks if an entity exists
 * 
 * @param manager Catalog
 * @param identifier Entity identifier
 * @param to_find Type of entity
 * @return true Entity exist
 * @return false Entity does not exist
 */
bool catalog_check_entity(const Catalog *manager, const char *identifier, Entity to_find);


#endif