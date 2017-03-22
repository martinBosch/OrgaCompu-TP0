#include "wordlist.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STATE_WAITING_WORD 0
#define STATE_IN_WORD 1
#define STATE_FINISHED 2
#define DELIM_WORDS " ,.-*:;/_?!#()[]{}0123456789\n\r\t\\\""

// Compara el caracter leído c y define el nuevo estado.
static char wordlist_next_state(wordlist_t *self, char state, char c);
//Añade el caracter c al string str
static void stradd(char* str,char c);


int wordlist_crear(wordlist_t *self) {
    buffer_crear(&self->word_list);
    self->current_word = malloc(MAX_WORD_SIZE*sizeof(char));
    if (self->current_word == NULL) {
        return 1;
    }
    memset(self->current_word,0,MAX_WORD_SIZE);
    return 0;
}

void wordlist_destruir(wordlist_t *self) {
    buffer_destruir(&self->word_list);
    free(self->current_word);
}

//buffer_t *wordlist_obtener_lista(wordlist_t *self) {
//    return self->word_list;
//}

void wordlist_procesar(wordlist_t *self, FILE *text_file) {
    char state = STATE_WAITING_WORD;
    do {
        int c = getc(text_file);
        state = wordlist_next_state(self, state, c);
    } while (state != STATE_FINISHED);
}

static char wordlist_next_state(wordlist_t *self, char state, char c) {
    char next_state = state;

    if (state == STATE_WAITING_WORD) {
        if (c == EOF) {
            next_state = STATE_FINISHED;
        } else if (strchr(DELIM_WORDS, c) == NULL) {
            next_state = STATE_IN_WORD;
            stradd(self->current_word,c);
        }
    } else if (state == STATE_IN_WORD) {
        if (c == EOF) {
            next_state = STATE_FINISHED;
            if(strlen(self->current_word)>1) {
                buffer_guardar(&self->word_list, self->current_word);
                memset(self->current_word,0,MAX_WORD_SIZE);
            }
        } else if (strchr(DELIM_WORDS, c) != NULL) {
            if(strlen(self->current_word)>1){
                buffer_guardar(&self->word_list, self->current_word);
                memset(self->current_word,0,MAX_WORD_SIZE);
                next_state = STATE_WAITING_WORD;
            }
        } else {
            stradd(self->current_word, c);
        }
    }

    return next_state;
}

void stradd(char* str,char c){
    if(strlen(str)+1<MAX_WORD_SIZE) {
        str[strlen(str)] = c;
        str[strlen(str)+1] =  '\0';
    }
}

void wordlist_imprimir_words(wordlist_t *self) {
    buffer_imprimir_words(&self->word_list);
}
