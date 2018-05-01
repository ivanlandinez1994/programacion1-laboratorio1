#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "contratacion.h"
#include "utn.h"
#include "pantalla.h"

static int contratacion_buscarPorId(Contratacion* array, int limite, int id);
static int contratacion_proximoId();
/** \brief
 * \param array Contratacion*
 * \param limite int
 * \return int
 */
int contratacion_init(Contratacion* array,int limite)
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

int contratacion_mostrarDebug(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %f - %d - %d - %s - %d - %d \n", array[i].cuit, array[i].idPantalla, array[i].dias, array[i].archivo, array[i].idContratacion, array[i].isEmpty);
        }
    }
    return retorno;
}

int contratacion_mostrar(Contratacion* array,int limite, Pantalla* arrayPantalla, int limitePantalla)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] -cuit: %f - idpantall: %d - dias: %d - Nombre: %s - IdContrat: %d - %d \n",array[i].cuit, array[i].idPantalla, array[i].dias, array[i].archivo, array[i].idContratacion, array[i].isEmpty);
        }
    }
    return retorno;
}

int contratacion_alta(Contratacion* arrayContratacion,int limite, Pantalla* arrayPantalla, int limitePantallas)
{
    int retorno = -1;
    int i;
    int auxiliarIdPantalla;
    float auxiliarCuit;
    int auxiliarDias;
    char auxiliarArchivo[32];
    int indiceDarDeAlta;
    for(i=0;i<limitePantallas;i++)
    {
        if(!arrayPantalla[i].isEmpty)
        {
            if(arrayContratacion[i].isEmpty)
                printf("pantallas disponibles, id: %d tipo: %d\n",arrayPantalla[i].idPantalla, arrayPantalla[i].tipo);
        }
    }

    if(limite > 0 && arrayContratacion != NULL)
    {
        i = buscarLugarLibre(arrayContratacion,limite);
        if(i >= 0)
        {
            if(!getValidInt("ID? ","\nNumero invalido\n",&indiceDarDeAlta,0,999999,2))
            {
                if(indiceDarDeAlta>=0)
                {
                    auxiliarIdPantalla = pantalla_buscarPorId(arrayPantalla, limitePantallas, indiceDarDeAlta);// preguntar porquee se sobreescribe?
                    if(auxiliarIdPantalla>=0)
                    {
                        if(!getValidFloat("\ncuit cliente? ", "\neso no es un cuit", &auxiliarCuit,1, 99999999999,2))
                        {
                            if(!getValidInt("\ncantidad de dias a contratar ","\ncantidad de dias ingresados no validos",&auxiliarDias,1,365,2))
                            {
                                if(!getValidString("\nnombre archivo? Ej:(Video1) ", "nombre archivo invalido\n", "tamaño maximo archivo 32\n", auxiliarArchivo, 32,2))
                                {
                                    arrayContratacion[auxiliarIdPantalla].cuit=auxiliarCuit;
                                    arrayContratacion[auxiliarIdPantalla].dias=auxiliarDias;
                                    strcpy(arrayContratacion[auxiliarIdPantalla].archivo,auxiliarArchivo);
                                    arrayContratacion[i].isEmpty=0;
                                    arrayContratacion[i].idContratacion = contratacion_proximoId();
                                    arrayContratacion[i].idPantalla = arrayPantalla[i].idPantalla; // preguntar
                                }
                            }
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


int contratacion_baja(Contratacion* arrayContratacion,int limite)
{
    int retorno = -1;
    int indiceAEliminar;
    int i;
    float auxiliarCuitCliente;
    int auxiliarIdPantalla;

    printf("ingrese el cuit del cliente\n");
    scanf("%f",&auxiliarCuitCliente);
    for(i=0; i<limite; i++)
    {
        if(arrayContratacion[i].cuit==auxiliarCuitCliente)
        {
            printf("id pantalla: %d dias de contrato: %d nombre archivo: %s idContrato: %d\n", arrayContratacion[i].idPantalla, arrayContratacion[i].dias, arrayContratacion[i].archivo, arrayContratacion[i].idContratacion);
        }
        else
        {
            printf("el cuit ingresado no tiene contrato de pantallas actualmente\n");
        }
    }
    getValidInt("ingrese el Id del contrato de la pantalla que desea dar de baja\n", "Id no valido\n", &indiceAEliminar,0,999999,2);
    if(indiceAEliminar>=0)
    {
        auxiliarIdPantalla = contratacion_buscarPorId(arrayContratacion, limite, indiceAEliminar);
        if(auxiliarIdPantalla>=0)
        {
            retorno = 0;
            arrayContratacion[indiceAEliminar].isEmpty = 1;
        }
    }

    return retorno;
}

/** \brief
 * \param array Contratacion*
 * \param limite int
 * \param id int
 * \return int
 */
int contratacion_modificacion(Contratacion* arrayContratacion,int limiteContratacion)
{
    int retorno = -1;
    int auxiliarIdPantalla;
    int auxiliarDias;
    char auxiliarArchivo[32];
    int indiceAModificar;
    int i;
    float auxiliarCuitCliente;
    printf("ingrese el cuit del cliente\n");
    scanf("%f", &auxiliarCuitCliente);
    for(i=0; i<limiteContratacion; i++)
    {
        if(arrayContratacion[i].cuit==auxiliarCuitCliente)
        {
            printf("id pantalla: %d dias de contrato: %d nombre archivo: %s idContrato: %d\n", arrayContratacion[i].idPantalla, arrayContratacion[i].dias, arrayContratacion[i].archivo, arrayContratacion[i].idContratacion);
            /*printf("ingrese el id de la pantalla a modificar");
            scanf("%d", &indiceAModificar);*/
        }
        else
        {
            printf("el cuit ingresado no tiene contrato de pantallas actualmente\n");
        }
    }
    getValidInt("ID pantalla?","\nNumero invalido\n",&indiceAModificar,0,999999,2);
    if(indiceAModificar>=0)
    {
        auxiliarIdPantalla = contratacion_buscarPorId(arrayContratacion, limiteContratacion, indiceAModificar);
        if(auxiliarIdPantalla>=0)
        {
            if(!getValidInt("\ncantidad de dias a contratar","\ncantidad de dias ingresados no validos",&auxiliarDias,1,365,2))
            {
                if(!getValidString("\nnombre archivo? Ej:(Video1)", "nombre archivo invalido", "tamaño maximo archivo 32", auxiliarArchivo, 32,2))
                {
                    arrayContratacion[auxiliarIdPantalla].dias=auxiliarDias;
                    strcpy(arrayContratacion[auxiliarIdPantalla].archivo,auxiliarArchivo);
                    //arrayContratacion[i].isEmpty=0;
                    //arrayContratacion[i].idContratacion = contratacion_proximoId();
                }
            }
        }
        else
        {
            retorno = -3;
        }
        retorno = 0;
    }
    return retorno;
}

int buscarLugarLibre(Contratacion* array,int limite)
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

static int contratacion_buscarPorId(Contratacion* array, int limite, int id)
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
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int contratacion_proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
