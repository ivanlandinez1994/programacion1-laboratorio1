#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
/*int main(){
    int edad;
    if(getInt(&edad,"ingrese la edad","el rango de edad valido es: [1-199]",199,1,2)==0){
        printf("la edad es %d\n",edad);
    }
    else{
        printf("no se sabe la edad");
    }
    return 0;

}*/
/*int main(){
    float precio;
    if(getFloat(&precio,"ingrese el precio\n","el rango de precio valido es: [1-1000000]\n",1000000,1,2)==0){
        printf("el precio es %f\n",precio);
    }
    else{
        printf("no se sabe el precio\n");
    }
    return 0;

}*/
int main(){
    char letra;
    if(getChar(&letra, "Ingrese Opcion [A][B][C]\n", "Solo [A][B][C]\n", 'C', 'A', 2)==0){
        printf("la letra ingresada es: %c\n", letra);
    }
    else{
        printf("la letra ingresada no fue valida\n");
    }
    return 0;
}
