/**
 * @file mjs_dotenv.c
 * @author Matthew J. Schmitt
 * @date 2024-02-05
 *
 * @copyright (c) 2024
*/

#define MJS_MAP
#define MJS_DOTENV
#include "mjs.h"

#define MAX_KEYSIZE 41  // 40 Character default limit
#define MAX_ENV_BUF 805416 // 716kb
#define DEFAULT_ENV ".env"

static bool env_initialized = 0;

char *read_file_contents(char *filename) {
    if (!filename) filename = DEFAULT_ENV;
    int ch;
    int count = 0;

    char *read = NULL;

    char file_buffer[MAX_ENV_BUF] = { 0 };
    using_file (file, filename, "rb", {
        do {
            ch = fgetc(file);
            file_buffer[count] = ch;
            count++;
        } while (ch != EOF && count < MAX_ENV_BUF);
    })

    size_t size = strnlen_s(file_buffer, MAX_ENV_BUF) + 1;
    read = (char *)malloc(sizeof(char) * size);
    if (!read) return NULL;

    errno_t err = strcpy_s(read, size, file_buffer);
    if (err != 0) return NULL;

    return read;
}

int load_dotenv(char *env_file) {
    if (env_initialized) return -1;
    char *contents = read_file_contents(env_file);
    if (!contents) {
        printf("Error reading from file: '%s'. Returning...\n", env_file);
        return -1;
    }

    printf("%s\n", contents);
    
    // while (fgets(line, sizeof(line), file)) {
    //     // Remove newline character, if present
    //     line[strcspn(line, "\n")] = 0;

    //     char* delimiter_position = strchr(line, '=');
    //     if (!delimiter_position) {
    //         fprintf(stderr, "Invalid line format: %s\n", line);
    //         continue;
    //     }

    //     // Split the line into key and value
    //     *delimiter_position = '\0';
    //     char* key = line;
    //     char* value = delimiter_position + 1;
    // }

    env_initialized = 1;

    free(contents);

    return 0;
}