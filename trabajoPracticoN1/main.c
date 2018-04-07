#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int numeroUno=0;
    int numeroDos=0;
    float resultadoOperacionMain;
    int operacionARealizar;

    while(operacionARealizar!=9){

        printf("\nelija una opcion del menu:\n");
        printf("1- Ingresar 1er operando (A=%d)\n", numeroUno);
        printf("2- Ingresar 2do operando (B=%d)\n", numeroDos);
        printf("3- Calcular la suma (%d+%d)\n", numeroUno, numeroDos);
        printf("4- Calcular la resta (%d-%d)\n", numeroUno, numeroDos);
        printf("5- Calcular la division (%d/%d)\n", numeroUno, numeroDos);
        printf("6- Calcular la multiplicacion (%d*%d)\n", numeroUno, numeroDos);
        printf("7- Calcular el factorial (%d!)\n", numeroUno);
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&operacionARealizar);

        while(operacionARealizar>9 || operacionARealizar<1){
            system("cls");
            printf("\nelija una opcion del menu:\n");
            printf("1- Ingresar 1er operando (A=%d)\n", numeroUno);
            printf("2- Ingresar 2do operando (B=%d)\n", numeroDos);
            printf("3- Calcular la suma (%d+%d)\n", numeroUno, numeroDos);
            printf("4- Calcular la resta (%d-%d)\n", numeroUno, numeroDos);
            printf("5- Calcular la division (%d/%d)\n", numeroUno, numeroDos);
            printf("6- Calcular la multiplicacion (%d*%d)\n", numeroUno, numeroDos);
            printf("7- Calcular el factorial (%d!)\n", numeroUno);
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");
            fflush(stdin);
            scanf("%d",&operacionARealizar);
        }

        switch (operacionARealizar){
        case 1:
            system("cls");
            printf("\ningrese el primer numero\n");
            scanf("%d",&numeroUno);
        break;
        case 2:
            system("cls");
            printf("\ningrese el segundo numero\n");
            scanf("%d",&numeroDos);
        break;
        case 3:
            system("cls");
            if(sumaNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("\n%d + %d = %.0f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 4:
            system("cls");
            if(restaNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("\n%d - %d = %.0f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 5:
            system("cls");
            if(divisionNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("\n%d / %d = %.2f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 6:
            system("cls");
            if(multiplicacionNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==0){
                printf("\n%d * %d = %.0f\n",numeroUno,numeroDos,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 7:
            system("cls");
            if(factorialNumero1(numeroUno, &resultadoOperacionMain)==0){
                printf("\n%d ! = %.0f\n",numeroUno,resultadoOperacionMain);
            }
            else{
                printf("ERROR\n");
            }
        break;
        case 8:
            system("cls");
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
            else if(divisionNumeros(numeroUno, numeroDos, &resultadoOperacionMain)==-2){
                printf("el divisior debe ser diferente de 0 para poder llevar a cabo la division\n");
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
                printf("ERROR, resultado fuera de rango ingrese un numero mas pequeño para allar su factorial\n");
            }
        break;
        case 9:
            printf("\nFin de la aplicacion.");
        break;
        }
    }
    return 0;
}

