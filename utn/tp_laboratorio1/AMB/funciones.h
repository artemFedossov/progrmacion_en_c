#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

void inicializarArray(EPersona *,int,int);
void ordenar(EPersona [],int);
void grafico(EPersona [],int);

#endif
