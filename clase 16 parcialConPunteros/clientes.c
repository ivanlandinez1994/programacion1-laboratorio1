#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clientes.h"
#include "validaciones.h"

Cliente* cliente_new()
{
    Cliente* auxCliente = malloc(sizeof(Cliente));//preguntar
    return auxCliente;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    if(this!=NULL && esSoloLetras(nombre))
    {
        strcpy(this->nombreCliente,nombre);
        return 1;
    }
    else
        return 0;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombreCliente);
        return 1;
    }
    else
        return 0;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    if(this!=NULL && esSoloLetras(apellido))
    {
        strcpy(this->apellidoCliente, apellido);
        return 1;
    }
    else
        return 0;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido, this->apellidoCliente);
        return 1;
    }
    else
        return 0;
}

int cliente_setCuit(Cliente* this, float cuit)
{
    if(this!=NULL && esCuit(cuit))
    {
        this->cuit = cuit;
        return 1;
    }
    else
        return 0;
}

int cliente_getCuit(Cliente* this, float* cuit)
{
    if(this!=NULL && cuit!=NULL)
    {
        *cuit = this->cuit;
        return 1;
    }
    else
        return 0;
}

