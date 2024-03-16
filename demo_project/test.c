#include <stdlib.h>
#include <unistd.h>

int main() {
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
            sleep(10); // Sleep for 10 seconds
        }
    }
    // Double free - freeing already freed memory
    free(ptr);
    return 0;
}