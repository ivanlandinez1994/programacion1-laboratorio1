/* problemas:
1. cuando pido subindice me toma letras
2. cuando digo borrar borra el dato origen no donde se ordeno
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"
#define ARRAY_SIZE 5

int main()
{
    EPersonas personas[ARRAY_SIZE];
    int opcion;
    int i;
    for(i=0; i<ARRAY_SIZE; i++){
        personas[i].flagEstadoVacio=1;
    }
    while(opcion!=5)
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        fflush(stdin);
        scanf("%d", &opcion);
        while(opcion>5 || opcion<=0)
        {
            printf("ingrese una opcion valida\n1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por  nombre\n");
            printf("4- Imprimir grafico de edades\n");
            printf("5- Salir\n");
            fflush(stdin);
            scanf("%d", &opcion);
        }
        switch(opcion)
        {
            case 1:
                system("cls");
                cargarDatosPersonas(personas, ARRAY_SIZE);
                break;
            case 2:
                system("cls");
                borrarDatosPersonas(personas, ARRAY_SIZE);
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
