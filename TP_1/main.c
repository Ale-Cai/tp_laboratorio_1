#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    int terminar = 0;
    int opcion=0;
    int flag1 = 0;
    int flag2 = 0;
    float num1;
    float num2;

    do
    {
        system("cls");
        printf("1- Ingresar 1er operando (A = %.2f)\n", num1);
        printf("2- Ingresar 2do operando (B = %.2f)\n", num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("\n\nPor favor elija una opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Por favor ingrese el primer operando: ");
                scanf("%f", &num1);
                flag1 = 1;
                break;

            case 2:
                system("cls");
                printf("Por favor ingrese el segundo operando: ");
                scanf("%f", &num2);
                flag2 = 1;
                break;

            case 3:
                system("cls");

                if(flag1 != 1 || flag2 != 1)
                    printf("\a\aERROR. Debe ingresar ambos operandos antes de realizar esta accion\n");

                else
                    printf("El resultado de la suma es %.2f\n", sumar(num1, num2));


                system("pause");
                break;

            case 4:
                system("cls");

                if(flag1 != 1 || flag2 != 1)
                    printf("\a\aERROR. Debe ingresar ambos operandos antes de realizar esta accion\n");

                else
                    printf("El resultado de la resta es %.2f\n", restar(num1, num2));


                system("pause");
                break;

            case 5:
                system("cls");

                if(flag1 != 1 || flag2 != 1)
                    printf("\a\aERROR. Debe ingresar ambos operandos antes de realizar esta accion\n");

                else
                    validarDivision(num1, num2);


                system("pause");
                break;

            case 6:
                system("cls");

                if(flag1 != 1 || flag2 != 1)
                    printf("\a\aERROR. Debe ingresar ambos operandos antes de realizar esta accion\n");

                else
                    printf("El resultado de la multiplicacion es %.2f\n", multiplicar(num1, num2));

                system("pause");
                break;

            case 7:
                system("cls");

                if(flag1 != 1 || flag2 != 1)
                    printf("\a\aERROR. Debe ingresar ambos operandos antes de realizar esta accion\n");

                else
                    validarFactorial(num1);

                system("pause");
                break;

            case 8:
                system("cls");

                if(flag1 != 1 || flag2 != 1)
                    printf("\a\aERROR. Debe ingresar ambos operandos antes de realizar esta accion\n");

                else
                {
                    printf("El resultado de la suma es %.2f\n", sumar(num1, num2));
                    printf("El resultado de la resta es %.2f\n", restar(num1, num2));
                    validarDivision(num1, num2);
                    printf("El resultado de la multiplicacion es %.2f\n", multiplicar(num1, num2));
                    validarFactorial(num1);
                }


                system("pause");

                break;
            case 9:
                terminar = 1;
                break;
            default:
                system("cls");
                printf("\a\aERROR. Por favor elija una opcion valida. (1 a 9)\n");
                system("pause");
        }

    }while(terminar == 0);

    return 0;
}

