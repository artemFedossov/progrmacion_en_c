/*Por teclado se ingresa el valor hora de un empleado. Posteriormente se ingresa el
  nombre del empleado, la antigüedad y la cantidad de horas trabajadas en el mes.
  Se pide calcular el importe a cobrar teniendo en cuenta que el total resulta de
  multiplicar el valor hora por la cantidad de horas trabajadas, hay que sumarle la
  cantidad de años trabajados multiplicados por $30, y al total de todas esas operaciones
  restarle el 13% en concepto de descuentos. Imprimir el recibo correspondiente con el
  nombre, la antigüedad, el valor hora, el total a cobrar en bruto, el total de
  descuentos y el valor neto a cobrar*/

#include <stdio.h>
#include <stdlib.h>

int ingreseInt(char []);
int validarAnio(int,int,int);
int validarMes(int,int,int);
float ingreseFloat(char []);
char ingreseArrayChar(char []);

int main()
{
    int anios;
    float valorHora, horasTraba, total, total_1, descuento, bruto;
    char nombre[51];
    char mensaje[4][51] = {"Ingrese el valor por hora: ","Ingrese el nombre del empleado: ","Ingrese los anios trabajados: ","Ingrese la cantidad de horas trabajadas: "};

    valorHora = ingreseFloat(mensaje[0]);
    nombre[51] = ingreseArrayChar(mensaje[1]);
    anios = ingreseInt(mensaje[2]);
    horasTraba = ingreseFloat(mensaje[3]);

    total = valorHora * horasTraba;
    total_1 = (float)anios * 30;

    bruto = total + total_1;

    descuento = bruto * 0.13;
    total = bruto - descuento;

    printf("\nRECIBO\n\nNombre: %s\nAntiguedad: %d\nPago por hora: %.3f\nTotal a cobrar en bruto: %.3f\nDescuento %.3f\nSueldo Neto %.3f\n",nombre,anios,valorHora,bruto,descuento,total);

    return 0;
}

float ingreseFloat(char mensaje[])
{
    float buffer;
    printf(mensaje);
    scanf("%f",&buffer);

    while(buffer <= 0)
    {
        printf("ERROR: Ingrese un valor valido: ");
        scanf("%f",&buffer);
    }

    return buffer;
}

int ingreseInt(char mensaje[])
{
    int buffer;
    printf(mensaje);
    scanf("%d",&buffer);

    buffer = validarAnio(buffer,100,0);

    return buffer;
}

char ingreseArrayChar(char mensaje[])
{
    int i=0;
    char buffer[51];
    printf(mensaje);
    fflush(stdin);
    gets(buffer);

    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] != ' '))
        {
            printf("ERROR: Reingrese: ");
            fflush(stdin);
            gets(buffer);
        }
        i++;
    }

    return buffer;
}

int validarAnio(int valor,int hasta,int desde)
{
    while(valor < desde || valor > hasta)
    {
        printf("ERROR: Reingrese un valor valido: ");
        scanf("%d",&valor);
    }

    return valor;
}
