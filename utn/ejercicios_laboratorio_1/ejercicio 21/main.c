/*Hacer el programa que nos permita contar los m�ltiplos de 3 desde la unidad hasta un n�mero que
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
        if(i % 3 == 0)
        {
            printf("%d\t",i);
        }
    }

    return 0;
}
