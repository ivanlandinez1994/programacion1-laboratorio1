/* problemas:
1. cuando pido subindice me toma letras
2. cuando digo borrar borra el dato origen no donde se ordeno
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "trabajoPractico.h"
#define ARRAY_SIZE 4

int main()
{
    EPersonas arrayPersonas[ARRAY_SIZE];
    personas_init(arrayPersonas, ARRAY_SIZE);
    int opcion;
    char auxNombreMain[50];
    int sentidoOrdenArray;
    do
    {
        getValidInt("\n1.Agregar persona\n2.Borrar persona\n3.Imprimir ordenado por nombre\n4.imprimir grafico edades\n5.salir\n","ingrese una opcion correcta",&opcion,1,5,3);
        switch(opcion)
        {
            case 1:
                system("cls");
                personas_alta(arrayPersonas, ARRAY_SIZE);
                break;
            case 2:
                system("cls");
                getValidString("\ningrese el nombre de la persona a borrar: ","\nnombre no encontrado","\nmaximo 50",auxNombreMain,50,3);
                personas_baja(arrayPersonas, ARRAY_SIZE, auxNombreMain);
                break;
            case 3:
                system("cls");
                getValidInt("\nOrdenar de la A a la Z PRESIONE(1) o de la Z a la A PRESIONE (0)","\nopcion no valida",&sentidoOrdenArray,0,1,3);
                personas_ordenar(arrayPersonas, ARRAY_SIZE, sentidoOrdenArray);
                personas_mostrar(arrayPersonas, ARRAY_SIZE);
                break;
            case 4:
                system("cls");
                personas_grafico(arrayPersonas,ARRAY_SIZE);
                break;
            case 5:
                printf("final de aplicacion");
                break;
        }
    }while(opcion!=5);
    return 0;
}
