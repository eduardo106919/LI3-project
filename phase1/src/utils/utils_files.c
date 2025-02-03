#include "utils/utils_files.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *create_error_file_name(const char *basename) {
    if (basename == NULL)
        return NULL;

    // find the last dot in the basename
    const char *ext = strrchr(basename, '.');
    size_t base_len = ext ? (size_t)(ext - basename) : strlen(basename);
    // "_errors" + extension + null terminator
    size_t new_len = base_len + 8 + (ext ? strlen(ext) : 0) + 1;

    char *result = (char *)calloc(new_len, sizeof(char));
    if (result == NULL)
        return NULL;

    snprintf(result, new_len, "%.*s_errors%s", (int)base_len, basename, ext ? ext : "");
    
    return result;
}

