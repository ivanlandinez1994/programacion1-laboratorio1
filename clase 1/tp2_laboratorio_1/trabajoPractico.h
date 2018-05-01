#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED
typedef struct
{
    char nombre[50];
    int edad;
    int isEmpty;
}EPersonas;
int personas_init(EPersonas* array,int limite);
int personas_mostrar(EPersonas* array,int limite);
int personas_mostrarDebug(EPersonas* array,int limite);
int personas_alta(EPersonas* array,int limite);
int personas_baja(EPersonas* array,int limite, char[50] persona);
int personas_modificacion(EPersonas* array,int limite, int id);
int personas_ordenar(EPersonas* array,int limite, int orden);
#endif // FANTASMA_H_INCLUDED





