#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "amb.h"
#include "menu.h"
#include "ingresoValidacion.h"

int menu(int *flag)
{
    char opcion[11];
    char *ptrOpcion;
    int cantCarracteres, retorno;
    ptrOpcion = &opcion[0];

    if(*flag != 1)
    {
        printf("\n\tTELEFONIA MOVIL\n\n");

        printf("1) Alta del Abonado\n2) Modificar datos del abonado\n3) Baja del abonado\n4) Nueva LLamada\n5) Fin de llamada\n6) Informar\n7) Salir\n\nOpcion: ");
        scanf("%s",ptrOpcion);
        cantCarracteres = strlen(ptrOpcion);

        validarMenu(ptrOpcion,'1','7',cantCarracteres);
    }
    else
    {
        printf("5) Fin de llamada\nOpcion: ");
        scanf("%s",ptrOpcion);
        cantCarracteres = strlen(ptrOpcion);

        validarMenu(ptrOpcion,'5','5',cantCarracteres);
    }

    retorno = atoi(ptrOpcion);

    return retorno;
}

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
