#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000  // tamaño del 

int main() {
    int a[N], b[N], c[N];
    int i;

    // iniciar arrays a y b
    for (i = 0; i < N; i++) {
        a[i] = i + 1;
        b[i] = (i + 1) * 2;
    }

    //imprimir arrays a y b
    printf("Array a:\n");
    for (i = 0; i < 10; i++) { // los primeros 10 elementos para brevedad
        printf("%d ", a[i]);
    }
    printf("\nArray b:\n");
    for (i = 0; i < 10; i++) { 
        printf("%d ", b[i]);
    }
    printf("\n");   

    // establecer el numero de hilos en 4
    omp_set_num_threads(4);

    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    // Imprimir algunos resultados para verificar
    printf("Primeros 10 resultados:\n");
    for (i = 0; i < 10; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }

    return 0;
}