#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"
#include "utn.h"
#include "publicacion.h"

//static int buscarPorId(Usuario* array, int limite, int id);
static int buscarLugarLibre(Usuario* array,int limite);
static int proximoId();
/** \brief
 * \param array Usuario*
 * \param limite int
 * \return int
 *
 */
int usuario_init(Usuario* array,int limite)
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

int usuario_mostrarDebug(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",array[i].idUsuario, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int usuario_mostrar(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("\nNombre: %s- ID: %d\n",array[i].nombre, array[i].idUsuario);
        }
    }
    return retorno;
}

int usuario_alta(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char password[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 10",nombre,10,2))
            {
                if(!getValidAlfaNumerico("\npassword? ","\nEso no es un password\n","El maximo es 10",password,10,2))
                {
                    retorno = 0;
                    strcpy(array[i].nombre,nombre);
                    strcpy(array[i].password,password);
                    array[i].idUsuario = proximoId();
                    array[i].isEmpty = 0;
                    printf("\nEL usuario se ha dado de alta");
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

int usuario_bajaUsuario(Usuario* array,int limite, int idUsuario)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==idUsuario)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int usuario_modificacion(Usuario* array,int limite, int idUsuario)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char password[50];

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==idUsuario)
            {
                if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 10",nombre,10,2))
                {
                    retorno = 0;
                    strcpy(array[i].nombre,nombre);
                    strcpy(array[i].password,password);
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

int usuario_ordenar(Usuario* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Usuario auxiliarEstructura;

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

int buscarLugarLibre(Usuario* array,int limite)
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
/*static int buscarPorId(Usuario* array, int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}*/
int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int usuario_altaForzada(Usuario* array,int limite,char* nombre,char* password)
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
            strcpy(array[i].password,password);
            array[i].calificacionAcum = 0;
            array[i].cantidadVentas = 0;
            //------------------------------
            //------------------------------
            array[i].idUsuario = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
