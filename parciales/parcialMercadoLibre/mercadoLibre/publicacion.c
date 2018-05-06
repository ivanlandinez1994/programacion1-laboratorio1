#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"


static int buscarLugarLibre(Publicacion* array,int limite);
static int proximoId();
/** \brief array Publicacion*
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
            printf("[DEBUG] - %d - %s - %d\n",array[i].idPublicacion, array[i].nombreProducto, array[i].isEmpty);
    }
    return retorno;
}

int publicacion_mostrarPublicaciones(Publicacion* array,int limite, Usuario* arrayUsuario, int limiteUsuario)
{
    int retorno = -1;
    int i;
    int indiceMostrar;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                {
                    indiceMostrar = usuario_buscarPorId(arrayUsuario, limiteUsuario, array[i].idUsuario);
                    printf("\nid publicacion: %d\nNombre producto: %s\nPrecio: %f\nStock: %d\nCantidad vendida: %d\nNombre Usuario: %s\n",
                       array[i].idPublicacion, array[i].nombreProducto, array[i].precio, array[i].stock, array[i].cantidadVendida, arrayUsuario[indiceMostrar].usuario);
                }
        }
    }
    return retorno;
}

int publicacion_alta(Publicacion* array,int limite, int idUsuario)
{
    int retorno = -1;
    int i;
    char nombreProducto[50];
    float precio;
    int stock;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre producto? ","\nEso no es un nombre","El maximo es 40",nombreProducto,40,2))
            {
                if(!getValidFloat("\nPrecio? ","\nEso no es un precio", &precio, 1, 9999999999, 2))
                {
                    if(!getValidInt("\nStock? ","\nEso no es un stock",&stock,1,999999,2))
                    {
                        retorno = 0;
                        strcpy(array[i].nombreProducto,nombreProducto);
                        array[i].precio = precio;
                        array[i].stock = stock;
                        array[i].idPublicacion = proximoId();
                        array[i].isEmpty = 0;
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

int publicacion_bajaUsuarioYProductos(Publicacion* array,int limite, int idUsuario)
{
    int retorno = -1;
    int i;
    for(i=0; i<limite; i++)
    {
        if(!array[i].isEmpty && array[i].idUsuario==idUsuario)
            {
                retorno = 0;
                array[i].isEmpty = 1;
                printf("producto %d dado de baja\n", i+1);
            }
    }
    return retorno;
}

int publicacion_baja(Publicacion* array,int limite, int idPublicacion)
{
    int retorno = -1;
    int indiceAEliminar;
    indiceAEliminar = publicacion_buscarPorId(array, limite, idPublicacion);
    if(indiceAEliminar>0)
    {
        retorno = 0;
        array[indiceAEliminar].isEmpty = 1;
    }
    return retorno;
}

int publicacion_mostrarProductosUsuario(Publicacion* array,int limite, int idUsuario)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==idUsuario)
            {
                printf("\nid publicacion: %d\nNombre producto: %s\nPrecio: %f\nStock: %d\nCantidad vendida: %d\nStock: %d\n"
                        ,array[i].idPublicacion, array[i].nombreProducto, array[i].precio, array[i].stock, array[i].cantidadVendida, array[i].stock);
            }
        }
    }
    return retorno;
}

int publicacion_modificacion(Publicacion* array,int limite, int idPublicacion)
{
    int retorno = -1;
    int indiceAModificar;
    float precio;
    int stock;
    indiceAModificar = publicacion_buscarPorId(array, limite, idPublicacion);
    if(indiceAModificar>0)
    {
        if(!getValidFloat("\nNuevo precio? ","\nEso no es un precio",&precio,1,99999999,2))
        {
            if(!getValidInt("\nNuevo precio? ","\nEso no es un precio",&stock,1,99999999,2))
                retorno = 0;
                array[indiceAModificar].precio = precio;
                array[indiceAModificar].stock = stock;

        }
        else
        {
            retorno = -2;
        }
    }
    retorno = 0;
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
                    if((strcmp(array[i].nombreProducto,array[i+1].nombreProducto) > 0 && orden) || (strcmp(array[i].nombreProducto,array[i+1].nombreProducto) < 0 && !orden)) //******
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

int publicacion_buscarPorId(Publicacion* array, int limite, int id)
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
}

static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int publicacion_altaForzada(int idUsuario, Publicacion* array,int limite,char* nombrePublicacion, float precio, int stock, int cantVend)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombreProducto,nombrePublicacion);
            array[i].precio = precio;
            array[i].stock = stock;
            array[i].cantidadVendida = cantVend;
            array[i].idUsuario = idUsuario;
            array[i].idPublicacion = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

static int buscarLugarLibre(Publicacion* array,int limite)
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

int publicacion_comprar(Publicacion* publicaciones, Usuario* usuarios, int limite_pub, int limite_user, int idPublicacion)
{
    int retorno=-1;
    int indiceAComprar, indiceUsuario;
    int calificacion;
    indiceAComprar = publicacion_buscarPorId(publicaciones, limite_pub, idPublicacion);
    if(indiceAComprar>=0)
    {
        if(publicaciones[indiceAComprar].stock>0)
        {
            if(!getValidInt("\nCalificacion", "No es una calificacion", &calificacion, 0, 10,1))
            {
                publicaciones[indiceAComprar].stock--;
                publicaciones[indiceAComprar].cantidadVendida++;
                indiceUsuario = usuario_buscarPorId(usuarios, limite_user, publicaciones[indiceAComprar].idUsuario);
                usuarios[indiceUsuario].calificacionesAcum+=calificacion;
                usuarios[indiceUsuario].cantidadVentas++;
                retorno =0;
            }
        }
    }
    return retorno;
}
