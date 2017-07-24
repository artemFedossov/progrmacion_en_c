#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "amb.h"
#include "menu.h"
#include "ingresoValidacion.h"

void inicializarArray(EAbonados array[],int hasta,int inicializa)
{
    int i;

    for(i=0; i<hasta; i++)
    {
        array[i].numero = inicializa;
        array[i].id = inicializa;
    }
}

void nuevaLLamada(Ellamadas arrayLlamadas[],EAbonados array[],int cantidad, int *indice, int enCurso, int *flag)
{
    int elementos, numero, i, carracteres;
    char opcion[10];
    char *ptrOpcion;
    ptrOpcion = &opcion;

    elementos = buscarElementos(array,cantidad);
    if(elementos == 1)
    {
        printf("\nIngrese el numero de abonado: ");
        scanf("%d",&numero);

        *indice = busquedaNumero(array,cantidad,numero);
        if(*indice != -1)
        {
            printf("Ingrese el motivo: \n");
            for(i=0; i<cantidad; i++)
            {
                printf("%s\n",arrayLlamadas[i].motivo);
            }
            printf("Opcion: ");
            scanf("%s",ptrOpcion);
            carracteres = strlen(ptrOpcion);
            validarMenu(ptrOpcion,'1','3',carracteres);

            if(*ptrOpcion == '1')
            {
                arrayLlamadas[*indice].cont3G ++;
                arrayLlamadas[*indice].estado = enCurso;
                printf("RECLAMO EN CURSO\n");
                system("pause");
            }
            else
            {
                if(*ptrOpcion == '2')
                {
                    arrayLlamadas[*indice].contLte ++;
                    arrayLlamadas[*indice].estado = enCurso;
                    printf("RECLAMO EN CURSO\n");
                    system("pause");
                }
                else
                {
                    arrayLlamadas[*indice].contEquipo ++;
                    arrayLlamadas[*indice].estado = enCurso;
                    printf("RECLAMO EN CURSO\n");
                    system("pause");
                }
            }
            *flag = 1;
        }
        else
        {
            printf("\nEl numero de abonado es inexistente\n\n");
            system("pause");
        }
    }
    else
    {
        printf("no hay datos cargados\n\n");
        system("pause");
    }
}

int busquedaNumero(EAbonados array[],int cantidad, int numero)
{
    int i, flag = -1;

    for(i=0; i<cantidad; i++)
    {
        if(array[i].numero == numero)
        {
            flag = i;
        }
    }
    return flag;
}

void finLlamada(Ellamadas arrayLlamadas[],EAbonados array[],int cantidad,int *indice,int *flag)
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
