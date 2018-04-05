long sumaNumeros (int numero1, int numero2, float* resultadoSuma){
    long long resultado;
    int retorno=-1;
    resultado= numero1 + numero2;
    if(resultado<32767){
        *resultadoSuma=(float)resultado;
        retorno=0;
    }
    return retorno;
}

long restaNumeros(int numero1, int numero2, float* resultadoResta){
    long long resultado;
    int retorno=-1;
    resultado=numero1 - numero2;
    if(resultado<32767){
        *resultadoResta=(float)resultado;
        retorno=0;
    }
    return retorno;
}

long divisionNumeros(int numero1, int numero2, float* resultadoDivision){
    float resultado;
    int retorno=-1;
    resultado=(float)numero1 / numero2;
    if((numero2<0 || numero2>0) && resultado<32767){
        *resultadoDivision=resultado;
        retorno=0;
    }
    return retorno;
}

long multiplicacionNumeros(int numero1, int numero2, float*resultadoMultiplicacion){
    long long resultado;
    int retorno=-1;
    resultado=numero1 * numero2;
    if(resultado<32767){
        *resultadoMultiplicacion=(float)resultado;
        retorno=0;
    }
    return retorno;
}
long factorialNumero1(int numero1, float* resultadoFactorial){
    long long resultado=numero1;
    int retorno=-1;
    while(numero1>1){
        numero1--;
        resultado=numero1*resultado;
    }
    if(resultado<3276700){
        *resultadoFactorial=resultado;
        retorno=0;
    }
    return retorno;
}
