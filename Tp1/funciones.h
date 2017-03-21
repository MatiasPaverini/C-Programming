#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "funciones.h"
/**  \brief sumar - Esta funcion ejecuta la suma de ambos operandos ingresados en caso de estar cargados, caso contrario no ejecuta la suma.
*
*  \param x - La variable toma el valor del operando A del main.
*  \param y - La variable toma el valor del operando B del main.
*  \param z - La variable que tomara el resultado de x + y.
*  \return z - Es el resultado de la funcion que se va a devolver al main, en caso de no haber sido posible ejecutar la suma sera 0, caso contrario devuelve
la suma de x + y.
*/
float sumar (float x, float y);
/** \brief factorear - Esta funcion ejecuta el factoreo del operando A ingresado en el main (si esta cargado), caso contrario no ejecuta el factoreo.
 *
 * \param x - Toma el valor del operando A del main.
 * \param y - Toma el valor del operando -1.
 * \param z - Toma el valor sin coma de 'x' y lo compara, en caso de ser numero entero se lo utiliza para el resto de las cuentas.
 * \return z - Devuelve el resultado del factoreo en entero, en caso de ser 0 devuelve 1 y en caso de ser numero decimal devuelve -1.
 *
 */
float factorear (float x, float y);
/** \brief dividir - Esta funcion ejecuta la division entre ambos operandos ingresados (si estan cargados), caso contrario no ejecuta la division.
*
* \param x - La variable toma el valor del operando A del main.
* \param y - La variable toma el valor del operando B del main, en caso de ser 0 no se ejecuta la division.
* \return z - Devuelve el resultado de la division en caso de ejecutarse, en caso de no hacerlo devuelve 0.
*/
float dividir (float x, float y);
/** \brief multiplicar - Esta funcion ejecuta la multiplicacion entre ambos operandos ingresados (si estan cargados), caso contrario no se ejecuta la multiplicacion.
 *
 * \param x - La variable toma el valor del operando A del main.
 * \param y - La variable toma el valor del operando B del main.
 * \return z - Devuelve el resultado de la multiplicacion en caso de que se ejecute, caso contrario devuelve 0
 *
 */
float multiplicar (float x, float y);
/** \brief restar - Esta funcion ejecuta la resta de ambos operandos ingresados (si estan cargados), caso contrario no ejecuta la resta.
 *
*  \param x - La variable toma el valor del operando A del main.
*  \param y - La variable toma el valor del operando B del main.
*  \param z - La variable que tomara el resultado de x - y.
 * \return z - Devolvera el resultado de la resta entre x - y en caso de tener ambos operandos cargados. En caso de no poder ejecutar la resta queda inicializado
  en 0.
 *
*/
float restar (float x, float y);
/** \brief ingresarNumeros - Toma los valores que ingrese el usuario a partir de una cadena para verificar si es efectivamente un numero.
En caso de ser un numero valido entonces lo pasa a float.
 *
 * \param x - Este parametro toma como valor la conversión de la cadena en caso de ser un numero valido. Caso contrario solo queda inicializado en 0.
 * \return x - Retorna x al main y así queda cargado el numero en la calculadora
 *
 */
float ingresarNumeros (float x);
/** \brief SeleccionarOpcion - esta funcion evalua el ingreso para las opciones de la calculadora, evaluando que se hayan ingresado numeros y no letras.
*
* \param numero - El parametro recibido por la funcion desde el main,
**/
int SeleccionarOpcion(int numero);
/**
**/
char ValidarCierre (char decision);
#endif
