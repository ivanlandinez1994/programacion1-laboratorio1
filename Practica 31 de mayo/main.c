#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "controller.h"

int main()
{
    ArrayList* pArrayClientes = al_newArrayList();

    int opcion;
    do
    {
        printf("\n1. Cargar datos desde data.csv\n");
        printf("2. Listar Clientes\n");
        printf("3. Ordenar por nombre y apellido\n");
        printf("4. Ordenar por mail\n");
        printf("5. Agregar un Cliente\n");
        printf("6. Elimina un Cliente\n");
        printf("7. Modificar Cliente (Nombre, Apellido y Mail)\n");
        printf("8. Listar Clientes\n");
        printf("9. Guardar datos en data.csv (modo texto)\n");
        printf("10. Guardar datos en data.bin (modo binario)\n");
        printf("11. Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                controller_leerArchivoCliente("data.csv",pArrayClientes);
                break;
            case 2:
                controller_mostrarArchivoCliente(pArrayClientes);
                break;
            case 3:
                controller_ordenarNombreApellido(pArrayClientes);
                break;
            case 4:
                controller_ordenarEmail(pArrayClientes);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                controller_guardaArchivoCliente("data2.csv",pArrayClientes);
                break;
            case 10:
                break;
            }
        }while(opcion!=11);
    return 0;
}
