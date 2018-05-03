#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "contratacion.h"
#include "utn.h"
#include "pantalla.h"
#include "informes.h"

int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas, float cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].cuit==cuit)
            {
                indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                printf("\n\nCuit: %f - Unitario: %.2f - Total: %.2f - Dias: %d\n",
                                    arrayC[i].cuit,
                                    pantallas[indexPantalla].precio,
                                    (arrayC[i].dias * pantallas[indexPantalla].precio),
                                    arrayC[i].dias );
            }
        }

        retorno = 0;
    }
    return retorno;
}
int informar_ListarContrataciones(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    printf("\nCuit: %f - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias);
                }


        }

        retorno = 0;
    }
    return retorno;
}
