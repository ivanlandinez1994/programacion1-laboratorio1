#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    char nombre[50];
    float precio;
    int stock;
    int idUsuario;
    int idPublicacion;
    int cantidadUnidadesVendidas;
    int isEmpty;
}Publicacion;
int publicacion_init(Publicacion* array,int limite);
int publicacion_mostrar(Publicacion* array,int limite);
int publicacion_mostrarDebug(Publicacion* array,int limite);

int publicacion_alta(Publicacion* array,int limite, int idUsuario);
int publicacion_comprarProductos(Publicacion* array, int limite, int idPublicacion);

int publicacion_baja(Publicacion* array,int limite, int id);
int publicacion_bajaPublicacionesUsuario(Publicacion* arrayPublicaciones,int limite, int id);

int publicacion_modificacion(Publicacion* array,int limite, int idPublicacion);
int publicacion_mostrarProductosDeUsuario(Publicacion* array, int limite, int idUsuario);

int publicacion_ordenar(Publicacion* array,int limite, int orden);
int publicacion_altaForzada(Publicacion* array,int limite,char* nombre, int id, float precio);
#endif // FANTASMA_H_INCLUDED





