#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "amb.h"
#include "menu.h"
#include "ingresoValidacion.h"

void ingresoNombre(char buffer[], char mensaje[], int *indice)
{
    printf(mensaje);
    fflush(stdin);
    gets(buffer);

    validarNombre(buffer);
}

void validarNombre(char validar[])
{
    int i = 0;
    while(validar[i] != '\0')
    {
        if((validar[i] < 'a' || validar[i] > 'z') && (validar[i] < 'A' || validar[i] > 'Z') && (validar[i] != ' '))
        {
            printf("Error: Reingrese: ");
            fflush(stdin);
            gets(validar);
            i=0;
            continue;
        }
        i++;
    }
    i=0;
    while(validar[i] != '\0')
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

void ingresoNumero(char buffer[],char mensaje[],int *indice)
{
    printf(mensaje);
    fflush(stdin);
    gets(buffer);

    validarNumero(buffer);
}

void validarNumero(char validar[])
{
    int i=0;

    while(validar[i] != '\0')
    {
        if(validar[i] < '0' || validar[i] > '9')
        {
            printf("ERROR: reingrese: ");
            fflush(stdin);
            gets(validar);
            i=0;
            continue;
        }
        i++;
    }
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
