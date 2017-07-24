/*Escribir un programa que realice las siguientes acciones:
  * limpie la pantalla
  * declare 2 variables y les asigne sendos valores
  * realice la resta de dichas variables y muestre por pantalla la leyenda "resultado positivo" en case de
    ser mayor que cero o "resultado negativo" si es menor que cero*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2, resultado;

    printf("Ingrese dos numeros (se restaran para mostrar si el resultado es positivo o negativo): ");
    scanf("%d%d",&numero1,&numero2);

    resultado = numero1 - numero2;

    if(resultado > 0)
    {
        printf("\nEl resultado es positivo\n");
    }
    else
    {
        if(resultado < 0)
        {
            printf("\nEl resultado es negativo\n");
        }
        else
        {
            printf("\nEl resultado es nulo\n");
        }
    }

    return 0;
}
