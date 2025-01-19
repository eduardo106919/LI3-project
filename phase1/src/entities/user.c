#include "entities/user.h"
#include "utils/utils_str.h"
#include <stdlib.h>
#include <string.h>

#define TOTAL_TOKENS 8
#define ID_LEN 9

typedef struct user {
    char *id;
    char *email;
    char *first_name;
    char *last_name;
    short unsigned age;
    char **liked_musics;
    unsigned num_liked;
} User;

void *create_user(const char **tokens, unsigned len) {
    if (tokens == NULL || len != TOTAL_TOKENS)
        return NULL;

    User *new_user = (User *)calloc(1, sizeof(User));
    if (new_user == NULL)
        return NULL;

    new_user->id = strdup(tokens[0]);
    new_user->email = strdup(tokens[1]);
    new_user->first_name = strdup(tokens[2]);
    new_user->last_name = strdup(tokens[3]);
    // new_user->age = date_to_age(tokens[4]);
    new_user->liked_musics = parse_string_list(tokens[7], &(new_user->num_liked), ID_LEN, ", ");

    return new_user;
}

void destroy_user(void *data) {
    if (data != NULL) {
        User *user = (User *)data;

        if (user->id != NULL)
            free(user->id);

        if (user->email != NULL)
            free(user->email);

        if (user->first_name != NULL)
            free(user->first_name);

        if (user->last_name != NULL)
            free(user->last_name);

        if (user->liked_musics != NULL) {
            for (unsigned i = 0; i < user->num_liked; i++) {
                if (user->liked_musics[i] != NULL)
                    free(user->liked_musics[i]);
            }
            
            free(user->liked_musics);
        }

        free(user);
    }
}

// SETTERS

void set_user_id(User *user, const char *id) {
    if (user != NULL || id != NULL) {
        if (user->id != NULL)
            free(user->id);

        user->id = strdup(id);
    }
}

void set_user_email(User *user, const char *email) {
    if (user != NULL || email != NULL) {
        if (user->email != NULL)
            free(user->email);

        user->email = strdup(email);
    }
}

void set_user_first_name(User *user, const char *first_name) {
    if (user != NULL || first_name != NULL) {
        if (user->first_name != NULL)
            free(user->first_name);

        user->first_name = strdup(first_name);
    }
}

void set_user_last_name(User *user, const char *last_name) {
    if (user != NULL || last_name != NULL) {
        if (user->last_name != NULL)
            free(user->last_name);

        user->last_name = strdup(last_name);
    }
}

void set_user_age(User *user, short unsigned value) {
    if (user != NULL)
        user->age = value;
}

// GETTERS

const char *get_user_id(const User *user) {
    if (user == NULL)
        return NULL;
    
    return user->id;
}

const char *get_user_email(const User *user) {
    if (user == NULL)
        return NULL;
    
    return user->email;
}

const char *get_user_first_name(const User *user) {
    if (user == NULL)
        return NULL;
    
    return user->first_name;
}

const char *get_user_last_name(const User *user) {
    if (user == NULL)
        return NULL;
    
    return user->last_name;
}

short unsigned get_user_age(const User *user) {
    if (user != NULL)
        return user->age;

    return 0;
}

char **get_user_liked_musics(const User *user) {
    if (user == NULL || user->liked_musics == NULL || user->num_liked == 0)
        return NULL;

    char **result = (char **)calloc(user->num_liked, sizeof(char *));
    if (result == NULL)
        return NULL;

    for (unsigned i = 0; i < user->num_liked; i++)
        result[i] = strdup(user->liked_musics[i]);

    return result;
}

unsigned get_user_num_liked(const User *user) {
    if (user != NULL)
        return user->num_liked;

    return 0;
}