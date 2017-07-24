#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "menu.h"
#include "amb.h"
#include "ingresoValidacion.h"

/** \brief inicializa con un valor el array
 *
 * \param array: es el array en donde se inicializa
 * \param hasta: el largo del array
 * \param inicializa: contiene el valor con el cual sera inicializado el array
 * \return void
 *
 */

void inicializarArray(EPersona *array,int hasta,int inicializa)
{
    int i;

    for(i=0; i<hasta; i++)
    {
        array[i].estado = inicializa;
    }
}


/** \brief funcion que ordena un array
 *
 * \param array: es el array en donde se van a ordenar los datos
 * \param  hasta: el largo del array
 * \return void
 *
 */

void ordenar(EPersona array[],int hasta)
{
    int i, j, elementos;
    EPersona aux;

    elementos = buscarElementos(array,hasta);
    if(elementos == 1)
    {
        for(i=0; i<hasta-1; i++)
        {
            if(array[i].estado == 0)
            {
                continue;
            }
            for(j=i+1; j < hasta; j++)
            {
                if(array[j].estado == 0)
                {
                    continue;
                }
                if(stricmp(array[i].nombre,array[j].nombre) > 0)
                {
                    aux = array[j];
                    array[j] = array[i];
                    array[i] = aux;
                }
            }
        }

        for(i=0; i<hasta; i++)
        {
            if(array[i].estado == 1)
            {
                printf("Nombre %s\tEdad %d\tDNI %d\n",array[i].nombre,array[i].edad,array[i].dni);
            }
        }
    }
    else
    {
        printf("no hay datos cargados\n");
    }
    printf("\n");
    system("pause");
}


/** \brief funcion que crea un grafico de edades
 *
 * \param array: es en donde se buscan los datos de la edad
 * \param hasta: el largo del array
 * \return void
 *
 */

void grafico(EPersona array[],int hasta)
{
    int contMayor=0;
    int contMedio=0;
    int contMenor=0;
    int i, mayor;
    int hasta18;
    int de19a35;
    int mayorDe35;
    int flag=0;

    for(i=0; i<hasta; i++)
    {
        if(array[i].estado == 1)
        {
            if(array[i].edad<=18)
            {
                contMenor=contMenor+1;
            }
            else
            {
                if(array[i].edad>=35)
                {
                    contMayor=contMayor+1;
                }
                else
                {
                    contMedio=contMedio+1;
                }
            }
        }

    }

    hasta18 = contMenor;
    de19a35 = contMedio;
    mayorDe35 = contMayor;

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
        {
            printf("%02d|",i);
        }
        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }

            if(flag==1)
            {
                printf("\t*");
            }
        }

        printf("\n");
    }
    printf("--+-----------------\n  |<18\t19-35\t>35\n\n");
    system("pause");
}
