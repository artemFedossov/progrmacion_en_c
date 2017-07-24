#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "menu.h"
#include "amb.h"
#include "ingresoValidacion.h"


/** \brief funcion que carga datos en un array
 *
 * \param array: es en donde se cargan los datos
 * \param hasta: el largo del array
 * \return void
 *
 */

void altas(EPersona array[],int hasta)
{
    char buffer[100];
    int numero;
    int indice;
    int flag;
    char mensaje[3][51] = {"Ingrese Nombre: ","Ingrese Edad: ","Ingrese DNI: "};
    indice = lugarLibre(array,hasta);
    if(indice != -1)
    {
        ingresoAlfabetico(buffer,mensaje[0]);
        strcpy(array[indice].nombre,buffer);

        ingresoEntero(buffer,mensaje[1]);
        numero = atoi(buffer);
        array[indice].edad = numero;

        do{
            ingresoDNI(buffer,mensaje[2]);
            numero = atoi(buffer);
            flag = existenciaDNI(array,hasta,numero);
            array[indice].dni = numero;
        }while(flag != 0);

        array[indice].estado = 1;
        system("cls");
    }
    else
    {
        printf("No queda mas espacio para seguir ingresando\n\n");
        system("pause");
        system("cls");
    }
}


/** \brief funcion que busca un ligar libre en el array
 *
 * \param array: en donde se busca el espacio vacio
 * \param hasta: el largo del array
 * \return indiceLibre: devuelve el indice libre en donde se cargaran los datos, en caso de no haber espacio devuelve -1
 *
 */

int lugarLibre(EPersona array[],int hasta)
{
    int i;
    int indiceLibre = -1;

    for(i=0; i<hasta; i++)
    {
        if(array[i].estado == 0)
        {
            indiceLibre = i;
            break;
        }
    }

    return indiceLibre;
}


/** \brief funcion que da de baja un dato en un array
 *
 * \param array: en donde se encuentra el dato que sera dado de baja
 * \param hasta: el largo del array
 * \return void
 *
 */

void baja(EPersona array[],int hasta)
{
    int elementos, dni, indice;

    elementos = buscarElementos(array,hasta);
    if(elementos == 1)
    {
        printf("\nIngrese el DNI para dar de baja: ");
        scanf("%d",&dni);

        indice = busquedaDNI(array,hasta,dni);
        if(indice != -1)
        {
            array[indice].estado = 0;
        }
        else
        {
            printf("\nEl DNI es inexistente\n");
        }
    }
    else
    {
        printf("no hay datos cargados\n");
    }
    printf("\n");
    system("pause");
}


/** \brief funcion que busca si hay datos cargado en un array
 *
 * \param array: en donde se busca si hay datos cargados
 * \param hasta: el largo del array
 * \return flag: 1 si hay datos cargados, 0 si esta vacio
 *
 */

int buscarElementos(EPersona array[],int hasta)
{
    int i;
    int flag = 0;

    for(i=0; i<hasta; i++)
    {
        if(array[i].estado == 1)
        {
            flag = 1;
        }
    }
    return flag;
}


/** \brief funcion que busca la igualdad de un dni
 *
 * \param array: en donde esta almacenado el dni
 * \param hasta: el largo del array
 * \param dni: el dni que sera comparado con los que estan en el array
 * \return flag -1 si no existe la igualdad, si no devuelve el indice del dni que esta cargado
 *
 */

int busquedaDNI(EPersona array[],int cantidad, int dni)
{
    int i, flag = -1;
    char opcion[10];

    for(i=0; i<cantidad; i++)
    {
        if(array[i].dni == dni && array[i].estado == 1)
        {
            printf("la persona que fue dada de baja es %s",array[i].nombre);
            flag = i;
        }
    }
    return flag;
}

/** \brief funcion que verefica si ya existe el mismo dni en un array
 *
 * \param array: en donde se busca la igualdad
 * \param hasta: el largo del array
 * \param dni: el dni que va ser comparado con los que tiene el array
 * \return retorno 0 si no se encontra la igualdad, 1 si se encontro la igualdad
 *
 */

int existenciaDNI(EPersona array[],int cantidad,int dni)
{
    int i, retorno = 0;

    for(i=0; i<cantidad; i++)
    {
        if(array[i].dni == dni && array[i].estado == 1)
        {
            retorno = 1;
            printf("Ya existe el mismo DNI\n");
            break;
        }
    }
    return retorno;
}
