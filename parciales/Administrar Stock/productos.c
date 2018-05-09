#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "proveedores.h"
#include "productos.h"
#include "utn.h"

static int buscarLugarLibre(Productos* arrayProductos,int limiteProductos);
static int proximoId();

/** \brief inicializa el arrayProductos en vacio
 *
 * \param arrayProductos Productos* el arrayProductos a inicializar
 * \param limiteProductos int el tamaño del arrayProductos
 * \return (0) esta todo inicializado en vacio (-1) no se inicializo
 *
 */
int productos_init(Productos* arrayProductos,int limiteProductos)
{
    int retorno = -1;
    int i;
    if(limiteProductos > 0 && arrayProductos != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteProductos;i++)
        {
            arrayProductos[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief imprime informacion sobre el arrayProductos
 *
 * \param arrayProductos Productos* el arrayProductos a inicializar
 * \param limiteProductos int el tamaño del arrayProductos
 * \return (0) si imprime correctamente todo el arrayProductos (-1) si no se logra imprimir
 *
 */
int productos_mostrarImportesPromediosStocks(Productos* arrayProductos,int limiteProductos, float* mainTotalImportes,
                                             int* mainTotalProductos, float* mainPromedioImportes)
{
    int retorno = -1;
    int i;
    float totalImportes=0;
    int totalProductos=0;
    float promedioImportes;
    int productosSuperanPromedioImportes=0;
    int productosQueNoSuperanPromedioImportes=0;
    int cantidadProductosStockMenor10=0;
    int cantidadProductosStockMayor10=0;
    if(limiteProductos > 0 && arrayProductos != NULL)
    {
        for(i=0; i<limiteProductos; i++)
        {
            totalImportes=arrayProductos[i].importe+totalImportes;
            totalProductos=arrayProductos[i].cantidad+totalProductos;
            *mainTotalImportes = totalImportes;
            *mainTotalProductos = totalProductos;
        }
        promedioImportes=totalImportes/totalProductos;
        *mainPromedioImportes = promedioImportes;
        retorno = 0;
        for(i=0;i<limiteProductos;i++)
        {
            if(arrayProductos[i].importe>promedioImportes)
            {
                productosSuperanPromedioImportes=arrayProductos[i].cantidad+productosSuperanPromedioImportes;
            }
            if(arrayProductos[i].importe<=promedioImportes)
            {
                productosQueNoSuperanPromedioImportes=arrayProductos[i].cantidad+productosQueNoSuperanPromedioImportes;
            }
            if(arrayProductos[i].cantidad<=10)
            {
                cantidadProductosStockMenor10=arrayProductos[i].cantidad+cantidadProductosStockMenor10;
            }
            if(arrayProductos[i].cantidad>10)
            {
                cantidadProductosStockMayor10=arrayProductos[i].cantidad+cantidadProductosStockMayor10;
            }

        }
        printf("(a)Total importes: %.2f\nPromedio importes: %.2f\nCantidad productos que superan el promedio: %d\n\n",
               totalImportes,promedioImportes,productosSuperanPromedioImportes);
        printf("(b)Total importes: %.2f\nPromedio importes: %.2f\nCantidad productos que no superan el promedio: %d\n\n",
               totalImportes,promedioImportes,productosQueNoSuperanPromedioImportes);
        printf("(c)La cantidad de productos cuyo stock es menor o igual a 10: %d\n\n",cantidadProductosStockMenor10);
        printf("(c)La cantidad de productos cuyo stock es mayor a 10: %d\n\n",cantidadProductosStockMayor10);

    }
    return retorno;
}

/** \brief imprime informacion sobre el arrayProductos
 *
 * \param arrayProductos Productos* el arrayProductos a inicializar
 * \param limiteProductos int el tamaño del arrayProductos
 * \return (0) si imprime correctamente todo el arrayProductos (-1) si no se logra imprimir
 *
 */
int productos_mostrar(Productos* arrayProductos,int limiteProductos)
{
    int retorno = -1;
    int i;
    if(limiteProductos > 0 && arrayProductos != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteProductos;i++)
        {
            if(!arrayProductos[i].isEmpty)
            {
                printf("(A) Productos ordenados:\n  Desc produc: %s\nCodigo proveedor: %d\n codigo producto: %d\nImporte: %.2f\n\n",
                    arrayProductos[i].descripcionProducto,arrayProductos[i].codigoProveedor,
                        arrayProductos[i].codigoProducto,arrayProductos[i].importe);
                if(arrayProductos[i].cantidad<=10)
                {
                    printf("(B) Productos que en cantidad son menor, igual a 10:\n  Descripcion producto: %s\nCodigo producto: %d\nCantidad: %d\n\n",arrayProductos[i].descripcionProducto,
                           arrayProductos[i].codigoProducto, arrayProductos[i].cantidad);
                }
                if(arrayProductos[i].cantidad>10)
                {
                    printf("(C) Productos que en cantidad son mayor a 10:\n  Descripcion producto: %s\nCodigo producto: %d\nCantidad: %d\n\n",arrayProductos[i].descripcionProducto,
                           arrayProductos[i].codigoProducto, arrayProductos[i].cantidad);
                }
                //if()
            }
        }
    }
    return retorno;
}

/** \brief alta de los datos a utilizar
 *
 * \param arrayProductos Productos* el arrayProductos a inicializar
 * \param limiteProductos int el tamaño del arrayProductos
 * \return (0) si el alta fue exitosa (-1) si no lo fue
 *
 */
int productos_alta(Productos* arrayProductos,int limiteProductos, Proveedores* arrayProveedores, int limiteProveedores)
{
    int retorno = -1;
    int i;
    int auxCodigoProveedor;
    int indiceADarDeAlta;
    char descripcionProducto[50];
    float importe;
    int cantidad;
    if((limiteProductos > 0 && arrayProductos != NULL)&&(limiteProveedores > 0 && arrayProveedores != NULL))
    {
        i = buscarLugarLibre(arrayProductos,limiteProductos);
        if(i >= 0)
        {
            if(!getValidInt("\nCodigo proveedor? ","\nEso no es un codigo valido",&indiceADarDeAlta,0,99999999,3))
            {
                if(indiceADarDeAlta>=0)
                {
                    auxCodigoProveedor = proveedores_buscarPorCodigoProveedor(arrayProveedores, limiteProveedores, indiceADarDeAlta);
                    if(auxCodigoProveedor>=0)
                    {
                        if(!getValidAlfaNumerico("\ndescripcionProducto? ","\nEso no es una descripcion","El maximo es 50",descripcionProducto,50,3))
                        {
                            if(!getValidFloat("\nImporte producto? ","\nEso no es un improte",&importe,1,99999999,3))
                            {
                                if(!getValidInt("\ncantidad de productos? ","\nEso no es un cantidad valida",&cantidad,1,999,3))
                                {
                                    retorno = 0;
                                    strcpy(arrayProductos[i].descripcionProducto,descripcionProducto);
                                    arrayProductos[i].codigoProducto = proximoId();
                                    arrayProductos[i].codigoProveedor = arrayProveedores[auxCodigoProveedor].codigoProveedor;
                                    arrayProductos[i].importe = importe;
                                    arrayProductos[i].cantidad = cantidad;
                                    arrayProductos[i].isEmpty = 0;
                                    printf("producto dado de alta\nDescripcion producto: %s | Codigo Proveedor: %d | Codigo Producto: %d",
                                           arrayProductos[i].descripcionProducto,arrayProductos[i].codigoProveedor,arrayProductos[i].codigoProducto);
                                }
                            }
                        }
                        else
                        {
                            retorno = -3;//NO SE INGRESO descrip producto
                        }
                    }

                }
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}



/** \brief baja de los datos a utilizar
 *
 * \param arrayProductos Productos* el arrayProductos a dar de baja
 * \param limiteProductos int el tamaño del arrayProductos
 * \param el id del lugar donde se quiere realizar la baja
 * \return (0) si la baja fue exitosa (-1) si no lo fue
 *
 */
int productos_baja(Productos* arrayProductos,int limiteProductos, int codigoProducto)
{
    int retorno = -1;
    int indiceAEliminar;
    indiceAEliminar = productos_buscarPorCodigoProducto(arrayProductos, limiteProductos, codigoProducto);
    if(indiceAEliminar>=0)
    {
        retorno = 0;
        arrayProductos[indiceAEliminar].isEmpty = 1;
    }
    return retorno;
}

/** \brief modificacion de los datos a utilizar
 *
 * \param arrayProductos Productos* el arrayProductos a modificar
 * \param limiteProductos int el tamaño del arrayProductos
 * \param el id del lugar donde se quiere realizar la modificacion
 * \return (0) si la modificacion fue exitosa (-1) si no lo fue (-2) si se ingreso algo que no era un string
 *
 */
int productos_modificacion(Productos* arrayProductos,int limiteProductos, int codigoProducto)
{
    int retorno = -1;
    int indiceAModificar;
    int opcion;
    char descripcionProducto[50];
    float importe;
    int cantidad;
    indiceAModificar = productos_buscarPorCodigoProducto(arrayProductos, limiteProductos, codigoProducto);
    if(indiceAModificar>=0)
    {
        getValidInt("MODIFICAR (1)Descripcion producto (2)Importe (3)Cantidad","opcion invalida",&opcion,1,3,3);
        switch(opcion)
        {
        case 1:
            if(!getValidString("\nDescripcion nueva del producto? ","\nEso no es una descripcion","El maximo es 50 caracteres"
                               ,descripcionProducto,50,3))
            {
                retorno = 0;
                strcpy(arrayProductos[indiceAModificar].descripcionProducto,descripcionProducto);
            }
            break;
        case 2:
            if(!getValidFloat("\nimporte nuevo del producto? ","\nEso no es un importe",&importe,1,99999999,3))
            {
                retorno = 0;
                arrayProductos[indiceAModificar].importe = importe;
            }
            break;
        case 3:
            if(!getValidInt("\nimporte nueva cantidad? ","\nEso no es una cantidad",&cantidad,1,999,3))
            {
                retorno = 0;
                arrayProductos[indiceAModificar].cantidad = cantidad;
            }
            break;
        }
    }
    retorno = 0;
    return retorno;
}
/** \brief ordenamiento de datos de tipo char o string
 *
 * \param arrayProductos Productos* el arrayProductos a ordenar
 * \param limiteProductos int el tamaño del arrayProductos
 * \param orden si es de mayor a menor o menor a mayor
 * \return (0) si el ordenamiento fue exitoso (-1) si no lo fue
 *
 */
int productos_ordenarChar(Productos* arrayProductos,int limiteProductos)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Productos auxiliarEstructura;

    if(limiteProductos > 0 && arrayProductos != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limiteProductos-1;i++)
            {
                if(!arrayProductos[i].isEmpty && !arrayProductos[i+1].isEmpty)
                {
                    if(strcmp(arrayProductos[i].descripcionProducto,arrayProductos[i+1].descripcionProducto) > 0)
                    {
                        auxiliarEstructura = arrayProductos[i];
                        arrayProductos[i] = arrayProductos[i+1];
                        arrayProductos[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
/** \brief ordenamiento de datos de tipo numerico
 *
 * \param arrayProductos Productos* el arrayProductos a ordenar
 * \param limiteProductos int el tamaño del arrayProductos
 * \param orden si es de mayor a menor o menor a mayor
 * \return (0) si el ordenamiento fue exitoso (-1) si no lo fue
 *
 */
int productos_ordenarNumericamente(Productos* arrayProductos,int limiteProductos)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Productos auxiliarEstructura;
    if(limiteProductos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limiteProductos-1;i++)
            {
                if(arrayProductos[i].importe < arrayProductos[i+1].importe)
                {
                    auxiliarEstructura = arrayProductos[i];
                    arrayProductos[i] = arrayProductos[i+1];
                    arrayProductos[i+1] = auxiliarEstructura;
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
/** \brief busca de un lugar libre en el arrayProductos
 *
 * \param arrayProductos Productos* el arrayProductos donde se buscara el lugar libre
 * \param limiteProductos int el tamaño del arrayProductos
 * \return devuelve el lugar libre
 *
 */
int buscarLugarLibre(Productos* arrayProductos,int limiteProductos)
{
    int retorno = -1;
    int i;
    if(limiteProductos > 0 && arrayProductos != NULL)
    {
        for(i=0;i<limiteProductos;i++)
        {
            if(arrayProductos[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief busca dentro del arrayProductos el valor que se le pasa como id
 *
 * \param arrayProductos Productos* el arrayProductos donde se buscara la coincidencia
 * \param limiteProductos int el tamaño del arrayProductos
 * \param el lugar que deseamos encontrar
 * \return devuelve la ubicacion del id
 *
 */
int productos_buscarPorCodigoProducto(Productos* arrayProductos, int limiteProductos, int codigoProducto)
{
    int retorno = -1;
    int i;
    if(limiteProductos > 0 && arrayProductos != NULL)
    {
        retorno = -2;
        for(i=0;i<limiteProductos;i++)
        {
            if(!arrayProductos[i].isEmpty && arrayProductos[i].codigoProducto==codigoProducto)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief genera un id unico
 *
 * \return el id
 *
 */
int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int productos_altaForzada(Productos* arrayProductos,int limiteProductos,Proveedores* arrayProveedores, int limiteProveedores,
                          char* descripcionProducto, int codigoProducto, float importe, int cantidad)
{
    int retorno = -1;
    int i;

    if(limiteProductos > 0 && arrayProductos != NULL)
    {
        i = buscarLugarLibre(arrayProductos,limiteProductos);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayProductos[i].descripcionProducto,descripcionProducto);
            arrayProductos[i].codigoProducto = proximoId();
            arrayProductos[i].importe = importe;
            arrayProductos[i].cantidad = cantidad;
            arrayProductos[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
