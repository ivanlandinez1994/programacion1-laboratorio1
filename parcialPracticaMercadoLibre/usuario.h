#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char password[50];
    int idUsuario;
    int calificacionAcum;
    int cantidadVentas;
    int isEmpty;
}Usuario;
#endif // Usuario_H_INCLUDED


int usuario_init(Usuario* array,int limite);
int usuario_mostrar(Usuario* array,int limite);
int Usuario_mostrarDebug(Usuario* array,int limite);
int usuario_alta(Usuario* array,int limite);
int usuario_bajaUsuario(Usuario* array,int limite, int idUsuario);
int usuario_modificacion(Usuario* array,int limite, int idUsuario);
int usuario_ordenar(Usuario* array,int limite, int orden);
int usuario_altaForzada(Usuario* array,int limite,char* nombre,char* password);


