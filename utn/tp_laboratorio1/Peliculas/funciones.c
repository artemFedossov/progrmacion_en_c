#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/**
 * \brief inicializa el array peliculas
 * \param peliculas es el array a inicializar
 * \return void
 *
 */

void inicializar(EMovie peliculas[],int largo,int valor)
{
    int i;
    for(i=0; i<largo; i++)
    {
        peliculas[i].id = valor;
    }
}

/**
 * \brief ejecuta el alta de peliculas
 * \param peliculas es el array en que se carga
 * \return void
 *
 */

void altaPelicula(EMovie peliculas[],int largo)
{
    char tituloAux[20];
    char generoAux[20];
    int duracionAux;
    char descripcionAux[50];
    int puntajeAux;
    char linkImagenAux[100];
    int indice;
    int caracteres;
    int idAux;

    indice = obtenerEspacioLibre(peliculas, largo);

    if(indice == -1)
    {
        printf("No cuenta con espacio para cargar peliculas\n");
    }
    else
    {
        idAux = validarNumero("Ingrese el ID: ");

        printf("Ingrese el titulo: ");
        fflush(stdin);
        gets(tituloAux);

        caracteres = strlen(tituloAux);

            if(validarCadena(caracteres,20) == 1)
            {
                while(caracteres > 21 || caracteres == 0)
                {
                    printf("\nERROR: Se paso el limite de caracteres\n\a");
                    printf("Reingrese el titulo: ");
                    fflush(stdin);
                    gets(tituloAux);
                    caracteres = strlen(tituloAux);
                }
            }

        do{

            printf("Ingrese el genero: ");
            fflush(stdin);
            gets(generoAux);

            if(validacionLetras(generoAux)==1)
            {
                printf("\nERROR: El genero solo debe contener letras\n\a");
            }

        }while(validacionLetras(generoAux)==1);

        duracionAux = validarNumero("Ingrese la duracion: ");

        do{

            printf("Ingrese la descripcion: ");
            fflush(stdin);
            gets(descripcionAux);

            caracteres = strlen(descripcionAux);

            if(validarCadena(caracteres,50) == 1)
            {
                while(caracteres > 51 || caracteres == 0)
                {
                    printf("\nERROR: Se paso el limite de caracteres\n\a");
                    printf("Reingrese la descripcion: ");
                    fflush(stdin);
                    gets(descripcionAux);
                    caracteres = strlen(descripcionAux);
                }
            }

            if(esAlfaNumerico(descripcionAux)==1)
            {
                printf("\nERROR: la descripcion tiene caracteres incorrectos\n\a");
            }

        }while(esAlfaNumerico(descripcionAux)==1);

        puntajeAux = validarPuntaje("Ingrese el puntaje: ");

        printf("Ingrese el link: ");
        fflush(stdin);
        gets(linkImagenAux);

        caracteres = strlen(linkImagenAux);

            if(validarCadena(caracteres,100) == 1)
            {
                while(caracteres > 100 || caracteres == 0)
                {
                    printf("\nERROR: Se paso el limite de caracteres\n\a");
                    printf("Reingrese el link: ");
                    fflush(stdin);
                    gets(linkImagenAux);
                    caracteres = strlen(linkImagenAux);
                }
            }

            peliculas[indice].id = idAux;
            strcpy(peliculas[indice].titulo,tituloAux);
            strcpy(peliculas[indice].genero,generoAux);
            peliculas[indice].duracion = duracionAux;
            strcpy(peliculas[indice].descripcion,descripcionAux);
            peliculas[indice].puntaje = puntajeAux;
            strcpy(peliculas[indice].linkImagen,linkImagenAux);

            crearTxt(peliculas,largo);
    }

}

/**
 * \brief ejecuta la baja de peliculas
 * \param peliculas es el array en el que se encuenta
 * \return void
 *
 */

void borrarPelicula(EMovie peliculas[], int largo)
{
    int idAux;
    int indice;

    indice = obtenerEspacioLibre(peliculas, largo);

        if(indice == 0)
        {
            printf("\nNo hay datos cargados\n");
            return;
        }

    idAux = validarNumero("Ingrese el ID: ");

    indice = busquedaID(peliculas, idAux, largo);

    peliculas[indice].id = 0;

    printf("\nLa pelicula %s ha sido dada de baja\n",peliculas[indice].titulo);

    crearTxt(peliculas,largo);

}


/**
 * \brief ejecuta la modificacion de peliculas
 * \param peliculas es el array en que se modifica
 * \return void
 *
 */

void ModificarPelicula(EMovie peliculas[], int largo)
{
    char tituloAux[20];
    char generoAux[20];
    int duracionAux;
    char descripcionAux[50];
    int puntajeAux;
    char linkImagenAux[100];
    int indice;
    int caracteres;
    int idAux;

    indice = obtenerEspacioLibre(peliculas, largo);

        if(indice == 0)
        {
            printf("\nNo hay datos cargados\n");
            return;
        }

    idAux = validarNumero("Ingrese el ID: ");

    indice = busquedaID(peliculas, idAux, largo);

    idAux = validarNumero("Ingrese el ID a modificar: ");

        printf("Ingrese el titulo: ");
        fflush(stdin);
        gets(tituloAux);

        caracteres = strlen(tituloAux);

            if(validarCadena(caracteres,20) == 1)
            {
                while(caracteres > 21 || caracteres == 0)
                {
                    printf("\nERROR: Se paso el limite de caracteres\n\a");
                    printf("Reingrese el titulo: ");
                    fflush(stdin);
                    gets(tituloAux);
                    caracteres = strlen(tituloAux);
                }
            }

        do{

            printf("Ingrese el genero: ");
            fflush(stdin);
            gets(generoAux);

            if(validacionLetras(generoAux)==1)
            {
                printf("\nERROR: El genero solo debe contener letras\n\a");
            }

        }while(validacionLetras(generoAux)==1);

        duracionAux = validarNumero("Ingrese la duracion: ");

        do{

            printf("Ingrese la descripcion: ");
            fflush(stdin);
            gets(descripcionAux);

            caracteres = strlen(descripcionAux);

            if(validarCadena(caracteres,50) == 1)
            {
                while(caracteres > 51 || caracteres == 0)
                {
                    printf("\nERROR: Se paso el limite de caracteres\n\a");
                    printf("Reingrese la descripcion: ");
                    fflush(stdin);
                    gets(descripcionAux);
                    caracteres = strlen(descripcionAux);
                }
            }

            if(esAlfaNumerico(descripcionAux)==1)
            {
                printf("\nERROR: la descripcion tiene caracteres incorrectos\n\a");
            }

        }while(esAlfaNumerico(descripcionAux)==1);

        puntajeAux = validarPuntaje("Ingrese el puntaje: ");

        printf("Ingrese el link: ");
        fflush(stdin);
        gets(linkImagenAux);

        caracteres = strlen(linkImagenAux);

            if(validarCadena(caracteres,100) == 1)
            {
                while(caracteres > 100 || caracteres == 0)
                {
                    printf("\nERROR: Se paso el limite de caracteres\n\a");
                    printf("Reingrese el link: ");
                    fflush(stdin);
                    gets(linkImagenAux);
                    caracteres = strlen(linkImagenAux);
                }
            }

            peliculas[indice].id = idAux;
            strcpy(peliculas[indice].titulo,tituloAux);
            strcpy(peliculas[indice].genero,generoAux);
            peliculas[indice].duracion = duracionAux;
            strcpy(peliculas[indice].descripcion,descripcionAux);
            peliculas[indice].puntaje = puntajeAux;
            strcpy(peliculas[indice].linkImagen,linkImagenAux);

            crearTxt(peliculas,largo);
}

/**
 * \brief busca el la igualdad de id en el array
 * \param peliculas es el array en el que se busca
 * \return i el indice
 *
 */

int busquedaID(EMovie peliculas[], int id, int largo)
{
    int i, flag = 0;;

    for(i=0; i<largo; i++)
    {
        if(peliculas[i].id == id)
        {
            return i;
        }
    }

    do{
        printf("No se encontro el ID en la base de datos reingrese: ");
        scanf("%d",&id);

        for(i=0; i<largo; i++)
        {
            if(peliculas[i].id == id)
            {
                return i;
            }
        }
        flag = 1;

    }while(flag == 1);


}

/**
 * \brief obtiene espacio vacio en el array pelicula
 * \param peliculas es el array en que se busca el espacio vacio
 * \return i el indice del lagra vacio, -1 si no hay lugar
 *
 */

int obtenerEspacioLibre(EMovie peliculas[], int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        if(peliculas[i].id==0)
        {
            return i;
        }
    }
    return -1;
}

/** \brief valida el largo de una cadena
 *
 * \param largo - el largo de la cadena
 * \param hasta - el total de espacio
 * \return (1) error () ok
 *
 */
int validarCadena(int largo, int hasta)
{
    if(largo > hasta)
    {
        return 1;
    }

    return 0;
}


/** \brief valida el que sea numero
 *
 * \param mensaje el mensaje enviado desde el main
 * \return numero validado
 *
 */
int validarNumero(char mensaje[])
{
    char numero[51];
    int numeroInt;
    int i = 0;
    int flag = 0;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(numero);
        flag = 0;

            while(numero[i] !='\0')
            {
                if((numero[i] < '0' || numero[i] > '9') && numero[i]!='.')
                {
                    printf("\nError: ingreso solo numerico\n");
                    flag = 1;
                    break;

                }
                i++;
            }

    }while(flag==1);

    numeroInt = atoi(numero);

    return numeroInt;
}

/** \brief valida el que sean letras
 *
 * \param letra a ser analizada
 * \return 1 erro o ok
 *
 */

int validacionLetras(char letras[])
{
    int i=0;

    while(letras[i] != '\0')
    {
        if((letras[i] < 'a' || letras[i] > 'z') && (letras[i] < 'A' || letras[i] > 'Z') && (letras[i] != ' '))
        {
            return 1;
        }

        i++;
    }
    return 0;
}


/** \brief valida el que sea alfa numerico
 *
 * \param mensaje el mensaje enviado desde el main
 * \return 1 error o ok
 *
 */
int esAlfaNumerico(char mensaje[])
{
   int i=0;
   while(mensaje[i] != '\0')
   {
       if((mensaje[i] != ' ') && (mensaje[i] < 'a' || mensaje[i] > 'z') && (mensaje[i] < 'A' || mensaje[i] > 'Z') && (mensaje[i] < '0' || mensaje[i] > '9'))
           return 1;
       i++;
   }
   return 0;
}

/** \brief valida el puntaje de 1 a 10
 *
 * \param mensaje el mensaje enviado
 * \return numero validado
 *
 */

int validarPuntaje(char mensaje[])
{
    char numero[51];
    int numeroInt;
    int i = 0;
    int flag = 0;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(numero);
        flag = 0;

            while(numero[i] !='\0')
            {
                if((numero[i] < '0' || numero[i] > '9') && numero[i]!='.')
                {
                    printf("\nError: ingreso solo numerico\n");
                    flag = 1;
                    break;

                }
                i++;
            }

    }while(flag==1);

    numeroInt = atoi(numero);

    while(numeroInt<1 || numeroInt>10)
    {
        printf("\nError: el puntaje tiene que estar entre el 1 y el 10 reingrese: ");
        scanf("%d",&numeroInt);
    }

    return numeroInt;
}

void crearTxt(EMovie peliculas[],int largo)
{
    int i;
    FILE *fichero;
    fichero=fopen("Peliculas.txt", "w");

    if(fichero == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    else
    {
        fprintf(fichero,"peliculas\n\n\n");

        for(i=0; i<largo; i++)
        {
            if(peliculas[i].id != 0 && peliculas[i].id !=-1)
            {
                fprintf(fichero,"ID -   %d\nTitulo  -   %s\nGenero  -   %s\nDuracion    -   %d\nDescripcion -   %s\nPuntaje -   %d\nLink   -   %s\n\n\n", peliculas[i].id, peliculas[i].titulo, peliculas[i].genero, peliculas[i].duracion, peliculas[i].descripcion, peliculas[i].puntaje,peliculas[i].linkImagen);

            }
        }
    }

    fclose(fichero);

    printf("creado con exito\n");

}


void crearHtml(EMovie peliculas[],int largo)
{
    int i, indice;

    indice = obtenerEspacioLibre(peliculas, largo);

        if(indice == 0)
        {
            printf("\nNo hay datos cargados\n");
            return;
        }

    FILE *fichero;

    fichero=fopen("pagina.html", "w");

    if(fichero == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    fprintf(fichero,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

  for(i=0;i<largo;i++)
    {
        if(peliculas[i].id != 0 && peliculas[i].id !=-1)
        {
         fprintf(fichero,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>", peliculas[i].linkImagen);
         fprintf(fichero,"</a><h3><a href='#'>%s</a></h3><ul>",peliculas[i].titulo);
         fprintf(fichero,"<li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul>", peliculas[i].genero, peliculas[i].puntaje,peliculas[i].duracion);
         fprintf(fichero,"<p>%s</p></article>",peliculas[i].descripcion);
        }
    }
    fprintf(fichero,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(fichero);
    printf("\n\n Archivo creado con exito\n\n");
}

/** \brief valida que la letra ingresada sea 's' o 'n'
*
 * \param la letra a ser analizada
 * \return (1) error (0) ok
 *
 */
int validacionConfirmar(char letra)
{

    letra = tolower(letra);

    while(letra != 's' && letra != 'n')
    {
        return 1;
    }

    return 0;
}

int guardar(EMovie peliculas[])
{
    FILE* fp;
    fp=fopen("bin.dat","ab+");
    if(fp==NULL)
    {
        printf("Error abriendo el archivo");
        return 1;
    }
    fwrite(peliculas,sizeof(EMovie),1,fp);

    fclose(fp);
    return 0;
}

/** \brief valida la opcion del menu
 *
 * \param la opcion que va ser analizada
 * \return 1 erro o ok
 *
 */

void validacionMenu(char validar[])
{

    int i=0, flag = 0;
    int aux;

    aux = strlen(validar);

    while(validar[i] != '\n')
    {
        if((validar[i] < '0' || validar[i] > '5') || (aux != 2))
        {
            printf("Error: reingrese: ");
            fflush(stdin);
            fgets(validar,100,stdin);
            i=0;
            aux = strlen(validar);
            continue;
        }
        i++;
    }
}
