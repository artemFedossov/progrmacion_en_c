/*Ingresar un número entero por consola y efectuar la suma de todos los números que le anteceden,
  comenzando desde 0 y mostrar el resultado por pantalla*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, suma = 0;

    printf("Ingrese un numero: ");
    scanf("%d",&num);

    for(i=0; i<num; i++)
    {
        suma += i;
    }

    printf("\nLa suma es: %d\n",suma);

    return 0;
}
