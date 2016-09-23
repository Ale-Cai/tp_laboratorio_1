#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include "funciones.h"


/**
 * \brief Inicializa todos los estados del array.
 * \param lista el array se pasa como parametro.
 * \param tam tamaño del array pasado anteriormente.
 * \return No devuelve ningun valor.
 */
void inicializarEstado(EPersona lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}

/**
 * \brief Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \param tam tamaño del array pasado anteriormente.
 * \return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)

            return i;
    }

    return -1;
}

/**
 * \brief Comprueba que el dni pasado no haya sido ingresado antes.
 * \param lista el array se pasa como parametro.
 * \param tam tamaño del array pasado anteriormente.
 * \param documento el dni a ser buscado en el array.
 * \return Un dni que no fue ingresado.
 */
int buscarDuplicado(EPersona lista[], int tam, long int documento)
{
    int i;

    for(i=0; i<tam; i++)
    {
        while(documento == lista[i].dni)
        {
            printf("Error. Ese D.N.I ya ha sido ingresado\n\nReingrese: ");
            scanf("%ld", &documento);
        }
    }
    return documento;
}

/**
 * \brief Valida que la cadena de caracteres no sobrepase la longitud maxima.
 * \param nombre cadena de caracteres que se debe validar.
 * \param min Longitud mínima de la cadena.
 * \param max Longitud máxima de la cadena.
 * \return Una cadena de caracteres dentro de las longitudes pasadas.
 */
int validarNombre(char nombre[], int min, int max)
{
    while(strlen(nombre) < min || strlen(nombre) > max)
    {
        printf("Error. El nombre debe contener entre %d y %d caracteres\n\nReingrese nombre: ", min, max);
        fflush(stdin);
        gets(nombre);
    }
    return nombre[strlen(nombre)];

}

/**
 * \brief Valida un numero dentro de un rango específico.
 * \param edad entero que se debe validar.
 * \param min el numero minimo que se puede ingresar.
 * \param max el numero maximo que se puede ingresar.
 * \return Un entero dentro del rango pasado.
 */
int validarEdad(int edad, int min, int max)
{
    while(edad < min || edad > max)
    {
        printf("Error. Ingrese una edad entre %d y %d: ", min, max);
        scanf("%d", &edad);
    }

    return edad;
}

/**
 * \brief Valida un dni dentro de los rangos permitidos.
 * \param dni dni a validar.
 * \param min el numero de dni minimo valido.
 * \param max el numero de dni maximo valido.
 * \return Un numero de dni entre los rangos pasados.
 */
int validarDni(long int dni, int min, int max)
{
     while(dni < min || dni > max)
    {
        printf("Error. Ingrese un DNI valido entre %d y %d: ", min, max);
        scanf("%ld", &dni);
    }

    return dni;
}

/**
 * \brief Agrega una persona al array pasado.
 * \param lista array pasado como parametro.
 * \param tam tamaño del array.
 * \return No retorna ningun valor.
 */
void altas(EPersona lista[], int tam)
{
    int pos, auxEdad;
    long int auxDni;
    char auxNombre[70];

    pos= obtenerEspacioLibre(lista, tam);

        if(pos !=- 1)
        {

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxNombre);
            validarNombre(auxNombre, 2, 49);
            strcpy(lista[pos].nombre, auxNombre);
            printf("\nIngrese edad: ");
            scanf("%d", & auxEdad);
            lista[pos].edad=validarEdad(auxEdad, 1, 120);
            printf("\nIngrese DNI: ");
            scanf("%ld", &auxDni);
            auxDni= buscarDuplicado(lista, tam, auxDni);
            lista[pos].dni=validarDni(auxDni, 1000000, 99999999);


            lista[pos].estado= 1;

               printf("\nLos datos se cargaron correctamente.\n");
               system("pause");
            }
        else{
            system("cls");
            printf("ERROR. No hay espacio disponible para seguir cargando.\n");
            system("pause");
        }
}


/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista el array se pasa como parametro.
 * \param tam tamaño del array pasado.
 * \param dni el dni a ser buscado en el array.
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dni o [-1] si no se encontró coincidencia.
 */
int buscarPorDni(EPersona lista[], int tam, long int dni)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].dni == dni)
            {
                return i;

                break;
             }
    }
    return -1;
}

/**
 * \brief Elimina los datos de una persona elegida.
 * \param lista el array se pasa como parametro.
 * \param tam tamaño del array pasado.
 * \return No retorna ningun valor.
 */
void borrarPersona(EPersona lista[], int tam)
{
    int i;
    char respuesta;
    long int auxDni;

    printf("Ingresar DNI de la persona que se desea eliminar.\n\nDNI: ");
    scanf("%ld", &auxDni);

    i= buscarPorDni(lista, tam, auxDni);

    if(i != -1)
    {
        printf("Nombre: %s\nEdad: %d", lista[i].nombre, lista[i].edad);
        printf("\nDesea eliminar estos datos? (S/N)");
        respuesta=tolower(getch());

        if(respuesta == 's')
        {
            system("cls");
            lista[i].estado = 0;
            lista[i].dni = 0;
            printf("Los datos han sido eliminados\n");
        }
        else{
            printf("Los datos no han sido eliminados\n");
        }
     }
     else{
        printf("\nNo se ha encontrado el DNI ingresado\n");
     }
}

/**
 * \brief Ordena a las personas por nombre en orden alfabetico.
 * \param lista el array se pasa como parametro.
 * \param tam tamaño del array pasado.
 * \return No retorna ningun valor.
 */
void listar(EPersona lista[], int tam)
{
    int i, j;
    EPersona auxPersona;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                auxPersona=lista[i];
                lista[i]=lista[j];
                lista[j]=auxPersona;
            }
        }
    }

        printf("%s\t\t\t\t     DNI\tEDAD\n", "NOMBRE");

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado == 1)
        printf("\n%-20s\t\t   %8ld\t %3d", lista[i].nombre, lista[i].dni, lista[i].edad);
    }
}

/**
 * \brief Muestra un grafico por pantalla de las personas de acuerdo a su edad.
 * \param lista el array se pasa como parametro.
 * \param tam tamaño del array pasado.
 * \return No retorna ningun valor.
 */
void grafico(EPersona lista[], int tam)
{
    int i, mayor, flag=0, menor18=0, e18y35=0, mayor35=0;


        for(i=0; i<tam; i++)
        {
            if(lista[i].estado != 0 && lista[i].edad > 35)
                mayor35++;

            if(lista[i].estado != 0 && lista[i].edad < 18)
                menor18++;

            if(lista[i].estado != 0 && lista[i].edad >= 18 && lista[i].edad <= 35)
                e18y35++;
        }

        if(menor18 >= e18y35 && menor18 >= mayor35)
        {
            mayor=menor18;
        }
        else if(e18y35 >= menor18 && e18y35 >= mayor35)
        {
            mayor=e18y35;
        }
        else{

            mayor=mayor35;
        }

        //Se imprime un '*' o un espacio.
        for(i = mayor; i>0; i--)
        {
            if(menor18 >= i)
                printf("  *");

            if(e18y35 >= i)
            {
                printf("\t  *");
                flag = 1;
            }

            if(mayor35 >= i)
            {
                if( flag == 0)
                {
                    printf("\t\t  *");
                }
                else{
                    printf("\t *");
                }
            }

            printf("\n");

        }

        printf("\n<18\t18-35\t>35\n");
}
