#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED
typedef struct
{
    char descripcionProducto[50];
    int codigoProveedor;//id
    int isEmpty;
}Proveedores;
int proveedores_init(Proveedores* arrayProveedores,int limiteProveedores);
int proveedores_buscarPorCodigoProveedor(Proveedores* arrayProveedores, int limiteProveedores, int codigoProveedor);

int proveedores_mostrar(Proveedores* arrayProveedores,int limiteProveedores);
int proveedores_mostrarDebug(Proveedores* arrayProveedores,int limiteProveedores);
int proveedores_alta(Proveedores* arrayProveedores,int limiteProveedores);
int proveedores_baja(Proveedores* arrayProveedores,int limiteProveedores, int id);
//int proveedores_modificacion(Proveedores* arrayProveedores,int limiteProveedores, int id);
//int proveedores_ordenarChar(Proveedores* arrayProveedores,int limiteProveedores, int orden);
//int proveedores_ordenarNumericamente(Proveedores* arrayProveedores,int limiteProveedores, int orden);
int proveedores_altaForzada(Proveedores* arrayProveedores,int limiteProveedores,char* descripcionProductos, int codigoProveedor);
#endif // PROVEEDORES_H_INCLUDED



