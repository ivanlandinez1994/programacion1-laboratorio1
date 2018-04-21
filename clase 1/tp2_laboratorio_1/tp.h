typedef struct
{
    char nombre[50];
    int edad;
    int flagEstadoVacio;
}EPersonas;
int cargarDatosPersonas(EPersonas* arrayPersonas, int sizeArray);
int validarString(char auxiliar[]);
int borrarDatosPersonas(EPersonas* arrayPersonas, int sizeArray);
int sort_ordenarArrayNombreEdad(EPersonas* arrayPersonas, int sizeArray, int flagOrden);
int sort_mostrarArrayOrdenadoNombreEdad(EPersonas* arrayPersonas, int sizeArray);

