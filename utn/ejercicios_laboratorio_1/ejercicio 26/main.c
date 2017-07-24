/*Hacer el programa ante la pregunta desea continuar sólo nos permita introducir como respuesta 'S' o'N'*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    char letra;

    printf("Ingrese si desea continuar con S / N: ");
    fflush(stdin);
    scanf("%c",&letra);

    while(letra != 'S' && letra != 'N')
    {
        printf("Reingrese: ");
        fflush(stdin);
        scanf("%c",&letra);
    }

    return 0;
}


