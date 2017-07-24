/*De 3 números ingresados desde el teclado por el usuario, indicar cuál es el mayor*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, max, i;

    for(i=0; i<3; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num);

        if(i == 0)
        {
            max = num;
        }
        if(num > max)
        {
            max = num;
        }
    }

    printf("\nEl maximo es: %d\n",max);

    return 0;
}
