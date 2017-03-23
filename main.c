#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "wordlist.h"

#define OPTSTRING "Vhqb:o:i"
struct globalArgs_t {
    size_t ordenamiento;
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
void print_version();

void setArgs(int argc, char *argv[]){
    initializeGlobalArgs();
    int opt=0;
    int longIndex=0;
    while( (opt=getopt_long(argc, argv, OPTSTRING, longOpts, &longIndex)) != -1){
        switch (opt){
            case 'V':
                print_version();
                break;
            case 'q':
                globalArgs.ordenamiento=ORDENAMIENTO_QUICKSORT;
                break;
            case 'b':
                globalArgs.ordenamiento=ORDENAMIENTO_BUBBLESORT;
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
    globalArgs.ordenamiento=ORDENAMIENTO_BUBBLESORT; //por default bubblesort
    globalArgs.outFileName=NULL;
    globalArgs.inFileName=NULL;
    globalArgs.outFile=NULL;
    globalArgs.inFile=NULL;
}
void display_usage(){
    printf("Usage: \n");
    printf("tp0 -h \n");
    printf("tp0 -V \n");
    printf("tp0 [options] file \n");
    printf("-V, --version \n");
    printf("Print version and quit.\n");
    printf("-h, --help\n");
    printf("Print this information.\n");
    printf("-o, --output\n");
    printf("Path to output file.\n");
    printf("-i, --input\n");
    printf("Path to input file.\n");
    printf("-q, --qsort\n");
    printf("Use quicksort.\n");
    printf("-b, --bsort\n");
    printf("Use bubblesort.\n");
    printf("Examples\n");
    printf("tp0 -q -i input.txt -o output.txt\n");
    exit(0);
}
void print_version(){
    printf("tp0 Version 0.0000000000000000000000000000001\n");
    exit(0);
}

int main(int argc, char *argv[]){
    wordlist_t wordList;

    setArgs(argc,argv);
    globalArgs.inFile=fopen(globalArgs.inFileName,"r");
    globalArgs.outFile=fopen(globalArgs.outFileName,"w");
    if(globalArgs.inFile==NULL)
        return 1;


    wordlist_crear(&wordList);
    wordlist_procesar(&wordList,globalArgs.inFile);
    wordlist_ordenar(&wordList, globalArgs.ordenamiento);
    wordlist_imprimir_pantalla(&wordList);
    if(globalArgs.outFile!=NULL){
        wordlist_imprimir_archivo(&wordList,globalArgs.outFile);
        fclose(globalArgs.outFile);
    }

    fclose(globalArgs.inFile);

    wordlist_destruir(&wordList);

    return 0;
}
