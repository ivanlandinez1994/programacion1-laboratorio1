#include <stdio.h>
#include <stdlib.h>
#include "opr.h"
#define SIZE_ARRAY 5

/*int main()
{
    int minimo;
    int numeros[SIZE_ARRAY];
    int i;
    for (i=0; i<SIZE_ARRAY; i++){
        printf("ingrese el %d numero\n", (i+1));
        scanf("%d",&numeros[i]);
    }
    if(getValorMinimo(numeros, SIZE_ARRAY, &minimo)==0){
        printf("el valor minimo es: %d\n", minimo);
    }
    return 0;

}*/


/*int main()
{
    int maximo;
    int numeros[SIZE_ARRAY];
    int i;

    for (i=0; i<SIZE_ARRAY; i++){
        printf("ingrese el %d numero\n", i+1);
        scanf("%d", &numeros[i]);
    }
    if(getValorMaximo(numeros, SIZE_ARRAY, &maximo)==0){
        printf("el valor maximo es: %d\n",maximo);
    }
}*/


int main(){
    float promedioMain;
    int numeros[SIZE_ARRAY];
    int i;
    for (i=0; i<SIZE_ARRAY; i++){
        if(getInt(&numeros[i], "ingrese numero", "el ingreso no fue valido", 32767, -32767, 3)==0){
        }
        else{
            printf("valores ingresados no validos");
        }
    }
    if(getCalcularPromedio(numeros, SIZE_ARRAY, &promedioMain)==0){
        printf("el promedio del array es: %.2f",promedioMain);
    }
    else {
        printf("ERROR");
    }
    return 0;
}
