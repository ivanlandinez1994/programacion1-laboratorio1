#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "est.h"
int validarString(char auxString[]);
int validarFloat(char* array, float* resultado);

int cargarDatosProductos(EProducto* arrayProductos, int subIndice, int sizeArray, int ID)
{
    int retorno=-1;
    char auxNombre[50];
    char auxPrecio[8];
    float auxPrecioF;
    char auxDescripcion[200];

    if(subIndice<sizeArray && subIndice>=0)
    {
        retorno=0;
        printf("\ningrese el nombre del producto\n");
        fflush(stdin);
        fgets(auxNombre, sizeof(auxNombre), stdin);
        auxNombre[strlen(auxNombre)-1]=0;// se le quita el ultimo enter que se guarda en el array.
        if(validarString(auxNombre)==0) //se valida que haya ingresado los datos correctamente
        {
            printf("nombre cargado\n");
            strcpy(arrayProductos[subIndice].nombre, auxNombre);//se copia el auxiliar en la variable perteneciente habiendo validado todo
        }
        else
        {
            printf("el dato ingresado no es correcto, dato no cargado\n");
        }

        printf("ingrese descripcion del producto\n");
        fflush(stdin);
        fgets(auxDescripcion, sizeof(auxDescripcion), stdin);
        auxDescripcion[strlen(auxDescripcion)-1]=0;
        if(validarString(auxDescripcion)==0)
        {
            printf("descripcion cargada\n");
            strcpy(arrayProductos[subIndice].descripcion, auxDescripcion);
        }
        else
        {
            printf("el dato ingresado no es correcto, dato no cargado\n");
        }

        printf("ingrese el precio del producto\n");
        fflush(stdin);
        fgets(auxPrecio, sizeof(auxPrecio), stdin);
        auxPrecio[strlen(auxPrecio)-1]=0;
        if(validarFloat(auxPrecio, &auxPrecioF)==0)
        {
            printf("precio cargado\n");
            arrayProductos[subIndice].precio=auxPrecioF;
        }
        else
        {
            printf("el dato ingresado no es correcto, dato no cargado\n");
        }

        arrayProductos[subIndice].flagVacio=0;
        if(arrayProductos[subIndice].flagVacio==0)
        {
            arrayProductos[subIndice].ID=ID;
        }
    }
    else
    {
        printf("\nel subindice ingresado no es valido\n");
    }
    return retorno;
}
int mostrarDatosProductos(EProducto* array, int subIndice, int sizeArray)
{
    int retorno=-1;

    if(subIndice<sizeArray && subIndice>=0)
    {
        retorno=0;
        printf("Nombre: %s\nDesripcion: %s\nPrecio: %.2f\nID: %d\n", array[subIndice].nombre,
               array[subIndice].descripcion, array[subIndice].precio,array[subIndice].ID);
    }
    else
    {
        printf("\nel subindice ingresado no es valido\n");
    }
    return retorno;
}
int devolverIndiceVacion(EProducto* arrayProductos, int sizeArray)
{
    int retorno=-1;
    int i;
    int auxiliarIndiceVacio;
    for(i=0; i<sizeArray; i++){
        retorno=0;
        auxiliarIndiceVacio=i;
        if(arrayProductos[i].flagVacio==1){
            printf("el subindice en el array que esta vacio es: %d", auxiliarIndiceVacio);
            break;
        }
    }
    return retorno;
}
int validarString(char auxiliar[])
{
    int retorno=0;
    int i=0;
    while(i<strlen(auxiliar))
    {
        if((auxiliar[i] != ' ') && (auxiliar[i] < 'a' || auxiliar[i] > 'z') && (auxiliar[i] < 'A' || auxiliar[i] > 'Z'))
        {
            retorno=-1;
        }
        i++;
    }
    return retorno;
}
int validarFloat(char* array, float* resultado){
    int retorno=0;
    int i;
    for(i=0; i<strlen(array); i++){
        if(array[i]>'9' || array[i]<'0'){
            retorno=-1;
            break;
        }
    }
    if(retorno==0){
        *resultado=atof(array);
    }
    else{
        printf("no ingreso un numero");
    }
    return retorno;
}
