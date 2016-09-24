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
 *  Inicializa el estado de todas las posiciones
*/
void Inicializar_Estado(Emovie *pelicula);

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
int BorrarPelicula();

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina();

void Cargar_Pelicula_Descripcion(Emovie *pelicula, int posicion);

void Cargar_Pelicula_duracion(Emovie *pelicula, int posicion);

void Cargar_Pelicula_genero(Emovie *pelicula, int posicion);

void Cargar_Pelicula_Nombre(Emovie *pelicula, int posicion);

void Cargar_puntaje_pelicula(Emovie *pelicula, int posicion);

int Modificar_Pelicula(Emovie *pelicula);


#endif // LIB_H_INCLUDED
