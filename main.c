#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct globalArgs_t {
    bool isVersion;
    bool isHelp;
    bool isQuickSort;
    bool isBubblesort;
    const char *outFileName;
    FILE *outFile;
    const char *inFileName;
    FILE *inFile;
} globalArgs;

static const char *optString= "Vhqb:o:i";

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

char* wordVec;
int  max = 0; // Tamaño del wordVec

void createWordVec(char text[]) {

    //char text[] = "This #is - www.tutorials+point.com/dale - {website}, esto; es:"
    const char delimit[] = " ,\n\t, ., -, *, :, ;, /, ·, _, ?, !, #, (, ), [, ], {, }"; //
    // Toma el primer token
    wordVec = strtok(text, delimit);
    // Los tokens restantes
    while (wordVec != NULL) {
        max++;
        printf("%s\n", wordVec);
        wordVec = strtok(NULL, delimit);
    }
}

int main(int argc, char *argv[]){
    int opt=0;
    int longIndex=0;
    initilizeGlobalArgs();
    while(opt=getopt_long(argc, argv, optString, longOpts, &longIndex) != -1){
        switch (opt){
            case 'V':
                globalArgs.isVersion=true;
                break;
            case 'h':
                globalArgs.isHelp=true;
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

    return 0;

}



