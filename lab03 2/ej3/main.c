#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000



void is_sorted(char sorted[], unsigned int indexes[], char letters[], unsigned int length) {
    unsigned int auxiliar;
    for (unsigned int i = 0; i<length; i++) {
        auxiliar = indexes[i];
        sorted[auxiliar] = letters[i];
    }
}



static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}


unsigned int data_from_file(const char *path,
                            unsigned int indexes[], 
                            char letters[], 
                            unsigned int max_size) {




    FILE *fp;
    unsigned int size;
    unsigned int check_fscanf;
    
    fp = fopen(path, "r");
    if (fp == NULL) {
        fprintf(stderr,"No se le pasó ningun archivo\n");
        exit(EXIT_FAILURE);
    }


    size = 0; //creo esta variable, porque el ejercicio me pide que la función me devuelva cuantas veces se leyó un archivo.
    while( (!feof(fp)) && size<max_size) {
        check_fscanf = fscanf(fp, " %u -> *%c* " , &indexes[size], &letters[size]);
        if(check_fscanf != 2) {
            fprintf(stderr, "Hubo un fallo en la lectura\n"); //porque debe tomar 2 argumentos: %u y %c
            exit(EXIT_FAILURE);
        }
        
        if (indexes[size] > MAX_SIZE) {
            fprintf(stderr, "Muy grande de un index detectado");
            exit(EXIT_FAILURE);
        }

        size++;
    }
    fclose (fp);
    
    return size;
}
    

int main(int argc, char *argv[]) {
    if(argc<2) {
        fprintf(stderr,"Esperaba 2 argumentos y le pasaste menos\n");
        exit(EXIT_FAILURE);
    }

    
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    
    char *filepath = argv[1];
    
    unsigned int length = data_from_file(filepath, indexes, letters, MAX_SIZE);
    
    
    is_sorted(sorted, indexes, letters,length);
    
    
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    /* -- completar -- */

    dump(sorted, length);

    return EXIT_SUCCESS;
}
