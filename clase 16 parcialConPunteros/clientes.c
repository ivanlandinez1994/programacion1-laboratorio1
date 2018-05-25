#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clientes.h"
#include "validaciones.h"

Cliente* cliente_new(void)
{
    return malloc(sizeof(Cliente));
}

Cliente* cliente_newP(char* nombreCliente, char* apellidoCliente,  float cuit, int idCliente)
{
    Cliente* this=cliente_new();
    if(   !cliente_setNombre(this, nombreCliente)
       && !cliente_setApellido(this, apellidoCliente)
       && !cliente_setCuit(this, cuit)
       && !cliente_setNewId(this))
                    return this;

    cliente_delete(this);
    return NULL;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

static int ultimoId=-1;

int cliente_setNewId(Cliente* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        ultimoId++;
        this->idCliente=ultimoId;
        retorno = 0;
    }
    return retorno;
}

int cliente_setId(Cliente* this, int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        if(id>ultimoId)
            id=ultimoId;

        this->idCliente=id;
        retorno = 0;
    }
    return retorno;
}

int cliente_getId(Cliente* this, int* idCliente)
{
    int retorno=-1;
    if(this!=NULL && idCliente!=NULL)
    {
        *idCliente=this->idCliente;
        retorno = 0;
    }
    return retorno;
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && !valid_esSoloLetras(nombre) && nombre!=NULL)// cualquier puntero tiene validacion no NULL
    {
        strcpy(this->nombreCliente,nombre);
        retorno=0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombreCliente);
        retorno=0;
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno=-1;
    if(this!=NULL && !valid_esSoloLetras(apellido) && apellido!=NULL)
    {
        strcpy(this->apellidoCliente, apellido);
        retorno=0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido, this->apellidoCliente);
        retorno = 0;
    }
    return retorno;
}

int cliente_setCuit(Cliente* this, float cuit)
{
    int retorno=-1;
    if(this!=NULL && !valid_esCuit(cuit))
    {
        this->cuit = cuit;
        retorno = 0;
    }
    return retorno;
}

int cliente_getCuit(Cliente* this, float* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        *cuit = this->cuit;
        retorno = 0;
    }
    return retorno;
}

Cliente* arrayCliente_getById(Cliente** arrayCliente, int limite, int idCliente)
{
    Cliente* retorno=NULL;
    int i=0;
    int auxId;
    for(i=0;i<limite;i++)
    {
        cliente_getId(*(arrayCliente+i),&auxId);
        if(auxId==idCliente)
        {
            retorno = *(arrayCliente+i);
            break;
        }
    }

    return retorno;
}

void arrayACliente_add(Alumno* array[],int cantidadMaxima,int* cantidadActual, char* nombre, char* apellido, float cuit, int id)
{
    //falta validar
    array[*cantidadActual]  = alumno_newP( nombre,apellido,cuit,id);
    (*cantidadActual)++;
}

void arrayAlumno_remove(Alumno* array[],int cantidadMaxima,int* cantidadActual, int id)
{
    //falta
}
