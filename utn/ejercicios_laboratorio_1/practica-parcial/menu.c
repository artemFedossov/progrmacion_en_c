#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "menu.h"
#include "abm.h"
#include "validacionIngreso.h"


/** \brief funcion que crea un menu
 *
 * \param *opcion: puntero que va gurdar la opcion ingresada por teclado
 * \return void
 *
 */

void menu(char *opcion,int *flag)
{
    int carracteres;

    if(*flag != 1)
    {
        printf("\t\tMENU\n\n1) Altas\n2) Modificaciones\n3) Bajas\n4) Nueva Llamada\n5) Fin LLamada\n6) Informar\n7) salr\n\nOpcion: ");
        scanf("%s",opcion);

        carracteres = strlen(opcion);

        validarMenu(opcion,'1','7',carracteres);
    }
    else
    {
        printf("5) Fin LLamada\nOpcion: ");
        scanf("%s",opcion);

        carracteres = strlen(opcion);

        validarMenu(opcion,'5','5',carracteres);
    }
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
