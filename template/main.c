#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"
#define SIZEFANTASMA 10

int main()
{
    Fantasma arrayFantasma[SIZEFANTASMA];

    int menu;
    int auxiliarId;

    fantasma_init(arrayFantasma,SIZEFANTASMA);

    fantasma_altaForzada(arrayFantasma,SIZEFANTASMA,"Pedro",123456);
    fantasma_altaForzada(arrayFantasma,SIZEFANTASMA,"Adrian",123456);
    fantasma_altaForzada(arrayFantasma,SIZEFANTASMA,"Walter",123456);
    fantasma_altaForzada(arrayFantasma,SIZEFANTASMA,"Liliana",123456);

    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                fantasma_alta(arrayFantasma,SIZEFANTASMA);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                fantasma_baja(arrayFantasma,SIZEFANTASMA,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                fantasma_modificacion(arrayFantasma,SIZEFANTASMA,auxiliarId);
                break;
            case 4:
                fantasma_mostrar(arrayFantasma,SIZEFANTASMA);
                break;
            case 5:
                fantasma_ordenarChar(arrayFantasma,SIZEFANTASMA,1);
                break;
            case 6:
                fantasma_mostrarDebug(arrayFantasma,SIZEFANTASMA);
                break;
        }

    }while(menu != 9);

    return 0;
}
