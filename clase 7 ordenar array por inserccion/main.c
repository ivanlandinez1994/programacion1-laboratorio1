#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#define SIZE_ARRAY 7
int main()
{
    int numeros[SIZE_ARRAY]={10,5,4,2,6,1,-1};
    sort_mostrarArray(numeros, SIZE_ARRAY);
    printf("\n");
    sort_expandirArray(numeros, SIZE_ARRAY);
    sort_mostrarArray(numeros, SIZE_ARRAY);
    printf("\n");

    return 0;
}
