#ifndef __WORDLIST_H__
#define __WORDLIST_H__

#include <string.h>
#include <stdio.h>
//#include "Lista.h"
#include "buffer.h"

#define MAX_WORD_SIZE 50


typedef struct {
    buffer_t word_list;
    char *current_word;
} wordlist_t;

// Initializa la instancia self para ser utilizada
// Pre: self apunta un sector válido de memoria
int wordlist_crear(wordlist_t *self);

// Destruye la instancia self liberando sus recursos.
// Pre: self fue inicializado mediante wordscounter_create
void wordlist_destruir(wordlist_t *self);

// Retorna la lista de palabras
// Pre: self fue inicializado mediante wordscounter_create
//buffer_t* wordlist_obtener_lista(wordlist_t *self);

// Procesa el contenido de text_file, obteniendo sus palabras.
// Pre: self fue inicializado mediante wordlist_create.
//      text_file es un archivo válido, abierto para lectura.
void wordlist_procesar(wordlist_t *self, FILE *text_file);

void wordlist_imprimir_pantalla(wordlist_t *self);

void wordlist_ordenar(wordlist_t *self, size_t modo);

void wordlist_imprimir_archivo(wordlist_t *self, FILE *text_file);
#endif
