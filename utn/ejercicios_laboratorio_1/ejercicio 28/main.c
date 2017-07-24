/*Escribir en y codificar en C un programa que muestre los números primos comprendidos entre 0 y 100*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, aux, cont;

    for(i=2; i<100; i++)
    {
        for(j=2; ;j++)
        {
            if(i % j != 0 || i == 2)
            {
                if(i / j != 1)
                {
                    continue;
                }
                printf("%d\t",i);
                break;
            }
            if(i % j == 0)
            {
                break;
            }
        }

    }
    return 0;
}
