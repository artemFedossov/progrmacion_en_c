#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

    unsigned int id;
    unsigned int numero;
    char nombre[51];
    char apellido[51];

}EAbonados;

typedef struct{

    char motivo[51];
    int estado;
    float tiempo;
    int cont3G;
    int contLte;
    int contEquipo;

}Ellamadas;

void inicializarArray(EAbonados [],int,int);
void nuevaLLamada(Ellamadas [],EAbonados [],int,int *,int, int *);
int busquedaNumero(EAbonados [],int,int);
void finLlamada(Ellamadas [],EAbonados [],int,int *,int *);


#endif
