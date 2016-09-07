#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<windows.h>


/**
*\brief Suma los dos numeros pasados y muestra el resultado en pantalla.
*\param numeroUno primer numero para sumar.
*\param numeroDos segundo numero para sumar.
*\return No devuelve ningun valor. Muestra el resultado de la suma por pantalla.
*
*/

void sumar(float numeroUno, float numeroDos)
{
    float suma;

    suma= numeroUno+numeroDos;
    printf("El resultado de la suma es: %.3f\n", suma);

}

/**
*\brief Resta los dos numeros pasados y muestra el resultado en pantalla.
*\param numeroUno primer numero para restar.
*\param numeroDos segundo numero para restar.
*\return No devuelve ningun valor. Muestra el resultado de la resta por pantalla.
*
*/
void restar(float numeroUno,float numeroDos)
{
    float resta;

    resta= numeroUno - numeroDos;
    printf("El resultado de la resta es: %.3f\n", resta);
}

/**
*\brief Divide el primer numero pasado por el segundo y muestra el resultado en pantalla.
*\param dividendo Es el numero a dividir.
*\param divisor Es el numero por el cual se divide.
*\return No devuelve ningun valor. Muestra el resultado de la division por pantalla.
*
*/
void dividir(float dividendo,float divisor)
{
    float division;

    if(divisor==0)
    {
        printf("ERROR. No se puede dividir por 0. Reingrese el divisor\n");
    }
    else{
    division= dividendo / divisor;
    printf("El resultado de la division es: %.3f\n", division);
    }
}

/**
*\brief Multiplica los dos numeros pasados y muestra el resultado en pantalla.
*\param numeroUno primer numero para multiplicar.
*\param numeroDos segundo numero para multiplicar.
*\return No devuelve ningun valor. Muestra el resultado de la suma por pantalla.
*
*/
void multiplicar(float numeroUno,float numeroDos)
{
    float multiplicacion;

    multiplicacion= numeroUno * numeroDos;
    printf("El resultado de la multiplicacion es: %.3f\n", multiplicacion);
}






/**
*\brief Calcula el factorial del numero pasado y retorna el resultado.
*\param numeroUno numero para calcular el factorial.
*\return Devuelve el factorial del numero pasado.
*
*/
double factorial(float numeroUno)
{
       double respuesta;

        if(numeroUno==0 || numeroUno==1)
            return 1;

       respuesta= (double)numeroUno * factorial (numeroUno - 1);

    return respuesta;
}



/**
*\brief Valida el numero y calcula el factorial.
*\param numeroUno Es el numero a factorear.
*\return No devuelve ningun valor. Muestra el factorial del numero pasado por pantalla.
*
*/
void validar_factorial(float numeroUno)
{
    double fact;

    if(numeroUno < 0)
    {
       printf("Error. No se puede calcular el factorial de un numero negativo.Reingrese el numero\n");
    }
    else if(numeroUno > 170)
    {
        printf("El resultado es INFINITO\n");
    }
    else if(floor(numeroUno) != numeroUno)
    {
        printf("ERROR. Debe ingresar un numero entero para calcular el factorial\n");
    }
    else{

        fact= factorial(numeroUno);
        printf("El factorial de %.0f es %.0f\n", numeroUno, fact);
    }


}




