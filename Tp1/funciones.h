#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "funciones.h"
/**  \brief sumar - Esta funcion ejecuta la suma de ambos operandos ingresados en caso de estar cargados, caso contrario no ejecuta la suma.
*
*  \param numero1 - La variable toma el valor del operando A del main.
*  \param numero2 - La variable toma el valor del operando B del main.
*  \param resultado - La variable que tomara el resultado de numero1 + numero2.
*  \return resultado - Es el resultado de la funcion que se va a devolver al main, en caso de no haber sido posible ejecutar la suma sera 0, caso contrario devuelve
la suma de numero1 + numero2.
*/
float sumar (float numero1, float numero2);
/** \brief factorear - Esta funcion ejecuta el factoreo del operando A ingresado en el main (si esta cargado), caso contrario no ejecuta el factoreo.
 *
 * \param numero1 - Toma el valor del operando A del main.
 * \param numero2 - Toma el valor del operando -1.
 * \param resultado - Toma el valor sin coma de 'numero1' y lo compara, en caso de ser numero entero se lo utiliza para el resto de las cuentas.
 * \return z - Devuelve el resultado del factoreo en entero, en caso de ser 0 devuelve 1 y en caso de ser numero decimal devuelve -1.
 *
 */
float factorear (float numero1, float numero2);
/** \brief dividir - Esta funcion ejecuta la division entre ambos operandos ingresados (si estan cargados), caso contrario no ejecuta la division.
*
* \param numero1 - La variable toma el valor del operando A del main.
* \param numero2 - La variable toma el valor del operando B del main, en caso de ser 0 no se ejecuta la division.
* \return resultado - Devuelve el resultado de la division en caso de ejecutarse, en caso de no hacerlo devuelve 0.
*/
float dividir (float numero1, float numero2);
/** \brief multiplicar - Esta funcion ejecuta la multiplicacion entre ambos operandos ingresados (si estan cargados), caso contrario no se ejecuta la multiplicacion.
 *
 * \param numero1 - La variable toma el valor del operando A del main.
 * \param numero2 - La variable toma el valor del operando B del main.
 * \return resultado - Devuelve el resultado de la multiplicacion en caso de que se ejecute, caso contrario devuelve 0
 *
 */
float multiplicar (float numero1, float numero2);
/** \brief restar - Esta funcion ejecuta la resta de ambos operandos ingresados (si estan cargados), caso contrario no ejecuta la resta.
 *
*  \param numero1 - La variable toma el valor del operando A del main.
*  \param numero2 - La variable toma el valor del operando B del main.
*  \param resultado - La variable que tomara el resultado de numero1 - numero2.
 * \return resultado - Devolvera el resultado de la resta entre numero1 - numero2 en caso de tener ambos operandos cargados. En caso de no poder ejecutar la resta queda inicializado
  en 0.
 *
*/
float restar (float numero1, float numero2);
/** \brief ingresarNumeros - Toma los valores que ingrese el usuario a partir de una cadena para verificar si es efectivamente un numero.
En caso de ser un numero valido entonces lo pasa a float.
 *
 * \param numero - Este parametro toma como valor la conversión de la cadena en caso de ser un numero valido. Caso contrario solo queda inicializado en 0.
 * \return numero - Retorna numero al main y así queda cargado el numero en la calculadora
 *
 */
float ingresarNumeros (float numero);
/** \brief SeleccionarOpcion - esta funcion evalua el ingreso para las opciones de la calculadora, evaluando que se hayan ingresado numeros y no letras.
*
* \param numero - El parametro recibido por la funcion desde el main.
* \return numero - si el procedimiento es correcto se devuelve el numero ingresado, caso contrario se pide que se reingrese un valor.
**/
int SeleccionarOpcion(int numero);
#endif
