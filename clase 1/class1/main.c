#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;
    char detener;

    do
    {
        printf("\ningrese el numero 1\n");
        scanf("%d",&numeroUno);
        printf("ingrese el numero 2\n");
        scanf("%d",&numeroDos);
        if(numeroUno>0 && numeroDos>0)
        {
            resultado=numeroUno+numeroDos;
            printf("\nel resultado es: %d",resultado);
        }

        else
        {
            printf("\nalguno de los numeros no es mayor a 0\n");
        }

        printf("\nsi desea continuar pulse s, si desea detenerse pulse n\n");
        fflush(stdin);
        scanf("%c",&detener);
    }while(detener !='n');

    return 0;
}
