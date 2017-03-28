#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ordenamiento.h"

typedef struct {
    char **buffer;
    size_t tam;
    size_t cant_words;
} buffer_t;

int buffer_crear(buffer_t *self);

void buffer_destruir(buffer_t *self);

int buffer_guardar(buffer_t *self, char *word);

//size_t buffer_obtener_cant(buffer_t *self);
bool esta_en_buffer(buffer_t *self, char *word);
void buffer_imprimir_words(buffer_t *self, FILE* stream);

void buffer_ordenar(buffer_t *self, size_t modo);

#endif //BUFFER_H
