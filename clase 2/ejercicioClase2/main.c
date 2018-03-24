#include <stdio.h>
#include <stdlib.h>
#define NUMEROS 3

int main()
{
    int numero;
    int sumatoria=0;
    float promedio;
    int i;
    char respuesta;

    do{
        for(i=0; i<NUMEROS; i++){
            printf("ingrese el %d numero\n", i+1);
            scanf("%d",&numero);
            sumatoria=sumatoria+numero;
        }
        promedio=(float)sumatoria/NUMEROS;
        printf("el promedio es: %.2f",promedio);
        printf("\ndesea continuar? s para si n para no\n");
        fflush(stdin);
        scanf("%c",&respuesta);
    }while(respuesta=='s');
    return 0;
}
