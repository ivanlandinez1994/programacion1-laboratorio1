#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char.h"

int main()
{
   char array[10];
   int resultadoNumero;
   if(getInt(array, 10, &resultadoNumero)==0){

   }



    /*char array1[10];
    printf("ingrese lo que desee\n");
    fgets(array1, sizeof(array1), stdin);
    system("cls");
    printf("%s\n", array1);*/

    /*int i;
    strcpy(array, "this is class 6");
    for (i=0; i<strlen(array); i++){
        printf("%c", array[i]);
    }*/

    /*int length=strlen(array);
    for(i=0; i<length; i++){
        printf("%c\n",array[i]);
    }*/
    //printf("\n%d\n", strlen(array));

    /*for(i=0; i<sizeof(array); i++){
        printf("%c",array[i]);
    }*/
    /*while(array[i]!=0){
        printf("%c",array[i]);
        i++;
    }*/
    return 0;
}
