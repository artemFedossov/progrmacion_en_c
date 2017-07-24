#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "menu.h"
#include "amb.h"
#include "ingresoValidacion.h"

/** \brief funcion que crea un menu
 *
 * \param *opcion: puntero que va gurdar la opcion ingresada por teclado
 * \return void
 *
 */

void menu(char *opcion)
{
    int cantCarracteres;

    printf("\n\tAGENDA\n\n1) Agregar una Persona\n2) Borrar una persona\n3) Imprimir lista ordenado por nombre\n4) Imprimir grafico de edades\n5) Salir\n\nOpcion: ");
    scanf("%s",opcion);
    cantCarracteres = strlen(opcion);

    validarMenu(opcion,'1','5',cantCarracteres);
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
    int i = 0;

    while(validar[i] != '\0')
    {
        if((validar[i] < desde || validar[i] > hasta) || (carracteres != 1))
        {
            printf("ERROR, Reingrese: ");
            fflush(stdin);
            scanf("%s",validar);
            carracteres = strlen(validar);
            continue;
        }
        i++;
    }

}
