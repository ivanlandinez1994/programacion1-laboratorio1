#include <stdio.h>
#include <stdlib.h>

long suma(int primerNumero, int segundoNumero);
long resta(int primerNumero, int segundoNumero);
float dividir(int primerNumero, int segundoNumero);
long multiplicar(int primerNumero, int segundoNumero);

int main(){
    int numero1;
    int numero2;
    float resultado;
    char operacionARealizar;
    char seguirOperacion='n';

    do{
        printf("ingrese el primer numero\n");
        scanf("%d",&numero1);
        printf("ingrese el segundo numero\n");
        scanf("%d",&numero2);
        printf("ingrese la operacion a realizar: s para sumar, r para restar, m para multiplicar y d para dividir\n");
        fflush(stdin);
        scanf("%c",&operacionARealizar);

        while(operacionARealizar!='s' && operacionARealizar!='r' && operacionARealizar!='d' && operacionARealizar!='m'){
            printf("ingrese una operacion correcta\n");
            printf("ingrese la operacion a realizar: s para sumar, r para restar, m para multiplicar y d para dividir\n");
            fflush(stdin);
            scanf("%c",&operacionARealizar);
        }

        switch(operacionARealizar){
            case 's':
                resultado=suma(numero1, numero2);
                printf("el resultado de la suma es: %.0f\n",resultado);
            break;
            case 'r':
                resultado=resta(numero1, numero2);
                printf("el resultado de la suma es: %.0f\n",resultado);
            break;
            case 'm':
                resultado=multiplicar(numero1, numero2);
                printf("el resultado de la suma es: %.0f\n",resultado);
            break;
            case 'd':
                resultado=dividir(numero1, numero2);
                printf("el resultado de la suma es: %.2f\n",resultado);
            break;
            default:
                printf("ingrese una operacion valida");
            break;
        }
        printf("desea seguir operando? para continuar presione s y para detener n\n");
        fflush(stdin);
        scanf("%c",&seguirOperacion);
    }while(seguirOperacion=='s');

    return 0;
}

long suma(int primerNumero, int segundoNumero){// el primer tipo de variable=long lo que devuelve la variable, lo segundo el nombre de la funcion y tercero lo que recibe
    long resultado;
    resultado=primerNumero+segundoNumero;
    return resultado;
}

long resta(int primerNumero, int segundoNumero){
    long resultado;
    resultado=primerNumero-segundoNumero;
    return resultado;
}

float dividir(int primeroNumero, int segundoNumero){
    float resultado;
    resultado=(float)primeroNumero/segundoNumero;
    return resultado;
}

long multiplicar(int primerNumero, int segundoNumero){
    long resultado;
    resultado=primerNumero*segundoNumero;
    return resultado;
}
