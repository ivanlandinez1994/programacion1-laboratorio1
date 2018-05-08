#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantallas.h"
#include "utn.h"

static int buscarPorId(Pantalla* array, int limite, int idPantalla);
static int buscarLugarLibre(Pantalla* array,int limite);
static int proximoId();
/** \brief array Pantalla*
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
            printf("\nNombre pantalla: %s\nID pantalla: %d\n",array[i].nombrePantalla, array[i].idPantalla);
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
                printf("Nombre pantalla: %s\nDireccion: %s\nPrecio %f\nId Pantalla: %d\n",
                       array[i].nombrePantalla, array[i].direccion, array[i].precio, array[i].idPantalla);
            if(array[i].tipo==2)
                printf("Pantalla LCD\n\n");
            if(array[i].tipo==1)
                printf("pantalla Led\n\n");
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre pantalla? ","\nEso no es un nombre","El maximo es 40",nombre,40,3))
            {
                if(!getValidString("Direccion? ","\nEso no es una direccion","El maximo es 40",direccion,40,3))
                {
                    if(!getValidFloat("Precio? ","\nEso no es un precio",&precio,1,999999999,3))
                    {
                        if(!getValidInt("Tipo de pantalla (1) para Led (2) para LCD? \n","\nEso no es un tipo",&tipo,1,2,3))
                        {
                            retorno = 0;
                            strcpy(array[i].nombrePantalla,nombre);
                            strcpy(array[i].direccion,direccion);
                            array[i].precio = precio;
                            array[i].tipo = tipo;
                            array[i].idPantalla = proximoId();
                            array[i].isEmpty = 0;
                            printf("Alta de pantalla exitosa\n");
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

int pantalla_baja(Pantalla* array,int limite, int idPantalla)
{
    int retorno = -1;
    int indiceAEliminar;
    indiceAEliminar = buscarPorId(array, limite, idPantalla);
    if(indiceAEliminar>0)
    {
        retorno = 0;
        array[indiceAEliminar].isEmpty = 1;
    }
    return retorno;
}

/** \brief
 *
 * \param array Pantalla*
 * \param limite int
 * \param idPantalla int
 * \return int
 *
 */
int pantalla_modificacion(Pantalla* array,int limite, int idPantalla)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
    indiceAModificar = buscarPorId(array, limite, idPantalla);
    if(indiceAModificar>0)
    {
        if(!getValidString("\nNombre nuevo de pantalla? ","\nEso no es un nombre","El maximo es 40",nombre,40,3))
        {
            if(!getValidString("Direccion nueva? ","\nEso no es una direccion","El maximo es 40",direccion,40,3))
            {
                if(!getValidFloat("Precio? ","\nEso no es un precio",&precio,1,999999999,3))
                {
                    if(!getValidInt("Tipo de pantalla (1) para Led (2) para LCD? \n","\nEso no es un tipo",&tipo,1,2,3))
                    {
                        retorno = 0;
                        strcpy(array[indiceAModificar].nombrePantalla,nombre);
                        strcpy(array[indiceAModificar].direccion,direccion);
                        array[indiceAModificar].precio = precio;
                        array[indiceAModificar].tipo = tipo;
                        array[indiceAModificar].idPantalla = proximoId();
                        array[indiceAModificar].isEmpty = 0;
                        printf("Modificacion de pantalla exitosa\n");
                    }
                }
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

int pantalla_ordenarChar(Pantalla* array,int limite, int orden)
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
                    if((strcmp(array[i].nombrePantalla,array[i+1].nombrePantalla) > 0 && orden) || (strcmp(array[i].nombrePantalla,array[i+1].nombrePantalla) < 0 && !orden)) //******
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

int pantalla_ordenarNumericamente(Pantalla* array,int limite, int orden)
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
                if((array[i].idPantalla < array[i+1].idPantalla && orden)||(array[i].idPantalla > array[i+1].idPantalla && !orden))
                {
                    strcpy(AuxiliarNombre,array[i+1].nombrePantalla);
                    strcpy(array[i+1].nombrePantalla,array [i].nombrePantalla);
                    strcpy(array[i].nombrePantalla,AuxiliarNombre);
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
static int buscarPorId(Pantalla* array, int limite, int idPantalla)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==idPantalla)
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

int pantalla_altaForzada(Pantalla* array,int limite,char* nombre, int idPantalla, float precio)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombrePantalla,nombre);
            array[i].precio = precio;
            array[i].idPantalla = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
