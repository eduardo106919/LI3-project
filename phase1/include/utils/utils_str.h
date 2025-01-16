/**
 * @file utils_str.h
 * @author Eduardo Freitas Fernandes
 * @brief Header file that contais utility functions for strings
 */

#ifndef UTILS_STR_H
#define UTILS_STR_H

#include <stddef.h>

/**
 * @brief Removes the first and last character from a string
 * if str is NULL, no work is done
 * 
 * @param str String
 */
void remove_first_last_char(char *str);

/**
 * @brief Separates a list of ids
 * 
 * @param string String to separate
 * @param len Stores the number of elements on the returned array
 * @param token_len Size of each element on the string
 * @param delim Delimiters of the elements
 * @return char** Array of strings
 * @note return value is heap allocated
 */
char **parse_string_list(const char *string, unsigned *len, size_t token_len, const char *delim);

#endif