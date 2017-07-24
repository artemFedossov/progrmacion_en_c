/*Ingresar por teclado 3 n�meros correspondientes a los lados de un tri�ngulo. Teniendo en cuenta que la
  suma de los dos lados menores tiene que ser superior al lado mayor para que formen un tri�ngulo, indicar si
  los n�meros indicados forman un tri�ngulo y si lo forman que tipo de tri�ngulo es */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float ladoA, ladoB, ladoC, flag = 0;

    do{
    printf("Ingrese el lado A: ");
    scanf("%f",&ladoA);

    printf("Ingrese el lado B: ");
    scanf("%f",&ladoB);

    printf("Ingrese el lado C: ");
    scanf("%f",&ladoC);

    if(((ladoA + ladoB) < ladoC) || ((ladoA + ladoC) < ladoB) || ((ladoB + ladoC) < ladoA))
    {
        printf("\nLas medidas no forman un triangulo\n");
        flag = 1;
    }
    else
    {
        if((ladoA == ladoB) && (ladoA == ladoC) && (ladoC == ladoB))
        {
            printf("\nEl triangulo es Equilatero\n");
        }
        if(((ladoA == ladoB) && (ladoA != ladoC)) || ((ladoA == ladoC) && (ladoA != ladoB)) || ((ladoC == ladoB) && (ladoC != ladoA)))
        {
            printf("\nEl triangulo es isoseles\n");
        }
        if((ladoA != ladoB) && (ladoA != ladoC) && (ladoC != ladoB))
        {
            printf("\nEl triangulo es escaleno\n");
        }
        flag = 1;
    }

    }while(flag != 1);

    return 0;
}
