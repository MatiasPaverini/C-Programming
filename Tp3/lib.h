#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 10

typedef struct
{
    char titulo[100];
    char genero[40];
    char descripcion[500];
    float puntaje;
    char linkImagen[500];
    int estado;
    int duracion;
    int id;
}Emovie;

/** \brief Busca una pelicula por medio del ID pedido al usuario.
 *
 * \param pelicula Emovie* - Lista de peliculas.
 * \param tamanio int - Tama�o del listado de peliculas.
 * \return int - Devuelve la posicion en la que se encontr� el ID ingresado o -2 en caso de no hacerlo.
 *
 */
int BuscarPosicionPorId(Emovie *pelicula, int tamanio);

/** \brief Valida el ingreso para las opciones del men� para saber si es una letra o no.
 *
 * \param opc int - opci�n ingresada por el usuario.
 * \return int - Devuelve el n�mero una vez validado.
 *
 */
int CargarOpcion(int opc);

/** \brief Inicializa el estado de los elementos del listado de pel�culas antes de ser utilizado en 0.
 *
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param tamanio int - Tama�o del listado.
 * \return void
 *
 */
void InicializarEstado(Emovie *pelicula, int tamanio);

/** \brief Busca una posicion libre (estado = 0) en el listado.
 *
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param tam int - Tama�o del listado.
 * \return int - Devuelve la posicion encontrada.
 *
 */
int BuscarPosicion(Emovie *pelicula, int tam);

/** \brief Agrega una pelicula al listado de pel�culas.
 *
 * \param pelicula Emovie* - Listado de peliculas.
 * \param tam int - tama�o del listado.
 * \return void
 *
 */
void AgregarPelicula(Emovie *pelicula, int tam);

/** \brief Elimina una pel�cula del listado.
 *
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param tam int - Tama�o del listado.
 * \return void
 *
 */
void BorrarPelicula(Emovie *pelicula, int tam);

/** \brief Crea una p�gina Web nueva con las pel�culas existentes del listado.
 *
 * \param ptr FILE* - Archivo HTML de formato texto donde se guardaran las peliculas.
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param tam int - Tama�o del listado.
 * \return void
 *
 */
void GenerarPagina(FILE *ptr, Emovie *pelicula, int tam);

/** \brief Carga el link de la im�gen que representa a la pel�cula.
 *
 * \param pelicula Emovie* - Listado de peliculas.
 * \param posicion int - Tama�o del listado.
 * \return void
 *
 */
void CargarLinkImagen(Emovie *pelicula, int posicion);

/** \brief Carga el nombre de la pel�cula.
 *
 * \param pelicula Emovie* - Listado de Pel�culas.
 * \param posicion int - Tama�o del listado.
 * \return void
 *
 */
void CargarPeliculaNombre(Emovie *pelicula, int posicion);

/** \brief Carga el genero de la pel�cula.
 *
 * \param pelicula Emovie* - Listado de peliculas.
 * \param posicion int - Tama�o del listado.
 * \return void
 *
 */
void CargarPeliculaGenero(Emovie *pelicula, int posicion);

/** \brief Carga la duracion de la pel�cula.
 *
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param posicion int - Tama�o del listado.
 * \return void
 *
 */
void CargarPeliculaDuracion(Emovie *pelicula, int posicion);

/** \brief Carga la descripci�n de la pel�cula.
 *
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param posicion int - Tama�o del listado.
 * \return void
 *
 */
void CargarPeliculaDescripcion(Emovie *pelicula, int posicion);

/** \brief Carga el puntaje de la pel�cula.
 *
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param posicion int - Tama�o del listado.
 * \return void
 *
 */
void CargarPuntajePelicula(Emovie *pelicula, int posicion);

/** \brief Modifica TODOS la pel�cula deseada
 *
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param tam int - Tama�o de la lista.
 * \return void
 *
 */
void ModificarPelicula(Emovie *pelicula, int tam);

/** \brief Guarda el listado de pel�culas en el archivo binario "Peliculas.bin".
 *
 * \param peliList Emovie* - Listado de pel�culas.
 * \param ptr FILE* - Puntero a el archivo.
 * \param tam int - Tama�o del listado.
 * \return void
 *
 */
void GuardarEnArchivoBinario(Emovie *peliList, FILE *ptr, int tam);

/** \brief Muestra las pel�culas actuales en el listado de pel�culas.
 *
 * \param peliculas Emovie* - Listado de pel�culas.
 * \param tam int - Tama�o del listado.
 * \return int - Devuelve la cantidad de pel�culas encontradas o 0 en caso de no haber.
 *
 */
int MostrarPeliculas(Emovie *peliculas, int tam);

/** \brief Carga el archivo "Peliculas.bin" en memoria, de no existir lo crea.
 *
 * \param ptr FILE* - Puntero al archivo "Peliculas.bin".
 * \return void
 *
 */
void CargarArchivo(FILE *ptr);

/** \brief Expande el espacio en memoria del listado de pel�culas.
 *
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param tamanio int - Tama�o del listado.
 * \return void
 *
 */
void ExpandirEstructura(Emovie *pelicula, int tamanio);

/** \brief Pasa la informarci�n dentro del archivo binario al listado.
 *
 * \param ptr FILE* - Puntero al archivo binario "Peliculas.bin".
 * \param pelicula Emovie* - Listado de pel�culas.
 * \param tamanio int - Tama�o del listado.
 * \return void
 *
 */
void LeerArchivoBinario(FILE *ptr, Emovie *pelicula, int tamanio);

#endif // LIB_H_INCLUDED
