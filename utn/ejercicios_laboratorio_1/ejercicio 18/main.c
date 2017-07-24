/*Diseñar en un programa que permita ingresar 10 números, ninguno de ellos igual a cero. Se pide sumar los
  positivos, obtener el producto de los negativos y luego mostrar ambos resultados*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, sumar = 0, producto = 0, flag = 0;

    for(i=0; i<10; i++)
    {
        printf("Ingrese un numero: ");

        scanf("%d",&num);

        while(num == 0)
        {
            printf("ERROR: Reingrese el numero: ");
            scanf("%d",&num);
        }
        if(num > 0)
        {
            sumar = sumar + num;
        }
        else
        {
            if(flag == 0)
            {
                producto++;
                flag = 1;
            }
            producto = producto * num;
        }
    }

    printf("\nLa suma de los positivos es: %d\nEl producto de los negativos es %d\n",sumar,producto);
    return 0;
}
