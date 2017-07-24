#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "amb.h"
#include "menu.h"
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


/** \brief funcion que pide el ingreso de enteros
 *
* \param buffer: en donde se cargaran los datos
 * \param mensaje: el mensaje que se mostrara por pantalla
 * \return void
 *
 */

void ingresoEntero(char buffer[],char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,100,stdin);

    validarEdad(buffer);
}


/** \brief funcion que valida la edad
 *
 * \param validar: el dato que sera analizado
 * \return void
 *
 */

void validarEdad(char validar[])
{
    int i=0;

    while(validar[i] != '\n')
    {
        if((validar[i] < '0' || validar[i] > '9') || (validar[0] == '0') || (validar[2] >= '0' && validar[1] >= '2'))
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


/** \brief funcion que pide el ingreso de un dni
 *
 * \param buffer: en donde se cargaran los datos
 * \param mensaje: el mensaje que se mostrara por pantalla
 * \return void
 *
 */

void ingresoDNI(char buffer[], char mensaje[])
{
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,100,stdin);

    validarDNI(buffer);
}


/** \brief funcion que valida un dni
 *
 * \param validar: el dato que sera analizado
 * \return void
 *
 */

void validarDNI(char validar[])
{
    int i=0;
    int carracteres;

    while(validar[i] != '\n')
    {
        carracteres = strlen(validar);

        if((validar[i] < '0' || validar[i] > '9') || (validar[1] == '0' && validar[0] == '0') || (carracteres != 9))
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
