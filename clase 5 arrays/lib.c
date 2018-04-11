#include <stdio.h>
#include <stdlib.h>
/*
* /brief Recibe un primer numero y un segundo numero y los suma
* /param primer numero ingresado por el usuario
* /param segundo numero ingresado por el usuario
* /param puntero del resultado de la suma
* /return retorna un valor quee nos dira si la funcion no tuvo problema para ejecutarse o si se dio algun error
*/
int sumaNumeros (int numero1, int numero2, float* resultadoSuma){
    long resultado;
    int retorno=-1;
    resultado= (float)numero1 + numero2;
    if(resultado<=2147483647 && resultado>=-2147483647){
        *resultadoSuma=(float)resultado;
        retorno=0;
    }
    return retorno;
}
/*
* /brief Recibe un primer numero y un segundo numero y los resta
* /param primer numero ingresado por el usuario
* /param segundo numero ingresado por el usuario
* /param puntero del resultado de la resta
* /return retorna un valor quee nos dira si la funcion no tuvo problema para ejecutarse o si se dio algun error
*/
int restaNumeros(int numero1, int numero2, float* resultadoResta){
    long resultado;
    int retorno=-1;
    resultado=(float)numero1 - numero2;
    if(resultado<=2147483647 && resultado>=-2147483647){
        *resultadoResta=(float)resultado;
        retorno=0;
    }
    return retorno;
}
/*
* /brief Recibe un primer numero y un segundo numero y los divide
* /param primer numero ingresado por el usuario
* /param segundo numero ingresado por el usuario
* /param puntero del resultado de la division
* /return retorna un valor quee nos dira si la funcion no tuvo problema para ejecutarse o si se dio algun error
* /el retorno=-2 es cuando el segundo operando es 0 con este retorno puedo saber que el usuario ingreso un 0 para la division.
*/
int divisionNumeros(int numero1, int numero2, float* resultadoDivision){
    float resultado;
    int retorno=-1;
    resultado=(float)numero1 / numero2;
    if((numero2<0 || numero2>0) && resultado<=2147483647 && resultado>=-2147483647){
        *resultadoDivision=(float)resultado;
        retorno=0;
    }
    else if (numero2==0){
        retorno=-2;
    }
    return retorno;
}
/*
* /brief Recibe un primer numero y un segundo numero y los multiplica
* /param primer numero ingresado por el usuario
* /param segundo numero ingresado por el usuario
* /param puntero del resultado de la multiplica
* /return retorna un valor que nos dira si la funcion no tuvo problema para ejecutarse o si se dio algun error
*/
int multiplicacionNumeros(int numero1, int numero2, float*resultadoMultiplicacion){
    long resultado;
    int retorno=-1;
    resultado=(float)numero1 * numero2;
    if(resultado<=2147483647 && resultado>=-2147483647){
        *resultadoMultiplicacion=(float)resultado;
        retorno=0;
    }
    return retorno;
}
/*
* /brief Recibe un primer numero y haya su factorial
* /param primer numero ingresado por el usuario
* /param puntero del resultado del factorial
* /return retorna un valor que nos dira si la funcion no tuvo problema para ejecutarse o si se dio algun error
*/
int factorialNumero1(int numero1, float* resultadoFactorial){
    long resultado=numero1;
    int retorno=-1;
    while(numero1>1){
        numero1--;
        resultado=numero1*resultado;
    }
    if(resultado<=2147483647 && resultado>0){
        *resultadoFactorial=(float)resultado;
        retorno=0;
    }
    return retorno;
}

int getInt(int* resultado, char* mensaje, char* mensajeError, int maximo, int minimo, int reintentos){

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

int getFloat(float *resultado, char* mensaje, char* mensajeError, float maximo, float minimo, int reintentos){
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

int getChar(char *resultado, char* mensaje, char* mensajeError, char maximo, char minimo, int reintentos){
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
float getCalcularPromedio(int valores[], int cantidad, float *promedio){
    int auxiliarAcumulador=0;
    int i;
    int retorno=-1;

    if(cantidad>=0){
        for (i=0; i<cantidad; i++){
            auxiliarAcumulador=valores[i]+auxiliarAcumulador;
        }
        *promedio=((float)auxiliarAcumulador)/cantidad;
        return 0;
    }
    return retorno;
}
int getValorMaximo(int valores[], int cantidad, int* maximo){
    int retorno=-1;
    int i;
    int bandera=0;
    for(i=0; i<cantidad; i++){
        if(bandera==0 || *maximo<valores[i]){
            *maximo=valores[i];
            bandera=1;
            retorno=0;
        }

    }
    return retorno;
}
int getValorMinimo(int valores[], int cantidad, int* minimo){
    int retorno=-1;
    int i;
    int bandera=0;
    for (i=0; i<cantidad; i++){
        if(bandera==0 || *minimo>valores[i]){
            *minimo=valores[i];
            bandera=1;
            retorno=0;
        }
    }
    return retorno;
}
