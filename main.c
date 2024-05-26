#include "struct.h"



int main(int argc, char* argv[]){
    FILE* fin, *fout1, *fout2;
    
    fin = fopen(argv[1], "rb");
    if(fin == NULL){
        exit(1);
    }

    fout1 = fopen(argv[2], "wb");
    if(fout1 == NULL){
        exit(1);
    }

    fout2 = fopen(argv[3], "wb");
    if(fout2 == NULL){
        exit(1);
    }

    task(fin, fout1, fout2);

    return 0;
}