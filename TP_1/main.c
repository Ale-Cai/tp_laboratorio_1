#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include "funciones.h"

int main()
{
   float num1=0, num2=0;
   int op, flag=0;


   while(flag==0)
   {
        system("cls");
        printf("MENU DE OPCIONES\n\n");
        printf("1. Ingresar primer operando (A=%.3f)\n",num1);
        printf("2. Ingresar segundo operando (B=%.3f)\n",num2);
        printf("3. Sumar (A+B)\n");
        printf("4. Restar(A-B)\n");
        printf("5. Dividir (A/B)\n");
        printf("6. Multiplicar (A*B)\n");
        printf("7. Factorial (A!)\n");
        printf("8. Calcular todas las operaciones\n");
        printf("9. Salir\n");

        printf("\nElija una opcion: ");
        scanf("%d",& op);
            switch(op)
            {
            case 1:
                system("cls");
                printf("Ingrese primer operando: ");
                scanf("%f",& num1);
                break;

            case 2:
                system("cls");
                printf("Ingrese segundo operando: ");
                scanf("%f",& num2);
                break;

            case 3:
                system("cls");
                sumar(num1, num2);
                system("pause");
                break;

            case 4:
                system("cls");
                restar(num1, num2);
                system("pause");
                break;

            case 5:
                system("cls");
                dividir(num1, num2);
                system("pause");
                break;

            case 6:
                system("cls");
                multiplicar(num1, num2);
                system("pause");
                break;

            case 7:
                system("cls");
                validar_factorial(num1);
                system("pause");
                break;

            case 8:
                system("cls");
                sumar(num1, num2);
                restar(num1, num2);
                dividir(num1, num2);
                multiplicar(num1, num2);
                validar_factorial(num1);
                system("pause");
                break;

            case 9:
                flag=1;
                break;

            default:
                system("cls");
                printf("ERROR. Ingrese una opcion valida (Entre 1 y 9)\n");
                system("pause");

            }

        }

        return 0;
}

