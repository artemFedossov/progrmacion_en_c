#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "menu.h"
#include "amb.h"
#include "ingresoValidacion.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "menu.h"
#include "amb.h"
#include "ingresoValidacion.h"

/** \brief inicializa con un valor el array
 *
 * \param array: es el array en donde se inicializa
 * \param hasta: el largo del array
 * \param inicializa: contiene el valor con el cual sera inicializado el array
 * \return void
 *
 */

void inicializarArray(EUsuario array[],int hasta,int inicializa)
{
    int i;

    for(i=0; i<hasta; i++)
    {
        array[i].id = inicializa;
    }
}

void inicializarProductos(EProductos array[],int hasta,int inicializa)
{
    int i;

    for(i=0; i<hasta; i++)
    {
        array[i].id = inicializa;
        array[i].ventas = 0;
    }
}

void publicar(EProductos arrayProducto[],int hastaProducto,EUsuario arrayUsuario[],int hastaUsuario)
{
    int elementos, bufferEntero, indice, numero, indicePr;
    float numeroFloat;
    char mensaje[3][51] = {"Ingrese Nombre: ","Ingrese Precio: ","Ingrese Stock: "};
    char buffer[100];

    elementos = buscarElementos(arrayUsuario,hastaUsuario);
    if(elementos == 1)
    {
        printf("\nIngrese el ID del Usuario: ");
        scanf("%d",&bufferEntero);

        indice = busquedaArray(arrayUsuario,hastaUsuario,bufferEntero);
        if(indice != -1)
        {
            indicePr = lugarLibreProd(arrayProducto,hastaProducto);
            if(indicePr != -1)
            {
                arrayProducto[indicePr].id = indice;
                printf("El usuario es\n%s\n",arrayUsuario[indice].usuario);
                ingresoAlfabetico(buffer,mensaje[0]);
                strcpy(arrayProducto[indicePr].nombre,buffer);

                ingresoFlotante(buffer,mensaje[1]);
                numeroFloat = atof(buffer);
                arrayProducto[indicePr].precio = numeroFloat;

                ingresoEntero(buffer,mensaje[2]);
                numero = atoi(buffer);
                arrayProducto[indicePr].stock = numero;

            }
            else
            {
                printf("No queda mas espacio para seguir ingresando productos\n\n");
                system("pause");
            }

        }
        else
        {
            printf("\nEl ID es inexistente\n");
        }
    }
    else
    {
        printf("no hay datos cargados\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}


void modificarPublicacion(EProductos arrayProducto[],int hastaProducto,EUsuario arrayUsuario[],int hastaUsuario)
{
    int elementos, bufferEntero, indice, numero, indicePr, i;
    float numeroFloat;
    char mensaje[3][51] = {"Ingrese Precio: ","Ingrese Stock: ","Modoficar Ventas: "};
    char buffer[100];

    elementos = buscarElementos(arrayUsuario,hastaUsuario);
    if(elementos == 1)
    {
        printf("\nIngrese el ID del Usuario: ");
        scanf("%d",&bufferEntero);

        indice = busquedaArray(arrayUsuario,hastaUsuario,bufferEntero);
        if(indice != -1)
        {
            printf("El usuario es\n%s\n",arrayUsuario[indice].usuario);

            for(i=0; i<hastaProducto; i++)
            {
                if(arrayProducto[i].id == indice)
                {
                    printf("Id del producto %d\nNombre del Producto: %s\nPrecio %.2f\nStok %d",arrayProducto[i].id,arrayProducto[i].nombre,arrayProducto[i].precio,arrayProducto[i].stock);
                }
            }

            printf("\nIngrese el ID del Producto: ");
            scanf("%d",&indicePr);

            ingresoFlotante(buffer,mensaje[0]);
            numeroFloat = atof(buffer);
            arrayProducto[indicePr].precio = numeroFloat;

            ingresoEntero(buffer,mensaje[1]);
            numero = atoi(buffer);
            arrayProducto[indicePr].stock = numero;

            ingresoEntero(buffer,mensaje[2]);
            numero = atoi(buffer);
            arrayProducto[indicePr].ventas = numero;


        }
        else
        {
            printf("\nEl ID es inexistente\n");
        }
    }
    else
    {
        printf("no hay datos cargados\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

int lugarLibreProd(EProductos array[],int hasta)
{
    int i;
    int indiceLibre = -1;

    for(i=0; i<hasta; i++)
    {
        if(array[i].id == -1)
        {
            indiceLibre = i;
            break;
        }
    }

    return indiceLibre;
}

void cancelarPublicacion(EProductos arrayProducto[],int hastaProducto,EUsuario arrayUsuario[],int hastaUsuario)
{
    int elementos, bufferEntero, indice, numero, indicePr, i;
    float numeroFloat;
    char mensaje[2][51] = {"Ingrese Precio: ","Ingrese Stock"};
    char buffer[100];

    elementos = buscarElementos(arrayUsuario,hastaUsuario);
    if(elementos == 1)
    {
        printf("\nIngrese el ID del Usuario: ");
        scanf("%d",&bufferEntero);

        indice = busquedaArray(arrayUsuario,hastaUsuario,bufferEntero);
        if(indice != -1)
        {
            printf("El usuario es\n%s\n",arrayUsuario[indice].usuario);

            for(i=0; i<hastaProducto; i++)
            {
                if(arrayProducto[i].id == indice)
                {
                    printf("Id del producto %d\nNombre del Producto: %s\nPrecio %.2f\nVendidas %d\nStok %d",arrayProducto[i].id,arrayProducto[i].nombre,arrayProducto[i].precio,arrayProducto[i].ventas,arrayProducto[i].stock);
                }
            }

            printf("\nIngrese el ID del Producto: ");
            scanf("%d",&indicePr);

            arrayProducto[i].id = -1;


        }
        else
        {
            printf("\nEl ID es inexistente\n");
        }
    }
    else
    {
        printf("no hay datos cargados\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

void listarPublicacionUsuario(EProductos arrayProducto[],int hastaProducto,EUsuario arrayUsuario[],int hastaUsuario)
{
    int elementos, bufferEntero, indice, numero, indicePr, i;
    float numeroFloat;
    char mensaje[2][51] = {"Ingrese Precio: ","Ingrese Stock"};
    char buffer[100];

    elementos = buscarElementos(arrayUsuario,hastaUsuario);
    if(elementos == 1)
    {
        printf("\nIngrese el ID del Usuario: ");
        scanf("%d",&bufferEntero);

        indice = busquedaArray(arrayUsuario,hastaUsuario,bufferEntero);
        if(indice != -1)
        {
            printf("El usuario es\n%s\n",arrayUsuario[indice].usuario);

            for(i=0; i<hastaProducto; i++)
            {
                if(arrayProducto[i].id == indice)
                {
                    printf("Id del producto %d\nNombre del Producto: %s\nPrecio %.2f\nVentas %d\nStok %d",arrayProducto[i].id,arrayProducto[i].nombre,arrayProducto[i].precio,arrayProducto[i].ventas,arrayProducto[i].stock);
                }
            }

        }
        else
        {
            printf("\nEl ID es inexistente\n");
        }
    }
    else
    {
        printf("no hay datos cargados\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

void listarPublicaciones(EProductos arrayProducto[],int hastaProducto,EUsuario arrayUsuario[],int hastaUsuario)
{
    int elementos, bufferEntero, indice, numero, indicePr, i, j;
    float numeroFloat;
    char buffer[100];

    elementos = buscarElementos(arrayUsuario,hastaUsuario);
    if(elementos == 1)
    {
        for(i=0; i<hastaProducto; i++)
        {
            if(arrayProducto[i].id != -1)
            {
                printf("Id %d\nNombre %s\nPrecio %.2f\nVentas %d\nStock %d\n",arrayProducto[i].id,arrayProducto[i].nombre,arrayProducto[i].precio,arrayProducto[i].ventas,arrayProducto[i].stock);
                for(j=0; j<hastaUsuario; j++)
                {
                    if(arrayProducto[i].id == j+1)
                    {
                        printf("Nombre %s\n\n",arrayUsuario[j+1].usuario);
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("no hay datos cargados\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}
