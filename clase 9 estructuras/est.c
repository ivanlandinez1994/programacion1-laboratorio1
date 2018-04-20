#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "est.h"
int cargarDatosProductos(EProducto* arrayProductos, int subIndice, int sizeArray)
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
        auxNombre[strlen(auxNombre)-1]=0;
        //validar
        printf("ingrese descripcion del producto\n");
        fflush(stdin);
        fgets(auxDescripcion, sizeof(auxDescripcion), stdin);
        auxDescripcion[strlen(auxDescripcion)-1]=0;
        //validar
        printf("ingrese el precio del producto\n");
        fflush(stdin);
        fgets(auxPrecio, sizeof(auxPrecio), stdin);
        auxPrecio[strlen(auxNombre)-1]=0;
        // validar;
        auxPrecioF=atof(auxPrecio);

        arrayProductos[subIndice].precio=auxPrecioF;

        strcpy(arrayProductos[subIndice].nombre, auxNombre);
        strcpy(arrayProductos[subIndice].descripcion, auxDescripcion);

        arrayProductos[subIndice].flagVacio=0;

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
        printf("Nombre: %s\nDesripcion: %s\nPrecio: %.2f\n", array[subIndice].nombre,
               array[subIndice].descripcion, array[subIndice].precio);
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



