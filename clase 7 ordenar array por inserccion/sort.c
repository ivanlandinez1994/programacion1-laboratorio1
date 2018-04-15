#include <stdio.h>
#include <stdlib.h>
int sort_expandirArray(int* array, int cantidad/*, int desde, int hasta*/){
    int retorno=-1;
    int i,j;
    int auxiliarTemporal;
    if(cantidad>0){
        retorno=0;
        for(i=1; i<cantidad; i++){
            auxiliarTemporal=array[i];
            j=i-1;
            while(j>=0 && auxiliarTemporal<array[j]){
                array[j+1]=array[j];
                j--;
            }
            array[j+1]=auxiliarTemporal;
        }
    }
    return retorno;
}
int sort_mostrarArray(int* array, int cantidad){
    int i;
    int retorno=-1;
    if(cantidad>0){
        retorno=0;
        for(i=0; i<cantidad; i++){
            printf("\n%d", array[i]);
        }
    }
    return retorno;
}
