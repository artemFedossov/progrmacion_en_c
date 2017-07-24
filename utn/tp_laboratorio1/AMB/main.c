/*
Hacer un programa que defina un array de 20 �tems de esta estructura y con un men�
como el siguiente:
1. Agregar una persona
2. Borrar una persona
3. Imprimir lista ordenada por nombre
4. Imprimir gr�fico de edades
Se utilizar� el campo de estado para indicar si el �tem del array esta ocupado o no.
El gr�fico deber� ser un gr�fico de barras en donde se agrupar�n 3 barras:
� Menores de 18
� De 19 a 35
� Mayores de 35.
En el eje Y se marcar�n la cantidad de personas en el grupo, y en el eje X el grupo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "menu.h"
#include "amb.h"
#include "ingresoValidacion.h"

#define CANTIDAD 5

int main()
{
    char seguir='s';
    char opcion[11];
    char *ptrOpcion;
    EPersona array[CANTIDAD];
    ptrOpcion = &opcion[0];

    inicializarArray(array,CANTIDAD,0);

    do
    {
        system("cls");
        menu(ptrOpcion);

        switch(*ptrOpcion)
        {
            case '1':
                system("cls");
                altas(array,CANTIDAD);
                break;
            case '2':
                system("cls");
                baja(array,CANTIDAD);
                break;
            case '3':
                system("cls");
                ordenar(array,CANTIDAD);
                break;
            case '4':
                system("cls");
                grafico(array,CANTIDAD);
                break;
            case '5':
                seguir = 'n';
                break;
        }

    }while(seguir == 's');

    return 0;
}
