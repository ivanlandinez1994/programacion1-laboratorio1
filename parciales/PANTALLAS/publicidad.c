#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantallas.h"
#include "publicidad.h"
#include "utn.h"

static int buscarPorId(Publicidad* array, int limite, int id);
static int buscarLugarLibre(Publicidad* array,int limite);
static int proximoId();
/** \brief array Publicidad*
 * \param limite int
 * \return int
 *
 */
int publicidad_init(Publicidad* array,int limite)
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

int publicidad_mostrarPantallasContratadas(Publicidad* array,int limite, float cuitCliente)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(cuitCliente == array[i].cuitCliente)
            {
                retorno = 0;
                printf("id pantalla: %d\nDias a contratar pantalla: %d\n",array[i].idPantalla, array[i].cantidadDiasContratar);
            }
        }
    }
    return retorno;
}

int publicidad_mostrar(Publicidad* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",array[i].idPublicidad, array[i].nombreArchivo, array[i].isEmpty);
        }
    }
    return retorno;
}

int publicidad_alta(Publicidad* array,int limite, Pantalla* arrayPantalla, int limitePantalla)
{
    int retorno = -1;
    int i;
    float cuitCliente;
    int cantidadDiasContratar;
    char nombreArchivo[50];
    int idPantalla;
    int indiceAGuardar;
    for(i=0;i<limitePantalla;i++)
    {
        if(!arrayPantalla[i].isEmpty)
        {
            if(array[i].isEmpty)
            {
                printf("Pantallas disponibles:\nNombre pantalla: %s\nId pantalla: %d\n",arrayPantalla[i].nombrePantalla, arrayPantalla[i].idPantalla);
                if(arrayPantalla[i].tipo==2)
                    printf("Tipo pantalla: LCD\n");
                if(arrayPantalla[i].tipo==1)
                    printf("Tipo pantalla: Led\n");
            }
        }
    }
    if((limite > 0 && array != NULL) && (limitePantalla > 0 && arrayPantalla != NULL))
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0 )
        {
            if(!getValidInt("Id pantalla a contratar\n","id invalido\n",&indiceAGuardar,0,99999999,3))
            {
                if(indiceAGuardar>=0)
                {
                    idPantalla = buscarPorId(array, limite, indiceAGuardar);
                    if(idPantalla>=0)
                    {
                        if(!getValidFloat("\nCuit cliente? ","\nEso no es un cuit", &cuitCliente,1111111, 99999999999,3))
                        {
                            if(!getValidInt("\nCantidad de dias a contratar? ","\nreIngrese la cantidad de dias", &cantidadDiasContratar,1,365,3))
                            {
                                if(!getValidString("\nNombre archivo (ej. Video1.avi)? ","\nreso no es un nombre","maximo de 40",nombreArchivo,40,3))
                                {
                                    retorno = 0;
                                    array[i].cuitCliente = cuitCliente;
                                    array[i].cantidadDiasContratar = cantidadDiasContratar;
                                    strcpy(array[i].nombreArchivo,nombreArchivo);
                                    array[i].idPantalla = arrayPantalla[i].idPantalla;
                                    array[i].idPublicidad = proximoId();
                                    array[i].isEmpty = 0;
                                }
                            }
                        }
                        else
                        {
                            retorno = -3;
                        }
                    }
                }
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}

int publicidad_baja(Publicidad* array,int limite, int id)
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

int publicidad_bajaPublicadesPantalla(Publicidad* array,int limitePublicidad, int idPantalla)
{
    int retorno = -1;
    int indiceAEliminar;
    indiceAEliminar = buscarPorId(array, limitePublicidad, idPantalla);
    if(indiceAEliminar>0)
    {
        retorno = 0;
        array[indiceAEliminar].isEmpty = 1;
    }
    return retorno;
}

/** \brief
 *
 * \param array Publicidad*
 * \param limite int
 * \param id int
 * \return int
 *
 */
int publicidad_modificacion(Publicidad* array,int limite, int idPantalla)
{
    int retorno = -1;
    int indiceAModificar;
    int dias;
    indiceAModificar = buscarPorId(array, limite, idPantalla);
    if(indiceAModificar>0)
    {
        if(idPantalla == array[indiceAModificar].idPantalla)
        {
            if(!getValidInt("\nCantidad de dias a contratar? ","\nre ingrese los dias",&dias,1,1000,3))
            {
                retorno = 0;
                array[indiceAModificar].cantidadDiasContratar = dias;
            }
            else
            {
                retorno = -2;
            }
        }
    }
    retorno = 0;
    return retorno;
}

int publicidad_ordenarChar(Publicidad* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicidad auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombreArchivo,array[i+1].nombreArchivo) > 0 && orden) || (strcmp(array[i].nombreArchivo,array[i+1].nombreArchivo) < 0 && !orden)) //******
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

int publicidad_ordenarNumericamente(Publicidad* array,int limite, int orden)
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
                if((array[i].idPublicidad < array[i+1].idPublicidad && orden)||(array[i].idPublicidad > array[i+1].idPublicidad && !orden))
                {
                    strcpy(AuxiliarNombre,array[i+1].nombreArchivo);
                    strcpy(array[i+1].nombreArchivo,array [i].nombreArchivo);
                    strcpy(array[i].nombreArchivo,AuxiliarNombre);
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int buscarLugarLibre(Publicidad* array,int limite)
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
static int buscarPorId(Publicidad* array, int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicidad==id)
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

int publicidad_altaForzada(Publicidad* arrayC,int limite,
                     Pantalla* pantallas, int lenPantallas,int idPantalla,char* archivo,float cuit,int dias)
{
    int retorno = -1;
    int i;

    if((limite > 0 && arrayC != NULL) && (lenPantallas > 0 && pantallas != NULL))
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayC[i].nombreArchivo,archivo);
            arrayC[i].idPantalla = idPantalla;
            arrayC[i].cuitCliente = cuit;
            arrayC[i].cantidadDiasContratar = dias;
            arrayC[i].idPublicidad = proximoId();
            arrayC[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
