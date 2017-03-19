#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "simclist.h"
#define OPTSTRING "Vhqb:o:i"
#define WORD_MAX_LENGTH
struct globalArgs_t {
    bool isVersion;
    bool isQuickSort;
    bool isBubblesort;
    const char *outFileName;
    FILE *outFile;
    const char *inFileName;
    FILE *inFile;
}globalArgs;

static const struct option longOpts[] = {
        { "version", no_argument, NULL, 'V' },
        { "help", no_argument, NULL, 'h' },
        { "qsort", no_argument, NULL, 'q' },
        { "bsort", no_argument, NULL, 'b' },
        { "output", required_argument, NULL, 'o' },
        { "input", required_argument, NULL, 'i' },
        { NULL, no_argument, NULL, 0 }
};

void bubbleSort(char* vec, int MAX) { // REVISAR
    char word;
    int i, j;
    bool swapped;

    for (i = 0; i < MAX - 1; i++) {
        swapped = false;
        for (j = 0; j < MAX - 1 - i; j++) {
            if (vec[j] > vec[j + 1]) {
                word = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = word;

                swapped = true;
            }
        }
        // Si no hubo swap, entonces el vector ya esta ordenado, se rompe el loop.
        if (!swapped) {
            break;
        }
    }
}


list_t getWordList(char* text) {
    list_t wordList;
    list_init(&wordList);
    char* word;
    const char *delimit = " ,\n\t.-*:;/·_?!#()[]{}";
    word = strsep(&text, delimit);
    while (word != NULL) {
        list_append(&wordList,word);
        do {
            word = strsep(&text, delimit);
        }while(word!=NULL&&strcmp(word,"")==0);
    }
    return wordList;

}
void printWordList(list_t* wordList){
    list_iterator_start(wordList);
    while(list_iterator_hasnext(wordList)){
        printf("%s\n",(char*)list_iterator_next(wordList));
    }
    list_iterator_stop(wordList);
}
void display_usage();
int main(int argc, char *argv[]){
    int opt=0;
    int longIndex=0;
    list_t lista;
   /* initializeGlobalArgs();
    while(opt=getopt_long(argc, argv, OPTSTRING, longOpts, &longIndex) != -1){
        switch (opt){
            case 'V':
                globalArgs.isVersion=true;
                break;
            case 'q':
                globalArgs.isQuickSort=true;
                break;
            case 'b':
                globalArgs.isBubblesort=true;
                break;
            case 'o':
                globalArgs.outFileName=optarg;
                break;
            case 'i':
                globalArgs.inFileName=optarg;
                break;
            case 'h':
            case '?':
            case 0:
                display_usage();
                break;
        }
    }*/
    lista=getWordList(argv[1]);
    printWordList(&lista);
    return 0;
}

void initializeGlobalArgs(){
    globalArgs.isBubblesort=false;
    globalArgs.isVersion=false;
    globalArgs.isQuickSort=false;
    globalArgs.outFileName=NULL;
    globalArgs.inFileName=NULL;
    globalArgs.outFile=NULL;
    globalArgs.inFile=NULL;
}
void display_usage(){

}



