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
Cliente* cliente_new(void);
Cliente* cliente_newP(char* nombreCliente, char* apellidoCliente,  float cuit, int idCliente);
void cliente_delete(Cliente* this);
int cliente_setId(Cliente* this, int id);
int cliente_setNewId(Cliente* this);

void arrayACliente_add(Alumno* array[],int cantidadMaxima,int* cantidadActual, char* nombre, char* apellido, float cuit, int id);
void arrayAlumno_remove(Alumno* array[],int cantidadMaxima,int* cantidadActual, int id);

int cliente_getId(Cliente* this, int* cuit);
int cliente_setNombre(Cliente* this, char* nombre);
int cliente_getNombre(Cliente* this, char* nombre);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_getApellido(Cliente* this, char* apellido);
int cliente_setCuit(Cliente* this, float cuit);
int cliente_getCuit(Cliente* this, float* cuit);

Cliente* arrayCliente_getById(Cliente** arrayCliente, int limite, int idCliente);

#endif // CLIENTES_H_INCLUDED
