#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion, x=0, y=0;
    float resp;
    while(seguir=='s')
    {
        system("cls");
        printf("\n1- Ingresar 1er operando (A=%d)\n",x);
        printf("2- Ingresar 2do operando (B=%d)\n",y);
        printf("3- Calcular la suma (A+B)\n", x,y);
        printf("4- Calcular la resta (A-B)\n", x, y);
        printf("5- Calcular la divisi%cn (A/B)\n", 162, x, y);
        printf("6- Calcular la multiplicaci%cn (A*B)\n", 162, x, y);
        printf("7- Calcular el factorial (A!)\n", x);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("\nElija una opci%cn\n",162);
        scanf("%d",&opcion);


        while(opcion<1 || opcion>9) //Validacion de opciones entre 1 y 9.
        {
            printf("ERROR. Ingrese una opcion entre 1 y 9: ");
            scanf("%d",& opcion);
        }//Fin de la validacion.

        switch(opcion)//Comienzo del switch para seleccionar la opcion.
        {
            case 1: //Carga del primer operando.
                system("cls");
                printf("Ingrese 1er operando:\n");
                scanf("%d",&x);
                break;
            case 2: //Carga del segundo operando.
                system("cls");
                printf("Ingrese 2do operando:\n");
                scanf("%d",&y);
                break;
            case 3: //Suma.
                system("cls");
                resp= suma(x,y);
                printf("\nLa suma es: %.0f\n", resp);
                system("pause");
                break;
            case 4: //Resta.
                system("cls");
                resp=resta(x,y);
                printf("\nLa resta es: %.0f\n", resp);
                system("pause");
                break;
            case 5: //Division.
                system("cls");
                 if(y==0)
                    {
                        printf("No se puede dividir entre 0, reingrese el segundo operando\n"); //Si el segundo operando es "0" se muestra el mensaje de error.
                        system("pause");
                    }
                 else
                    {
                        resp=division(x,y);
                        printf("\nLa division es: %.2f\n", resp);
                        system("pause");
                    }
                break;
            case 6: //Multiplicacion
                system("cls");
                resp=multiplicacion(x,y);
                printf("\nLa multiplicacion es: %.0f\n", resp);
                system("pause");
                break;
            case 7: //Factorial.
                system("cls");
                if(x<1)
                {
                    printf("\nERROR. Ingrese un numero positivio para calcular factorial.\n");
                    system("pause");
                }
                else
                {
                resp=factorial(x);
                printf("\nEl factorial de %d es: %.0f\n", x, resp);
                system("pause");
                }
                break;
            case 8: //Todas las operaciones.
                system("cls");
                resp=suma( x, y);
                printf("\nLa suma es: %.0f\n", resp);
                resp=resta(x, y);
                printf("\nLa resta es: %.0f\n", resp);
                resp=division( x, y);
                if(y==0)
                {
                    printf("\nNo se puede dividir entre 0, reingrese el segundo operando\n");
                }

                 else
                 {
                    resp=division(x,y);
                    printf("\nLa division es: %.2f\n", resp);
                 }

                resp=multiplicacion(x,y);
                printf("\nLa multiplicacion es: %.0f\n", resp);
                if(x<1)
                {
                    printf("ERROR. Ingrese un numero positivio para calcular factorial.\n");
                }

                else
                {
                resp=factorial(x);
                printf("\nEl factorial de %d es: %.0f\n", x, resp);
                }

                system("pause");
                break;
            case 9: //Salida de la calculadora.
                seguir = 'n';
                break;
        }//Fin del switch

    }//Fin del while
            return 0;

}//Final del main
