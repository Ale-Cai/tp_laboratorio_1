#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20

int main()
{
    EPersona persona[20];
    char seguir = 's';
    int op = 0, flag = 0, carga = 0;
    long int auxDni;

    do{
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&op);

        switch(op)
        {
            case 1:
                system("cls");

                if(flag == 0){
                    inicializarEstados(persona, TAM);
                    flag = 1;
                }
                    agregarPersona(persona, TAM);
                    carga = 1;
                    system("pause");
                break;
            case 2:
                system("cls");
                if (carga == 0)
                    printf("Debe ingresar algun dato primero\n");
                else{
                    auxDni = getLongInt(auxDni, "Ingrese DNI a eliminar: ", "\n\nERROR. El DNI debe ser entre 1000000 y 99999999.\nReingrese: ", 100000, 99999999);
                    borrarPersona(persona, auxDni, TAM);
                }

                system("pause");
                break;
            case 3:
                system("cls");
                if (carga == 0)
                    printf("Debe ingresar algun dato primero\n");
                else
                    ordenarPersonas(persona, TAM);

                system("pause");
                break;
            case 4:
                system("cls");
                if (carga == 0)
                    printf("Debe ingresar algun dato primero\n");
                else
                    graficoPersonas(persona, TAM);

                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("Opcion invalida. Elija una opcion entre 1 y 5\n");
                system("pause");
        }

    }while(seguir=='s');

    return 0;
}
