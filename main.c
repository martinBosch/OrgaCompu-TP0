#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdbool.h>

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
            case 'h':	/* fall-through is intentional */
            case '?':
            case 0:
                display_usage();
                break;
        }
    }

    return 0;
}