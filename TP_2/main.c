#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define D 20



int main()
{
    EPersona persona[D];
    char seguir='s';
    int opcion=0, i;

    for(i=0; i<D; i++)
    {
        persona[i].estado=0;
    }

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altas(persona);
                break;
            case 2:
                borrar(persona);
                break;
            case 3:
                ordenar(persona);
                break;
            case 4:
                grafico(persona);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta. Por favor Ingrese una opcion entre 1 y 5");
                system("pause");

        }
    }

    return 0;
}
