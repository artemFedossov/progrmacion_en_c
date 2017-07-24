/*Escribir en C un programa que muestre los números impares entre 0 y 100 y que imprima
  cuantos impares hay*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, cont = 0;

    for(i=0; i<100; i++)
    {
        if(i % 2 != 0)
        {
            printf("%d\t",i);
        }

    }

    return 0;
}
