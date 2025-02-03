#include "parsers/parser.h"
#include "utils/utils_str.h"
#include "utils/utils_files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 
 * 
 * Assumes the input is not NULL
 * 
 * @param manager 
 * @param type 
 * @param line 
 * @param n_tokens 
 * @return true 
 * @return false 
 */
static bool parse_entity_line(Catalog *manager, Entity type, const char *line, unsigned n_tokens) {
    char *temp = strdup(line);
    char *tokens[n_tokens];
    char *delim = ";";

    // tokenize the line
    for (unsigned i = 0; i < n_tokens; i++) {
        tokens[i] = strsep(&temp, delim);

        // remove the quotation marks
        remove_first_last_char(tokens[i]);
    }

    // validate the entity
    if (catalog_validate_entity(manager, tokens, n_tokens, type) == true)
        catalog_add_entity(manager, tokens, n_tokens, type);
    else
        return false;

    return true;
}

int parse_entity(Catalog *manager, const char *file_name, Entity type, unsigned n_tokens) {
    if (manager == NULL || file_name == NULL)
        return 1;

    FILE *input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        perror("Error");
        return 2;
    }

    char *output_name = create_error_file_name(file_name);
    // allocation went wrong
    if (output_name == NULL)
        return 3;

    FILE *output_file = fopen(output_name, "w");
    if (output_file == NULL) {
        free(output_name);
        perror("Error");
        return 2;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    // first line is the header
    read = getline(&line, &len, input_file);
    fprintf(output_file, "%s", line);

    while ((read = getline(&line, &len, input_file)) != EOF) {
        // remove the new line at the end
        if (read > 0 && line[read - 1] == '\n')
            line[read - 1] = '\0';

        // entity is not valid
        if (parse_entity_line(manager, type, line, n_tokens) == false)
            fprintf(output_file, "%s\n", line);
    }

    return 0;
}