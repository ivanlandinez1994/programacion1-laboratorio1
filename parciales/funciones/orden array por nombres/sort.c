#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swapInt(int* primerEntero,int* segundoEntero);


/** \brief  Ordena un array de enteros
 *
 * \param array int* Puntero al array
 * \param cantidadElementos int cantidad de elementos del array
 * \param flagOrden int [1] Ordena de mayor a menor [0] Ordena de menor a mayor
 * \return int [-1] Error [0] Ok
 *
 */
int sort_ordenarArrayEnteros(int* array,int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<cantidadElementos-1;i++)
            {
                if((array[i] < array[i+1] && flagOrden)||(array[i] > array[i+1] && !flagOrden))
                {
                    swapInt(&array[i],&array[i+1]);
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief Intercambia dos enteros
 *
 * \param primerEntero int*
 * \param segundoEntero int*
 * \return int
 *
 */
int swapInt(int* primerEntero,int* segundoEntero)
{
    int auxiliar;
    auxiliar = *primerEntero;
    *primerEntero = *segundoEntero;
    *segundoEntero = auxiliar;
    return 0;
}


/** \brief
 *
 * \param array int*
 * \param cantidadElementos int
 * \return int
 *
 */
int sort_mostrarArrayEnteros(int* array, int cantidadElementos)
{
    int retorno = -1;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        for(i=0;i<cantidadElementos;i++)
        {
            printf("\n%d",array[i]);
        }
    }
    return retorno;
}


/** \brief
 *
 * \param
 * \param cantidadElementos int
 * \return int
 *
 */
int sort_mostrarArrayCadenaCaracteres(char array[][50], int cantidadElementos)
{
    int retorno = -1;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        for(i=0;i<cantidadElementos;i++)
        {
            printf("\n%s",array[i]);
        }
    }
    return retorno;
}
int sort_ordenarArrayChar(char array[][50],int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    char auxiliar[50];
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap=0;
            for(i=0;i<cantidadElementos-1;i++)
            {
                if((strcmp(array[i],array[i+1])>0  && flagOrden)||(strcmp(array[i],array[i+1])<0 && !flagOrden))
                {
                    strcpy(auxiliar,array[i]);
                    strcpy(array[i],array[i+1]);
                    strcpy(array[i+1],auxiliar);
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
int sort_ordenarArrayCharyEdad(char arrayNombre[][50], int* arrayEdad, int cantidadElementosNombre, int cantidadElementosArrayEdad, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    char auxiliarNombre[50];
    int auxiliarEdad;
    if(cantidadElementosArrayEdad > 0)
    {
        retorno = 0;
        do
        {
            flagSwap=0;
            for(i=0;i<cantidadElementosArrayEdad-1;i++)
            {
                if((strcmp(arrayNombre[i],arrayNombre[i+1])>0  && flagOrden)||(strcmp(arrayNombre[i],arrayNombre[i+1])<0 && !flagOrden))
                {
                    strcpy(auxiliarNombre,arrayNombre[i]);
                    auxiliarEdad=arrayEdad[i];

                    strcpy(arrayNombre[i],arrayNombre[i+1]);
                    arrayEdad[i]=arrayEdad[i+1];

                    strcpy(arrayNombre[i+1],auxiliarNombre);
                    arrayEdad[i+1]=auxiliarEdad;

                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
int sort_mostrarArrayCharYEdad(char arrayNombre[][50],int* arrayEdad, int cantidadElementosNombre, int cantidadElementosArrayEdad)
{
    int retorno = -1;
    int i;
    if(cantidadElementosArrayEdad > 0)
    {
        retorno = 0;
        for(i=0;i<cantidadElementosArrayEdad;i++)
        {
            printf("\n%s %d",arrayNombre[i], arrayEdad[i]);
        }
    }
    return retorno;
}
int sort_ordenarArrayCharyEdadYApellido(char arrayNombre[][50],char arrayApellido[][50], int* arrayEdades, int cantidadElementosNombres, int cantidadElementosEdades, int cantidadElementosApellido, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    char auxiliarNombre[50];
    char auxiliarApellido[50];
    int auxiliarEdad;
    if(cantidadElementosApellido > 0)
    {
        retorno = 0;
        do
        {
            flagSwap=0;
            for(i=0;i<cantidadElementosApellido-1;i++)
            {
                if((strcmp(arrayNombre[i],arrayNombre[i+1])>0  && flagOrden)||(strcmp(arrayNombre[i],arrayNombre[i+1])<0 && !flagOrden))
                {
                    strcpy(auxiliarNombre,arrayNombre[i]);
                    auxiliarEdad=arrayEdades[i];
                    strcpy(auxiliarApellido, arrayApellido[i]);

                    strcpy(arrayNombre[i],arrayNombre[i+1]);
                    arrayEdades[i]=arrayEdades[i+1];
                    strcpy(arrayApellido[i],arrayApellido[i+1]);

                    strcpy(arrayNombre[i+1],auxiliarNombre);
                    arrayEdades[i+1]=auxiliarEdad;
                    strcpy(arrayApellido[i+1],auxiliarApellido);

                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int sort_mostrarArrayCharYEdadYApellido(char arrayNombre[][50],int* arrayEdad, char arrayApellido[][50], int cantidadElementosNombres, int cantidadElementosArrayEdades, int cantidadElementosArrayApellido)
{
    int retorno = -1;
    int i;
    if(cantidadElementosArrayApellido > 0)
    {
        retorno = 0;
        for(i=0;i<cantidadElementosArrayApellido;i++)
        {
            printf("\n%s %s %d",arrayNombre[i],arrayApellido[i], arrayEdad[i]);
        }
    }
    return retorno;
}
