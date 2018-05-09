#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "proveedores.h"
#include "productos.h"
#include "utn.h"
#define SIZEPROVEEDORES 2
#define SIZEPRODUCTOS 4

int main()
{
    Proveedores arrayProveedores[SIZEPROVEEDORES];
    Productos arrayProductos[SIZEPRODUCTOS];

    int menu;
    int auxCodigoProducto;
    float totalImportes;
    int totalProductos;
    float promedioImportes;

    proveedores_init(arrayProveedores,SIZEPROVEEDORES);
    productos_init(arrayProductos, SIZEPRODUCTOS);

    proveedores_altaForzada(arrayProveedores,SIZEPROVEEDORES,"televisor samsung 23pg",233);
    proveedores_altaForzada(arrayProveedores,SIZEPROVEEDORES,"mouses scorpion",155);

    productos_altaForzada(arrayProductos,SIZEPRODUCTOS,arrayProveedores,SIZEPROVEEDORES,"televisor samsung",233, 2500, 20);
    productos_altaForzada(arrayProductos,SIZEPRODUCTOS,arrayProveedores,SIZEPROVEEDORES,"douse scorpion",233, 500, 5);
    productos_altaForzada(arrayProductos,SIZEPRODUCTOS,arrayProveedores,SIZEPROVEEDORES,"computador acer",155, 1400,12);
    productos_altaForzada(arrayProductos,SIZEPRODUCTOS,arrayProveedores,SIZEPROVEEDORES,"aelular sony",233, 1000,16);


    do
    {
        getValidInt("\n1.Alta proveedor\n2.Alta productos\n3.Modificar productos\n4.Baja producto\n5.Informar \n"
                    "6.listar orden por importe y descripcion\n7.LIstar productos\n8.Salir\n","\nNo valida\n",&menu,1,8,1);
        switch(menu)
        {
            case 1:
                proveedores_alta(arrayProveedores,SIZEPROVEEDORES);
                break;
            case 2:
                productos_alta(arrayProductos,SIZEPRODUCTOS,arrayProveedores,SIZEPROVEEDORES);
                break;
            case 3:
                getValidInt("Codigo del producto?","\nNumero invalido\n",&auxCodigoProducto,0,9999999,3);
                productos_modificacion(arrayProductos,SIZEPRODUCTOS,auxCodigoProducto);
                break;
            case 4:
                getValidInt("Codigo del producto?","\nNumero invalido\n",&auxCodigoProducto,0,9999999,3);
                productos_baja(arrayProductos, SIZEPRODUCTOS, auxCodigoProducto);
                break;
            case 5:
                productos_mostrarImportesPromediosStocks(arrayProductos,SIZEPRODUCTOS,&totalImportes,&totalProductos,&promedioImportes);
                break;
            case 6:
                productos_ordenarChar(arrayProductos,SIZEPRODUCTOS);
                productos_mostrar(arrayProductos,SIZEPRODUCTOS);
                productos_ordenarNumericamente(arrayProductos,SIZEPRODUCTOS);
                productos_mostrar(arrayProductos,SIZEPRODUCTOS);
                break;
            case 7:
                //estamos modificando el productos_mostrar para hacer el 5.D del parcial
                break;

        }

    }while(menu != 8);

    return 0;
}
