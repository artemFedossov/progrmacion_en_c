/* Desarrollar en ANSI C:
   Una compañía que brinda el servicio de mesa de ayuda a una empresa de telefonía
   móvil requiere una aplicación que permita registrar cada uno de los reclamos
   recibidos de manera telefónica. Cada llamada pertenece a un abonado, tiene un
   motivo, un estado y se insume un tiempo en dar o no con la solución.
   1. ALTA DEL ABONADO: Se da de alta el abonado (ID, NUMERO, NOMBRE y APELLIDO)
   teniendo en cuenta que el ID es auto-incrementable.
   2. MODIFICAR DATOS DEL ABONADO: Se ingresará el ID de abonado, permitiendo
   modificar: NOMBRE y APELLIDO
   3. BAJA DEL ABONADO: Se ingresará el ID de abonado y se marcara a este como
   inhabilitado.
   4. NUEVA LLAMADA: En esta opción se registran los datos (abonado y motivo) indicando
   que el estado es “EN CURSO”
   5. FIN LLAMADA: En esta opción se registran los datos (tiempo insumido) y se indica
   que el estado es “SOLUCIONADO” o “NO SOLUCIONADO”
   6. INFORMAR: ◦ El nombre y apellido del abonado con mas reclamos
   ◦ El reclamo mas realizado
   ◦ El reclamo que en promedio mas demora en ser resuelto
   Nota 0: Tanto los motivos como los estados pueden ser definidos con #defines
   • Motivos (FALLA 3G – FALLA LTE – FALLA EQUIPO)
   • Estados (EN CURSO – SOLUCIONADO” – “NO SOLUCIONADO”)
   Nota 1: Se deberá desarrollar una biblioteca lib.c y lib.h la cual contendrá las funciones (Alta, Baja,
   Modificar, Nueva llamada, Fin de llamada e Informar).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "amb.h"
#include "menu.h"
#include "ingresoValidacion.h"
#define CANTIDAD 3
#define EN_CURSO 1
#define SOLUCIONADO 2
#define NO_SOLUCIONADO 3

int main()
{
    int opcion, i;
    int indice;
    int *ptrIndice;
    int flag = 0;
    int *ptrFlag;
    ptrFlag = &flag;
    EAbonados array[CANTIDAD];
    Ellamadas arrayLlamadas[CANTIDAD];
    inicializarArray(array,CANTIDAD,-1);
    ptrIndice = &indice;

    char motivo[3][51] = {"1) Falla 3G","2) Falla Lte","3) Falla equipo"};

    for(i=0; i<CANTIDAD; i++)
    {
        strcpy(arrayLlamadas[i].motivo,motivo[i]);
        arrayLlamadas[i].contEquipo = 0;
        arrayLlamadas[i].cont3G = 0;
        arrayLlamadas[i].contLte = 0;
    }

    char nombre[3][51] = {"juan","Marcelo","Isabel"};
    char apellido[3][51] = {"Fernandez","Rodriguez","Samuel"};
    int numero[3] = {2,3,4};

    for(i=0; i<CANTIDAD; i++)
    {
        strcpy(array[i].nombre,nombre[i]);
        strcpy(array[i].apellido,apellido[i]);
        array[i].numero = numero[i];
        array[i].id = i+1;
    }

    do{
        system("cls");
        opcion = menu(ptrFlag);

        switch(opcion)
        {
            case 1:
                system("cls");
                altas(array,CANTIDAD,ptrIndice);
                break;
            case 2:
                system("cls");
                modificar(array,CANTIDAD,ptrIndice);
                break;
            case 3:
                system("cls");
                baja(array,CANTIDAD,ptrIndice);
                break;
            case 4:
                system("cls");
                nuevaLLamada(arrayLlamadas,array,CANTIDAD,ptrIndice,EN_CURSO,ptrFlag);
                break;
            case 5:
                system("cls");
                finLlamada(arrayLlamadas,array,CANTIDAD,ptrIndice,ptrFlag);
                break;
            case 6:

                for(i=0;i<CANTIDAD;i++)
                    if(array[i].numero != -1)
                        printf("%s\n%s\n%d\n%d\n%d\n%d\n",array[i].nombre,array[i].apellido,array[i].numero,arrayLlamadas[i].cont3G,arrayLlamadas[i].contLte,arrayLlamadas[i].contEquipo);
               system("pause");
                break;
        }
    }while(opcion != 7);

    return 0;
}
