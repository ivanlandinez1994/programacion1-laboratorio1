#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"

int validarInt(char* array, int* resultado);
int validarString(char auxiliar[]);
int cargarDatosPersonas(EPersonas* arrayPersonas, int sizeArray)
{
    int retorno=-1;
    char auxNombre[50];
    char auxEdad[10];
    int auxEdadI;
    int subIndice;

    printf("ingrese el subindice donde desea ingresar el nombre de la persona\n");
    fflush(stdin);
    scanf("%d", &subIndice);
    fflush(stdin);
    while(subIndice>sizeArray || subIndice<0)
    {
        printf("subindice incorrecto");
        printf("ingrese el subindice donde desea ingresar el nombre de la persona\n");
        fflush(stdin);
        scanf("%d", &subIndice);
    }

    if(subIndice<sizeArray && subIndice>=0)
    {
        retorno=0;
        printf("\ningrese el nombre de la persona\n");
        fflush(stdin);
        fgets(auxNombre, sizeof(auxNombre), stdin);
        auxNombre[strlen(auxNombre)-1]=0;// se le quita el ultimo enter que se guarda en el array.
        if(validarString(auxNombre)==0) //se valida que haya ingresado los datos correctamente
        {
            printf("nombre cargado\n");
            strcpy(arrayPersonas[subIndice].nombre, auxNombre);//se copia el auxiliar en la variable perteneciente habiendo validado todo
        }
        else
        {
            printf("el dato ingresado no es correcto, dato no cargado\n");
        }

        printf("ingrese la edad de la persona\n");
        fflush(stdin);
        fgets(auxEdad, sizeof(auxEdad), stdin);
        auxEdad[strlen(auxEdad)-1]=0;
        if(validarInt(auxEdad, &auxEdadI)==0)
        {
            printf("Edad cargada\n");
            arrayPersonas[subIndice].edad=auxEdadI;
        }
        else
        {
            printf("el dato ingresado no es correcto, dato no cargado\n");
        }

        arrayPersonas[subIndice].flagEstadoVacio=0;
    }
    else
    {
        printf("\nel subindice ingresado no es valido\n");
    }
    return retorno;
}
int validarString(char auxiliar[])
{
    int retorno=0;
    int i=0;
    while(i<strlen(auxiliar))
    {
        if((auxiliar[i] != ' ') && (auxiliar[i] < 'a' || auxiliar[i] > 'z') && (auxiliar[i] < 'A' || auxiliar[i] > 'Z'))
        {
            retorno=-1;
        }
        i++;
    }
    return retorno;
}
int validarInt(char* array, int* resultado)
{
    int retorno=0;
    int i;
    for(i=0; i<strlen(array); i++){
        if(array[i]>'9' || array[i]<'0'){
            retorno=-1;
            break;
        }
    }
    if(retorno==0){
        *resultado=atoi(array);
    }
    else{
        printf("no ingreso un numero");
    }
    return retorno;
}
int borrarDatosPersonas(EPersonas* arrayPersonas, int sizeArray)
{
    int retorno=-1;
    int subIndicePersonaABorrar;
    char seguroBorrar;
    printf("ingrese el subIndice de la persona a borrar");
    fflush(stdin);
    scanf("%d", &subIndicePersonaABorrar);
    if(subIndicePersonaABorrar<sizeArray && subIndicePersonaABorrar>=0)
    {
        printf("esta seguro que desea borrar estos datos? (s) / (n)");
        fflush(stdin);
        scanf("%c", &seguroBorrar);
        if(seguroBorrar=='s'){
            retorno=0;
            strcpy(arrayPersonas[subIndicePersonaABorrar].nombre, " ");
            arrayPersonas[subIndicePersonaABorrar].edad=0;
            arrayPersonas[subIndicePersonaABorrar].flagEstadoVacio=1;
            printf("datos borrados correctamente");
        }
    }
    return retorno;
}
int sort_ordenarArrayNombreEdad(EPersonas* arrayPersonas, int sizeArray, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    EPersonas auxiliarPersonas;
        retorno = 0;
        do
        {
            flagSwap=0;
            for(i=0;i<sizeArray-1;i++)
            {
                if((strcmp(arrayPersonas[i].nombre,arrayPersonas[i+1].nombre)>0 && flagOrden==0) || (strcmp(arrayPersonas[i].nombre,arrayPersonas[i+1].nombre)<0 && flagOrden==1))
                {
                    auxiliarPersonas=arrayPersonas[i];
                    arrayPersonas[i]=arrayPersonas[i+1];
                    arrayPersonas[i+1]=auxiliarPersonas;
                    flagSwap = 1;
                }
            }
        }while(flagSwap);

    return retorno;
}
int sort_mostrarArrayOrdenadoNombreEdad(EPersonas* arrayPersonas, int sizeArray)
{
    int retorno = -1;
    int i;

    for(i=0;i<sizeArray;i++)
    {
        retorno = 0;
        printf("\nNombre: %s Edad: %d",arrayPersonas[i].nombre, arrayPersonas[i].edad);
    }

    return retorno;
}
