#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

int buscarEstado(EPersona lista[]);
long int ingresar_dni(long int documento);
int ingresar_edad(int edad);
char validar_S_N(char respuesta);
void altas(EPersona lista[]);
void borrar(EPersona lista[]);
void ordenar(EPersona lista[]);
void grafico(EPersona lista[]);


#endif // FUNCIONES_H_INCLUDED



