#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int id;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[100];
}EMovie;

void inicializar(EMovie peliculas[], int, int);
void altaPelicula(EMovie peliculas[], int);
void borrarPelicula(EMovie peliculas[], int);
void ModificarPelicula(EMovie peliculas[], int);
void crearTxt(EMovie peliculas[],int);
void crearHtml(EMovie peliculas[],int);
int obtenerEspacioLibre(EMovie peliculas[], int);
int validarCadena(int, int);
int validarNumero(char []);
int validacionLetras(char []);
int esAlfaNumerico(char []);
int validarPuntaje(char []);
int lugarLibre(EMovie peliculas[], int);
int busquedaID(EMovie peliculas[], int, int);
int validacionConfirmar(char);
int guardar(EMovie peliculas[]);
void validacionMenu(char []);

#endif // FUNCIONES_H_INCLUDED
