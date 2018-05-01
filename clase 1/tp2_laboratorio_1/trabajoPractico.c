#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "personas.h"
#include "utn.h"
static int buscarLugarLibre(EPersonas* array,int limite);

int personas_init(EPersonas* array,int limite)
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
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",array[i].idEPersonas, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int personas_mostrar(EPersonas* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",array[i].idEPersonas, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int personas_alta(EPersonas* array,int limite)
{
    int retorno = -1;
    char auxNombre[50];
    char auxEdad[10];
    int i;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",&auxNombre,40,2))
            {
                if(!getValidInt("\nEdad?","\neso no es una edad",&auxEdad,1,150,2))
                {
                    retorno = 0;
                    strcpy(array[i].nombre,auxNombre);
                    array[i].edad=auxEdad;
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

int personas_baja(EPersonas* array,int limite, char[50] auxPersona)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && strcmp(array[i].nombre,auxPersona)==0)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int personas_ordenar(EPersonas* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    EPersonas auxiliarEstructura;

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

int buscarLugarLibre(EPersonas* array,int limite)
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
