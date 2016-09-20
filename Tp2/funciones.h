#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    char nombre[79];
    long int dni;
    int estado;
    int edad;
}Persona;
/** \brief Agregar_Persona - La funcion es llamada desde el main y carga una persona en la estructura.
*
*   \param posicion - obtiene la posicion de la estructura donde se va a cargar el estado de la persona.
*
*/
void Agregar_Persona();
/** \brief Borrar_Persona - Se busca por medio del DNI una persona y se cambia su estado a 0, lo cual significa que no será tomado en cuenta para el registro.
*   \param posicion - Obtiene el valor de la posicion dentro de la estructura donde se entuentra el DNI solicitado.
*
*/
void Borrar_Persona();
/** \brief Imprimir_Lista - Imprime la lista de personas cargadas de manera alfabética (A-Z) o con DNI más chico al más grande en caso de tener nombres iguales.
*   \param posicion1 - valor de iteracion para el primer objeto a comparar.
*   \param posicion2 - valor de iteracion para el segundo objeto a comparar.
*
*/
void Imprimir_Lista();
/** \brief Graficar - Genera un grafico de barras para mostrar la cantidad de personas con distintas edades ingresadas.
*   \param iteracion_busqueda - valor asignado a la busqueda de valores de los acumuladores.
*   \param i - limite de cantidad en el grafico de barras, luego se lo usa de referencia para iterar y armar el grafico de arriba hacia abajo.
*   \param menor_de_edad - acumulador de cuantas personas menores de 18 años o con 18 años fueron ingresadas.
*   \param adulto - acumulador de cuantas personas ingresadas con una edad mayor a 18 años y menor de 36 existen en la base de datos.
*   \param mayor_de_35 - acumulador de cuantas personas mayores de 35 fueron ingresadas.
*   \param flag - bandera de estado para armar el grafico, en caso de estar en 0 se hace una doble tabulacion, en caso de estar en 1 se hace solo una.
*   \param mayor - toma el valor el acumulador con la mayor cantidad de personas ingresadas.
*
*/
void Graficar();
/** \brief Inicializacion - inicializa las variables de estado en 0.
*   \param posicion_aux - valor de iteracion para avanzar en el array.
*
*
*/
void Inicializacion();
/** \brief Cargar_Nombre - carga el nombre de la persona ingresada y lo guarda dentro de la estructura.
*   \param nombre - cadena de caracteres donde se van a ingresar todos los nombres y apellidos deseados.
*   \param nombre_completo - cadena de caracteres donde se van a concatenar todos los nombres y apellidos ingresados, luego guardara el valor en la estructura.
*   \param posicion - obtiene el valor de la posicion en la que se va a ubicar el nombre dentro de la estructura.
*   \param i - valor de referencia para controlar si el usuario ingresa un espacio y asi seguir cargando datos en la cadena.
*   \param iteracion - avlor de referencia para la iteracion del bucle en el que se comprueba si se cargo correctamente.
*   \param lower_case - valor de referencia para el bucle en el que se pasa todos los caracteres ingresados a minuscula.
*
*/
void Cargar_Nombre();
/** \brief Cargar_DNI - carga el DNI de la persona dentro de la estructura.
*   \param posicion - toma el valor del lugar donde se va a cargar el DNI.
*   \param largo - toma como valor el largo del DNI, minimo 7, maximo 9.
*   \param flag - valor de referencia para el bucle en el que se hacen las comprobaciones generales.
*   \param iteracion - valor de referencia para la posicion en el bucle de comprobacion si el ingreso de datos es valido o no.
*   \param dni_repeticion - valor de referencia para la posicion de la estructura en el bucle para averiguar si ya existe el DNI.
*   \param dni_n - tomara el valor de la cadena dni y lo transforma en entero (largo) para luego pasarlo a la estructura.
*   \param dni - cadena de caracteres en la que se ingresa el DNI y se hace comprobaciones.
*   \param fin - dato para confirmacion si es efectivamente el DNI que se quiere ingresar.
*
*/
void Cargar_DNI();
/** \brief Cargar_Edad - carga la edad de la persona dentro de la estructura.
*   \param posicion - obtiene el valor de la posicion en la que se va a ubicar la edad.
*   \param flag - valor de referencia para las comprobaciones generales.
*   \param edads - obtiene el valor de la cadena edad luego de ser comprobada correctamente y luego la guarda en la estructura.
*   \param iteracion - valor de referencia para el bucle de comprobacion de datos ingresados en la caedna.
*   \param edad - cadena de caracteres donde se va a ingresar la edad para luego hacerle sus comprobaciones.
*
*/
void Cargar_Edad();
/** \brief Buscar_casilla_desocupada - Busca la posicion disponible para poder cargar una nueva persona.
*   \param pos - valor de iteracion para la busqueda de estado en 0.
*   \return pos - devuelve el valor de pos.
*/
int Buscar_casilla_desocupada(int pos);
#endif // FUNCIONES_H_INCLUDED

