#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int *ptr = NULL; // Initialize ptr outside the loop

    int i;
    for (i = 0; i < 10000; i++) {
        // Allocate memory dynamically
        ptr = (int *)malloc(sizeof(int));
        
        if (ptr == NULL) {
            // Handle memory allocation failure
            return 1;
        }
        
        // Use allocated memory
        *ptr = i;
        
        // Free allocated memory
        free(ptr);
        
        // Sleep after a certain number of iterations
        if (i == 5000) {
            FILE *file = fopen(filename, "r");
            if (file != NULL) {
                int sleep_duration;
                if (fscanf(file, "%d", &sleep_duration) == 1) {
                    printf("Sleeping for %d seconds...\n", sleep_duration);
                    sleep(sleep_duration);
                } else {
                    printf("Error: Failed to read sleep duration from file.\n");
                }
                fclose(file);
            } else {
                printf("Error: Failed to open file.\n");
            }
        }
    }
    // Double free - freeing already freed memory
    free(ptr);
    return 0;
}