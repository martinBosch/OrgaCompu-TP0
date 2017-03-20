#ifndef __WORDLIST_H__
#define __WORDLIST_H__

#include <string.h>
#include <stdio.h>
#include "Lista.h"
#define MAX_WORD_SIZE 50
// Tipo wordscounter_t: procesa cantidad de palabras dentro de un archivo.
typedef struct {
    TListaSimple word_list;
    char* currentWord;
} wordlist_t;

// Initializa la instancia self para ser utilizada
// Pre: self apunta un sector válido de memoria
void wordlist_create(wordlist_t *self);

// Destruye la instancia self liberando sus recursos.
// Pre: self fue inicializado mediante wordscounter_create
void wordlist_destroy(wordlist_t *self);

// Retorna la cantidad de palabras procesadas
// Pre: self fue inicializado mediante wordscounter_create
TListaSimple* wordlist_get_list(wordlist_t *self);

// Procesa el contenido de text_file, contando sus palabras.
// Pre: self fue inicializado mediante wordscounter_create.
//      text_file es un archivo válido, abierto para lectura.
void wordlist_process(wordlist_t *self, FILE *text_file);

#endif
