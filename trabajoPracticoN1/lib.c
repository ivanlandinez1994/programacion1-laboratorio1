int sumaNumeros (int numero1, int numero2, float* resultadoSuma){
    long resultado;
    int retorno=-1;
    resultado= (float)numero1 + numero2;
    if(resultado<=32767 && resultado>=-32767){
        *resultadoSuma=(float)resultado;
        retorno=0;
    }
    return retorno;
}

int restaNumeros(int numero1, int numero2, float* resultadoResta){
    long resultado;
    int retorno=-1;
    resultado=(float)numero1 - numero2;
    if(resultado<=32767 && resultado>=-32768){
        *resultadoResta=(float)resultado;
        retorno=0;
    }
    return retorno;
}

int divisionNumeros(int numero1, int numero2, float* resultadoDivision){
    float resultado;
    int retorno=-1;
    resultado=(float)numero1 / numero2;
    if((numero2<0 || numero2>0) && resultado<=32767 && resultado>=-32768){
        *resultadoDivision=(float)resultado;
        retorno=0;
    }
    else if (numero2==0){
        retorno=-2;
    }
    return retorno;
}

int multiplicacionNumeros(int numero1, int numero2, float*resultadoMultiplicacion){
    long resultado;
    int retorno=-1;
    resultado=(float)numero1 * numero2;
    if(resultado<=32767 && resultado>=-32768){
        *resultadoMultiplicacion=(float)resultado;
        retorno=0;
    }
    return retorno;
}
int factorialNumero1(int numero1, float* resultadoFactorial){
    long resultado=numero1;
    int retorno=-1;
    while(numero1>1){
        numero1--;
        resultado=numero1*resultado;
    }
    if(resultado<=32767 && resultado>=-32768){
        *resultadoFactorial=(float)resultado;
        retorno=0;
    }
    return retorno;
}


