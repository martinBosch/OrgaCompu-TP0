#include "wordlist.h"

#define STATE_WAITING_WORD 0
#define STATE_IN_WORD 1
#define STATE_FINISHED 2
#define DELIM_WORDS "\xbb\xef\xbf ,.-*$%&·:;/_?=@«¡!#()[]{}0123456789\n\r\t\\\""
// Compara el caracter leído c y define el nuevo estado.
static char wordlist_next_state(wordlist_t *self, char state, int c);
//Añade el caracter c al string str
static void stradd(char* str,int c);
//guarda en el buffer la current word
static void save_word(wordlist_t *self);

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

void wordlist_procesar(wordlist_t *self, FILE *text_file) {
    char state = STATE_WAITING_WORD;
    do {
        int c = getc(text_file);
        state = wordlist_next_state(self, state, c);
    } while (state != STATE_FINISHED);
}

static char wordlist_next_state(wordlist_t *self, char state, int c) {
    char next_state = state;

    if (state == STATE_WAITING_WORD) {
        if (c == EOF) {
            next_state = STATE_FINISHED;
        } else if (strchr(DELIM_WORDS, c) == NULL && c!='\'') {// Hay que comparar solo en este estado el caracter ' porque si no se saltea las contractions
            next_state = STATE_IN_WORD;
            stradd(self->current_word,c);
        }
    } else if (state == STATE_IN_WORD) {
        if (c == EOF) {
            save_word(self);
            next_state = STATE_FINISHED;
        } else if (strchr(DELIM_WORDS, c) != NULL) {
            save_word(self);
            next_state = STATE_WAITING_WORD;
        } else {
            stradd(self->current_word, c);
        }
    }

    return next_state;
}

void save_word(wordlist_t *self){

        if(strlen(self->current_word)>1) {//Si es de menos de un caracter puede ser que haya encontrado solo dos delimitadores seguidos
            buffer_guardar(&self->word_list, self->current_word);
            memset(self->current_word,0,MAX_WORD_SIZE);
        }
        else{
            if(strpbrk(self->current_word,DELIM_WORDS)==NULL){//Hay que guardar las palabras de un solo caracter que no sea delim
                buffer_guardar(&self->word_list, self->current_word);
                memset(self->current_word,0,MAX_WORD_SIZE);
            }
        }


}

void stradd(char* str,int c){
    if(strlen(str)+1<MAX_WORD_SIZE) {
        str[strlen(str)] = c;
        str[strlen(str)+1] =  '\0';
    }
}

void wordlist_imprimir_pantalla(wordlist_t *self) {
    buffer_imprimir_words(&self->word_list,stdout);
}

void wordlist_imprimir_archivo(wordlist_t *self, FILE *text_file){
    buffer_imprimir_words(&self->word_list,text_file);
}

void wordlist_ordenar(wordlist_t *self, size_t modo) {
    buffer_ordenar(&self->word_list, modo);
}
