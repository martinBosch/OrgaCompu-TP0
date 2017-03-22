#include <string.h>
#include <stdbool.h>

#include <stdio.h>

/* ADAPTAR
void intercambiarQS(int num1, int num2) {

    char temp = charArray[num1];
    charArray[num1] = charArray[num2];
    charArray[num2] = temp;
}

int partition(int left, int right, int pivot) {
    int leftPointer = left -1;
    int rightPointer = right;

    while(true) {
        while(intArray[++leftPointer] < pivot) {
            //do nothing
        }

        while(rightPointer > 0 && intArray[--rightPointer] > pivot) {
            //do nothing
        }

        if(leftPointer >= rightPointer) {
            break;
        } else {
            swap(leftPointer,rightPointer);
        }
    }

    swap(leftPointer,right);
    return leftPointer;
}

void quickSort(int left, int right) {
    if(right-left <= 0) {
        return;
    } else {
        int pivot = intArray[right];
        int partitionPoint = partition(left, right, pivot);
        quickSort(left,partitionPoint-1);
        quickSort(partitionPoint+1,right);
    }
}
*/


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
