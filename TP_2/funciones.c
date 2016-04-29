#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "funciones.h"
#define D 4

    EPersona lista[D];
    int men18=0, e18y35=0, may35=0;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible.
 */
int buscarEstado(EPersona lista[])
{
    int i, pos=-1;
    for(i=0; i<D; i++)
    {
        if(lista[i].estado==0)
        {
            pos=i;
            break;
        }

    }
    return pos;
}

/**
 * Ingresa y valida que el DNI se encuentre entre los valores correctos.
 * @param documento el entero se pasa como parametro.
 * @return el DNI validado.
 */
long int ingresar_dni(long int documento)
{
        printf("Ingrese DNI: ");
        scanf("%ld",& documento);

        while(documento<1000000 || documento > 99999999)
        {
            system("cls");

            printf("\nError. Ingrese un DNI entre 1000000 y 99999999\n\n DNI: ");
            scanf("%ld",&documento);
        }
        return documento;
}

/**
 * Valida que la edad se encuentre entre los valores correctos.
 * @param edad el entero se pasa como parametro.
 * @return la edad validada.
 */
int ingresar_edad(int edad)
{
        printf("Ingresar edad: ");
        scanf("%d",&edad);

        while(edad<1 || edad > 120)
        {
            system("cls");
            printf("\nError. Ingrese una edad entre 1 y 120: ");
            scanf("%d",&edad);
        }
        return edad;
}



/**
 * Permite ingresar los datos una vez que se obtuvo el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 */
void altas(EPersona lista[])
{

    system("cls");
    int i, pos, duplicado=0, auxEdad=0;
    long int auxdni=0;

    pos=buscarEstado(lista);
    if(pos!=-1)
    {
       auxdni=ingresar_dni(auxdni);

        for(i=0; i<D; i++)
        {
            if(auxdni==lista[i].dni)
            {
                duplicado=1;

            }
            break;
        }
        if(duplicado==0)
        {
            printf("Ingresar nombre: ");
            fflush(stdin);
            gets(lista[pos].nombre);
            strlwr(lista[pos].nombre);
            auxEdad=ingresar_edad(auxEdad);
            if(auxEdad >= 18)
            {
                if(auxEdad >35)
                {
                    may35++;
                }
                else
                {
                    e18y35++;
                }
            }
            else
            {
                men18++;
            }

            lista[pos].edad=auxEdad;
            lista[pos].dni=auxdni;
            lista[pos].estado=1;

        }
        else
        {
            printf("ERROR. El DNI ya fue ingresado");

        }
    }

    else
	{
		printf("No queda espacio");
	}



    system("pause");




}

/**
 * Valida la respuesta entre S y N.
 * @param respuesta el char se pasa como parametro.
 * @return la respuesta validada.
 */
char validar_S_N(char respuesta)
{
          while(respuesta != 's' && respuesta != 'n' )
          {
              printf("\nError. Ingrese una respuesta valida. s/n");
              respuesta=tolower(getch());
          }
          return respuesta;
}


/**
 * Busca por DNI y elimina los datos correspondientes al mismo si el usuario lo desea.
 * @param lista el array se pasa como parametro.
 */
void borrar(EPersona lista[])
{
    long int auxdni;
    int i, bandera=0;
    char rta;

    system("cls");
    printf("Ingrese DNI que desea eliminar: ");
    scanf("%ld",&auxdni);
    for(i=0; i<D; i++)
    {
        if(auxdni==lista[i].dni)
        {
            printf("DNI: %ld\nNombre: %s\nEdad: %d\n",lista[i].dni, lista[i].nombre, lista[i].edad);
            printf("Desea elminar estos datos? (Ingrese S o N)");
            rta=tolower(getch());
            validar_S_N(rta);
            if(lista[i].edad >=18)
            {
                if(lista[i].edad > 35)
                {
                    may35--;
                }
                else
                {
                    e18y35--;
                }
            }
            else
            {
                men18--;
            }

            if(rta=='s')
            {
                system("cls");
                lista[i].estado=0;
                printf("\nSe han eliminado los datos");
                system("pause");
            }
            else
            {
                system("cls");
                printf("\nLos datos no han sido eliminados");
                system("pause");
            }
            bandera=1;
            break;
        }
    }
    if(bandera==0)
    {
        printf("El DNI ingresado no existe");
        system("pause");
    }
}

/**
 * Ordena e imprime en pantalla los datos de las personas en orden alfabetico.
 * @param lista el array se pasa como parametro.
 */
void ordenar(EPersona lista[])
{
    int i,c;
    EPersona auxNom;

    for(i=0; i<D-1; i++)
    {
            for(c=i+1; c<D; c++)
            {
                if(strcmp(lista[i].nombre, lista[c].nombre)>0)
                {
                            auxNom=lista[i];
                            lista[i]=lista[c];
                            lista[c]=auxNom;

                }
            }
    }

            system("cls");
            printf("Lista en orden alfabetico\n");

            for(i=0; i<D; i++)
            {
                if(lista[i].estado==1)
                {
                    strupr(lista[i].nombre);
                    printf("\nNombre: %s\nDNI: %ld\nEdad: %d\n\n",lista[i].nombre, lista[i].dni, lista[i].edad);
                }
            }
              system("pause");

}

/**
 * Imprime en pantalla un grafico que muestra la cantidad de personas y sus respectivas edades.
 * @param lista el array se pasa como parametro.
 */
void grafico(EPersona lista[])
{
    int i, flag=0, mayor;

        system("cls");
        if(men18>e18y35 && men18> may35)
        {
            mayor=men18;
        }
        else
        {
            if(e18y35>men18 && e18y35> may35)
                mayor=e18y35;
            else
            {
                mayor=may35;
            }
        }

        for(i=mayor; i>0; i--)
        {
            if(men18>= i)
            {
                printf(" * ");
            }
            if(e18y35>= i)
            {
                    printf("\t  *  ");
                    flag=1;
            }

            if(may35>=i)
            {
                if(flag==0)
                    printf("\t\t * ");
             else
            {
                printf("\t * ");
            }

        }

               printf("\n");
        }

        printf("<18\t18-35\t>35\n");
        system("pause");
}










