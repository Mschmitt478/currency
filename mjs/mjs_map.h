/**
 * @file map.h
 * @author Matthew J. Schmitt
 * @date 2024-02-05
 *
 * @copyright (c) 2024
*/
#ifndef MJS_MAP_H
#define MJS_MAP_H
#include "mjs.h"
#include <sha256/sha256.h>

#define MAP_MAX 100

struct map {
    char *arr[MAP_MAX];
    size_t (*hash_func)(char *value, size_t keysize);
};

/**
 * @brief An extremely basic example hash
 * 
 * @param value the value being hashed
 * @return the hashed value
*/
size_t hash_basic(char *value, size_t keysize);
size_t hash_sha256(char *value, size_t keysize);

/**
 * @brief Initializes the map structure for use.
 * 
 * @param map the map to initialize
 * @param hash_func the hashing function to use in insertion
*/
void map_init(struct map *map, size_t (*hash_func)(char *, size_t));
int map_insert(struct map *map, char *key, size_t keysize, char *value);
/**
 * @brief Gets the value at the key if there is one.
 * 
 * @param map the map to retrieve the value
 * @param key the key to search for
 * 
 * @return the found or not found value
 *  NOTE: Unknown behavior if array indexes are not initialized to 0 or NULL
*/
char *map_get(struct map* map, char *key, size_t keysize);

#endif // MJS_MAP_H