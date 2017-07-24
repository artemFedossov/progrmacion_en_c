/*Dados 3 números donde el primero y el último son límites de un intervalo, indicar si el tercero pertenece a dicho intervalo*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2, num3;

    printf("Ingrese dos numeros que forman un limite\n");
    printf("Ingrese el primer limite: ");
    scanf("%f",&num1);
    printf("Ingrese el segundo limete: ");
    scanf("%f",&num2);
    printf("Ingrese el numero para saber si se encuentra en el intervalo: ");
    scanf("%f",&num3);

    if(num3 > num1 && num3 < num2)
    {
        printf("\nEl numero pertenece al intervalo\n");
    }
    else
    {
        printf("\nEl numero no pertenece al intervalo\n");
    }

    return 0;
}
