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
        getValidInt("1.Alta Pantallas\n2.Baja Pantallas \n3.Modificar Pantallas \n4.Mostrar Pantallas\n5.Ordenar Pantallas\n6.Mostrar Debug\n7.Contratar Publicidad"
                "\n8.Baja publicidad\n9.Modificar Publicidad\n10.Mostrar Contrataciones\n11.mostrar debug contrataciones\n12.Salir\n","\nNo valida\n",&menu,1,11,1);
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
            case 7:
                contratacion_alta(arrayContrataciones,sizeArrayContrataciones,array, sizeArrayPantalla);
                break;
            case 8:
                contratacion_baja(arrayContrataciones,sizeArrayContrataciones);
                break;
            case 9:
                contratacion_modificacion(arrayContrataciones, sizeArrayContrataciones);
                break;
            case 10:
                contratacion_mostrar(arrayContrataciones, sizeArrayContrataciones, array,sizeArrayPantalla);
                break;
            case 11:
                contratacion_mostrarDebug(arrayContrataciones, sizeArrayContrataciones);
                break;
        }

    }while(menu != 12);

    return 0;
}
