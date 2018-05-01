/* problemas:
1. cuando pido subindice me toma letras
2. cuando digo borrar borra el dato origen no donde se ordeno
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajoPractico.h"
#include "utn.h"
#define ARRAY_SIZE 5

int main()
{
    EPersonas personas[ARRAY_SIZE];
    personas_init(personas, ARRAY_SIZE);
    int opcion;
    char auxPersona[50];
    getValidInt("\n1.Agregar persona\n2.Borrar persona\n3.Imprimir ordenado por nombre\n4.imprimir grafico edades\n5.salir","ingrese una opcion correcta",&opcion,1,5,3);
    do
    {
        switch(opcion)
        {
            case 1:
                system("cls");
                personas_alta(personas, ARRAY_SIZE);
                break;
            case 2:
                system("cls");
                getValidString("ingrese el nombre de la persona a borrar","nombre no encontrado","maximo 50",auxPersona,50,3);
                personas_baja(personas, ARRAY_SIZE,auxPersona);
                break;
            case 3:
                system("cls");
                sort_ordenarArrayNombreEdad(personas, ARRAY_SIZE, 0);
                sort_mostrarArrayOrdenadoNombreEdad(personas, ARRAY_SIZE);
                break;
            case 4:
                system("cls");
                break;
            case 5:
                printf("final de aplicacion");
                break;
        }
    }
    return 0;
}
