/*Calcular y generar los primeros 100 números múltiplos de 5, de 7 y de ambos*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, flag = 0;

    for(i=1; i<=100; i++)
    {
        if(i % 5 == 0 || i % 7 == 0)
        {
            if(i % 5 == 0)
            {
                if(flag == 0)
                {
                    printf("\nMultiplos de 5: ");
                    flag = 1;
                }
                printf("%d ",i);
            }

        }
    }

    for(i=1; i<100; i++)
    {
        if(i % 7 == 0)
        {
            if(flag == 1)
            {
                printf("\nMultiplos de 7: ");
                flag = 0;
            }
            printf("%d ",i);
        }

    }
    printf("\n");


    return 0;
}
