#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"

static int buscarPorId(Fantasma* array, int limite, int id);
static int buscarLugarLibre(Fantasma* array,int limite);
static int proximoId();


/** \brief inicializa el array en vacio
 *
 * \param array Fantasma* el array a inicializar
 * \param limite int el tamaño del array
 * \return (0) esta todo inicializado en vacio (-1) no se inicializo
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

/** \brief imprime informacion sobre el array
 *
 * \param array Fantasma* el array a inicializar
 * \param limite int el tamaño del array
 * \return (0) si imprime correctamente todo el array (-1) si no se logra imprimir
 *
 */
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

/** \brief imprime informacion sobre el array
 *
 * \param array Fantasma* el array a inicializar
 * \param limite int el tamaño del array
 * \return (0) si imprime correctamente todo el array (-1) si no se logra imprimir
 *
 */
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

/** \brief alta de los datos a utilizar
 *
 * \param array Fantasma* el array a inicializar
 * \param limite int el tamaño del array
 * \return (0) si el alta fue exitosa (-1) si no lo fue
 *
 */
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



/** \brief baja de los datos a utilizar
 *
 * \param array Fantasma* el array a dar de baja
 * \param limite int el tamaño del array
 * \param el id del lugar donde se quiere realizar la baja
 * \return (0) si la baja fue exitosa (-1) si no lo fue
 *
 */
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

/** \brief modificacion de los datos a utilizar
 *
 * \param array Fantasma* el array a modificar
 * \param limite int el tamaño del array
 * \param el id del lugar donde se quiere realizar la modificacion
 * \return (0) si la modificacion fue exitosa (-1) si no lo fue (-2) si se ingreso algo que no era un string
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
/** \brief ordenamiento de datos de tipo char o string
 *
 * \param array Fantasma* el array a ordenar
 * \param limite int el tamaño del array
 * \param orden si es de mayor a menor o menor a mayor
 * \return (0) si el ordenamiento fue exitoso (-1) si no lo fue
 *
 */
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
/** \brief ordenamiento de datos de tipo numerico
 *
 * \param array Fantasma* el array a ordenar
 * \param limite int el tamaño del array
 * \param orden si es de mayor a menor o menor a mayor
 * \return (0) si el ordenamiento fue exitoso (-1) si no lo fue
 *
 */
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
/** \brief busca de un lugar libre en el array
 *
 * \param array Fantasma* el array donde se buscara el lugar libre
 * \param limite int el tamaño del array
 * \return devuelve el lugar libre
 *
 */
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
/** \brief busca dentro del array el valor que se le pasa como id
 *
 * \param array Fantasma* el array donde se buscara la coincidencia
 * \param limite int el tamaño del array
 * \param el lugar que deseamos encontrar
 * \return devuelve la ubicacion del id
 *
 */
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
/** \brief genera un id unico
 *
 * \return el id
 *
 */
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
