#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, float cuit);

int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);

#endif // INFORMES_H_INCLUDED
