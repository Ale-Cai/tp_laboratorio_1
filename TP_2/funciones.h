#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <conio.h>




typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;



/** \brief valida un dato  int dentro de un rango determinado
 *
 * \param input dato a validar
 * \param message mensaje para pedir el dato
 * \param eMessage mensaje de error
 * \param lowLimit limite inferior de la validacion
 * \param hiLimit limite superior de la validacion
 * \return el numero validado.
 *
 */

int getInt(int input, char message[], char eMessage[], int lowLimit, int hiLimit);



/** \brief valida un dato del tipo float dentro de un rango determinado
 *
 * \param input dato a validar
 * \param message mensaje para pedir el dato
 * \param eMessage mensaje de error
 * \param lowLimit limite inferior de la validacion
 * \param hiLimit limite superior de la validacion
 * \return el numero validado.
 *
 */

int getFloat(float input, char message[], char eMessage[], float lowLimit, float hiLimit);





/** \brief valida una cadena de caracteres dentro de un rango determinado
 *
 * \param *input cadena a validar
 * \param message mensaje para pedir el dato
 * \param eMessage mensaje de error
 * \param lowLimit limite inferior de la validacion
 * \param hiLimit limite superior de la validacion
 * \return cadena validada.
 *
 */

int getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit);



/** \brief valida un dato long int dentro de un rango determinado
 *
 * \param input dato a validar
 * \param message mensaje para pedir el dato
 * \param eMessage mensaje de error
 * \param lowLimit limite inferior de la validacion
 * \param hiLimit limite superior de la validacion
 * \return el numero validado.
 *
 */

int getLongInt(long int input, char message[], char eMessage[], long int lowLimit, long int hiLimit);



/** \brief valida una respuesta s/n
 *
 * \param message mensaje a mostrar
 * \param eMessage mensaje de error
 * \return caracter validado
 */

char getSN(char message[], char eMessage[]);



/** \brief Coloca las iniciales en mayuscula.
 *
 * \param name cadena a la cual se le cambian las iniciales
 * \return 0 si todo es correcto
 *
 */

int mayusNombre(char name[]);



/** \brief inicializa todos los estados del array a 0
 *
 * \param lista el array se pasa como parametro.
 * \param size tamaño del array
 * \return no retorna ningun valor
 *
 */

void inicializarEstados(EPersona lista[], int size);



/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param size tamaño del array
 * @return el primer indice disponible
 */

int obtenerEspacioLibre(EPersona lista[], int size);



/** \brief Valida que el dni no se haya ingresado antes
 *
 * \param lista el array se pasa como parametro.
 * \param size tamaño del array
 * \return 1 si encontro un duplicado
 *
 */

int buscarDuplicado(EPersona lista[], long int dni, int size);



/** \brief agrega los datos de una persona al array
 *
 * \param lista el array se pasa como parametro.
 * \param size tamaño del array
 * \return 0 si todo es correcto
 *
 */

int agregarPersona(EPersona lista[], int size);



/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param size tamaño del array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

int buscarPorDni(EPersona lista[], long int dni, int size);



/** \brief
 *
 * \param lista el array se pasa como parametro.
 * \param dni numero de dni de la persona a eliminar
 * \param size tamaño del array
 * \return 0 si se borro correctamente, -1 si se produjo un error
 *
 */

int borrarPersona(EPersona lista[], long int dni, int size);



/** \brief muestra las personas del array
 *
 * \param lista el array se pasa como parametro.
 * \param size tamaño del array
 * \return no retorna valor
 *
 */

void mostrarPersonas(EPersona lista[], int size);



/** \brief Ordena de manera alfabetica las personas del array
 *
 * \param lista el array se pasa como parametro.
 * \param size tamaño del array
 * \return no retorna valor
 *
 */

void ordenarPersonas(EPersona lista[], int size);



/** \brief muestra un grafico de las personas del array dependiendo su edad
 *
 * \param lista el array se pasa como parametro.
 * \param size tamaño del array
 * \return no retorna valor
 *
 */

void graficoPersonas(EPersona lista[], int size);











#endif // FUNCIONES_H_INCLUDED
