#include "usuario.h"
#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    int idUsuario;
    int idPublicacion;
    char nombreProducto[50];
    float precio;
    int stock;
    int cantidadVendida;
    int isEmpty;
}Publicacion;
int publicacion_init(Publicacion* array,int limite);
int publicacion_buscarPorId(Publicacion* array, int limite, int id);

int publicacion_mostrarPublicaciones(Publicacion* array,int limite, Usuario* arrayUsuario, int limiteUsuario);
int publicacion_mostrarDebug(Publicacion* array,int limite);
int publicacion_mostrarProductosUsuario(Publicacion* array,int limite, int idUsuario);

int publicacion_alta(Publicacion* array,int limite, int idUsuario);

int publicacion_baja(Publicacion* array,int limite, int idPublicacion);
int publicacion_bajaUsuarioYProductos(Publicacion* array,int limite, int idUsuario);

int publicacion_modificacion(Publicacion* array,int limite, int idPublicacion);
int publicacion_ordenar(Publicacion* array,int limite, int orden);

int publicacion_comprar(Publicacion* publicaciones, Usuario* usuarios, int limite_pub, int limite_user, int idPublicacion);

int publicacion_altaForzada(int idUsuario, Publicacion* array,int limite,char* nombrePublicacion, float precio, int stock, int cantVend);

#endif // PUBLICACION_H_INCLUDED



