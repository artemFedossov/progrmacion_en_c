/*Diseñar en un programa que permita registrar de los empleados de una fábrica (no se sabe cuántos) su peso
  y saber cuántos pesan hasta 80 kg. inclusive y cuantos pesan más de 80 kg.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int peso, contMas = 0, contMen = 0;
    char rta;

    do{
        printf("Ingrese el peso del empleado: ");
        scanf("%d",&peso);

        while(peso <= 0)
        {
            printf("ERROR: Peso incorrecto: ");
            scanf("%d",&peso);
        }

        if(peso > 80)
        {
            contMas++;
        }
        else
        {
            contMen++;
        }

        printf("\nPara continuar ingrese la letra 's': ");
        fflush(stdin);
        scanf("%c",&rta);

        system("cls");

    }while(rta == 's');

    printf("\nEmpleados con mayor a 80 kg es: %d\nEmpleados con menor a 80 kg es: %d\n",contMas,contMen);

    return 0;
}
