#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "menu.h"
#include "abm.h"
#include "validacionIngreso.h"


/** \brief funcion que carga datos en un array
 *
 * \param array: es en donde se cargan los datos
 * \param hasta: el largo del array
 * \return void
 *
 */

void altas(EAbonado array[],int hasta)
{
    char buffer[100];
    int numero;
    int indice;
    int flag = 0;
    char mensaje[3][51] = {"Ingrese Nombre: ","Ingrese Apellido: ","Ingrese Numero: "};
    indice = lugarLibre(array,hasta);
    if(indice != -1)
    {
        ingresoAlfabetico(buffer,mensaje[0]);
        strcpy(array[indice].nombre,buffer);

        ingresoAlfabetico(buffer,mensaje[1]);
        strcpy(array[indice].apellido,buffer);

        ingresoEntero(buffer,mensaje[2]);
        numero = atoi(buffer);
        array[indice].numero = numero;

        array[indice].id = indice+1;

    }
    else
    {
        printf("No queda mas espacio para seguir ingresando\n\n");
        system("pause");
    }

    system("cls");
}


/** \brief funcion que busca un ligar libre en el array
 *
 * \param array: en donde se busca el espacio vacio
 * \param hasta: el largo del array
 * \return indiceLibre: devuelve el indice libre en donde se cargaran los datos, en caso de no haber espacio devuelve -1
 *
 */

int lugarLibre(EAbonado array[],int hasta)
{
    int i;
    int indiceLibre = -1;

    for(i=0; i<hasta; i++)
    {
        if(array[i].id == -1)
        {
            indiceLibre = i;
            break;
        }
    }

    return indiceLibre;
}

void modificar(EAbonado array[],int hasta)
{
    int elementos, bufferEntero, indice;
    char mensaje[2][51] = {"Ingrese Nombre: ","Ingrese Apellido: "};
    char buffer[100];

    elementos = buscarElementos(array,hasta);
    if(elementos == 1)
    {
        printf("\nIngrese el ID para ser modificado: ");
        scanf("%d",&bufferEntero);

        indice = busquedaArray(array,hasta,bufferEntero);
        if(indice != -1)
        {
            printf("la persona que sera modificada es\n%s %s\n",array[indice].nombre,array[indice].apellido);
            ingresoAlfabetico(buffer,mensaje[0]);
            strcpy(array[indice].nombre,buffer);

            ingresoAlfabetico(buffer,mensaje[1]);
            strcpy(array[indice].apellido,buffer);
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


/** \brief funcion que da de baja un dato en un array
 *
 * \param array: en donde se encuentra el dato que sera dado de baja
 * \param hasta: el largo del array
 * \return void
 *
 */

void baja(EAbonado array[],int hasta)
{
    int elementos, buffer, indice;

    elementos = buscarElementos(array,hasta);
    if(elementos == 1)
    {
        printf("\nIngrese el ID para dar de baja: ");
        scanf("%d",&buffer);

        indice = busquedaArray(array,hasta,buffer);
        if(indice != -1)
        {
            printf("la persona que fue dada de baja es\n%s %s\n",array[indice].nombre,array[indice].apellido);
            array[indice].id = -1;
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


/** \brief funcion que busca si hay datos cargado en un array
 *
 * \param array: en donde se busca si hay datos cargados
 * \param hasta: el largo del array
 * \return flag: 1 si hay datos cargados, 0 si esta vacio
 *
 */

int buscarElementos(EAbonado array[],int hasta)
{
    int i;
    int flag = 0;

    for(i=0; i<hasta; i++)
    {
        if(array[i].id != -1)
        {
            flag = 1;
        }
    }
    return flag;
}


/** \brief funcion que busca la igualdad en un array
 *
 * \param array: en donde esta almacenado el dato
 * \param hasta: el largo del array
 * \param buffer: el dato que sera comparado con los que estan en el array
 * \return flag -1 si no existe la igualdad, si no devuelve el indice del dni que esta cargado
 *
 */

int busquedaArray(EAbonado array[],int hasta, int buffer)
{
    int i, flag = -1;
    char opcion[10];

    for(i=0; i<hasta; i++)
    {
        if(array[i].id == buffer)
        {
            flag = i;
        }
    }
    return flag;
}
