#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantallas.h"
#include "publicidad.h"
#include "utn.h"
#define SIZEPANTALLA 5
#define SIZEPUBLICIDAD 10

int main()
{
    Pantalla arrayPantallas[SIZEPANTALLA];
    Publicidad arrayPublicidad[SIZEPUBLICIDAD];

    int menu;
    int auxiliarIdPantalla;
    float auxiliarCuitCliente;

    pantalla_init(arrayPantallas,SIZEPANTALLA);
    publicidad_init(arrayPublicidad,SIZEPUBLICIDAD);

    pantalla_altaForzada(arrayPantallas,SIZEPANTALLA,"Pedro",0, 2500);
    pantalla_altaForzada(arrayPantallas,SIZEPANTALLA,"Adrian",1, 500);
    pantalla_altaForzada(arrayPantallas,SIZEPANTALLA,"Walter",2, 100);
    pantalla_altaForzada(arrayPantallas,SIZEPANTALLA,"Liliana",3, 6500);

    publicidad_altaForzada(arrayPublicidad,SIZEPUBLICIDAD,arrayPantallas,SIZEPANTALLA,0,"video.avi",20911911915,100);
    publicidad_altaForzada(arrayPublicidad,SIZEPUBLICIDAD,arrayPantallas,SIZEPANTALLA,0,"video1.avi",20911911915,400);
    publicidad_altaForzada(arrayPublicidad,SIZEPUBLICIDAD,arrayPantallas,SIZEPANTALLA,0,"video2.avi",30911911915,300);
    publicidad_altaForzada(arrayPublicidad,SIZEPUBLICIDAD,arrayPantallas,SIZEPANTALLA,2,"video3.avi",30911911915,400);
    publicidad_altaForzada(arrayPublicidad,SIZEPUBLICIDAD,arrayPantallas,SIZEPANTALLA,2,"video4.avi",40911911915,500);
    publicidad_altaForzada(arrayPublicidad,SIZEPUBLICIDAD,arrayPantallas,SIZEPANTALLA,2,"video5.avi",40911911915,600);

    do
    {
        getValidInt("\n1.Alta pantalla\n2.Baja Pantalla y contrataciones de publicidad\n3.Modificar datos pantalla\n4.Contratar publicidad\n5.Modificar condiciones publicidad"
                    "\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                pantalla_alta(arrayPantallas,SIZEPANTALLA);
                pantalla_mostrarDebug(arrayPantallas,SIZEPANTALLA);
                break;
            case 2:
                getValidInt("ID pantalla?","\nNumero invalido\n",&auxiliarIdPantalla,1,9999999,2);
                if(!pantalla_baja(arrayPantallas,SIZEPANTALLA,auxiliarIdPantalla))
                {
                    printf("Baja pantalla exitosa ");
                    if(!publicidad_bajaPublicadesPantalla(arrayPublicidad, SIZEPUBLICIDAD, auxiliarIdPantalla))
                    {
                        printf("y baja contrataciones de pantalla fue exitosa\n");
                    }
                }
                break;
            case 3:
                getValidInt("ID pantalla?","\nNumero invalido\n",&auxiliarIdPantalla,1,9999999,2);
                pantalla_modificacion(arrayPantallas,SIZEPANTALLA,auxiliarIdPantalla);
                break;
            case 4:
                publicidad_alta(arrayPublicidad,SIZEPUBLICIDAD, arrayPantallas, SIZEPANTALLA);
                break;
            case 5:
                getValidFloat("Ingrese cuit cliente?","\nNumero invalido\n",&auxiliarCuitCliente,1,99999999999,2);
                if(!publicidad_mostrarPantallasContratadas(arrayPublicidad,SIZEPUBLICIDAD,auxiliarCuitCliente))
                {
                    getValidInt("ID pantalla?","\nNumero invalido\n",&auxiliarIdPantalla,0,99999999,2);
                    publicidad_modificacion(arrayPublicidad,SIZEPUBLICIDAD,auxiliarIdPantalla);
                }
                else
                    printf("el cuit ongresado no tiene contrato de pantallas");
                break;
            case 6:
                pantalla_mostrarDebug(arrayPantallas,SIZEPANTALLA);
                break;
        }

    }while(menu != 9);

    return 0;
}
