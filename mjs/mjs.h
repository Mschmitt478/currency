/**
 * @file mjs.h
 * @author Matthew J. Schmitt
 * @date 2024-02-05
 *
 * @copyright (c) 2024
*/
#ifndef MJS_H
#define MJS_H

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

/* Typedefs */

extern int main(void);

/* Definitions */

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef bool
#define bool _Bool
#endif

#ifndef size_t
#define size_t unsigned long long
#endif

#define PRINT_FAILURE -1

/* MACROS */

#define foreach_arr(item, iter, iter_size, codeBlock) do { \
    for (int i = 0; i < iter_size; i++) { \
        item = iter[i]; \
        {codeBlock} \
    } \
} while (0);

#define foreach_ptr(item, iter, codeBlock) do { \
    while (*iter) { \
        item = *iter; \
        {codeBlock} \
        iter++; \
    } \
} while (0);

#define using_file(var_name, filename, mode, codeBlock) do { \
    FILE *var_name = fopen(filename, mode); \
    if (!var_name) { \
        perror("Error opening file"); \
    } \
    else { \
        {codeBlock} \
        if (fclose(var_name) == EOF) { \
            perror("Error closing file"); \
        } \
    } \
} while (0);

/* Includes */
#ifdef MJS_MAP
#include "mjs_map.h"
#endif

#ifdef MJS_DOTENV
#include "mjs_dotenv.h"
#endif

/* Functions */

#endif // MJS_H