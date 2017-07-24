#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "menu.h"
#include "abm.h"
#include "validacionIngreso.h"

#define CANTIDAD 5
#define CANTIDAD_LLAMADAS 10

int main()
{
    char opcion[11];
    char *ptrOpcion;
    ptrOpcion = &opcion[0];
    int *ptrIndice;
    int flag = 0;
    int *ptrFlag;
    ptrFlag = &flag;

    int i;

    EAbonado array[CANTIDAD];
    ELlamada arrayLlamada[CANTIDAD_LLAMADAS];

    inicializarArray(array,CANTIDAD,-1);
    inicializarArrayLlamada(arrayLlamada,CANTIDAD_LLAMADAS,0);

    char nombre[5][51] = {"Luis","Tamara","Juan","Franco","Sara"};
    char apellido[5][51] = {"Gimenez","Fernandez","Barros","Samuel","Rolon"};
    int numero[5] = {2,5,6,1,5};

    for(i=0;i<CANTIDAD;i++)
    {
        strcpy(array[i].nombre,nombre[i]);
        strcpy(array[i].apellido,apellido[i]);
        array[i].numero = numero[i];
        array[i].id = i+1;
    }

    do{
        menu(ptrOpcion,ptrFlag);

        switch(*ptrOpcion)
        {
            case '1':
                system("cls");
                altas(array,CANTIDAD);
                break;

            case '2':
                system("cls");
                modificar(array,CANTIDAD);
                break;

            case '3':
                system("cls");
                baja(array,CANTIDAD);
                break;

            case '4':
                system("cls");
                nuevaLlamada(array,CANTIDAD,arrayLlamada,CANTIDAD_LLAMADAS,ptrFlag);
                break;

            case '5':
                system("cls");
                finLlamada(array,CANTIDAD,arrayLlamada,CANTIDAD_LLAMADAS,ptrFlag);
                break;

            case '6':

                for(i=0; i<CANTIDAD; i++)
                {
                    if(array[i].id != -1)
                    printf("Nombre %s\nApellido %s\nNumero %d\nid %d\nmotivo %d\n\n",array[i].nombre,array[i].apellido,array[i].numero,array[i].id,arrayLlamada[i].TresG);
                }
        }

    }while(*ptrOpcion != '7');

    return 0;
}
