/*Hacer el programa que nos permita introducir un número por teclado y nos informe si es positivo o negativo*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d",&num);

    if(num>0)
    {
        printf("\nEl numero es positivo\n");
    }
    else
    {
        if(num==0)
        {
            printf("\nEl numero es nulo\n");
        }
        else
        {
            printf("\nEl numero es negativo\n");
        }

    }

    return 0;
}
