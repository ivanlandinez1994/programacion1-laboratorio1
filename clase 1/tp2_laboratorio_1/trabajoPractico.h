#ifndef TRABAJOPRACTICO_H_INCLUDED
#define TRABAJOPRACTICO_H_INCLUDED
typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int isEmpty;
}EPersonas;
int personas_init(EPersonas* array,int limite);
int personas_mostrar(EPersonas* array,int limite);
int personas_alta(EPersonas* array,int limite);
int personas_baja(EPersonas* array, int limite, int dni);
int personas_modificacion(EPersonas* array,int limite, int id);
int personas_ordenar(EPersonas* array,int limite, int orden);
int personas_grafico(EPersonas* array, int limite);
#endif // FANTASMA_H_INCLUDED





