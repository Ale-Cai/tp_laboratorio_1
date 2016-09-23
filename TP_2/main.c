#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include<windows.h>
#define TAM 20 //tamaño del array de persona

int main()
{
    EPersona persona[TAM];
    int opcion=0, flag=0, carga=0;

    inicializarEstado(persona, TAM);

    while(flag == 0)
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\n\nElija una opcion:  ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                altas(persona, TAM);
                carga = 1;
                break;

            case 2:
                system("cls");

                if(carga == 0)
                {
                    printf("ERROR. Cargue los datos primero.\n\n");
                    system("pause");
                }
                else{
                    borrarPersona(persona, TAM);
                    system("pause");
                }
                    break;
            case 3:
                system("cls");

                if(carga == 0)
                {
                    printf("ERROR. Cargue los datos primero.\n\n");
                    system("pause");
                }
                else{
                    listar(persona, TAM);
                    system("pause");
                }
                    break;

            case 4:
                system("cls");

                if(carga == 0)
                {
                    printf("ERROR. Cargue los datos primero.\n\n");
                    system("pause");
                }
                else{
                    grafico(persona, TAM);
                    system("pause");
                }
                break;

            case 5:
                flag = 1;
                break;

            default:
                printf("Error. Ingrese una opcion valida.\n");
                system("pause");

        }
    }

    return 0;
}
