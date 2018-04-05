#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int numeroUno;
    int numeroDos;
    float resultadoOperacionMain;
    int operacionARealizar;

    while(operacionARealizar!=9){
        printf("elija una opcion del menu: (1/2/3/4/5/6/7/8/9).\n(1)para ingresar el primer operando  (2)para ingresar el segundo operando"
                "\n(3)sumarlos (4)restarlos (5)dividirlos (6)multiplicarlos\n (7)hacer el factorial del primer numero"
                "\n(8)todas las operaciones (9)para salir.\n");
        scanf("%d",&operacionARealizar);

        while(operacionARealizar>9 || operacionARealizar<1){
            printf( "elija una opcion del menu de opciones:\n(1) para ingresar el primer operando(2) para ingresar el segundo operando"
                "(3) sumarlos(4) restarlos(5) dividirlos\n(6) multiplicarlos(7) hacer el factorial del primer numero"
                "(8) todas las operaciones(9) para salir.\n");
            fflush(stdin);
            scanf("%d",&operacionARealizar);
        }

        switch (operacionARealizar){
        case 1:
            printf("\ningrese el primer numero\n");
            scanf("%d",&numeroUno);
        break;
        case 2:
            printf("\ningrese el segundo numero\n");
            scanf("%d",&numeroDos);
        break;
        case 3:
            if(sumaNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("\n%d + %d = %.0f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 4:
            if(restaNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("\n%d - %d = %.0f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 5:
            if(divisionNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("\n%d / %d = %.2f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 6:
            if(multiplicacionNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("\n%d * %d = %.0f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 7:
            if(factorialNumero1(numeroUno, &resultadoOperacionMain)==0){
                printf("\n%d ! = %.0f\n",numeroUno,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 8:
            if(sumaNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("\n%d + %d = %.0f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
            if(restaNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("%d - %d = %.0f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
            if(divisionNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("%d / %d = %.2f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
            if(multiplicacionNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("%d * %d = %.0f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
            if(factorialNumero1(numeroUno, &resultadoOperacionMain)==0){
                printf("%d ! = %.0f\n",numeroUno,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 9:
            printf("fin de la aplicacion.¡");
        break;
        }
    }
    system("cls");
    return 0;
}

