#include <stdio.h>
#include <stdlib.h>

int sumar (int x, int y){
    int total;
    total=x+y;
    return total;
}
int restar (int x, int y){
    int total;
    total=x-y;
    return total;
}
int dividir(int x, int y){
    int total;
    total=x/y;
    return total;
}
int multiplicacion(int x, int y){
    int total;
    total=x*y;
    return total;
}
int factorial(int x){
    int total=1;
    int i;
    for (i=1; i<=x; i++){
        total=total*i;
    }
    return total;
}

int main()
{
    int A;
    int B;
    int resultado;
    char seguirOperando='s';
    char operacion;

        do{
            printf("ingrese el primer operando\n");
            scanf("%d",&A);
            printf("usted ingreso %d\n",A);
            printf("ingrese el segundo operando\n");
            scanf("%d",&B);
            printf("usted ingreso %d\n",B);
            printf("ingrese que operacion desea realizar: \n(s) para sumar \n(r) para restar:"
                   "\n(d) para dividir:\n(m) para multiplicar: \n(f)para factorial: \n");
            fflush(stdin);
            scanf("%c",&operacion);

            while(operacion!='s' && operacion!='r' && operacion!='d' && operacion!='m' && operacion!='f'){
                printf("usted no ingreso una operacion valida\n");
                printf("ingrese que operacion desea realizar: \n(s) para sumar \n(r) para restar:"
                       "\n(d) para dividir:\n(m) para multiplicar: \n(f)para factorial: \n");
                fflush(stdin);
                scanf("%c",&operacion);
            }

            switch(operacion){
                case 's':
                    resultado=sumar(A,B);
                    printf("el resultado de la suma es: %d\n",resultado);
                break;
                case 'r':
                    resultado=restar(A, B);
                    printf("el resultado de la resta es: %d\n",resultado);
                break;
                case 'd':
                    resultado=dividir(A, B);
                    printf("el resultado de la division es: %d\n",resultado);
                break;
                case 'm':
                    resultado=multiplicacion(A,B);
                    printf("el resultado de la multiplicacion es: %d\n",resultado);
                break;
                case 'f':
                    resultado=factorial(A);
                    printf("el resultado factorial del primer operando es: %d\n",resultado);
                break;
            }
            printf("desea continuar operando? presione s para continuar y n para salir\n");
            fflush(stdin);
            scanf("%c",&seguirOperando);
        }while(seguirOperando!='n');

    return 0;
}
