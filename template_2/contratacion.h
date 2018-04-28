#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
typedef struct
{
    float cuit;
    int idPantalla;
    int dias;
    char archivo[32];
    int idContratacion;
    int isEmpty;
}Contratacion;
#include "pantalla.h"
int contratacion_init(Contratacion* array,int limite);
int contratacion_mostrar(Contratacion* array,int limite);
int contratacion_mostrarDebug(Contratacion* array,int limite);
int contratacion_alta(Contratacion* arrayContratacion,int limite, Pantalla* arrayPantalla, int limitePantallas);
int contratacion_baja(Contratacion* arrayContratacion,int limite, float cuitCliente);
int contratacion_modificacion(Contratacion* arrayContratacion,int limite, float cuitCliente, Pantalla* arrayPantalla, int limitePantallas);
int contratacion_ordenar(Contratacion* array,int limite, int orden);
int buscarLugarLibre(Contratacion* array,int limite);
#endif // FANTASMA_H_INCLUDED






