#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    char nombrePantalla[50];
    char direccion[50];
    float precio;
    int tipo;
    int idPantalla;
    int isEmpty;
}Pantalla;
int pantalla_init(Pantalla* array,int limite);
int pantalla_mostrar(Pantalla* array,int limite);
int pantalla_mostrarDebug(Pantalla* array,int limite);
int pantalla_alta(Pantalla* array,int limite);
int pantalla_baja(Pantalla* array,int limite, int idPantalla);
int pantalla_modificacion(Pantalla* array,int limite, int idPantalla);
int pantalla_ordenarChar(Pantalla* array,int limite, int orden);
int pantalla_ordenarNumericamente(Pantalla* array,int limite, int orden);
int pantalla_altaForzada(Pantalla* array,int limite,char* nombre, int idPantalla, float precio);
#endif // PANTALLA_H_INCLUDED



