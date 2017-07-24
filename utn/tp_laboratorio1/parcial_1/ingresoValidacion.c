#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "menu.h"
#include "amb.h"
#include "ingresoValidacion.h"

/** \brief funcion que pide el ingreso solamente alfabetico
 *
 * \param buffer: en donde se cargaran los datos
 * \param mensaje: el mensaje que se mostrara por pantalla
 * \return void
 *
 */

void ingresoAlfabetico(char buffer[], char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,100,stdin);

    validarAlfabetico(buffer);
}

/** \brief funcion que valida que el dato solo contenga letras
 *
 * \param validar: el dato que va ser analizado
 * \return void
 *
 */

void validarAlfabetico(char validar[])
{
    int i = 0;
    while(validar[i] != '\n')
    {
        if((validar[i] < 'a' || validar[i] > 'z') && (validar[i] < 'A' || validar[i] > 'Z') && (validar[i] != ' '))
        {
            printf("Error: Reingrese: ");
            fflush(stdin);
            fgets(validar,100,stdin);
            i=0;
            continue;
        }
        i++;
    }
    i=0;
    while(validar[i] != '\n')
    {
        if(i == 0)
        {
            validar[i] = toupper(validar[i]);
        }
        else
        {
            if(validar[i] == ' ')
            {
                i++;
                validar[i] = toupper(validar[i]);
            }
            else
            {
                validar[i] = tolower(validar[i]);
            }
        }

        i++;
    }
}

void ingresoEntero(char buffer[],char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,100,stdin);

    validarEntero(buffer);
}

void validarEntero(char validar[])
{
    int i=0, flag = 0;

    while(validar[i] != '\n')
    {
        if((validar[i] < '0' || validar[i] > '9') && (validar[i] != '-'))
        {
            printf("Error: reingrese: ");
            fflush(stdin);
            fgets(validar,100,stdin);
            i=0;
            continue;
        }
        i++;
    }

}

void ingresoFlotante(char buffer[],char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,100,stdin);

    validarFlotante(buffer);
}

void validarFlotante(char validar[])
{
    int i = 0;

    while(validar[i] != '\n')
    {
        if((validar[i] != '.') && (validar[i]<'0' || validar[i]>'9'))
        {
            printf("ERROR: reingrese: ");
            fflush(stdin);
            fgets(validar,100,stdin);
            i=0;
            continue;
        }
        i++;
    }
}
