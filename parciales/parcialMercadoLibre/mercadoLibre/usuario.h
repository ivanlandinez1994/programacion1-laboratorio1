#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
typedef struct
{
    char usuario[50];
    char password[50];
    int idUsuario;
    int isEmpty;
    int calificacionesAcum;
    int cantidadVentas;
}Usuario;
int usuario_init(Usuario* array,int limite);
int usuario_buscarPorId(Usuario* array, int limite, int id);

int usuario_mostrar(Usuario* array,int limite);
int usuario_mostrarDebug(Usuario* array,int limite);
int usuario_alta(Usuario* array,int limite);
int usuario_baja(Usuario* array,int limite, int idUsuario);
int usuario_modificacion(Usuario* array,int limite, int idUsuario);
int usuario_ordenar(Usuario* array,int limite, int orden);
int usuario_altaForzada(Usuario* array,int limite,char* nombre, int idUsuario);
#endif // USUARIO_H_INCLUDED



