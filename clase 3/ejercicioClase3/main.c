#include <stdio.h>
#include <stdlib.h>

int retornoNumero(){
    int n;
    printf("ingrese un numero\n");
    scanf("%d",&n);
    return n;
}
int areaCirculo(int r){
    int area;
    area=3.14*r*r;
    return area;
}

int main()
{
    int numeroMostrar;
    numeroMostrar=retornoNumero();
    printf("el numero ingresado es: %d\n",numeroMostrar);

    int radio;
    int resultado;
    printf("ingrese el radio para calcular el area del circulo\n");
    scanf("%d",&radio);
    resultado=areaCirculo(radio);
    printf("el area del circulo es: %d\n",resultado);

    return 0;
}
