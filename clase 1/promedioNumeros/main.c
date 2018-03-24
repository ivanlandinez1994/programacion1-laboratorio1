#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 5
int main()
{

    int i;
    int numero;
    int sumatoria=0;
    float promedio;

    for(i=0; i<CANTIDAD_NUMEROS; i++)
    {
        printf("\ningrese numero %d\n",i+1);
        scanf("%d",&numero);
        sumatoria=numero+sumatoria;
    }
    promedio=(float)sumatoria/CANTIDAD_NUMEROS;
    printf("\nel promedio de los numeros es: %f", promedio);
    return 0;
}
