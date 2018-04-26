#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#define SIZE 10

int main()
{
    Pantalla array[SIZE];

    int menu;
    int auxiliarId;

    pantalla_init(array,SIZE);
    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(array,SIZE);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(array,SIZE,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(array,SIZE,auxiliarId);
                break;
            case 4:
                pantalla_mostrar(array,SIZE);
                break;
            case 5:
                pantalla_ordenar(array,SIZE,1);
                break;
            case 6:
                pantalla_mostrarDebug(array,SIZE);
                break;
        }

    }while(menu != 9);

    return 0;
}
