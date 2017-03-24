#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdlib.h>

#define ORDENAMIENTO_BUBBLESORT 0
#define ORDENAMIENTO_QUICKSORT 1

void bubbleSort(char **vec, size_t largo_vec);
void quicksort(char **vec, size_t izq, size_t der);

#endif //ORDENAMIENTO_H
