#include <stdio.h>
#include <stdlib.h>
#define NUMEROS 5
// segundo intento
int main()
{
    int numero;
    int sumatoria=0;
    float promedio;
    int i;
    int max;
    int min;
    int flag=0;

    for(i=0; i<NUMEROS; i++){
        printf("ingrese el %d numero\n", i+1);
        scanf("%d",&numero);
        sumatoria=sumatoria+numero;

        if(max<numero || flag==0){
            max=numero;
            flag=1;
        }
        if(min>numero || flag==0){
            min=numero;
            flag=1;
        }
    }
    promedio=(float)sumatoria/NUMEROS;
    printf("el promedio es: %.2f\n",promedio);
    printf("el maximo es: %d y el minimo es: %d\n",max,min);

    return 0;
}
