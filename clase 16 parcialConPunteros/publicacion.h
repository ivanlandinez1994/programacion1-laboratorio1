#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    int idCliente;
    int numeroRubro;
    char textoAviso[50];
    int idPublicacion;
    int estado;//1 - activo  0 - pausado - 2 no existe
    int isEmpty;
}Publicacion;

Publicacion* publicacion_new();
void publicacion_delete(Publicacion* this);
int publicacion_setNumeroRubro(Publicacion* this, int numeroRubro);
int publicacion_getNumeroRubro(Publicacion* this, int* numeroRubro);

#endif // PUBLICACION_H_INCLUDED
