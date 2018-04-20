#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "est.h"

int main()
{
    EPersona personas[3];
    int i;
    for(i=0;i<3;i++)
    {
        printf("\ningrese nombre\n");
        gets(personas[i].nombre);
        printf("ingrese apellido\n");
        gets(personas[i].apellido);
        printf("ingrese edad\n");
        scanf("%d", &personas[i].edad);
        fflush(stdin);
    }
    for(i=0;i<3;i++)
    {
       printf("\nla persona es: %s %s y tiene %d años\n",personas[i].nombre, personas[i].apellido, personas[i].edad);
    }
    /*EPersona persona1;
    printf("ingrese nombre\n");
    gets(persona1.nombre);
    //strcpy(persona1.apellido,"landinez");
    printf("ingrese apellido\n");
    gets(persona1.apellido);
    printf("ingrese su legajo\n");
    scanf("%d", &persona1.legajo);
    printf("la persona es: %s %s con legajo %d\n",persona1.nombre, persona1.apellido, persona1.legajo);

    persona1.fechaNacimiento.dia=14;
    strcpy(persona1.fechaNacimiento.mes, "diciembre");
    persona1.fechaNacimiento.anio=1994;
    printf("\nfecha de nacimiento %d %s %d", persona1.fechaNacimiento.dia, persona1.fechaNacimiento.mes, persona1.fechaNacimiento.anio);*/
    return 0;
}
