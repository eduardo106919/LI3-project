#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include "managers/catalog.h"
#include <stdbool.h>

bool check_artist(Catalog *manager, char **tokens, unsigned n_tokens);

#endif