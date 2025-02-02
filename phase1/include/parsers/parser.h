#ifndef PARSER_H
#define PARSER_H

#include "managers/catalog.h"
#include <stdbool.h>

int parse_entity(Catalog *manager, const char *file_name, unsigned num_tokens,
                 bool (*check_entity)(Catalog *, char **, unsigned),
                 void *(*create_entity)(const char **, unsigned), Entity ent);

#endif