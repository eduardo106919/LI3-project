#include "managers/catalog.h"
#include "utils/utils_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_entity_line(Catalog *manager, const char *line,
                             bool (*check_entity)(Catalog *, char **, unsigned),
                             unsigned num_tokens, Entity ent) {
    char *temp = strdup(line);
    char *tokens[num_tokens];

    // tokenize the line
    for (unsigned i = 0; i < num_tokens; i++) {
        tokens[i] = strsep(&temp, ";");

        remove_first_last_char(tokens[i]);        
    }

    // entity is valid
    if (check_entity(manager, tokens, num_tokens) == true)
        catalog_add_entity(tokens, num_tokens, ent);
    else
        return 1;
    
    free(*tokens);
    return 0;
}

int parse_entity(Catalog *manager, const char *file_name, unsigned num_tokens,
                 bool (*check_entity)(Catalog *, char **, unsigned),
                 void *(*create_entity)(const char **, unsigned), Entity ent) {
    FILE *input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        perror("Error");
        return 1;
    }

    size_t len = strlen(file_name);

    char output_name[len + strlen("_errors") + 1];
    strncpy(output_name, file_name, len - strlen(".csv"));
    output_name[len - strlen(".csv")] = '\0';
    strcat(output_name, "_errors.csv");

    FILE *output_file = fopen(output_name, "w");
    if (output_file == NULL) {
        perror("Error");
        fclose(input_file);
        return 1;
    }

    char *line = NULL;
    ssize_t read = 0;

    // first line is the header
    read = getline(&line, &len, input_file);
    fprintf(output_file, "%s", line);

    while ((read = getline(&line, &len, input_file)) != EOF) {
        // remove the new line at the end
        if (read > 0 && line[read - 1] == '\n')
            line[read - 1] = '\0';

        if (parse_entity_line(manager, line, check_entity, num_tokens, create_entity) != 0)
            fprintf(output_file, "%s", line);
    }

    free(line);

    fclose(input_file);
    fclose(output_file);

    return 0;
}