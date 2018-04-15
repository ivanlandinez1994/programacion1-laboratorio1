#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getInt(char* array, int cantidad, int* resultado){
    int retorno=-1;
    int i;
    if(cantidad>0){
        printf("\ningrese los numeros deseados\n");
        fgets(array, sizeof(array), stdin);
        //array[strlen(array)-1]=0;
        for(i=0; i<strlen(array); i++){
            if(array[i]>'9' || array[i]<'0'){
                retorno=-1;
                break;
            }
            else{
                retorno=0;
            }
        }
        if(retorno==0){
            *resultado=atoi(array);
            printf("\n%d",atoi(array));
        }
        else{
            printf("no ingreso un numero");
        }
    }
    return retorno;
}
