#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "menu.h"
#include "abm.h"
#include "validacionIngreso.h"

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

    validarEntero(buffer);
}

void validarEntero(char validar[])
{
    int i=0, flag = 0;

    do{

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

    if(numero < 1)
    {
        printf("Numero fuera de rango\nReingrese: ");
        fflush(stdin);
        fgets(validar,100,stdin);
        retorno = 1;
    }

    return retorno;
}

void validarFloat(char validacion[])
{
    int i = 0;

    while(validacion[i] != '\0')
    {
        if((validacion[i] != '.') && (validacion[i]<'0' || validacion[i]>'9'))
        {
            printf("ERROR: reingrese: ");
            fflush(stdin);
            gets(validacion);
            i=0;
            continue;
        }
        i++;
    }
}
