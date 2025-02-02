#include "managers/users_manager.h"
#include "data_structures/hash_table.h"
#include "entities/user.h"
#include <stdlib.h>

typedef struct users_manager {
    Hash_Table *table;
} Users_Manager;


Users_Manager *create_users_manager(void) {
    Users_Manager *new = (Users_Manager *)calloc(1, sizeof(Users_Manager));
    if (new == NULL)
        return NULL;

    new->table = create_ht(&fnv_hash);
    if (new->table == NULL) {
        free(new);
        return NULL;
    }

    return new;
}

void destroy_users_manager(Users_Manager *manager) {
    if (manager != NULL) {
        if (manager->table != NULL)
            destroy_ht(manager->table, &destroy_user);

        free(manager);
    }
}

int add_user_UM(Users_Manager *manager, char **tokens, unsigned n_tokens) {
    if (manager == NULL || tokens == NULL || n_tokens == 0)
        return 1;

    User *new_user = create_user(tokens, n_tokens);
    if (new_user == NULL)
        return 2;

    if (ht_insert(manager->table, new_user, get_user_id(new_user)) != 0)
        return 2;

    return 0;
}

bool check_user_UM(const Users_Manager *manager, const char *identifier) {
    if (manager == NULL || identifier == NULL)
        return false;

    return ht_check(manager->table, identifier);
}
