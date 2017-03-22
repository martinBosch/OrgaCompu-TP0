#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "wordlist.h"

#define OPTSTRING "Vhqb:o:i"
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


void setArgs(int argc, char *argv[]);
void initializeGlobalArgs();
void printWordList(buffer_t* lista);
void display_usage();

void setArgs(int argc, char *argv[]){
    initializeGlobalArgs();
    int opt=0;
    int longIndex=0;
    while( (opt=getopt_long(argc, argv, OPTSTRING, longOpts, &longIndex)) != -1){
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
    }
    if(globalArgs.inFileName==NULL)
        globalArgs.inFileName=argv[optind]; //Si no se utilizo -i el archivo será el ultimo arg

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
    exit(0);
}

/*
//Funcion de prueba para imprimir la lista
void printWordList(buffer_t *lista) {
    char aux[MAX_WORD_SIZE];
    L_Mover_Cte(wordList,L_Primero);
    do{
        L_Elem_Cte(*wordList,aux);
        printf("%s\n",aux);
    }while(L_Mover_Cte(wordList,L_Siguiente));
 }
 */



int main(int argc, char *argv[]){
    wordlist_t wordList;

    setArgs(argc,argv);

    globalArgs.inFile=fopen(globalArgs.inFileName,"r");

    if(globalArgs.inFile==NULL)
        return 1;

    wordlist_crear(&wordList);
    wordlist_procesar(&wordList,globalArgs.inFile);
    wordlist_imprimir_words(&wordList);

    wordlist_ordenar(&wordList, BUBBLESORT);
    printf("ORDENADAS\n");
    wordlist_imprimir_words(&wordList);


    fclose(globalArgs.inFile);
    wordlist_destruir(&wordList);

    return 0;
}
