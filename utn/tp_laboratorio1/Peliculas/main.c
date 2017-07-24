#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANTIDAD 100

int main()
{
    char seguir='s';
    char aux[15];
    int opcion;
    EMovie peliculas[CANTIDAD];

    inicializar(peliculas,CANTIDAD,0);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        printf("Opcion: ");
        fflush(stdin);
        fgets(aux,100,stdin);

       validacionMenu(aux);
       opcion = atoi(aux);

        switch(opcion)
        {
            case 1:

                altaPelicula(peliculas,CANTIDAD);
                system("pause");
                system("cls");
                break;

            case 2:

                borrarPelicula(peliculas,CANTIDAD);
                system("pause");
                system("cls");
                break;

            case 3:

                ModificarPelicula(peliculas,CANTIDAD);
                system("pause");
                system("cls");
                break;

            case 4:

               crearHtml(peliculas,CANTIDAD);
               break;
            case 5:

                printf("\nDesea guardar los cambios: S / N ?: ");
                fflush(stdin);
                scanf("%c",&seguir);

				while(validacionConfirmar(seguir) == 1)
                {
                    printf("\nERROR: Opcion incorrecta, Reingrese: \n\a");
                    fflush(stdin);
                    scanf("%c",&seguir);
                }

				if(seguir == 's')
				{
					if(guardar(peliculas)==-1)
					{
						printf("\nNo se pudo abrir el archivo\n");
					}
					else
					{
						printf("\nDatos guardados\n");
						seguir = 'n';
						break;
					}
				}

                seguir = 'n';
                break;
        }
    }

    return 0;
}
