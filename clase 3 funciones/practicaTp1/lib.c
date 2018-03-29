long suma(int primerNumero, int segundoNumero, float* resultadoSuma){// el primer tipo de variable=long lo que devuelve la variable, lo segundo el nombre de la funcion y tercero lo que recibe
    float resultado;
    int retorno=-1;

    resultado=primerNumero+segundoNumero;
    if(resultado<32767){
        *resultadoSuma=resultado;
        retorno=0;
    }
    return retorno;
}

long resta(int primerNumero, int segundoNumero, float* resultadoResta){
    float resultado;
    int retorno=-1;

    resultado=primerNumero-segundoNumero;
    if(resultado<32767){
        *resultadoResta=resultado;
        retorno=0;
    }
    return retorno;
}

float dividir(int primeroNumero, int segundoNumero, float* resultadoDivision){
    float resultado;
    int retorno=-1;
    resultado=(float)primeroNumero/segundoNumero;
    if(segundoNumero>0 && resultado<32767){
        *resultadoDivision=resultado;
        retorno=0;
    }
    return retorno;
}

long multiplicar(int primerNumero, int segundoNumero, float* resultadoMultiplicacion){
    float resultado;
    int retorno=-1;
    resultado=primerNumero*segundoNumero;
    if(resultado<32767){
        *resultadoMultiplicacion=resultado;
        retorno=0;
    }
    return retorno;
}
