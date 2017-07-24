#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "amb.h"
#include "menu.h"
#include "ingresoValidacion.h"

void altas(EAbonados array[],int cantidad, int *indice)
{
    char buffer[1000];
    int numero;
    char mensaje[3][51] = {"Ingrese Nombre: ","Ingrese Apellido: ","Ingrese el numero del abonado: "};
    *indice = lugarLibre(array,cantidad);
    if(*indice != -1)
    {
        array[*indice].id = *indice + 1;
        ingresoNombre(buffer,mensaje[0],indice);
        strcpy(array[*indice].nombre,buffer);

        ingresoNombre(buffer,mensaje[1],indice);
        strcpy(array[*indice].apellido,buffer);

        ingresoNumero(buffer,mensaje[2],indice);
        numero = atoi(buffer);
        numero = coicidencia(array,numero,cantidad);
        array[*indice].numero = numero;
        system("cls");
    }
    else
    {
        printf("No queda mas espacio para seguir ingresando\n\n");
        system("pause");
    }
}

int lugarLibre(EAbonados array[],int cantidad)
{
    int i;
    int indiceLibre = -1;

    for(i=0; i<cantidad; i++)
    {
        if(array[i].numero == -1 && array[i].id == -1)
        {
            indiceLibre = i;
            break;
        }
    }

    return indiceLibre;
}

void modificar(EAbonados array[],int cantidad,int *indice)
{
    int elementos, id;
    char buffer[1000];
    int numero;
    char mensaje[2][51] = {"Ingrese Nombre: ","Ingrese Apellido: "};

    elementos = buscarElementos(array,cantidad);
    if(elementos == 1)
    {
        printf("\nIngrese el ID del abonado para modificar los datos: ");
        scanf("%d",&id);

        *indice = busquedaId(array,cantidad,id);
        if(*indice != -1)
        {
            ingresoNombre(buffer,mensaje[0],indice);
            strcpy(array[*indice].nombre,buffer);

            ingresoNombre(buffer,mensaje[1],indice);
            strcpy(array[*indice].apellido,buffer);

            system("cls");
        }
        else
        {
            printf("\nEl ID es inexistente\n\n");
            system("pause");
        }
    }
    else
    {
        printf("no hay datos cargados\n\n");
        system("pause");
    }
}

int buscarElementos(EAbonados array[],int cantidad)
{
    int i;
    int cont = 0;
    int flag = 1;

    for(i=0; i<cantidad; i++)
    {
        if(array[i].id == -1)
        {
            cont ++;
            if(cont == cantidad)
            {
                flag = 0;
            }

        }
    }
    return flag;
}

int busquedaId(EAbonados array[],int cantidad, int id)
{
    int i, flag = -1;

    for(i=0; i<cantidad; i++)
    {
        if(array[i].id == id && array[i].numero != -1)
        {
            flag = i;
        }
    }
    return flag;
}

void baja(EAbonados array[],int cantidad,int *indice)
{
    int elementos, id;

    elementos = buscarElementos(array,cantidad);
    if(elementos == 1)
    {
        printf("\nIngrese el ID del abonado para dar de baja: ");
        scanf("%d",&id);

        *indice = busquedaId(array,cantidad,id);
        if(*indice != -1)
        {
            array[*indice].numero = -1;
        }
        else
        {
            printf("\nEl ID es inexistente\n\n");
            system("pause");
        }
    }
    else
    {
        printf("no hay datos cargados\n\n");
        system("pause");
    }
}

int coicidencia(EAbonados array[],int numero,int cantidad)
{
    int i;
    char buffer[51];

    for(i=0; i<cantidad; )
    {
        if(array[i].numero == numero)
        {
            printf("El numero de abonado ya exsiste: reingrese: ");
            fflush(stdin);
            gets(buffer);
            validarNumero(buffer);
            numero = atoi(buffer);
            i=0;
            continue;
        }
        i++;
    }

    return numero;
}
