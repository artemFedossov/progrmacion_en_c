/*Hacer el programa que imprima todos los números naturales que hay desde la unidad hasta un número que
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
