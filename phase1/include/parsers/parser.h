#ifndef PARSER_H
#define PARSER_H

#include "managers/catalog.h"
#include <stdbool.h>

int parse_entity(Catalog *manager, const char *file_name, Entity type, unsigned n_tokens);


#endif