#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "menu.h"
#include "amb.h"
#include "ingresoValidacion.h"

#define CANTIDAD_USUARIOS 5
#define CANTIDAD_PRODUCTOS 10

int main()
{
    int menuOpcion;
    char opcion[15];
    char *ptrOpcion;
    ptrOpcion = &opcion;

    EUsuario arrayUsuario[CANTIDAD_USUARIOS];
    EProductos arrayProducto[CANTIDAD_PRODUCTOS];

    inicializarArray(arrayUsuario,CANTIDAD_USUARIOS,-1);
    inicializarProductos(arrayProducto,CANTIDAD_PRODUCTOS,-1);

    char nombre[5][51] = {"alicia","juan","Pedro","Fran","Tomas"};
    int password[5] = {123,232,312,432,512};
    int id, i;

    for(i=0; i<CANTIDAD_USUARIOS; i++)
    {
        strcpy(arrayUsuario[i].usuario,nombre[i]);
        arrayUsuario[i].password = password[i];
        arrayUsuario[i].id = i+1;
    }

    do{
        menu(ptrOpcion);
        menuOpcion = atoi(ptrOpcion);

        switch(menuOpcion)
        {
            case 1:
                system("cls");
                altas(arrayUsuario,CANTIDAD_USUARIOS);
                break;
            case 2:
                system("cls");
                modificar(arrayUsuario,CANTIDAD_USUARIOS);
                break;
            case 3:
                system("cls");
                baja(arrayUsuario,CANTIDAD_USUARIOS);
                break;
            case 4:
                system("cls");
                publicar(arrayProducto,CANTIDAD_PRODUCTOS,arrayUsuario,CANTIDAD_USUARIOS);
                break;
            case 5:
                system("cls");
                modificarPublicacion(arrayProducto,CANTIDAD_PRODUCTOS,arrayUsuario,CANTIDAD_USUARIOS);
                break;
            case 6:
                system("cls");
                cancelarPublicacion(arrayProducto,CANTIDAD_PRODUCTOS,arrayUsuario,CANTIDAD_USUARIOS);
                break;
            case 8:
                system("cls");
                listarPublicacionUsuario(arrayProducto,CANTIDAD_PRODUCTOS,arrayUsuario,CANTIDAD_USUARIOS);
                break;
            case 9:
                system("cls");
                listarPublicaciones(arrayProducto,CANTIDAD_PRODUCTOS,arrayUsuario,CANTIDAD_USUARIOS);
                break;
        }

    }while(menuOpcion != 11);

    return 0;
}
