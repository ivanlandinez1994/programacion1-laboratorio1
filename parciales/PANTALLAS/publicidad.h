#ifndef PUBLIDAD_H_INCLUDED
#define PUBLIDAD_H_INCLUDED
typedef struct
{
    float cuitCliente;
    int idPantalla;
    int cantidadDiasContratar;
    char nombreArchivo[50];
    int idPublicidad;
    int isEmpty;
}Publicidad;
int publicidad_init(Publicidad* array,int limite);
int publicidad_mostrar(Publicidad* array,int limite);
int publicidad_mostrarPantallasContratadas(Publicidad* array,int limite, float cuitCliente);
int publicidad_alta(Publicidad* array,int limite, Pantalla* arrayPantalla, int limitePantalla);

int publicidad_baja(Publicidad* array,int limite, int idPublicidad);
int publicidad_bajaPublicadesPantalla(Publicidad* array,int limitePublicidad, int idPantalla);

int publicidad_modificacion(Publicidad* array,int limite, int id);
int publicidad_ordenarChar(Publicidad* array,int limite, int orden);
int publicidad_ordenarNumericamente(Publicidad* array,int limite, int orden);
int publicidad_altaForzada(Publicidad* arrayC,int limite,
                     Pantalla* pantallas, int lenPantallas,int idPantalla,char* archivo,float cuit,int dias);
#endif // PUBLIDAD_H_INCLUDED



