#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* cliente_new()
{
    return malloc(sizeof(Cliente));
}

Cliente* cliente_newParametros(char nombre[64],char apellido[64],char email[256],char genero[10],char profesion[256],
                          char nacionalidad[256],char usuario[64],int id)
{
    Cliente* this;
    this=cliente_new();
    if(    !cliente_setNombre(this,nombre)
        && !cliente_setApellido(this,apellido)
        && !cliente_setEmail(this,email)
        && !cliente_setGenero(this,genero)
        && !cliente_setProfesion(this, profesion)
        && !cliente_setNacionalidad(this, nacionalidad)
        && !cliente_setUsuario(this, usuario)
        && !cliente_setId(this,id))
    {
        return this;
    }
    cliente_delete(this);
    return NULL;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno = 0;
    }
    return retorno;
}

int cliente_setEmail(Cliente* this, char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL && isValidEmail(email))
    {
        strcpy(this->email,email);
        retorno = 0;
    }
    return retorno;
}

int cliente_getEmail(Cliente* this, char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(email,this->email);
        retorno = 0;
    }
    return retorno;
}

int cliente_setGenero(Cliente* this, char* genero)
{
    int retorno=-1;
    if(this!=NULL && genero!=NULL && isValidGenero(genero))
    {
        strcpy(this->genero,genero);
        retorno = 0;
    }
    return retorno;
}

int cliente_getGenero(Cliente* this, char* genero)
{
    int retorno=-1;
    if(this!=NULL && genero!=NULL)
    {
        strcpy(genero,this->genero);
        retorno = 0;
    }
    return retorno;
}

int cliente_setProfesion(Cliente* this, char* profesion)
{
    int retorno=-1;
    if(this!=NULL && profesion!=NULL && isValidProfesion(profesion))
    {
        strcpy(this->profesion,profesion);
        retorno = 0;
    }
    return retorno;
}

int cliente_getProfesion(Cliente* this, char* profesion)
{
    int retorno=-1;
    if(this!=NULL && profesion!=NULL)
    {
        strcpy(profesion,this->profesion);
        retorno = 0;
    }
    return retorno;
}

int cliente_setNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno=-1;
    if(this!=NULL && nacionalidad!=NULL && isValidNacionalidad(nacionalidad))
    {
        strcpy(this->nacionalidad,nacionalidad);
        retorno = 0;
    }
    return retorno;
}

int cliente_getNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno=-1;
    if(this!=NULL && nacionalidad!=NULL)
    {
        strcpy(nacionalidad,this->nacionalidad);
        retorno = 0;
    }
    return retorno;
}

int cliente_setId(Cliente* this, int id)
{
    int retorno=-1;
    static int ultimoId=-1;
    if(this!=NULL)
    {
        if(id>ultimoId)
        {
            this->id=id;
            retorno=0;
            ultimoId=id;
        }
        else if(id==-1)
        {
            ultimoId++;
            this->id=ultimoId;
            retorno=0;
        }
    }
    return retorno;
}

int cliente_getId(Cliente* this, int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
    }

    return retorno;
}

int cliente_setUsuario(Cliente* this, char* usuario)
{
    int retorno=-1;
    if(this!=NULL && usuario!=NULL && isValidUsuario(usuario))
    {
        strcpy(this->usuario,usuario);
        retorno = 0;
    }
    return retorno;
}

int cliente_getUsuario(Cliente* this, char* usuario)
{
    int retorno=-1;
    if(this!=NULL && usuario!=NULL)
    {
        strcpy(usuario,this->usuario);
        retorno = 0;
    }
    return retorno;
}

int isValidNombre(char* nombre)
{
    return 1;
}

int isValidApellido(char* apellido)
{
    return 1;
}

int isValidEmail(char* email)
{
    return 1;
}

int isValidGenero(char* genero)
{
    return 1;
}

int isValidProfesion(char* profesion)
{
    return 1;
}

int isValidNacionalidad(char* nacionalidad)
{
    return 1;
}

int isValidUsuario(char* usuario)
{
    return 1;
}

int cliente_ordenarNombreApellido(void* cliente1, void* cliente2)
{
    char nameCliente1[50];
    char nameCliente2[50];
    char apellidoCliente1[50];
    char apellidoCliente2[50];
    if(cliente1!=NULL && cliente2!=NULL)
    {
        cliente_getNombre(cliente1,nameCliente1);
        cliente_getNombre(cliente2,nameCliente2);
        if(!strcmp(nameCliente1,nameCliente2))
        {

            cliente_getApellido(cliente1,apellidoCliente1);
            cliente_getApellido(cliente2,apellidoCliente2);
            return strcmp(apellidoCliente1,apellidoCliente2);
        }
    }
    return strcmp(nameCliente1,nameCliente2);
}

int cliente_ordenarEmail(void* cliente1, void* cliente2)
{
    char mailCliente1[50];
    char mailCliente2[50];
    if(cliente1!=NULL && cliente2!=NULL)
    {
        cliente_getEmail(cliente1,mailCliente1);
        cliente_getEmail(cliente2,mailCliente2);
    }
    return strcmp(mailCliente1,mailCliente2);
}

