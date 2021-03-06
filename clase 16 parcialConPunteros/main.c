#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "publicacion.h"

void mostrar(Cliente* array[],int cantidad);
void cargar(Cliente* array[],int cantidad, int* cantidadActual);
void modificar(Cliente* array[],int cantidad);

int main()
{
    int cantidadActualArrayAlumnos = 0;
    int cantidadMaximaArrayAlumnos = 50;
    Cliente* arrayClientePunteros[cantidadMaximaArrayAlumnos];

    cargar(arrayClientePunteros, cantidadMaximaArrayAlumnos, &cantidadActualArrayAlumnos);
    //modificar(arrayClientePunteros, 50);
    mostrar(arrayClientePunteros,cantidadActualArrayAlumnos);

    return 0;
}

void cargar(Cliente** array,int cantidad,int* cantidadActual)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        *(array+i) = cliente_newP("IVAN","LANDINEZ",95468562, i);
    }
}

void mostrar(Cliente** array,int cantidad)
{
    int i;
    char apellidoCliente[50];
    float cuit;
    for(i=0; i<cantidad; i++)
    {
        cliente_getCuit(*(array+i),&cuit);
        cliente_getApellido(*(array+i),apellidoCliente);
        printf("\nApellido: %s - Cuit: %.0f",apellidoCliente,cuit);
    }
}

void modificar(Cliente* array[],int cantidad)
{
    int i;
    Cliente* auxCliente;
    for(i=5; i<10; i++)
    {
        auxCliente = arrayCliente_getById(array, cantidad, i);
        if(auxCliente!=NULL)
        {
            cliente_setCuit(auxCliente, 20954685625);
        }
    }
}
