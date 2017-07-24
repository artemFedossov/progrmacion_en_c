/*Ingresar 5 numeros y calcular su media*/

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int main()
{
    int num, i, contador = 0;
    float promedio;

    for(i=0; i<CANTIDAD; i++)
    {
        printf("Ingrese 5 numeros: ");
        scanf("%d",&num);

        contador = contador + num;

        promedio = (float)contador / CANTIDAD;
    }

    printf("\nEl promedio general es %.2f\n",promedio);

    return 0;
}
