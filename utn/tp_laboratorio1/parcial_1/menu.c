#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "menu.h"
#include "amb.h"
#include "IngresoValidacion.h"


/** \brief funcion que crea un menu
 *
 * \param *opcion: puntero que va gurdar la opcion ingresada por teclado
 * \return void
 *
 */

void menu(char *opcion)
{
    int carracteres;

    printf("\t\tMENU\n\n1) Alta Usuario\n2) Modificar Usuario\n3) Baja Usuario\n4) Publicar Producto\n5) Modificar Publicacion\n6) Cancelar Publicacion\n7) Comprar Producto\n8) Listar Publicacion de Usuario\n9) Listar Publicacion\n10) Listar Usuario\n11) salir\n\nOpcion: ");
    fflush(stdin);
    fgets(opcion,100,stdin);

    carracteres = strlen(opcion);

    validarMenu(opcion,'1','11',carracteres);

}


/** \brief funcion que valida la opcion ingresada en el menu
 *
 * \param *validar: puntero que contiene la opcion ingresada por teclado
 * \param desde: Representa el limite del menu, desde que opcion empieza
 * \param hasta: representa el limite del menu, hasta que opcion termina
 * \param carracteres: la cantidad de carracteres que tiene la opccion del menu
 * \return void
 *
 */

void validarMenu(char *validar, char desde,char hasta, int carracteres)
{
    int i = 0, flag = 0;

    do{

        while(validar[i] != '\n')
        {
            if(validar[i] < '0' || validar[i] > '9')
            {
                printf("ERROR, Reingrese: ");
                fflush(stdin);
                fgets(validar,100,stdin);
                carracteres = strlen(validar);
                continue;
            }
            i++;
        }
        i=0;

        flag = rangoEntero(validar);

    }while(flag != 0);

}


/** \brief funcion que valida el rango de un entero
 *
 * \param validar: el dato que sera analizado
 * \return retorno 0 si el numero esta dentro del rango 1 si esta fuera de rango
 *
 */

int rangoEntero(char validar[])
{
    int numero, retorno = 0;

    numero = atoi(validar);

    if(numero < 1 || numero > 11)
    {
        printf("Numero fuera de rango\nReingrese: ");
        fflush(stdin);
        fgets(validar,100,stdin);
        retorno = 1;
    }

    return retorno;
}
