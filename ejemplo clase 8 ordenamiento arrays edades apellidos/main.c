#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main()
{
    int arrayEdades[11] = {22,56,55,66,29};
    char arrayNombres[11][50] = {"Juan","Pedro","Jose","Luis","Diego"};
    char arrayApellidos[11][50]={"landinez","lopez","rodriguez","arango","gonzales"};

    sort_mostrarArrayCharYEdadYApellido(arrayNombres,arrayEdades, arrayApellidos, 5, 5, 5);
    sort_ordenarArrayCharyEdadYApellido(arrayNombres, arrayApellidos, arrayEdades, 5,5,5,1);
    printf("\n\n");
    printf("\n\n");
    sort_mostrarArrayCharYEdadYApellido(arrayNombres,arrayEdades, arrayApellidos, 5, 5, 5);

    /*sort_mostrarArrayCharYEdad(arrayNombres, arrayEdades, 5, 5);
    sort_ordenarArrayCharyEdad(arrayNombres, arrayEdades, 5, 5, 1);
    printf("\n\n");
    printf("\n\n");
    sort_mostrarArrayCharYEdad(arrayNombres, arrayEdades, 5, 5);*/

    //sort_mostrarArrayEnteros(arrayEdades,5);
    /*sort_mostrarArrayCadenaCaracteres(arrayNombres,5);
    sort_ordenarArrayChar(arrayNombres, 5, 1);
    printf("\n\n");
    printf("\n\n");
    sort_mostrarArrayCadenaCaracteres(arrayNombres,5);
    printf("\n\n");*/





    /*if(!sort_ordenarArrayEnteros(arrayEdades,5,1))
    {
        sort_mostrarArrayEnteros(arrayEdades,5);
        printf("\n\n");
    }
    else
    {
        printf("ERROR");
    }*/
    return 0;
}
