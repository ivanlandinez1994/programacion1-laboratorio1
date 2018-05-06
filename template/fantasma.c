#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"

static int buscarPorId(Fantasma* array, int limite, int id);
static int buscarLugarLibre(Fantasma* array,int limite);
static int proximoId();
/** \brief array Fantasma*
 * \param limite int
 * \return int
 *
 */
int fantasma_init(Fantasma* array,int limite)
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

int fantasma_mostrarDebug(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",array[i].idFantasma, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int fantasma_mostrar(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",array[i].idFantasma, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int fantasma_alta(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    char buffer[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
            {
                retorno = 0;
                strcpy(array[i].nombre,buffer);
                array[i].idFantasma = proximoId();
                array[i].isEmpty = 0;
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int fantasma_baja(Fantasma* array,int limite, int id)
{
    int retorno = -1;
    int indiceAEliminar;
    indiceAEliminar = buscarPorId(array, limite, id);
    if(indiceAEliminar>0)
    {
        retorno = 0;
        array[indiceAEliminar].isEmpty = 1;
    }
    return retorno;
}

/** \brief
 *
 * \param array Fantasma*
 * \param limite int
 * \param id int
 * \return int
 *
 */
int fantasma_modificacion(Fantasma* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char buffer[50];
    indiceAModificar = buscarPorId(array, limite, id);
    if(indiceAModificar>0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
        {
            retorno = 0;
            strcpy(array[indiceAModificar].nombre,buffer);
        }
        else
        {
            retorno = -2;
        }
    }
    retorno = 0;
    return retorno;
}

int fantasma_ordenarChar(Fantasma* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Fantasma auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
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
}

int fantasma_ordenarNumericamente(Fantasma* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    char AuxiliarNombre[50];
    if(limite > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if((array[i].idFantasma < array[i+1].idFantasma && orden)||(array[i].idFantasma > array[i+1].idFantasma && !orden))
                {
                    strcpy(AuxiliarNombre,array[i+1].nombre);
                    strcpy(array[i+1].nombre,array [i].nombre);
                    strcpy(array[i].nombre,AuxiliarNombre);
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int buscarLugarLibre(Fantasma* array,int limite)
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
static int buscarPorId(Fantasma* array, int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idFantasma==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int fantasma_altaForzada(Fantasma* array,int limite,char* nombre, int id)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            array[i].idFantasma = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
