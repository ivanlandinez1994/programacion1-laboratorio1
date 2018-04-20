typedef struct
{
    char nombre[50];
    char descripcion[200];
    float precio;
    int flagVacio;
}EProducto;
int cargarDatosProductos(EProducto* array, int subIndice, int sizeArray);
int mostrarDatosProductos(EProducto* array, int subIndice, int sizeArray);
int devolverIndiceVacion(EProducto* arrayProductos, int sizeArray);

