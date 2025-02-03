#include "interface/batch.h"
#include "interface/test.h"
#include <stdio.h>

int main(int argc, char **argv) {
    // main program
    if (argc == 3) {
        batch_mode(argv[1], argv[2]);
    } else if (argc == 4) {
        // test program
        test_mode(argv[1], argv[2], argv[3]);
    } else {
        fprintf(stdout, "Usage:\n");
        fprintf(stdout, "Main Program: ./programa-principal [dataset-folder] [inputs-file]\n");
        fprintf(stdout, "Test Program: ./programa-testes [dataset-folder] [inputs-file] [correct-output-folder]\n");
        return 1;
    }

    return 0;
}