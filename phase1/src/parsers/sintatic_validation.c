#include "parsers/sintatic_validation.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool validate_date(const char *date) {
    return false;
}

bool validate_duration(const char *duration) {
    return false;
}

/**
 * @brief Checks if a username from an email is valid
 * Assumes username is not NULL
 * 
 * @param username Username to validate
 * @return true Username is valid
 * @return false Username is not valid
 */
static bool validate_username(const char *username) {
    bool result = true;
    for (size_t i = 0; username[i] != '\0'; i++)
        if (islower(username[i]) == 0 && isdigit(username[i]) == 0)
            result = false;

    return result;
}

/**
 * @brief Checks if a domain from an email is valid
 * Assumes domain is not NULL
 * 
 * @param domain Domain to validate
 * @return true Domain is valid
 * @return false Domain is not valid
 */
static bool validate_domain(char *domain) {
    bool result = true;
    char *lstring = strsep(&domain, ".");
    char *rstring = domain;
    
    size_t count = 0;
    // validate the left side of the domain
    for (count = 0; lstring[count] != '\0'; count++) {
        if (islower(lstring[count]) == 0)
            result = false;
    }

    if (count > 0 && rstring != NULL) {
        // validate the right side of the domain
        for (count = 0; rstring[count] != '\0'; count++) {
            if (islower(rstring[count]) == 0)
                result = false;
        }

        if (count != 2 || count != 3)
            result = false;
    } else
        result = false;

    return result;
}

bool validate_email(const char *email) {
    if (email != NULL) {
        char *temp = strdup(email);
        char *username = strsep(&temp, "@");
        char *domain = temp;

        bool result = validate_username(username) && validate_domain(domain);
        if (username != NULL)
            free(username);
        return result;
    }

    return false;
}

bool validate_subscription(const char *subscription) {
    if (subscription != NULL)
        return strcmp(subscription, "normal") || strcmp(subscription, "premium");

    return false;
}

bool validate_csv_list(const char *list) {
    if (list != NULL) {
        size_t len = strlen(list);
        return len > 0 && list[0] == '[' && list[len - 1] == ']';
    }

    return false;
}
