#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    char *titulo;
    char *genero;
    char *descripcion;
    int puntaje;
    char *linkImagen;
    int estado;
    int duracion;
    int id;
}Emovie;

/**
 *  Carga la opcion del menu y revisa que sea correcta
 *  @param opci variable que toma la opcion ingresada para ser evaluada
 *  @return retorna el valor en caso de ser valido
*/
int Cargar_opcion(int opc);

/**
 *  Inicializa el estado de todas las posiciones en 0
 *  @param  pos la posicion del array en el bucle
*/
void Inicializar_Estado(Emovie *pelicula);

/**
 *  Busca una posicion libre (estado 0) en el array para una cargar nueva, en caso de no haber posicion
 hace un realloc para obtener nuevas
 *  @param aux estructura auxiliar para crear redimensionar la lista de peliculas originales
 *  @param pos posicion del array dentro del bucle
 *  @param flag_realloc flag de estado, si pasa por el realloc lo modifica para así repetir la busqueda de espacio
 *  @return devuelve la posicion disponible dentro del array
*/
int Buscar_Posicion(Emovie *pelicula);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void agregarPelicula(Emovie *pelicula);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int BorrarPelicula(Emovie *pelicula);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 */
void generarPagina(Emovie *pelicula);

/**
 *  Carga la descripcion de la pelicula
*/
void Cargar_Pelicula_Descripcion(Emovie *pelicula, int posicion);

/**
 * Carga la duracion de la pelicula
*/
void Cargar_Pelicula_duracion(Emovie *pelicula, int posicion);

/**
 * Carga el genero de la pelicula
*/
void Cargar_Pelicula_genero(Emovie *pelicula, int posicion);

/**
 * Carga el nombre de la pelicula
*/
void Cargar_Pelicula_Nombre(Emovie *pelicula, int posicion);

/**
 *  carga el puntaje de la pelicula
*/
void Cargar_puntaje_pelicula(Emovie *pelicula, int posicion);

void Cargar_Link(Emovie *pelicula, int posicion);

/**
 *  Modifica los datos de la pelicula seleccionada por id
 @param id carga por el id de la pelicula seleccionada
 @param resultado flag de estado, se modifica en caso de que la operacion haya sido correcta
 @param posicion lugar de memoria donde se encuentra actualmente el array de estructuras
 @return devuelve 0 en caso de no haber podido modificar la pelicula o 1 en caso de haberlo hecho exitosamente
*/
int Modificar_Pelicula(Emovie *pelicula);


#endif // LIB_H_INCLUDED
