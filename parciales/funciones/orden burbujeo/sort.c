#include <stdio.h>
#include <stdlib.h>
int swapInt(int* primerNumero, int* segundoNumero);

/** \brief ordenamiento del array
 *
 * \param puntero que refiere al array
 * \param cantidad de elementos del array
 * \param (1) para ordenar de mayor a menor (0) menor a mayor
 * \return (-1) error (0) ok
 *
 */
int sort_ordenarArrayInt(int* array, int cantidad, int flagOrden){
    int retorno=-1;
    int flagSwap;
    int i;
    if(cantidad>0){
        retorno=0;
        do{
            flagSwap=0;
            for(i=0; i<cantidad-1; i++){
                if((array[i]<array[i+1] && flagOrden) || (array[i]>array[i+1] && !flagOrden)){
                    swapInt(&array[i], &array[i+1]);
                    flagSwap=1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}
/** \brief muestra los elementos del array
 *
 * \param puntero que refiere al array
 * \param cantidad de elementos del array
 * \return (-1) error (0) ok
 */
int sort_mostrarArrayEnteros(int* array, int cantidad){
    int retorno=-1;
    int i;
    if(cantidad>0){
        retorno=0;
        for (i=0; i<cantidad; i++){
            printf("\n%d", array[i]);
        }
    }
    return retorno;
}
/** \brief swamp de numero en la posicion 1 y numero en la posicion 2
 *
 * \param toma de primer numero
 * \param segundoNumero int*
 * \return void
 *
 */
int swapInt(int* primerNumero, int* segundoNumero){
    int auxiliar;
        auxiliar=*primerNumero;
        *primerNumero=*segundoNumero;
        *segundoNumero=auxiliar;
    return 0;
}
