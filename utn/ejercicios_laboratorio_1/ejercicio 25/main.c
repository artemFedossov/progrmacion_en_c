/*En una tienda de art�culos para caballeros al final del d�a se carga en la computadora las boletas que
  confeccionaron los distintos vendedores para saber cu�nto fue la comisi�n del d�a de cada uno de ellos. Los
  datos que se ingresan (por boleta) son: el n�mero de vendedor y el importe. Cuando no hay m�s boletas
  para cargar se ingresa 0. Teniendo en cuenta que el negocio tiene 3 vendedores y que el porcentaje sobre
  las ventas es del 5%, indicar cu�nto gan� cada vendedor en el d�a*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vendedor, importe;

    do{
        printf("Ingrese el numero del vendedor: ");
        scanf("%d",&vendedor);

        printf("Ingrese el importe: ");
        scanf("%d",&importe);



    }

    return 0;
}
