/*Hacer el programa que imprima todos los n�meros naturales que hay desde la unidad hasta un n�mero que
  introducimos por teclado*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i;

    printf("Ingrese un numero: ");
    scanf("%d",&num);

    for(i=1; i<=num; i++)
    {
        printf("%d\t",i);
    }

    return 0;
}
