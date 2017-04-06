#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"




float sumar(float num1, float num2)
{
    float resultado;

    resultado = num1 + num2;

    return resultado;
}


float restar(float num1, float num2)
{
    float resultado;

    resultado = num1 - num2;

    return resultado;
}


float dividir(float num1, float num2)
{
    float resultado;

    resultado = num1 / num2;

    return resultado;
}


void validarDivision(float num1, float num2)
{
    float resultado;

    if(num2 == 0)
        printf("\a\aERROR. No se puede dividir por 0. Por favor cambie el divisor\n");
    else
    {
        resultado = dividir(num1, num2);
        printf("El resultado de la division es %.2f\n", resultado);
    }


}


float multiplicar(float num1, float num2)
{
    float resultado;

    resultado = num1 * num2;

    return resultado;
}


double factorial(float num)
{
    double resultado;

    if(num == 1)
        resultado = 1;
    else
        resultado = num * factorial(num - 1);

    return resultado;
}


void validarFactorial(float num)
{
    double resultado;

    if(num < 0)
        printf("\a\aERROR. No se puede calcular el factorial de un numero negativo\n");

    else if(num == 0)
            printf("El factorial de 0 es 1\n");

    else if(floor(num) != num)
        printf("Error. Debe ingresar un numero natural para calcular el factorial\n");

    else{

       resultado = factorial(num);
       printf("El factorial de %.f es %.lf\n", num, resultado);
    }

}




