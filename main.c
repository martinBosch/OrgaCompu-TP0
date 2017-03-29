#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <errno.h>
#include "wordlist.h"

#define OPTSTRING "Vhqb:o:i"
static struct args_t {
    char ordenamiento;
    const char *outFileName;
    FILE *outFile;
    const char *inFileName;
    FILE *inFile;
    bool is_qsort;
    bool is_bsort;
    bool is_oset;
    bool is_iset;
}args;

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
                args.ordenamiento = ORDENAMIENTO_QUICKSORT;
                args.is_qsort = true;
                break;
            case 'b':
                args.ordenamiento = ORDENAMIENTO_BUBBLESORT;
                args.is_bsort = true;
                break;
            case 'o':
                if(args.is_oset)
                    display_usage();
                args.outFileName = optarg;
                args.is_oset = true;
                break;
            case 'i':
                if(args.is_iset)
                    display_usage();
                args.inFileName = optarg;
                args.is_iset = true;
                break;
            case 'h':
            case '?':
            case 0:
            default:
                display_usage();
                break;
        }
    }
    if(args.is_bsort && args.is_qsort){
        printf("ERROR: options q b are incompatible\n");
        display_usage();
    }

    if (args.inFileName == NULL){
        if(argv[optind] != NULL && strcmp(args.outFileName, argv[optind]) != 0)
            args.inFileName = argv[optind];
        else{
            printf("ERROR: no input file\n");
            display_usage();
        }
    }
}
void initializeGlobalArgs(){
    args.ordenamiento = ORDENAMIENTO_QUICKSORT;
    args.outFileName = NULL;
    args.inFileName = NULL;
    args.outFile = NULL;
    args.inFile = NULL;
    args.is_oset = false;
    args.is_bsort = false;
    args.is_qsort = false;
    args.is_iset = false;
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
    printf("Use quickSort.\n");
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
    if(args.inFileName != NULL)
        args.inFile = fopen(args.inFileName,"r");

    if(args.outFileName != NULL)
        args.outFile=fopen(args.outFileName,"w");

    if(args.inFile == NULL){
        printf("ERROR: %s %s\n", args.inFileName, strerror(errno));
        return 1;
    }

    if(args.outFileName != NULL && args.outFile == NULL){
        printf("ERROR: %s %s\n", args.outFileName, strerror(errno));
        return 1;
    }

    wordlist_crear(&wordList);
    wordlist_procesar(&wordList,args.inFile);
    wordlist_ordenar(&wordList, args.ordenamiento);
    wordlist_imprimir_pantalla(&wordList);
    if(args.outFile != NULL){
        wordlist_imprimir_archivo(&wordList,args.outFile);
        fclose(args.outFile);
    }
    fclose(args.inFile);
    wordlist_destruir(&wordList);

    return 0;
}
