#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#define SIZE_ARRAY 6

int main()
{
    int numeros[SIZE_ARRAY]={1,8,3,4,1,2};
    if(!sort_mostrarArrayEnteros(numeros, SIZE_ARRAY)){
        printf("\n");
    }

    if(!sort_ordenarArrayInt(numeros, SIZE_ARRAY, 0)){
        if(!sort_mostrarArrayEnteros(numeros, SIZE_ARRAY)){
            printf("\n");
        }
    }
    if(!sort_ordenarArrayInt(numeros, SIZE_ARRAY, 1)){
        if(!sort_mostrarArrayEnteros(numeros, SIZE_ARRAY)){
            printf("\n");
        }
    }

    return 0;
}

