/**
 * @file sintatic_validation.h
 * @author Eduardo Freitas Fernandes (ef05238@gmail.com)
 * @brief Header file that contains the sintatic validation functions
 */

#ifndef SINTATIC_VALIDATION_H
#define SINTATIC_VALIDATION_H

#include <stdbool.h>

/**
 * @brief Checks if a data is valid
 * 
 * A date is valid if it follows this type: yyyy/mm/dd; y, m and d are integers between 0 and 9
 * The @b month (second collumn) must be between 1 and 12
 * The @b day (third column) must be between 1 and 31
 * The @b date can't be more recent than the current date
 * 
 * @param date Date to validate
 * @return true Date is valid
 * @return false Date is not valid
 */
bool validate_date(const char *date);

/**
 * @brief Checks if a duration is valid
 * 
 * The duration must follow this format: hh:mm:ss; h, m and s must be integers between 0 and 9
 * The @b hours (first collumn) must be between 0 and 99
 * The @b minutes and seconds must be between 0 and 59
 * 
 * @param duration Duration to validate
 * @return true Duration is valid
 * @return false Durations is not valid
 */
bool validate_duration(const char *duration);

/**
 * @brief Checks if an email is valid
 * 
 * An email must follow this format: username@domain
 * @b username must be a set of characters from [a-z0-9]
 * @b domain must follow this format: <lstring>.<rstring>
 * @b lstring must be a string with atleast 1 character
 * @b rstring must be a string with 2 or 3 characters
 * They @b both must have characters from this set: [a-z] 
 * 
 * @param email Email to validate
 * @return true Email is valid
 * @return false Email is not valid
 */
bool validate_email(const char *email);

/**
 * @brief Checks if a subscription is valid
 * 
 * A subscription must be @b normal or @b premium
 * 
 * @param subscription Subscription to validate
 * @return true Subscription is valid
 * @return false Subscription is not valid
 */
bool validate_subscription(const char *subscription);

/**
 * @brief Checks if a list in a CSV file starts with '[' and ends with ']'
 * 
 * @param list List to validate
 * @return true List is valid
 * @return false List is not valid
 */
bool validate_csv_list(const char *list);

#endif
