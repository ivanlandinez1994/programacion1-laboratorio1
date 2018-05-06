#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"
#include "utn.h"

static int buscarLugarLibre(Usuario* array,int limite);
static int proximoId();
/** \brief array Usuario*
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
            printf("[DEBUG] - %d - %s - %d\n",array[i].idUsuario, array[i].usuario, array[i].isEmpty);
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
                printf("Nombre usuario: %s\nCalificacion promedio: %d\n",array[i].usuario, array[i].calificacionesAcum/array[i].cantidadVentas);
        }
    }
    return retorno;
}

int usuario_alta(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    char usuario[50];
    char password[20];

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un usuario","El maximo es 40",usuario,40,2))
            {
                if(!getValidAlfaNumerico("\nContraseña? ","\nEso no es una contraseña","El maximo es 20",password,20,2))
                {
                    retorno = 0;
                    strcpy(array[i].usuario,usuario);
                    strcpy(array[i].password,password);
                    array[i].idUsuario = proximoId();
                    array[i].isEmpty = 0;
                    printf("usuario dado de alta: \nUsuario: %s\nID Usuario: %d\n\n", array[i].usuario, array[i].idUsuario);
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

int usuario_baja(Usuario* array,int limite, int idUsuario)
{
    int retorno = -1;
    int indiceAEliminar;
    indiceAEliminar = usuario_buscarPorId(array, limite, idUsuario);
    if(indiceAEliminar>0)
    {
        retorno = 0;
        array[indiceAEliminar].isEmpty = 1;
        printf("usuario dado de baja\n");
    }
    return retorno;
}

/** \brief
 *
 * \param array Usuario*
 * \param limite int
 * \param id int
 * \return int
 *
 */
int usuario_modificacion(Usuario* array,int limite, int idUsuario)
{
    int retorno = -1;
    int indiceAModificar;
    char usuario[50];
    char password[20];
    indiceAModificar = usuario_buscarPorId(array, limite, idUsuario);
    if(indiceAModificar>0)
    {
        if(!getValidString("\nNuevo Usuario? ","\nEso no es un usuario","El maximo es 50",usuario,50,2))
        {
            if(!getValidAlfaNumerico("\nNueva contraseña? ","\nEso no es u ana contraseña","\nEl maximo es 20",password,20,2))
            {
                retorno = 0;
                strcpy(array[indiceAModificar].usuario,usuario);
                strcpy(array[indiceAModificar].password,password);
            }
        }
        else
        {
            retorno = -2;
        }
    }
    retorno = 0;
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
                    if((strcmp(array[i].usuario,array[i+1].usuario) > 0 && orden) || (strcmp(array[i].usuario,array[i+1].usuario) < 0 && !orden)) //******
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
int usuario_buscarPorId(Usuario* array, int limite, int id)
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
}

static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int usuario_altaForzada(Usuario* array,int limite,char* usuario, int idUsuario)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].usuario,usuario);
            array[i].idUsuario = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
