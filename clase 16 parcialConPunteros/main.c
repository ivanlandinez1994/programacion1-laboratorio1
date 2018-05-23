#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "publicacion.h"

int main()
{
    Cliente* arrayClientePunteros[50];
    Cliente* auxCliente;
    Publicacion* arrayPunteroPublicacion[50];
    Publicacion* auxPublicacion;
    int i;
    float auxCuit;
    int auxNumeroRubro;


    for(i=0;i<50;i++)
    {
        auxCliente = cliente_new();
        cliente_setCuit(auxCliente, i);
        arrayClientePunteros[i]=auxCliente;

        auxPublicacion = publicacion_new();
        publicacion_setNumeroRubro(auxPublicacion, i);
        arrayPunteroPublicacion[i]=auxPublicacion;
    }
    for(i=0;i<50;i++)
    {
        cliente_getCuit(arrayClientePunteros[i],&auxCuit);
        printf("Mem: %p - Cuit: %.0f\n",arrayClientePunteros[i],auxCuit);
        publicacion_getNumeroRubro(arrayPunteroPublicacion[i], &auxNumeroRubro);
        printf("Mem: %p - Num rubro: %d\n",arrayPunteroPublicacion[i],auxNumeroRubro);

    }
}
