#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

void mostrar(Alumno* array[],int cantidad);
void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual);
int guardarTodo(Alumno* array[],int cantidad);

int main()
{

    Alumno* arrayPunteroAlumnos[4000];
    int qtyActualArrayAlumnos = 0;
    int qtyMaximaArrayAlumnos = 4000;

    cargar(arrayPunteroAlumnos,qtyMaximaArrayAlumnos,&qtyActualArrayAlumnos);
    mostrar(arrayPunteroAlumnos,qtyActualArrayAlumnos);

    arrayAlumno_add(arrayPunteroAlumnos, qtyMaximaArrayAlumnos, &qtyActualArrayAlumnos, "1213", "nuevo","nuevo2","20-215165-2",1.5,-1);

    guardarTodo(arrayPunteroAlumnos, qtyActualArrayAlumnos);
    //modificar(arrayPunteroAlumnos,qtyActualArrayAlumnos);

   // mostrar(arrayPunteroAlumnos,qtyActualArrayAlumnos);
    return 0;
}


void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual)
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    float altura;
    int id;
    int validacionFile;
    FILE* archivo;
    archivo = fopen("data.txt","r");
    if(archivo!=NULL)
    {
        do
        {
            validacionFile=fscanf(archivo,"%d,%[^,],%[^,],%[^,],%f\n",&id,nombre,apellido,cuit,&altura);
            if(validacionFile==5)
                arrayAlumno_add(array, cantidadMaxima, cantidadActual, "1213", nombre,apellido,cuit,altura,id);

        }while(!feof(archivo));
    }
    fclose(archivo);
}

void mostrar(Alumno* array[],int cantidad)
{
    int i;
    char cuit[50];
    float altura;
    char nombre[50];
    char apellido[50];
    int id;
    for(i=0;i<cantidad;i++)
    {
        alumno_getCuit(array[i],cuit);
        alumno_getAltura(array[i],&altura);
        alumno_getId(array[i],&id);
        alumno_getNombre(array[i],nombre);
        alumno_getApellido(array[i],apellido);
        printf("\nCuit:%s - Altura:%f - Nombre: %s - Apellido: %s - Id: %d\n",cuit,altura,nombre,apellido,id);
    }
}

void modificar(Alumno* array[],int cantidad)
{
    int i;
    Alumno* auxiliarAlumno;
    for(i=5;i<10;i++)
    {
        auxiliarAlumno = arrayAlumno_getById(array,cantidad,i);
        if(auxiliarAlumno != NULL)
        {
            alumno_setAltura(auxiliarAlumno,88);
        }
    }
}

int guardarTodo(Alumno* array[],int cantidad)
{
    int retorno=-1;
    int i;
    char cuit[50];
    float altura;
    char nombre[50];
    char apellido[50];
    int id;
    FILE* archivo;
    archivo=fopen("data.txt","w");
    if(archivo!=NULL)
    {
        for(i=0;i<cantidad;i++)
        {
            alumno_getCuit(array[i],cuit);
            alumno_getAltura(array[i],&altura);
            alumno_getId(array[i],&id);
            alumno_getNombre(array[i],nombre);
            alumno_getApellido(array[i],apellido);
            fprintf(archivo,"%d,%s,%s,%s,%f\n",id,nombre,apellido,cuit,altura);
            retorno=0;
        }
    }
    return retorno;
}
