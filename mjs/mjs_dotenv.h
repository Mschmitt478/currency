/**
 * @file mjs_dotenv.h
 * @author Matthew J. Schmitt
 * @date 2024-02-05
 *
 * @copyright (c) 2024
*/
#ifndef MJS_DOTENV_H
#define MJS_DOTENV_H

#define MJS_MAP
#include "mjs.h"

extern struct map env = { .arr = { 0 }, .hash_func=NULL };

int load_dotenv(char *filename);
#define load_dotenvWP(filename) load_dotenv(filename)
#define load_dotenvNP() load_dotenv(NULL)

#endif // MJS_DOTENV_H