#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;



void inicializarEstado(EPersona lista[], int tam);
int obtenerEspacioLibre(EPersona lista[], int tam);
int buscarDuplicado(EPersona lista[], int tam, long int documento);
char validarNombre(char nombre[], int min, int max);
int validarEdad(int edad, int min, int max);
int validarDni(long int dni, int min, int max);
void altas(EPersona lista[], int tam);
int buscarPorDni(EPersona lista[], int tam, long int dni);
void borrarPersona(EPersona lista[], int tam);
void listar(EPersona lista[], int tam);
void grafico(EPersona lista[], int tam);


#endif // FUNCIONES_H_INCLUDED
