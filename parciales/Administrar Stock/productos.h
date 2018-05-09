#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
typedef struct
{
    char descripcionProducto[50];
    int codigoProveedor;
    int codigoProducto;
    float importe;
    int cantidad;
    int isEmpty;
}Productos;
int productos_init(Productos* arrayProductos,int limiteProductos);
int productos_buscarPorCodigoProducto(Productos* arrayProductos, int limiteProductos, int codigoProducto);

int productos_mostrar(Productos* arrayProductos,int limiteProductos);
int productos_mostrarImportesPromediosStocks(Productos* arrayProductos,int limiteProductos, float* mainTotalImportes,
                                             int* mainTotalProductos, float* mainPromedioImportes);

int productos_alta(Productos* arrayProductos,int limiteProductos, Proveedores* arrayProveedores, int limiteProveedores);
int productos_baja(Productos* arrayProductos,int limiteProductos, int id);
int productos_modificacion(Productos* arrayProductos,int limiteProductos, int id);
int productos_ordenarChar(Productos* arrayProductos,int limiteProductos);
int productos_ordenarNumericamente(Productos* arrayProductos,int limiteProductos);
int productos_altaForzada(Productos* arrayProductos,int limiteProductos,Proveedores* arrayProveedores, int limiteProveedores,
                          char* descripcionProducto, int codigoProducto, float importe, int cantidad);
#endif // PRODUCTOS_H_INCLUDED



