/**
 * @file map.c
 * @author Matthew J. Schmitt
 * @date 2024-02-05
 *
 * @copyright (c) 2024
*/
#define MJS_MAP
#include "mjs.h"

#include <stdlib.h>

size_t hash_basic(char *value, size_t keysize) {
    int sum = 0;
    char *temp = value;
    size_t i = 0;
    foreach_ptr (int ch, temp, {
        if (i > keysize) break;
        sum += ch;
        i++;
    })
    return (sum % MAP_MAX);
}

size_t hash_sha256(char *value, size_t keysize) {
    uint8_t *digest = sha256_data((uint8_t *)value, keysize);
    if (digest == NULL) {
        // Handle error
        return 0;
    }
    
    // Assuming size_t is 8 bytes and taking the first 8 bytes of the hash for simplicity
    size_t hashValue = 0;
    memcpy(&hashValue, digest, sizeof(size_t));
    free(digest); // Free the allocated memory for the digest
    
    size_t index = hashValue % MAP_MAX;
    
    return index;
}

void map_init(struct map *map, size_t (*hash_func)(char *, size_t)) {
    memset(map->arr, 0, sizeof(map->arr));
    map->hash_func = hash_func;
}

int map_insert(struct map *map, char *key, size_t keysize, char *value) {
    int idx = map->hash_func(key, keysize);
    map->arr[idx] = value;
    return idx;
}

/**
 * @brief Gets the value at the key if there is one.
 * 
 * @param map the map to retrieve the value
 * @param key the key to search for
 * 
 * @return the found or not found value
 *  NOTE: Unknown behavior if array indexes are not initialized to 0 or NULL
*/
char *map_get(struct map* map, char *key, size_t keysize) {
    int idx = map->hash_func(key, keysize);
    char *ret = map->arr[idx];
    return ret;
}