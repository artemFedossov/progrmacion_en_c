/*Escribir en y codificar en C un programa que muestre los múltiplos de 6 comprendidos entre 0 y 100*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    for(i=0; i<=100; i++)
    {
        if(i % 6 == 0)
        {
            printf("%d\t",i);
        }
    }

    return 0;
}
