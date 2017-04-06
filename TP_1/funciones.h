#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


/** \brief Suma los numero pasados
 *
 * \param num1 numero a sumar
 * \param num2 numero a sumar
 * \return resultado de la suma
 *
 */

float sumar(float num1, float num2);


/** \brief Resta los numeros pasados
 *
 * \param num1 numero a restar
 * \param num2 numero a restar
 * \return resultado de la resta
 *
 */

float restar(float num1, float num2);


/** \brief Divide los numeros pasados
 *
 * \param num1 dividendo
 * \param num2 divisor
 * \return resultado de la division
 *
 */

float dividir(float num1, float num2);


/** \brief valida el divisor y muestra el resultado de la division
 *
 * \param num1 dividendo
 * \param num2 divisor
 * \return no retorna valor, muestra el resultado por pantalla o mensaje de error segun corresponda
 *
 */

void validarDivision(float num1, float num2);


/** \brief Multiplica los numeros pasados
 *
 * \param num1 numero a multiplicar
 * \param num2 numero a multiplicar
 * \return resultado de la multiplicacion
 *
 */

float multiplicar(float num1, float num2);


/** \brief calcula el factorial del numero pasado
 *
 * \param num1 numero a factorizar
 * \return numero factorizado
 *
 */

double factorial(float num);


/** \brief Valida que el numero pasado sea un numero natural y calcula su factorial
 *
 * \param num1 numero a validar
 * \return no devuelve valor, muestra el mensaje de error o el resultado por pantalla
 *
 */

void validarFactorial(float num);





#endif // FUNCIONES_H_INCLUDED
