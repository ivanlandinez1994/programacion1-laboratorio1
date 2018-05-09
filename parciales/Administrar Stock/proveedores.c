#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "proveedores.h"
#include "productos.h"
#include "utn.h"

static int buscarLugarLibre(Proveedores* arrayProveedores,int limiteProveedores);
static int proximoId();


/** \brief inicializa el arrayProveedores en vacio
 *
 * \param arrayProveedores Proveedores* el arrayProveedores a inicializar
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \return (0) esta todo inicializado en vacio (-1) no se inicializo
 *
 */
int proveedores_init(Proveedores* arrayProveedores,int limiteProveedores)
{
    int retorno = -1;
    int i;
    if(limiteProveedores > 0 && arrayProveedores != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteProveedores;i++)
        {
            arrayProveedores[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief imprime informacion sobre el arrayProveedores
 *
 * \param arrayProveedores Proveedores* el arrayProveedores a inicializar
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \return (0) si imprime correctamente todo el arrayProveedores (-1) si no se logra imprimir
 *
 */
int proveedores_mostrarDebug(Proveedores* arrayProveedores,int limiteProveedores)
{
    int retorno = -1;
    int i;
    if(limiteProveedores > 0 && arrayProveedores != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteProveedores;i++)
        {
            printf("[DEBUG] - %d - - %d\n",arrayProveedores[i].codigoProveedor, arrayProveedores[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief imprime informacion sobre el arrayProveedores
 *
 * \param arrayProveedores Proveedores* el arrayProveedores a inicializar
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \return (0) si imprime correctamente todo el arrayProveedores (-1) si no se logra imprimir
 *
 */
int proveedores_mostrar(Proveedores* arrayProveedores,int limiteProveedores)
{
    int retorno = -1;
    int i;
    if(limiteProveedores > 0 && arrayProveedores != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteProveedores;i++)
        {
            if(!arrayProveedores[i].isEmpty)
                printf("Descp: %s\nCodigo proveedor: %d\n\n",arrayProveedores[i].descripcionProducto, arrayProveedores[i].codigoProveedor);
        }
    }
    return retorno;
}

/** \brief alta de los datos a utilizar
 *
 * \param arrayProveedores Proveedores* el arrayProveedores a inicializar
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \return (0) si el alta fue exitosa (-1) si no lo fue
 *
 */
int proveedores_alta(Proveedores* arrayProveedores,int limiteProveedores)
{
    int retorno = -1;
    int i;
    char descripcionProducto[50];
    if(limiteProveedores > 0 && arrayProveedores != NULL)
    {
        i = buscarLugarLibre(arrayProveedores,limiteProveedores);
        if(i >= 0)
        {
            if(!getValidAlfaNumerico("\ndescripcionProducto? ","\nEso no es una descripcion","El maximo es 50 caracteres",
                                     descripcionProducto,50,3))
            {
                retorno = 0;
                strcpy(arrayProveedores[i].descripcionProducto,descripcionProducto);
                arrayProveedores[i].codigoProveedor = proximoId();
                arrayProveedores[i].isEmpty = 0;
                printf("Proveedor dado de alta exitosamente, codigo de proveedor: %d \n\n",arrayProveedores[i].codigoProveedor);
            }
            else
            {
                retorno = -3;//no ingreso una descripcion correcta luego de los 3 intentos
            }
        }
        else
        {
            retorno = -2;//no se encontro mas lugar para ingresar registrar el nuevo proveedor
        }
    }
    return retorno;
}

/** \brief baja de los datos a utilizar
 *
 * \param arrayProveedores Proveedores* el arrayProveedores a dar de baja
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \param el id del lugar donde se quiere realizar la baja
 * \return (0) si la baja fue exitosa (-1) si no lo fue
 *
 */
int proveedores_baja(Proveedores* arrayProveedores,int limiteProveedores, int codigoProveedor)
{
    int retorno = -1;
    int indiceAEliminar;
    indiceAEliminar = proveedores_buscarPorCodigoProveedor(arrayProveedores, limiteProveedores, codigoProveedor);
    if(indiceAEliminar>=0)
    {
        retorno = 0;
        arrayProveedores[indiceAEliminar].isEmpty = 1;
    }
    return retorno;
}

/** \brief modificacion de los datos a utilizar
 *
 * \param arrayProveedores Proveedores* el arrayProveedores a modificar
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \param el id del lugar donde se quiere realizar la modificacion
 * \return (0) si la modificacion fue exitosa (-1) si no lo fue (-2) si se ingreso algo que no era un string
 *
 */
/*int proveedores_modificacion(Proveedores* arrayProveedores,int limiteProveedores, int codigoProveedor)
{
    int retorno = -1;
    int indiceAModificar;
    char buffer[50];
    indiceAModificar = buscarPorId(arrayProveedores, limiteProveedores, id);
    if(indiceAModificar>0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
        {
            retorno = 0;
            strcpy(arrayProveedores[indiceAModificar].nombre,buffer);
        }
        else
        {
            retorno = -2;
        }
    }
    retorno = 0;
    return retorno;
}*/
/** \brief ordenamiento de datos de tipo char o string
 *
 * \param arrayProveedores Proveedores* el arrayProveedores a ordenar
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \param orden si es de mayor a menor o menor a mayor
 * \return (0) si el ordenamiento fue exitoso (-1) si no lo fue
 *
 */
/*int proveedores_ordenarChar(Proveedores* arrayProveedores,int limiteProveedores, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Proveedores auxiliarEstructura;

    if(limiteProveedores > 0 && arrayProveedores != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limiteProveedores-1;i++)
            {
                if(!arrayProveedores[i].isEmpty && !arrayProveedores[i+1].isEmpty)
                {
                    if((strcmp(arrayProveedores[i].nombre,arrayProveedores[i+1].nombre) > 0 && orden) || (strcmp(arrayProveedores[i].nombre,arrayProveedores[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = arrayProveedores[i];
                        arrayProveedores[i] = arrayProveedores[i+1];
                        arrayProveedores[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}*/
/** \brief ordenamiento de datos de tipo numerico
 *
 * \param arrayProveedores Proveedores* el arrayProveedores a ordenar
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \param orden si es de mayor a menor o menor a mayor
 * \return (0) si el ordenamiento fue exitoso (-1) si no lo fue
 *
 */
/*int proveedores_ordenarNumericamente(Proveedores* arrayProveedores,int limiteProveedores, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    char AuxiliarNombre[50];
    if(limiteProveedores > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limiteProveedores-1;i++)
            {
                if((arrayProveedores[i].idProveedores < arrayProveedores[i+1].idProveedores && orden)||(arrayProveedores[i].idProveedores > arrayProveedores[i+1].idProveedores && !orden))
                {
                    strcpy(AuxiliarNombre,arrayProveedores[i+1].nombre);
                    strcpy(arrayProveedores[i+1].nombre,arrayProveedores [i].nombre);
                    strcpy(arrayProveedores[i].nombre,AuxiliarNombre);
                }
            }
        }while(flagSwap);
    }
    return retorno;
}*/
/** \brief busca de un lugar libre en el arrayProveedores
 *
 * \param arrayProveedores Proveedores* el arrayProveedores donde se buscara el lugar libre
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \return devuelve el lugar libre
 *
 */
int buscarLugarLibre(Proveedores* arrayProveedores,int limiteProveedores)
{
    int retorno = -1;
    int i;
    if(limiteProveedores > 0 && arrayProveedores != NULL)
    {
        for(i=0;i<limiteProveedores;i++)
        {
            if(arrayProveedores[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief busca dentro del arrayProveedores el valor que se le pasa como id
 *
 * \param arrayProveedores Proveedores* el arrayProveedores donde se buscara la coincidencia
 * \param limiteProveedores int el tamaño del arrayProveedores
 * \param el lugar que deseamos encontrar
 * \return devuelve la ubicacion del id
 *
 */
int proveedores_buscarPorCodigoProveedor(Proveedores* arrayProveedores, int limiteProveedores, int codigoProveedor)
{
    int retorno = -1;
    int i;
    if(limiteProveedores > 0 && arrayProveedores != NULL)
    {
        retorno = -2;
        for(i=0;i<limiteProveedores;i++)
        {
            if(!arrayProveedores[i].isEmpty && arrayProveedores[i].codigoProveedor == codigoProveedor)
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

int proveedores_altaForzada(Proveedores* arrayProveedores,int limiteProveedores,char* descripcionProductos, int codigoProveedor)
{
    int retorno = -1;
    int i;

    if(limiteProveedores > 0 && arrayProveedores != NULL)
    {
        i = buscarLugarLibre(arrayProveedores,limiteProveedores);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayProveedores[i].descripcionProducto,descripcionProductos);
            arrayProveedores[i].codigoProveedor = codigoProveedor;
            arrayProveedores[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
