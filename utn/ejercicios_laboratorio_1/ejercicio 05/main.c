/*Escribir el programa necesario para calcular y mostrar el cuadrado de un numero. el numero debe ser mayor que cero.
  en caso de error que aparezca el mensaje "Error, el numero debe ser mayor que cero"*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, cuadrado;

    printf("Ingrese un numero para calcular el cuadrado del mismo: ");
    scanf("%d",&numero);

    while(numero < 1)
    {
        printf("ERROR, el numero debe ser mayor a cero: \a");
        scanf("%d",&numero);
    }

    cuadrado = numero * numero;

    printf("\nEl cuadrado de %d es %d\n",numero,cuadrado);
    return 0;
}
