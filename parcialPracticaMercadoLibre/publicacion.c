#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"
#include "usuario.h"

//static int buscarPorId(Publicacion* array, int limite, int id);
static int buscarLugarLibre(Publicacion* array,int limite);
static int proximoId();
/** \brief
 * \param array Publicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_init(Publicacion* array,int limite)
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

int publicacion_mostrarDebug(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %d - %d\n",array[i].idPublicacion, array[i].idUsuario, array[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_mostrar(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %d - %d\n",array[i].idPublicacion, array[i].idUsuario, array[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_alta(Publicacion* array,int limite, int idUsuario)
{
    int retorno = -1;
    int i;
    char nombre[50];
    float precioProducto;
    int stockProducto;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre producto? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidFloat("\nprecio? ","\nEso no es un precio", &precioProducto,1,999999999999,2))
                {
                    if(!getValidInt("\nstock? ","\nVerifique el stock", &stockProducto,1,99999999,2))
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        array[i].precio=precioProducto;
                        array[i].idPublicacion = proximoId();
                        array[i].stock=stockProducto;
                        array[i].isEmpty = 0;
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

int publicacion_baja(Publicacion* array,int limite, int idPublicacion)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==idPublicacion)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_bajaPublicacionesUsuario(Publicacion* arrayPublicaciones,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPublicaciones != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].idUsuario==id)
            {
                arrayPublicaciones[i].isEmpty=1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_modificacion(Publicacion* array,int limite, int idPublicacion)
{

    int retorno = -1;
    int i;
    float precio;
    int stock;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==idPublicacion)
            {
                if(!getValidFloat("\nPrecio? ","\nEso no es un precio", &precio, 1, 9999999999, 2))
                {
                    if(!getValidInt("\nStock ","\nEso no es un precio", &stock, 1, 99999999, 2))
                    {
                        array[i].precio = precio;
                        array[i].stock = stock;
                        retorno = 0;
                    }
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
int publicacion_mostrarProductosDeUsuario(Publicacion* array, int limite, int idUsuario)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==idUsuario)
            {
                retorno=0;
                printf("id: %d - Nombre: %s - Precio: %f - Cantidad vendida: %d - Stock: %d\n",
                   array[i].idPublicacion, array[i].nombre, array[i].precio, array[i].cantidadUnidadesVendidas, array[i].stock);
            }
        }
    }
    return retorno;
}

int publicacion_ordenar(Publicacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

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

int buscarLugarLibre(Publicacion* array,int limite)
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
/*static int buscarPorId(Publicacion* array, int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==id)
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

int publicacion_altaForzada(Publicacion* array,int limite,char* nombre, int id, float precio)
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
            array[i].precio = precio;
            array[i].idPublicacion = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

/*int publicacion_comprarProductos(Publicacion* array, int limite, int idPublicacion)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        if(array[i].stock>0)
        {
            for(i=0;i<limite;i++)
            {

            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}*/
