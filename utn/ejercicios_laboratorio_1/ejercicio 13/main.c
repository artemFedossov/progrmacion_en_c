/*Hacer el programa que imprima los n�meros del 100 al 0 en orden decreciente*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    for(i=100; i>=0; i--)
    {
        printf("%d\t",i);
    }

    return 0;
}
