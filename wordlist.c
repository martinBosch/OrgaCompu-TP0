#include "wordlist.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//#define MAX_WORD_SIZE 50
#define STATE_WAITING_WORD 0
#define STATE_IN_WORD 1
#define STATE_FINISHED 2
#define DELIM_WORDS " ,.-*:;/_?!#()[]{}0123456789\n\r\t\\\""

// Compara el caracter leído c y define el nuevo estado.
static char wordlist_next_state(wordlist_t *self, char state, char c);
//
void stradd(char* str,char c);

void wordlist_create(wordlist_t *self) {
    L_Crear(&(self->word_list),MAX_WORD_SIZE);
    self->currentWord=malloc(MAX_WORD_SIZE*sizeof(char));
    memset(self->currentWord,0,MAX_WORD_SIZE);
}

void wordlist_destroy(wordlist_t *self) {
    L_Vaciar(&(self->word_list));
    free(self->currentWord);
}

TListaSimple* wordlist_get_list(wordlist_t *self) {
    return &(self->word_list);
}

void wordlist_process(wordlist_t *self, FILE *text_file) {
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
            stradd(self->currentWord,c);
        }
    } else if (state == STATE_IN_WORD) {
        if (c == EOF) {
            next_state = STATE_FINISHED;
            if(strlen(self->currentWord)>1) {
                L_Insertar_Cte(&(self->word_list),L_Siguiente,self->currentWord);
                memset(self->currentWord,0,MAX_WORD_SIZE);
            }
        } else if (strchr(DELIM_WORDS, c) != NULL) {
            if(strlen(self->currentWord)>1){
                L_Insertar_Cte(&(self->word_list),L_Siguiente,self->currentWord);
                memset(self->currentWord,0,MAX_WORD_SIZE);
            }
        }else
        stradd(self->currentWord,c);
    }

    return next_state;
}
void stradd(char* str,char c){
    if(strlen(str)+1<MAX_WORD_SIZE) {
        str[strlen(str)] = c;
        str[strlen(str)+1] =  '\0';
    }
}
