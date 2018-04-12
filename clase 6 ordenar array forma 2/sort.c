#include <stdio.h>
#include <stdlib.h>
int sort_expandirArray(int* array, int cantidad, int desde, int hasta, int sentido){
    int retorno=-1;
    int i;
    int auxiliar;

    for (i=desde; i<hasta-1; i++){
        auxiliar=array[i];
        array[i]=array[i+1];
        array[i+1]=auxiliar;
    }

    return retorno;
}
int sort_mostrarArray(int* array, int cantidad){
    int i;
    int retorno=-1;
    for(i=0; i<cantidad; i++){
        printf("\n%d", array[i]);
    }
    return retorno;
}
