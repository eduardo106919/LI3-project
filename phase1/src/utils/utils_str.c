#include "utils/utils_str.h"
#include <stdlib.h>
#include <string.h>

void remove_first_last_char(char *str) {
    if (str == NULL)
        return;

    size_t len = strlen(str);
    if (len < 2)
        return;

    memmove(str, str + 1, len - 1);
    str[len - 2] = '\0';
}

char **parse_string_list(const char *string, unsigned *len, size_t token_len, const char *delim) {
    if (string == NULL || len == NULL || delim == NULL)
        return NULL;

    unsigned n_tokens = strlen(string) / token_len;
    *len =  n_tokens;
    if (n_tokens == 0)
        return NULL;

    char **tokens = (char **)calloc(n_tokens, sizeof(char *));
    if (tokens == NULL)
        return NULL;

    char *temp = strdup(string);
    // remove the parentheses
    remove_first_last_char(temp);
    char *aux = strdup(strtok(temp, delim));

    for (unsigned i = 0; i < n_tokens; i++) {
        // remove the quotation marks
        remove_first_last_char(aux);

        tokens[i] = strdup(aux);
        aux = strtok(NULL, delim);
    }

    return tokens;
}
