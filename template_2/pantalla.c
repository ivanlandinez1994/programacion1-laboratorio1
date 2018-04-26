#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

/** \brief
 * \param array Pantalla*
 * \param limite int
 * \return int
 *
 */
int pantalla_init(Pantalla* array,int limite)
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

int pantalla_mostrarDebug(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %d - %d\n",array[i].idPantalla, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int pantalla_mostrar(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",array[i].idPantalla, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    char auxNombre[50];
    char auxDireccion[50];
    float auxPrecio;
    int auxTipo;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",auxNombre,40,2))
            {
                if(!getValidString("\nDireccion? ","\nEso no es una direccion","El maximo es 40",auxDireccion,40,2))
                {
                    if(!getValidFloat("\nPrecio? ","\nEso no es un precio",&auxPrecio,0,9999999,3))
                    {
                        if(!getValidInt("\nTipo? ","\nEso no es un precio",&auxTipo,0,1,2))
                        {
                            retorno = 0;
                            strcpy(array[i].direccion,auxNombre);
                            strcpy(array[i].direccion,auxDireccion);
                            array[i].precio = auxPrecio;
                            array[i].tipo= auxTipo;
                            //------------------------------
                            //------------------------------
                            array[i].idPantalla = proximoId();
                            array[i].isEmpty = 0;
                        }
                    }
                }
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


int pantalla_baja(Pantalla* array,int limite, int id)
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
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief
 *
 * \param array Pantalla*
 * \param limite int
 * \param id int
 * \return int
 *
 */
int pantalla_modificacion(Pantalla* array,int limite, int id)
{
    int retorno = -1;
    int i;
    char buffer[50];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==id)
            {
                if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
                {
                    retorno = 0;
                    strcpy(array[i].nombre,buffer);
                    //------------------------------
                    //------------------------------
                }
                else
                {
                    retorno = -3;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_ordenar(Pantalla* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

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

int buscarLugarLibre(Pantalla* array,int limite)
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


int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
