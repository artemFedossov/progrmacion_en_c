/*Diseñar un programa que calcule la longitud de la circunferencia y el area del circulo de radio dado*/

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main()
{
    float radio, longitud, area;

    printf("Ingrese el radio del circulo: ");
    scanf("%f",&radio);

    longitud = 2 * PI * radio;

    area = PI * radio * radio;

    printf("\nLa longitud es: %.2f\nEl area es: %.2f\n",longitud,area);

    return 0;
}
