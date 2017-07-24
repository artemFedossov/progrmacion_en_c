/*Escribir el programa necesario para calcular la suma de dos numeros. mostrar el resultado.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numA, numB, suma;

    printf("Ingrese el primer numero: ");
    scanf("%d",&numA);

    printf("Ingrese el segundo numero: ");
    scanf("%d",&numB);

    suma = numA + numB;

    printf("\nLa suma de %d + %d = %d\n",numA,numB,suma);

    return 0;
}
