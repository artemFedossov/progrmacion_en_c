/*Diseñar un programa que imprima y sume la serie de números 3,6,9,12,...,99.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    for(i=0; i<100; i++)
    {
        if(i % 3 == 0)
        {
            printf("%d\t",i);
        }
    }
    return 0;
}
