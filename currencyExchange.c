/**
 * @file currencyExchange.c
 * @author Matthew J. Schmitt
 * @date 2024-02-02
 *
 * @copyright (c) 2024
*/

#define MJS_MAP
#define MJS_DOTENV
#include "mjs.h"

int main(void) {
    struct map my_map;

    map_init(&my_map, hash_sha256);
    map_insert(&my_map, "API_KEY", 8, "test value");
    char *val = map_get(&my_map, "API_KEY", 8);
    if (!val) {
        printf("No API_KEY found in environment. Exiting...");
        return -1;
    }
    printf("%s\n", val);

    // load_dotenvWP(".env");
    // load_dotenvNP();
    
    return 0;
}