/*Hacer el programa que nos permita introducir un número por teclado y nos informe si es par o impar*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d",&num);

    if(num % 2 == 0)
    {
        printf("\nEl numero es par\n");
    }
    if(num % 2 == 1)
    {
        printf("\nEl numero es impar\n");
    }

    return 0;
}
