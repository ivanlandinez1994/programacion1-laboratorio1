#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "cliente.h"
#include "controller.h"

int controller_leerArchivoCliente(char* path, ArrayList* pArrayClientes)
{
    int retorno = -1;
    char bNombre[4096];
    char bApellido[4096];
    char bEmail[4096];
    char bGenero[4096];
    char bProfesion[4096];
    char bNacionalidad[4096];
    char bUsuario[4096];
    char bId[4096];
    Cliente* pAuxCliente;
    FILE* pFile;
    pFile=fopen(path,"r");
    if(pFile != NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"\
                   ,bId,bNombre,bApellido,bEmail,bGenero,bProfesion,bUsuario,bNacionalidad);
            //printf("%s\n",bNombre);
            pAuxCliente = cliente_newParametros(bNombre,bApellido,bEmail,bGenero,bProfesion,bNacionalidad,bUsuario,atoi(bId));
            al_add(pArrayClientes,pAuxCliente);
        }
    }
    fclose(pFile);
    return retorno;
}

int controller_mostrarArchivoCliente(ArrayList* pArrayList)
{
    int retorno=-1;
    int i;
    Cliente* auxCliente;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[10];
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    int id;
    for(i=0; i<al_len(pArrayList);i++)
    {
        retorno=0;
        auxCliente = al_get(pArrayList,i);
        cliente_getNombre(auxCliente,nombre);
        cliente_getApellido(auxCliente,apellido);
        cliente_getEmail(auxCliente,email);
        cliente_getGenero(auxCliente,genero);
        cliente_getProfesion(auxCliente,profesion);
        cliente_getNacionalidad(auxCliente,nacionalidad);
        cliente_getUsuario(auxCliente,usuario);
        cliente_getId(auxCliente,&id);
        printf("\n%s - %s - %d -%s",nombre,apellido,i,email);
    }
    return retorno;
}

int controller_ordenarNombreApellido(ArrayList* pArrayList)
{
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        retorno=0;
        al_sort(pArrayList,cliente_ordenarNombreApellido,1);
    }
    return retorno;
}

int controller_ordenarEmail(ArrayList* pArrayList)
{
    int retorno=-1;
    if(pArrayList!=NULL)
    {
        retorno=0;
        al_sort(pArrayList,cliente_ordenarEmail,1);
    }
    return retorno;
}

int controller_guardaArchivoCliente(char* path, ArrayList* pArrayList)
{
    int retorno=-1;
    int i;
    Cliente* auxCliente;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[10];
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    int id;
    FILE* pFile;
    pFile=fopen(path,"w");
    if(pFile!=NULL)
    {
    fprintf(stdout,"id,nombre,apellido,email,genero,profesion,usuario,nacionalidad\n");
        for(i=0; i<al_len(pArrayList);i++)
        {
            retorno=0;
            auxCliente = al_get(pArrayList,i);
            cliente_getNombre(auxCliente,nombre);
            cliente_getApellido(auxCliente,apellido);
            cliente_getEmail(auxCliente,email);
            cliente_getGenero(auxCliente,genero);
            cliente_getProfesion(auxCliente,profesion);
            cliente_getNacionalidad(auxCliente,nacionalidad);
            cliente_getUsuario(auxCliente,usuario);
            cliente_getId(auxCliente,&id);

            fprintf(pFile,"%d,%s,%s,%s,%s,%s,%s,%s\n",
                    id,nombre,apellido,email,genero,profesion,usuario,nacionalidad);

        }
    }
    fclose(pFile);
    return retorno;
}

