#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"


/** \brief Muestra el menu con sus opciones;
 *
 * \param void;
 * \return void;
 *
 */

void menu()
{
    char opcion[11];
    char *ptrOpcion;
    float numeroA = 0;
    float numeroB = 0;
    float *ptrNumA;
    float *ptrNumB;
    char mensaje[2][51] = {"1) Ingrese el primer operador ","2) Ingrese el segundo operador "};
    int cantidad;
    int retornoA = 1;
    int retornoB = 1;
    ptrOpcion = &opcion[0];
    ptrNumA = &numeroA;
    ptrNumB = &numeroB;

    do{
        printf("\n\t\tCALCULADORA\n\n%s(A=%.2f)\n%s(B=%.2f)\n",mensaje[0],numeroA,mensaje[1],numeroB);

        if(retornoA == 0)
        {
            printf("3) Calcular el factorial (A!)\n");
        }
        if(retornoA == 0 && retornoB == 0)
        {
            printf("4) Calcular la suma (A+B)\n5) Calcular la resta (A-B)\n6) Calcular la division (A/B)\n7) Calcular la multiplicacion (A*B)\n8) Calcular todas las operaciones\n");
        }
        printf("9) Salir\n");

        printf("Opcion: ");
        fflush(stdin);
        scanf("%s",ptrOpcion);
        cantidad = strlen(ptrOpcion);

        if(*ptrOpcion == '9')
            break;

        if(retornoA == 1 && retornoB == 1)
            validarMenu(ptrOpcion,1,2,cantidad);
        else
        {
            if(retornoA == 1)
                validarMenu(ptrOpcion,1,3,cantidad);
            else
                validarMenu(ptrOpcion,1,8,cantidad);
        }

        switch(*ptrOpcion)
        {
            case '1':
                system("cls");
                retornoA = ingresoFloat(mensaje[0],ptrNumA);
                break;

            case '2':
                system("cls");
                retornoB = ingresoFloat(mensaje[1],ptrNumB);
                break;

            case '3':
                system("cls");
                factorial(ptrNumA);
                break;

            case '4':
                system("cls");
                funcionSuma(ptrNumA,ptrNumB);
                break;

            case '5':
                system("cls");
                funcionResta(ptrNumA,ptrNumB);
                break;

            case '6':
                system("cls");
                funcionDividir(ptrNumA,ptrNumB);
                break;

            case '7':
                system("cls");
                funcionMultiplo(ptrNumA,ptrNumB);
                break;

            case '8':
                system("cls");
                factorial(ptrNumA);
                funcionSuma(ptrNumA,ptrNumB);
                funcionResta(ptrNumA,ptrNumB);
                funcionDividir(ptrNumA,ptrNumB);
                funcionMultiplo(ptrNumA,ptrNumB);
                break;
        }

    }while(*ptrOpcion != 9);

}


/** \brief Valida las opciones del menu;
 *
 * \param *Validar: puntero que contiene la opcion ingresada por el usuario;
 * \param desde: indica el intervalo de la validacion;
 + \param hasta: indica el intervalo de la validacion;
 * \param cantidad: indica la cantidad de caracteres ingresados por el usuario;
 * \return void;
 *
 */

void validarMenu(char *validar,int desde, int hasta,int cantidad)
{
    int i = 0;
    char limite1[3], limite2[3];
    itoa(desde,limite1,10);
    itoa(hasta,limite2,10);

    while(validar[i] != '\0')
    {
        if((validar[i] < limite1[0] || validar[i] > limite2[0]) || (cantidad != 1))
        {
            printf("ERROR: Ingrese una opcion valida: ");
            scanf("%s",validar);
            cantidad = strlen(validar);
            if(validar[i] == '9')
                break;
            continue;
        }
        i++;
    }

}


/** \brief Pide el ingreso de un numero por teclado;
 *
 * \param mensaje[]: array que contiene un mensaje;
 * \param *num: espacio de memoria reservado para el numero ingeresado;
 * \return return O; retorna un cero cuando se ingreso correctamente el numero;
 *
 */

int ingresoFloat(char mensaje[],float *num)
{
    char numero[51];
    printf(mensaje);
    scanf("%s",numero);

    validarFloat(numero,num);

    return 0;
}


/** \brief Funcion que valida un numero flotante;
 *
 * \param validar[]: contiene el numero ingresado por el usuario, el cual va ser verificado si es flotante;
 * \param *flotante: puntero que reserva espacio de memoria para el numero despues de ser varificado;
 * \return void;
 *
 */

void validarFloat(char validar[], float *flotante)
{
    int i = 0;
    while(validar[i] != '\0')
    {
        if((validar[i] != '-') && (validar[i] < '0' || validar[i] > '9') && (validar[i] != '.'))
        {
            printf("ERROR: Ingrese un numero valido: ");
            fflush(stdin);
            scanf("%s",validar);
            i = 0;
            continue;
        }

        i++;
    }


    *flotante = atof(validar);
    system("cls");

}


/** \brief Funcione que calcula el factorial de un numero;
 *
 * \param *numero: puntero que contiene el numero;
 * \return void;
 *
 */

void factorial(float *numero)
{
    long total;
    float num;
    int factor;
    int flag = 0;
    factor = *numero;
    num = *numero;

    if(num == factor)
    {
        if(factor > 0)
        {
            while(factor != 1)
            {
                if(flag == 0)
                {
                    total = factor * (factor - 1);
                    factor = factor - 1;
                    flag = 1;
                }
                else
                {
                    total = (factor - 1) * total;
                    factor = factor - 1;
                }
            }
        }

        printf("\nEl factorial de %.f es: %ld\n",*numero,total);
    }
    else
    {
        printf("\nEl numero A no es decimal reingrese un valor correcto\n");
    }

}


/** \brief Funcion que suma dos numeros;
 *
 * \param *numero1: puntero que contiene el primer operando;
 * \param *numero2: puntero que contiene el segundo operando;
 * \return void;
 *
 */

void funcionSuma(float *numero1,float *numero2)
{
    float sumaA;
    int sumaB;

    sumaA = *numero1 + *numero2;
    sumaB = *numero1 + *numero2;

    if(sumaA == sumaB)
        printf("\nLa suma de %.f + %.f es: %d\n",*numero1,*numero2,sumaB);
    else
        printf("\nLa suma de %.2f + %.2f es: %.2f\n",*numero1,*numero2,sumaA);

}


/** \brief Funcion que resta dos numeros;
 *
 * \param *numero1: puntero que contiene el primer operando;
 * \param *numero2: puntero que contiene el segundo operando;
 * \return void;
 *
 */

void funcionResta(float *numero1,float *numero2)
{
    float restaA;
    int restaB;

    restaA = *numero1 - *numero2;
    restaB = *numero1 - *numero2;

    if(restaA == restaB)
        printf("\nLa resta de %.f - %.f es: %d\n",*numero1,*numero2,restaB);
    else
        printf("\nLa resta de %.2f - %.2f es: %.2f\n",*numero1,*numero2,restaA);

}


/** \brief Funcion que divide dos numeros;
 *
 * \param *numero1: puntero que contiene el primer operando;
 * \param *numero2: puntero que contiene el segundo operando;
 * \return void;
 *
 */

void funcionDividir(float *numero1,float *numero2)
{
    float total;

    if(*numero2 == 0)
        printf("\nPara hacer la divion, el numero B tiene que se mayor a cero\nreingrese el operador\n");
    else
    {
        total = *numero1 / *numero2;
        printf("\nLa division de %.2f / %.2f es: %.2f\n",*numero1,*numero2,total);
    }
}


/** \brief Funcion que multiplica dos numeros;
 *
 * \param *numero1: puntero que contiene el primer operando;
 * \param *numero2: puntero que contiene el segundo operando;
 * \return void;
 *
 */

void funcionMultiplo(float *numero1,float *numero2)
{
    float totalA;
    int totalB;

    totalA = *numero1 * *numero2;
    totalB = *numero1 * *numero2;

    if(totalA == totalB)
        printf("\nLa multiplicacion de %.f * %.f es: %d\n",*numero1,*numero2,totalB);
    else
        printf("\nLa multiplicacion de %.2f * %.2f es: %.2f\n",*numero1,*numero2,totalA);
}
