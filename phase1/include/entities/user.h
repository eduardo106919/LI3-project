#ifndef USER_H
#define USER_H

/**
 * @brief Struct for a User, this entity can only 
 * be created or destroyed with the functions presented in this header file
 */
typedef struct user User;

/**
 * @brief Creates a user entity
 * 
 * @param tokens Array with the conten to create this entity
 * @param len Number of elements on the array
 * @return void* New User
 */
void *create_user(const char **tokens, unsigned len);

/**
 * @brief Frees the allocated space for a User
 * 
 * @param data User
 */
void destroy_user(void *data);

// SETTERS

/**
 * @brief Set the user id
 * 
 * @param user User
 * @param id New Id
 */
void set_user_id(User *user, const char *id);

/**
 * @brief Set the user email
 * 
 * @param user User
 * @param email New Email
 */
void set_user_email(User *user, const char *email);

/**
 * @brief Set the user first name
 * 
 * @param user User
 * @param first_name New First Name
 */
void set_user_first_name(User *user, const char *first_name);

/**
 * @brief Set the user last name
 * 
 * @param user User
 * @param last_name New Last Name
 */
void set_user_last_name(User *user, const char *last_name);

/**
 * @brief Set the user age
 * 
 * @param user User
 * @param value New Age
 */
void set_user_age(User *user, short unsigned value);

// GETTERS

/**
 * @brief Get the user id
 * 
 * @param user User 
 * @return const char* User Id
 */
const char *get_user_id(const User *user);

/**
 * @brief Get the user email
 * 
 * @param user User
 * @return const char* User Email
 */
const char *get_user_email(const User *user);

/**
 * @brief Get the user first name
 * 
 * @param user User
 * @return const char* User First Name
 */
const char *get_user_first_name(const User *user);

/**
 * @brief Get the user last name
 * 
 * @param user User
 * @return const char* User Last Name
 */
const char *get_user_last_name(const User *user);

/**
 * @brief Get the user age
 * 
 * @param user User
 * @return short unsigned* User age
 */
short unsigned get_user_age(const User *user);

/**
 * @brief Get the user liked musics
 * 
 * @param user User
 * @return const char** User liked musics
 */
char **get_user_liked_musics(const User *user);

/**
 * @brief Get the number of liked musics by the user
 * 
 * @param user User
 * @return unsigned* Number of liked musics
 */
unsigned get_user_num_liked(const User *user);



#endif