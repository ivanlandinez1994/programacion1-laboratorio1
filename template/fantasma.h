#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED
typedef struct
{
    char nombre[50];
    int idFantasma;
    int isEmpty;
}Fantasma;
int fantasma_init(Fantasma* array,int limite);
int fantasma_mostrar(Fantasma* array,int limite);
int fantasma_mostrarDebug(Fantasma* array,int limite);
int fantasma_alta(Fantasma* array,int limite);
int fantasma_baja(Fantasma* array,int limite, int id);
int fantasma_modificacion(Fantasma* array,int limite, int id);
int fantasma_ordenarChar(Fantasma* array,int limite, int orden);
int fantasma_ordenarNumericamente(Fantasma* array,int limite, int orden);
int fantasma_altaForzada(Fantasma* array,int limite,char* nombre, int id);
#endif // FANTASMA_H_INCLUDED



