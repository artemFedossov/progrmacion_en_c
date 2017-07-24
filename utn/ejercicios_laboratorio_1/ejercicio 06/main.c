/*De 10 numeros ingresados indicar cuantos son mayores a cero y cuantos son menores a cero*/

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10

int main()
{
    int num, i, contadorMay = 0, contadorMen = 0, contadorCero = 0;

    for(i=0; i<CANTIDAD; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num);

        if(num > 0)
        {
            contadorMay++;
        }
        else
        {
            if(num < 0)
            {
                contadorMen++;
            }
            else
            {
                contadorCero++;
            }
        }
    }

    printf("\nLa cantidad de:\nmayores a cero es %d\nMenores a cero %d\nIguales a cero %d\n",contadorMay,contadorMen,contadorCero);

    return 0;
}
