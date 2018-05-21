#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
{
    char nombreCliente[50];
    char apellidoCliente[50];
    float cuit;
    int idCliente;
    int isEmpty;
}Cliente;

Cliente* cliente_new();
void cliente_delete(Cliente* this);
int cliente_setNombre(Cliente* this, char* nombre);
int cliente_getNombre(Cliente* this, char* nombre);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_getApellido(Cliente* this, char* apellido);
int cliente_setCuit(Cliente* this, float cuit);
int cliente_getCuit(Cliente* this, float* cuit);

#endif // CLIENTES_H_INCLUDED
