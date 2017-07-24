/*Diseñar un programa que calcule la superficie de un triangulo a partir del ingreso de su base y altura y muestre el resultado.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base, altura, superficie;

    printf("Ingrese la base del triangulo: ");
    scanf("%f",&base);

    printf("Ingrese la altura del triangulo: ");
    scanf("%f",&altura);

    superficie = (base * altura) / 2;

    printf("\nLa superficie del triangulo es %.2f\n",superficie);

    return 0;
}
