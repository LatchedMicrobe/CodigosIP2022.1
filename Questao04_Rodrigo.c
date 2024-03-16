#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITSIZE 10
#define BUFFSIZE 100

int
main(void) {
    char **strings;
    size_t currsize = INITSIZE, str_count = 0, slen;

    char buffer[BUFFSIZE];
    char *word;
    const char *delim = " ";
    int i;

    /* Allocate initial space for array */
    strings = malloc(currsize * sizeof(*strings));
    if(!strings) {
        printf("Issue allocating memory for array of strings.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter some words(Press enter again to end): ");
    while (fgets(buffer, BUFFSIZE, stdin) != NULL && strlen(buffer) > 1) {

        /* grow array as needed */
        if (currsize == str_count) {
            currsize *= 2;
            strings = realloc(strings, currsize * sizeof(*strings));
            if(!strings) {
                printf("Issue reallocating memory for array of strings.\n");
                exit(EXIT_FAILURE);
            }
        }

        /* Remove newline from fgets(), and check for buffer overflow */
        slen = strlen(buffer);
        if (slen > 0) {
            if (buffer[slen-1] == '\n') {
                buffer[slen-1] = '\0';
            } else {
                printf("Exceeded buffer length of %d.\n", BUFFSIZE);
                exit(EXIT_FAILURE);
            }
        }

        /* Parsing of words from stdin */
        word = strtok(buffer, delim);
        while (word != NULL) {

            /* allocate space for one word, including nullbyte */
            strings[str_count] = malloc(strlen(word)+1);
            if (!strings[str_count]) {
                printf("Issue allocating space for word.\n");
                exit(EXIT_FAILURE);
            }

            /* copy strings into array */
            strcpy(strings[str_count], word);

            str_count++;
            word = strtok(NULL, delim);
        }
    }

    /* free strings */
    printf("Your array of strings:\n");
    for (i = 0; i < str_count; i++) {
        free(strings[i]);
        strings[i] = NULL;
    }

    free(strings);
    strings = NULL;

    return 0;
}
