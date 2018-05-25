#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidCuit(char* cuit);
static int isValidAltura(int altura);

Alumno* alumno_new()
{
    return malloc(sizeof(Alumno));
}

Alumno* alumno_newP( char* dni, char* nombre, char* apellido, char* cuit,float altura,int id)
{
    Alumno* this = alumno_new();

    if(     !alumno_setCuit(this,cuit)
       &&   !alumno_setAltura(this,altura)
       &&   !alumno_setId(this, id)
       &&   !alumno_setNombre(this,nombre)
       &&   !alumno_setApellido(this,apellido))
    {
        return this;
    }
    alumno_delete(this);
    return NULL;

}

void alumno_delete(Alumno* this)
{
    free(this);
}

static int ultimoId = -1;
int alumno_setNewId(Alumno* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        ultimoId++;
        this->id = ultimoId;
        retorno = 0;
    }
    return retorno;
}

int alumno_setId(Alumno* this,int id)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(id!=-1)
        {
            if(id > ultimoId)
            {
                ultimoId = id;
                this->id = id;
            }
        }
        else
            alumno_setNewId(this);
        retorno = 0;
    }
    return retorno;
}

int alumno_getId(Alumno* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


int alumno_setAltura(Alumno* this, float altura)
{
    int retorno = -1;
    if(this != NULL && isValidAltura(altura))
    {
        this->altura = altura;
        retorno = 0;
    }
    return retorno;
}

int alumno_getAltura(Alumno* this, float* altura)
{
    int retorno = -1;
    if(this != NULL && altura != NULL)
    {
        *altura = this->altura;
        retorno = 0;
    }
    return retorno;
}

static int isValidAltura(int altura)
{

    return 1;
}

int alumno_setApellido(Alumno* this, char* apellido)
{
    int retorno=-1;
    if(this!=NULL  && apellido!=NULL)
    {
        strcpy(this->apellido, apellido);
        retorno=0;
    }
    return retorno;
}

int alumno_getApellido(Alumno* this, char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido, this->apellido);
        retorno = 0;
    }
    return retorno;
}

int alumno_setNombre(Alumno* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL  && nombre!=NULL)// cualquier puntero tiene validacion no NULL
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int alumno_getNombre(Alumno* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno=0;
    }
    return retorno;
}

int alumno_setCuit(Alumno* this, char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL && isValidCuit(cuit))
    {
        strcpy(this->cuit,cuit);
        retorno = 0;
    }
    return retorno;
}

int alumno_getCuit(Alumno* this, char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL)
    {
        strcpy(cuit , this->cuit);
        retorno = 0;
    }
    return retorno;
}

static int isValidCuit(char* cuit)
{

    return 1;
}



//*************************************

Alumno* arrayAlumno_getById (Alumno* array[],int cantidad,int id)
{
    Alumno* retorno = NULL;
    int i;
    int auxiliarId;
    for(i=0;i<cantidad;i++)
    {
        alumno_getId(array[i],&auxiliarId);
        if(auxiliarId == id)
        {
            retorno = array[i];
            break;
        }
    }
    return retorno;
}

void arrayAlumno_add(Alumno* array[],int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit,float altura,int id)
{
    //falta validar
    array[*cantidadActual]  = alumno_newP( dni,nombre,apellido,cuit,altura,id);
    (*cantidadActual)++;
}

void arrayAlumno_remove(Alumno* array[],int cantidadMaxima,int* cantidadActual, int id)
{
    //falta
}






