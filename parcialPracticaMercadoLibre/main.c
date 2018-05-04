#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"
#include "publicacion.h"
#include "utn.h"
#define SIZEUSUARIO 5
#define SIZEPUBLICACION 10

int main()
{
    Usuario arrayUsuario[SIZEUSUARIO];
    Publicacion arrayPublicacion[SIZEPUBLICACION];
    usuario_init(arrayUsuario,SIZEUSUARIO);
    publicacion_init(arrayPublicacion,SIZEPUBLICACION);

    /*usuario_altaForzada(arrayUsuario,SIZEUSUARIO,"Wilde","Las Flores 50",50,0);
    usuario_altaForzada(arrayUsuario,SIZEUSUARIO,"Avellaneda","Belgrano 250",2000,0);
    usuario_altaForzada(arrayUsuario,SIZEUSUARIO,"Bernal","Cerrito 300",3000,0);
    usuario_altaForzada(arrayUsuario,SIZEUSUARIO,"Quilmes","Lavalle 450",1000,1);
    usuario_altaForzada(arrayUsuario,SIZEUSUARIO,"Berazategui","Mitre 150",5000,1);

    cont_altaForzada(arrayPublicacion,SIZEPUBLICACION,arrayUsuario,SIZEUSUARIO,0,"video.avi","20911911915",100);
    cont_altaForzada(arrayPublicacion,SIZEPUBLICACION,arrayUsuario,SIZEUSUARIO,0,"video1.avi","20911911915",400);
    cont_altaForzada(arrayPublicacion,SIZEPUBLICACION,arrayUsuario,SIZEUSUARIO,0,"video2.avi","30911911915",300);
    cont_altaForzada(arrayPublicacion,SIZEPUBLICACION,arrayUsuario,SIZEUSUARIO,2,"video3.avi","30911911915",400);
    cont_altaForzada(arrayPublicacion,SIZEPUBLICACION,arrayUsuario,SIZEUSUARIO,2,"video4.avi","40911911915",500);
    cont_altaForzada(arrayPublicacion,SIZEPUBLICACION,arrayUsuario,SIZEUSUARIO,2,"video5.avi","40911911915",600);

    informar_ConsultaFacturacion(arrayPublicacion,SIZEPUBLICACION,arrayUsuario,SIZEUSUARIO,"20911911915");
    informar_ListarContrataciones(arrayPublicacion,SIZEPUBLICACION,arrayUsuario,SIZEUSUARIO);
    */

    int menu;
    int idUsuario;
    int idPublicacion;


    do
    {
        getValidInt("\n1.Alta Usuario\n2.modificar usuario \n3.baja usuario\n4.publicar producto\n5.modificar publicacion"
                    "\n6.cancelar publicion\n7.comprar producto\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                usuario_alta(arrayUsuario, SIZEUSUARIO);
                usuario_mostrar(arrayUsuario, SIZEUSUARIO);
                break;
            case 2:
                getValidInt("id usuario", "error", &idUsuario, 0, 999999999, 2);
                usuario_modificacion(arrayUsuario, SIZEUSUARIO, idUsuario);
                break;
            case 3:
                getValidInt("\nID usuario?","\nNumero valida\n",&idUsuario,0,9999999,2);
                usuario_bajaUsuario(arrayUsuario, SIZEUSUARIO, idUsuario);
                break;
            case 4:
                getValidInt("\nID usuario?","\nNumero valida\n",&idUsuario,0,9999999,2);
                publicacion_alta(arrayPublicacion, SIZEPUBLICACION, idUsuario);
                break;
            case 5:
                getValidInt("\nID usuario?","\nNumero valida\n",&idUsuario,0,9999999,2);
                publicacion_mostrarProductosDeUsuario(arrayPublicacion, SIZEPUBLICACION, idUsuario);
                getValidInt("ID publicacion?","\nNumero valida\n",&idPublicacion,0,9999999,2);
                publicacion_modificacion(arrayPublicacion, SIZEPUBLICACION, idPublicacion);
                break;
            case 6:
                getValidInt("\nID usuario?","\nNumero valida\n",&idUsuario,0,9999999,2);
                publicacion_mostrarProductosDeUsuario(arrayPublicacion, SIZEPUBLICACION, idUsuario);
                getValidInt("ID publicacion?","\nNumero valida\n",&idPublicacion,0,9999999,2);
                publicacion_baja(arrayPublicacion, SIZEPUBLICACION, idPublicacion);
                break;
            case 7:
                getValidInt("\nID usuario?","\nNumero valida\n",&idUsuario,0,9999999,2);
                //publicacion_comprarProductos(arrayPublicacion, SIZEPUBLICACION, idUsuario);

                break;
        }

    }while(menu != 9);

    return 0;
}
