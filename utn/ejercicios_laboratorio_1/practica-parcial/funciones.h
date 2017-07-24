

typedef struct
{
    int id;
    int idLlamadas;
    int numero;
    char nombre[51];
    char apellido[51];

}EAbonado;

typedef struct
{
    int id;
    int TresG;
    int fallaLTE;
    int fallaEquipo;
    int estado;

}ELlamada;

void inicializarArray(EAbonado [],int,int);
void inicializarArrayLlamada(ELlamada [],int,int);
void nuevaLlamada(EAbonado [],int,ELlamada [],int,int *);
void finLlamada(EAbonado [],int,ELlamada [],int,int *);
