#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//DECLARACION DE FUNCIONES
int suma(int a, int b);
int resta(int a, int b);
float division(float a, float b);
int multiplicacion(int a, int b);
int factorial (int a);

//DESARROLLO DE LAS FUNCIONES
int suma(int a, int b) //Funcion sumar
{
    int resultado;

    resultado=a+b;
    return resultado;
}//Suma los operandos

int resta(int a, int b) //Funcion restar
{
    int resultado;

    resultado=a-b;
    return resultado;
}//Resta los operandos

float division(float a, float b)
{
     float resultado;

     resultado=a/b;
     return resultado;

}//Divide el primer operando por el segundo operando

int multiplicacion(int a, int b) //Funcion multiplicar
{
    int resultado;

    resultado=a*b;
    return resultado;
}//Multiplica los operandos

int factorial(int a) //Funcion factorial
{
        int resultado;

        if(a==1)
        return 1;
        resultado=a* factorial(a-1);
        return (resultado);
}//Calcula el factorial del primer operando






#endif // FUNCIONES_H_INCLUDED
