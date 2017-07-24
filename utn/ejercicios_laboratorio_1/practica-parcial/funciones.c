#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "menu.h"
#include "abm.h"
#include "validacionIngreso.h"

/** \brief inicializa con un valor el array
 *
 * \param array: es el array en donde se inicializa
 * \param hasta: el largo del array
 * \param inicializa: contiene el valor con el cual sera inicializado el array
 * \return void
 *
 */

void inicializarArray(EAbonado array[],int hasta,int inicializa)
{
    int i;

    for(i=0; i<hasta; i++)
    {
        array[i].id = inicializa;
    }
}

void inicializarArrayLlamada(ELlamada array[],int hasta,int inicializa)
{
    int i;

    for(i=0; i<hasta; i++)
    {
        array[i].fallaLTE = inicializa;
        array[i].fallaEquipo = inicializa;
        array[i].TresG = inicializa;

    }
}

void nuevaLlamada(EAbonado array[],int cantidadAbonado,ELlamada arrayLlamada[],int cantidadLlamad,int *flag)
{
    int elementos, buffer, indice, carracteres, motivo;
    char opcion[11];

    elementos = buscarElementos(array,cantidadAbonado);
    if(elementos == 1)
    {
        printf("\nIngrese el ID del abonado: ");
        scanf("%d",&buffer);

        indice = busquedaArray(array,cantidadAbonado,buffer);
        if(indice != -1)
        {
            printf("El abonado es\n%s %s\n",array[indice].nombre,array[indice].apellido);
            printf("\n1) Falla 3G\n2) Falla lte\n3) Falla Equipo\nIngrese el motivo: ");
            fflush(stdin);
            scanf("%s",opcion);
            carracteres = strlen(opcion);
            validarMenu(opcion,'1','3',carracteres);
            motivo = atoi(opcion);

            if(motivo == 1)
            {
                arrayLlamada[indice].TresG ++;
            }
            else
            {
                if(motivo == 2)
                {
                    arrayLlamada[indice].fallaLTE ++;
                }
                else
                {
                    arrayLlamada[indice].fallaEquipo ++;
                }
            }
            arrayLlamada[indice].estado = 1;
            *flag = 1;
        }
        else
        {
            printf("\nEl ID es inexistente\n");
        }
    }
    else
    {
        printf("no hay datos cargados\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

void finLlamada(EAbonado array[],int cantidadAbonado,ELlamada arrayLlamada[],int cantidadLlamad,int *flag)
{
    char buffer[51];
    float tiempo;
    if(*flag == 0)
    {
        printf("No se registra una llamada entrante\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese el tiempo transcurrido: ");
        fflush(stdin);
        gets(buffer);
        validarFloat(buffer);

        tiempo = atof(buffer);

        printf("%.2f",tiempo);
        *flag = 0;
        system("pause");
    }
}
