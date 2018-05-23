#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "clientes.h"
#include "publicacion.h"
#include "validaciones.h"

Publicacion* publicacion_new()
{
    Publicacion* auxPublicacion= malloc(sizeof(Publicacion));
    return auxPublicacion;
}

void publicacion_delete(Publicacion* this)
{
    free(this);
}

int publicacion_setNumeroRubro(Publicacion* this, int numeroRubro)
{
    if(this!=NULL && valid_esNum(numeroRubro))
    {
        this->numeroRubro = numeroRubro;
        return 1;
    }
    else
        return 0;
}

int publicacion_getNumeroRubro(Publicacion* this, int* numeroRubro)
{
    if(this!=NULL && numeroRubro!=NULL)
    {
        *numeroRubro = this->numeroRubro;
        return 1;
    }
    else
        return 0;
}
