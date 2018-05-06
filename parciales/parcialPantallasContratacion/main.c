#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "contratacion.h"
#include "informes.h"
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

    pantalla_altaForzada(array,sizeArrayPantalla,"Wilde","Las Flores 50",50,0);
    pantalla_altaForzada(array,sizeArrayPantalla,"Avellaneda","Belgrano 250",2000,0);
    pantalla_altaForzada(array,sizeArrayPantalla,"Bernal","Cerrito 300",3000,0);
    pantalla_altaForzada(array,sizeArrayPantalla,"Quilmes","Lavalle 450",1000,1);
    pantalla_altaForzada(array,sizeArrayPantalla,"Berazategui","Mitre 150",5000,1);

    cont_altaForzada(arrayContrataciones,sizeArrayContrataciones,array,sizeArrayPantalla,0,"video.avi",20911911915,100);
    cont_altaForzada(arrayContrataciones,sizeArrayContrataciones,array,sizeArrayPantalla,0,"video1.avi",20911911915,400);
    cont_altaForzada(arrayContrataciones,sizeArrayContrataciones,array,sizeArrayPantalla,0,"video2.avi",30911911915,300);
    cont_altaForzada(arrayContrataciones,sizeArrayContrataciones,array,sizeArrayPantalla,2,"video3.avi",30911911915,400);
    cont_altaForzada(arrayContrataciones,sizeArrayContrataciones,array,sizeArrayPantalla,2,"video4.avi",40911911915,500);
    cont_altaForzada(arrayContrataciones,sizeArrayContrataciones,array,sizeArrayPantalla,2,"video5.avi",40911911915,600);

    informar_ConsultaFacturacion(arrayContrataciones,sizeArrayContrataciones,array,sizeArrayPantalla,20911911915);
    informar_ListarContrataciones(arrayContrataciones,sizeArrayContrataciones,array,sizeArrayPantalla);

    do
    {
        getValidInt("1.Alta Pantallas\n2.Baja Pantallas \n3.Modificar Pantallas \n4.Mostrar Pantallas\n5.Ordenar Pantallas\n6.Mostrar Debug\n7.Contratar Publicidad"
                "\n8.Baja publicidad\n9.Modificar Publicidad\n10.Mostrar Contrataciones\n11.mostrar debug contrataciones\n12.Salir\n","\nNo valida\n",&menu,1,12,1);
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
