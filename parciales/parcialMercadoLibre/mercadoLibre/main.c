#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"
#include "utn.h"
#include "publicacion.h"
#define SIZEUSUARIO 4
#define SIZEPUBLICACION 8

int main()
{
    Usuario arrayUsuario[SIZEUSUARIO];
    Publicacion arrayPublicacion[SIZEPUBLICACION];

    int menu;
    int auxiliarIdUsuario;
    int auxiliarIdPublicacion;

    usuario_init(arrayUsuario,SIZEUSUARIO);
    publicacion_init(arrayPublicacion, SIZEPUBLICACION);

    usuario_altaForzada(arrayUsuario,SIZEUSUARIO,"Pedro\n",1);
    usuario_altaForzada(arrayUsuario,SIZEUSUARIO,"Adrian\n",2);
    usuario_altaForzada(arrayUsuario,SIZEUSUARIO,"Walter\n",3);
    usuario_altaForzada(arrayUsuario,SIZEUSUARIO,"Liliana\n",2);

    publicacion_altaForzada(1, arrayPublicacion, SIZEPUBLICACION, "tele", 2.500, 5, 0);
    publicacion_altaForzada(1,arrayPublicacion, SIZEPUBLICACION, "radio", 500, 8, 1);
    publicacion_altaForzada(1,arrayPublicacion, SIZEPUBLICACION, "cel", 1500, 3, 2);
    publicacion_altaForzada(1,arrayPublicacion, SIZEPUBLICACION, "porn", 700, 7, 3);
    publicacion_altaForzada(2,arrayPublicacion, SIZEPUBLICACION, "poaaa", 700, 7, 3);
    publicacion_altaForzada(3,arrayPublicacion, SIZEPUBLICACION, "asdsf", 700, 7, 3);

    do
    {
        getValidInt("\n1.Alta\n2.Baja\n3.Modificar\n4.Publicar producto\n5.Modificar publicacion\n6.Baja publicacion\n7.Comprar producto"
                    "\n8.Listar publicaciones de usuario\n9.Listar publicaciones\n10.Listar usuarios\n11.Salir\n","\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                usuario_alta(arrayUsuario,SIZEUSUARIO);
                break;
            case 2:
                getValidInt("ID usuario?","\nNumero invalido\n",&auxiliarIdUsuario,0,200,2);
                usuario_baja(arrayUsuario,SIZEUSUARIO,auxiliarIdUsuario);
                publicacion_bajaUsuarioYProductos(arrayPublicacion, SIZEPUBLICACION, auxiliarIdUsuario);
                break;
            case 3:
                getValidInt("ID usuario?","\nNumero invalido\n",&auxiliarIdUsuario,0,200,2);
                usuario_modificacion(arrayUsuario,SIZEUSUARIO,auxiliarIdUsuario);
                break;
            case 4:
                getValidInt("ID usuario?","\nNumero invalido\n",&auxiliarIdUsuario,0,200,2);
                publicacion_alta(arrayPublicacion,SIZEPUBLICACION, auxiliarIdUsuario);
                break;
            case 5:
                getValidInt("ID usuario?","\nNumero invalido\n",&auxiliarIdUsuario,0,200,2);
                publicacion_mostrarProductosUsuario(arrayPublicacion,SIZEPUBLICACION, auxiliarIdUsuario);
                getValidInt("ID producto?","\nNumero invalido\n",&auxiliarIdPublicacion,0,200,2);
                publicacion_modificacion(arrayPublicacion, SIZEPUBLICACION, auxiliarIdPublicacion);
                break;
            case 6:
                getValidInt("ID usuario?","\nNumero invalido\n",&auxiliarIdUsuario,0,200,2);
                publicacion_mostrarProductosUsuario(arrayPublicacion,SIZEPUBLICACION, auxiliarIdUsuario);
                getValidInt("ID producto?","\nNumero invalido\n",&auxiliarIdPublicacion,0,200,2);
                publicacion_baja(arrayPublicacion, SIZEPUBLICACION, auxiliarIdPublicacion);
                break;
            case 7:
                getValidInt("ID publicacion?","\nNumero invalido\n",&auxiliarIdPublicacion,0,200,2);
                publicacion_comprar(arrayPublicacion, arrayUsuario, SIZEPUBLICACION, SIZEUSUARIO, auxiliarIdPublicacion);
                break;
            case 8:
                getValidInt("ID usuario?","\nNumero invalido\n",&auxiliarIdUsuario,0,200,2);
                publicacion_mostrarProductosUsuario(arrayPublicacion,SIZEPUBLICACION, auxiliarIdUsuario);
                break;
            case 9:
                publicacion_mostrarPublicaciones(arrayPublicacion, SIZEPUBLICACION, arrayUsuario, SIZEUSUARIO);
                break;
            case 10:
                usuario_mostrar(arrayUsuario, SIZEUSUARIO);
                break;
            case 11:

                break;
        }

    }while(menu != 11);

    return 0;
}
