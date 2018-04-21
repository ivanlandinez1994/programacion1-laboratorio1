#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "est.h"
#define ARRAY_SYZE 200
int main()
{
    EProducto productos[ARRAY_SYZE];
    char opcion;
    int i;
    int subIndice;
    char continuar='s';
    int ID;
    ID=0;
    for(i=0; i<ARRAY_SYZE; i++)
    {
        productos[i].flagVacio=1;

    }
    do
    {
        printf("elja una opcion (a) cargar producto (b) imprimir lista productos\n");
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
            case 'a':
                system("cls");
                printf("ingrese el indice donde desea ingresar los datos\n");
                fflush(stdin);
                scanf("%d",&subIndice);
                if(productos[subIndice].flagVacio==0)
                {
                    printf("en el indice que eligio ya hay un producto cargado\n");
                }
                else
                {
                    ID++;
                    if(cargarDatosProductos(productos, subIndice, ARRAY_SYZE, ID)==0)
                    {
                        printf("el subindice es valido\n");
                    }
                    else
                    {
                        printf("error\n");
                    }
                }
            break;
            case 'b':
                system("cls");
                for(i=0; i<ARRAY_SYZE; i++)
                {
                    mostrarDatosProductos(productos, i, ARRAY_SYZE);
                    printf("\n");
                    //devolverIndiceVacion(productos, ARRAY_SYZE);
                }
            break;
            default:
                printf("ingrese una opcion valida\n");
            break;
        }
        printf("si desea detenerse escriba (p) de los contrario presione cualquier tecla\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }while(continuar!='p');
    return 0;
}
