/*Escribir un programa que realice las siguientes acciones
  * Limpie la pantalla
  * Asigne a 2 variables numero1 y numero2 valores distintos a cero
  * Efectue el producto de dichas variables
  * Muestre el resultado pos pantalla
  * Obtenga el cuadrado del numero1 y lo muestre por pantalla*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2, producto, cuadrado, opcion;

    printf("Ingrese el primer numero: ");
    scanf("%d",&numero1);

    while(numero1 == 0)
    {
        printf("Ingrese un numero mayor a cero: ");
        scanf("%d",&numero1);
    }

    printf("Ingrese el segundo numero: ");
    scanf("%d",&numero2);

    while(numero2 == 0)
    {
        printf("Ingrese un numero mayor a cero: ");
        scanf("%d",&numero2);
    }

    system("cls");

    do
    {
        printf("\nRealizar el producto de numeros %d * %d (opcion 1)\n",numero1,numero2);
        printf("Realizar el cuadrado del numero %d (opcion 2)\n",numero1);
        printf("Terminar (opcion 3)\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        while(opcion < 1 || opcion > 3)
        {
            printf("Ingrese una opcion correcta: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                producto = numero1 * numero2;
                printf("\nEl producto es %d\n",producto);
                break;

            case 2:
                cuadrado = numero1 * numero1;
                printf("\nEl cuadrado es %d\n",cuadrado);
                break;

            default:
                break;
        }

        system("pause");
        system("cls");

    }while(opcion != 3);

    return 0;
}
