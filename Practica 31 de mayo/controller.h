#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
int controller_leerArchivoCliente(char* path, ArrayList* pArrayList);
int controller_mostrarArchivoCliente(ArrayList* pArrayList);
int controller_ordenarNombreApellido(ArrayList* pArrayList);
int controller_ordenarEmail(ArrayList* pArrayList);
int controller_guardaArchivoCliente(char* path, ArrayList* pArrayList);


#endif // CONTROLLER_H_INCLUDED
