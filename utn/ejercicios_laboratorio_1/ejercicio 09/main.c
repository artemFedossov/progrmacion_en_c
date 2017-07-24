/*Escribir un programa que realice. lea por teclado 20 caracteres.
  Luego de la lectura indicar cuantas "a" se ingresaron, cuantas "e, i, o, u"*/

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 20

int main()
{
    char letra;
    int contA = 0, contE = 0, contI = 0, contO = 0, contU = 0, cont = 0;
    int i;

    for(i=0; i<CANTIDAD; i++)
    {
        printf("Ingrese una letra: ");
        scanf("%c",&letra);
        fflush(stdin);

        switch(letra)
        {
            case 'a':
                contA++;
                break;
            case 'e':
                contE++;
                break;
            case 'i':
                contI++;
                break;
            case 'o':
                contO++;
                break;
            case 'u':
                contU++;
                break;
            default:
                cont++;
                break;
        }
    }

    printf("\nLa cantidad de:\nA: %d\nE: %d\nI: %d\nO: %d\nU: %d\nOtras: %d\n",contA,contE,contI,contO,contU,cont);

    return 0;
}
