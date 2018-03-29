#include <stdio.h>
#include <stdlib.h>

long suma(int primerNumero, int segundoNumero, float* resultadoSuma);
long resta(int primerNumero, int segundoNumero, float *resultadoResta);
float dividir(int primeroNumero, int segundoNumero, float* resultadoDivision);
long multiplicar(int primerNumero, int segundoNumero, float* resultadoMultiplicacion);

int main(){
    int numero1;
    int numero2;
    float resultadoMain;
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
                if(suma(numero1, numero2, &resultadoMain)==0){
                    printf("el resultado de la suma es: %.0f\n",resultadoMain);
                }
                else {
                    printf("ERROR\n");
                }
            break;
            case 'r':
                if(resta(numero1, numero2, &resultadoMain)==0){
                    printf("el resultado de la suma es: %.0f\n",resultadoMain);
                }
                else {
                    printf("ERROR\n");
                }
            break;
            case 'm':
                if(multiplicar(numero1,numero2, &resultadoMain)==0){
                    printf("el resultado de la suma es: %.0f\n",resultadoMain);
                }
                else {
                    printf("ERROR\n");
                }

            break;
            case 'd':
                if(dividir(numero1, numero2, &resultadoMain)==0){
                    printf("el resultado de la suma es: %.2f\n",resultadoMain);
                }
                else{
                    printf("ERROR\n");
                }
            break;
            default:
                printf("ingrese una operacion valida");
            break;
        }
        printf("desea seguir operando? para continuar presione s y para detener n\n");
        fflush(stdin);
        scanf("%c",&seguirOperacion);
        system("cls");
    }while(seguirOperacion=='s');

    return 0;
}

long suma(int primerNumero, int segundoNumero, float* resultadoSuma){// el primer tipo de variable=long lo que devuelve la variable, lo segundo el nombre de la funcion y tercero lo que recibe
    float resultado;
    int retorno=-1;

    resultado=primerNumero+segundoNumero;
    if(resultado<32767){
        *resultadoSuma=resultado;
        retorno=0;
    }
    return retorno;
}

long resta(int primerNumero, int segundoNumero, float* resultadoResta){
    float resultado;
    int retorno=-1;

    resultado=primerNumero-segundoNumero;
    if(resultado<32767){
        *resultadoResta=resultado;
        retorno=0;
    }
    return retorno;
}

float dividir(int primeroNumero, int segundoNumero, float* resultadoDivision){
    float resultado;
    int retorno=-1;
    resultado=(float)primeroNumero/segundoNumero;
    if(segundoNumero>0 && resultado<32767){
        *resultadoDivision=resultado;
        retorno=0;
    }
    return retorno;
}

long multiplicar(int primerNumero, int segundoNumero, float* resultadoMultiplicacion){
    float resultado;
    int retorno=-1;
    resultado=primerNumero*segundoNumero;
    if(resultado<32767){
        *resultadoMultiplicacion=resultado;
        retorno=0;
    }
    return retorno;
}
