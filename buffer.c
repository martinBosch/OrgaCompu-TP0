#include "buffer.h"
#include <string.h>
#include <strings.h>

#define TAM_INICIAL 5000


int buffer_crear(buffer_t *self) {
    self->buffer = malloc(TAM_INICIAL * sizeof(char*));
    if(self->buffer == NULL) {
        return 1;
    }
    self->tam = TAM_INICIAL;
    self->cant_words = 0;
    return 0;
}

void buffer_destruir(buffer_t *self) {
    for (int i = 0; i < self->cant_words; i+=1) {
        free(self->buffer[i]);
    }
    free(self->buffer);
}

static int buffer_redimensionar(buffer_t *self, size_t tam_nuevo) {
    char **buffer_nuevo = realloc(self->buffer, tam_nuevo * sizeof(char*));
    // Cuando tam_nuevo es 0, es correcto que devuelva NULL
    // En toda otra situación significa que falló el realloc
    if (tam_nuevo > 0 && buffer_nuevo == NULL) {
        return 1;
    }
    self->buffer = buffer_nuevo;
    self->tam = tam_nuevo;
    return 0;
}

int buffer_guardar(buffer_t *self, char *word) {
    if(!buffer_esta(self, word)){
        if (self->cant_words >= self->tam) {
            int redimension = buffer_redimensionar(self, self->tam*2);
            if (redimension == 1) {
                return 1;
            }
        }
        size_t tam_word = strlen(word);
        char *aux = malloc((tam_word+1) * sizeof(char));
        memcpy(aux, word, tam_word+1);
        self->buffer[self->cant_words] = aux;
        self->cant_words += 1;
    }

    return 0;
}

void buffer_imprimir_words(buffer_t *self, FILE* stream) {
    for (int i = 0; i < self->cant_words; i+=1) {
        fprintf(stream,"%s\n", self->buffer[i]);
    }
}

void buffer_ordenar(buffer_t *self, size_t modo) {
    if (modo == ORDENAMIENTO_BUBBLESORT)
        bubbleSort(self->buffer, self->cant_words);

    if (modo == ORDENAMIENTO_QUICKSORT)
        quickSort(self->buffer, 0, (self->cant_words) - 1);
}

bool buffer_esta(buffer_t *self, char *word) {
    for (int i = 0; i < self->cant_words; i+=1) {
        if(strncasecmp(word,self->buffer[i],50)==0)
            return true;
    }
    return false;
}
