#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

int main()
{
    Cliente* arrayClientePunteros[50];
    Cliente* auxCliente;
    int i;
    float auxCuit;


    for(i=0;i<50;i++)
    {
        auxCliente = cliente_new();
        cliente_setCuit(auxCliente, i);
        arrayClientePunteros[i]=auxCliente;
    }
    for(i=0;i<50;i++)
    {
        cliente_getCuit(arrayClientePunteros[i],&auxCuit);
        printf("Mem: %p - Cuit: %.0f\n",arrayClientePunteros[i],auxCuit);
    }
}
