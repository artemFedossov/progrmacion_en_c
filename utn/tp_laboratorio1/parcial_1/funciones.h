#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

    char usuario[51];
    int password;
    int id;

}EUsuario;

typedef struct{

    char nombre[51];
    float precio;
    int stock;
    int id;
    int ventas;

}EProductos;

void inicializarArray(EUsuario [],int,int);
void publicar(EProductos [],int,EUsuario [],int);
void inicializarProductos(EProductos [],int,int);
void modificarPublicacion(EProductos [],int,EUsuario [],int);
int lugarLibreProd(EProductos [],int);
void cancelarPublicacion(EProductos [],int,EUsuario [],int);
void listarPublicacionUsuario(EProductos [],int,EUsuario [],int);
void listarPublicaciones(EProductos [],int,EUsuario [],int);

#endif
