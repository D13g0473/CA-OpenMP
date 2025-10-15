#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num_threads = 4;  // Default number of threads

    if (argc > 1) {
        num_threads = atoi(argv[1]);
        if (num_threads <= 0) {
            printf("Error: Number of threads must be a positive integer.\n");
            return 1;
        }
    }

    omp_set_num_threads(num_threads);

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("Hola Mundo Desde El Thread %d\n", tid);
    }

    return 0;
}