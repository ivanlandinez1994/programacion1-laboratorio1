#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "contratacion.h"
#include "utn.h"
#include "pantalla.h"

static int contratacion_buscarPorId(Contratacion* array, int limite, int id);
static int buscarLugarLibre(Contratacion* array,int limite);
static int contratacion_proximoId();
/** \brief
 * \param array Contratacion*
 * \param limite int
 * \return int
 *
 */
int contratacion_init(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int contratacion_mostrarDebug(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %s - %d - %d - %s - %d - %d \n", array[i].cuit, array[i].idPantalla, array[i].dias, array[i].archivo, array[i].idContratacion, array[i].isEmpty);
        }
    }
    return retorno;
}

int contratacion_mostrar(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %s - %d - %d - %s - %d - %d \n",array[i].cuit, array[i].idPantalla, array[i].dias, array[i].archivo, array[i].idContratacion, array[i].isEmpty);
        }
    }
    return retorno;
}

int contratacion_alta(Contratacion* arrayContratacion,int limite, Pantalla* arrayPantalla, int limitePantallas)
{
    int retorno = -1;
    int i;
    int auxiliarIdPantalla;
    int auxiliarIdDias;

    if(limite > 0 && arrayContratacion != NULL)
    {
        i = buscarLugarLibre(arrayContratacion,limite);
        if(i >= 0)
        {
           getValidInt("ID?","\nNumero invalido\n",&auxiliarIdPantalla,0,999999,2);
           auxiliarIdPantalla = pantalla_buscarPorId(arrayPantalla, limitePantallas, auxiliarIdPantalla);
           if(auxiliarIdPantalla>=0)
           {
                getValidInt("dias?","\nNumero invalido\n",&auxiliarIdDias,0,200,2);
                arrayContratacion[i].dias = auxiliarIdDias;
                arrayContratacion[i].idPantalla = auxiliarIdPantalla;
                arrayContratacion[i].isEmpty=0;
                arrayContratacion[i].idContratacion = contratacion_proximoId();

           }

        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int contratacion_baja(Contratacion* array,int limite, int id)
{
    int retorno = -1;
    int indiceAEliminar;

    indiceAEliminar=contratacion_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        retorno = 0;
        array[indiceAEliminar].isEmpty = 1;
    }

    return retorno;
}

/** \brief
 *
 * \param array Contratacion*
 * \param limite int
 * \param id int
 * \return int
 *
 */
int contratacion_modificacion(Contratacion* array,int limite, int id)
{
    int retorno = -1;
    char cuit[50];
    int indiceAModificar;
    indiceAModificar=contratacion_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nCuit? ","\nEso no es un cuit","El maximo es 40",cuit,40,2))
        {
            retorno = 0;
            strcpy(array[indiceAModificar].cuit,cuit);
            //------------------------------
            //------------------------------
        }
        else
        {
            retorno = -3;
        }
        retorno = 0;
    }
    return retorno;
}

/*int contratacion_ordenar(Contratacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Contratacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}*/

int buscarLugarLibre(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int contratacion_buscarPorId(Contratacion* array, int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int contratacion_proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
