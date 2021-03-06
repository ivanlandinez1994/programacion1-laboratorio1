#include <stdio.h>
#include <stdlib.h>
int get_getInt(int* resultado, char* mensaje, char* mensajeError, int maximo, int minimo, int reintentos){

    int retorno=-1;
    long auxiliarLongNumeroIngresado;

    do{
        printf("%s\n", mensaje);
        scanf("%ld",&auxiliarLongNumeroIngresado);
        if(auxiliarLongNumeroIngresado>=minimo && auxiliarLongNumeroIngresado<=maximo){
            retorno=0;
            *resultado=(int)auxiliarLongNumeroIngresado;
            break;
        }
        printf("%s\n", mensajeError);
        printf("el numero ingresado es: %ld\n", auxiliarLongNumeroIngresado);
        printf("cantidad de intentos restanteses: %d\n", reintentos);
        reintentos--;
    }while(reintentos>=0);
    return retorno;
}

int get_getFloat(float *resultado, char* mensaje, char* mensajeError, float maximo, float minimo, int reintentos){
    int retorno=-1;
    float auxiliarNumeroIngresado;

    do{
        printf("%s",mensaje);
        scanf("%f",&auxiliarNumeroIngresado);
        if(auxiliarNumeroIngresado>minimo && auxiliarNumeroIngresado<maximo){
            retorno=0;
            *resultado=auxiliarNumeroIngresado;
            break;
        }
        printf("%s\n", mensajeError);
        printf("el numero ingresado es: %f\n", auxiliarNumeroIngresado);
        printf("cantidad de intentos restanteses: %d\n", reintentos);
        reintentos--;
    }while(reintentos>=0);
    return retorno;
}

int get_getChar(char *resultado, char* mensaje, char* mensajeError, char maximo, char minimo, int reintentos){
    int retorno=-1;
    char auxiliarCharIngresado;

    do{
        printf("%s",mensaje);
        scanf("%c",&auxiliarCharIngresado);
        if(auxiliarCharIngresado>=minimo && auxiliarCharIngresado<=maximo){
            retorno=0;
            *resultado=auxiliarCharIngresado;
            break;
        }
        printf("%s\n", mensajeError);
        printf("la letra ingresada es: %c\n", auxiliarCharIngresado);
        printf("cantidad de intentos restanteses: %d\n", reintentos);
        fflush(stdin);
        reintentos--;
    }while(reintentos>=0);
    return retorno;
}
