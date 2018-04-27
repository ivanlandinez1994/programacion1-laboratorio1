#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "contratacion.h"
#define sizeArrayPantalla 100
#define sizeArrayContrataciones 1000




int main()
{
    Pantalla array[sizeArrayPantalla];
    Contratacion arrayContrataciones[sizeArrayContrataciones];
    int menu;
    int auxiliarId;

    pantalla_init(array,sizeArrayPantalla);
    contratacion_init(arrayContrataciones, sizeArrayContrataciones);

    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(array,sizeArrayPantalla);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_baja(array,sizeArrayPantalla,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                pantalla_modificacion(array,sizeArrayPantalla,auxiliarId);
                break;
            case 4:
                pantalla_mostrar(array,sizeArrayPantalla);
                break;
            case 5:
                pantalla_ordenar(array,sizeArrayPantalla,0);
                break;
            case 6:
                pantalla_mostrarDebug(array,sizeArrayPantalla);
                break;
        }

    }while(menu != 9);

    return 0;
}
