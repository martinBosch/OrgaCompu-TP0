#include <string.h>
#include <stdbool.h>

#include <stdio.h>


static bool intercambiar(char **word1, char **word2){
    char *aux = *word1;
    *word1 = *word2;
    *word2 = aux;
    return true;
}

// < 0 indica word1 < word2
// = 0 indica word1 = word2
// > 0 indica word1 > word2
static int comparar(const char *word1, const char *word2) {
    return strcmp(word1, word2);
}

static int partition(char **vec, int izq, int der) {
    while (der - izq > 0) {
        char *pivot = vec[izq];
        char *word_a_comparar = vec[izq+1];
        // word_a_comparar es menor al pivot
        if (comparar(word_a_comparar, pivot) < 0) {
            intercambiar(&vec[izq], &vec[izq+1]);
            izq += 1;
        }
        else {
            intercambiar(&vec[izq+1], &vec[der]);
            der -= 1;
        }
    }
    return izq;
}

void quicksort(char **vec, int izq, int der) {
    // Si la lista esta vacia, o es de tamanio 1 esta ordenada.
    if (der-izq <= 0) {
        return;
    }
    int pos_pivot = partition(vec, izq, der);
    // Ordeno los menores al pivot
    quicksort(vec, izq, pos_pivot-1);
    // Ordeno los mayores al pivot
    quicksort(vec, pos_pivot+1, der);
}

void bubbleSort(char **vec, size_t largo_vec) {
    int i, j;
    bool swapped;

    for (i = 0; i < largo_vec - 1; i++) {
        swapped = false;
        for (j = 0; j < largo_vec - 1 - i; j++) {
            if (comparar(vec[j], vec[j + 1]) > 0) {
                swapped = intercambiar(&vec[j], &vec[j + 1]);
            }
        }
        // Si no hubo swap, entonces el vector ya esta ordenado, se rompe el loop.
        if (!swapped) {
            break;
        }
    }
}
