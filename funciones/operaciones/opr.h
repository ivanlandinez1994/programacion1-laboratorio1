#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#endif // LIB_H_INCLUDED

int sumaNumeros (int numero1, int numero2, float* resultadoSuma);
int restaNumeros(int numero1, int numero2, float* resultadoResta);
int divisionNumeros(int numero1, int numero2, float* resultadoDivision);
int multiplicacionNumeros(int numero1, int numero2, float*resultadoMultiplicacion);
int factorialNumero1(int numero1, float* resultadoFactorial);
int getInt(int* resultado, char*mensaje, char*mensajeError, int maximo, int minimo, int reintentos);
int getFloat(float *resultado, char* mensaje, char* mensajeError, float maximo, float minimo, int reintentos);
int getChar(char *resultado, char* mensaje, char* mensajeError, char maximo, char minimo, int reintentos);
float getCalcularPromedio(int valores[], int cantidad, float *promedio);
int getValorMaximo(int valores[], int cantidad, int* maximo);
int getValorMinimo(int valores[], int cantidad, int* minimo);
