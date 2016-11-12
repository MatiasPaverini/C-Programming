#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"
#define SIZE 10
Emovie *pelicula = NULL;
int tamanio = 10;

int Buscar_posicion_por_id(Emovie *pelicula)
{
  int id, iteracion;
  int *resultado = NULL;

  printf("Ingrese el numero de la pelicula.\n");
  scanf("%d", &id);

  for (iteracion = 0 ; iteracion < tamanio ; iteracion++);
  {
    if (id == (pelicula + iteracion)->id)
    {
      *resultado = (pelicula + iteracion);
      printf("exito");
    }
    else
    {
      printf("Error");
      exit(1);
    }
  }
  return *resultado;
}

void mostrarPeliculas(Emovie *movie)
{
  int i;
  for(i=0;i<tamanio;i++)
  {
    if((pelicula+i)->estado == 1)
    {
      printf("\n%s -- %s -- %s -- %d -- %d", (pelicula+i)->titulo, (pelicula+i)->genero, (pelicula+i)->descripcion, (pelicula+i)->puntaje, (pelicula+i)->duracion);
    }
  }
}

int Cargar_opcion(int opc)
{
  char opci;
  do
  {
    setbuf(stdin, NULL);
    scanf(" %c", &opci);
    //opci = (char) opc;
    if (!isdigit(opci))
    {
      printf("Ingrese solo numeros.\n");
    }
  }while (!isdigit(opci));
  opc = atoi(&opci);
  return opc;
}

void Inicializar_Estado(Emovie *pelicula)
{
	int pos = 0;
	for (pos = (tamanio - SIZE); pos < tamanio ; pos++)
	{
    (pelicula+pos)->estado = 0;
  }
}

int Buscar_Posicion(Emovie *pelicula)
{
  Emovie *aux;
  int pos, flag_realloc = -1;
  do
  {
    for (pos = 0 ; pos < tamanio ; pos ++)
    {
      if ((pelicula + pos)->estado == 0)
      {
        break;
      }
      else
      {
        tamanio = SIZE + tamanio;
        aux = (Emovie*) realloc(pelicula, sizeof(Emovie)*tamanio);
        if (aux == NULL)
        {
          exit (2);
        }
        pelicula = aux;
        free(aux);
        Inicializar_Estado(pelicula);
        flag_realloc = 1;
        //printf("No hay posiciones");
        //exit(1);
      }
    }
	}while(flag_realloc != -1);
	return pos;
}
void agregarPelicula(Emovie *pelicula)
{
  int posicion;
  posicion = Buscar_Posicion(pelicula);
  Cargar_Pelicula_Nombre(pelicula, posicion);
  Cargar_Pelicula_Descripcion(pelicula, posicion);
  Cargar_Pelicula_genero(pelicula, posicion);
  Cargar_puntaje_pelicula(pelicula, posicion);
  Cargar_Pelicula_duracion(pelicula, posicion);
  (pelicula+posicion)->estado = 1;
  (pelicula + posicion) -> id = posicion + 1;
  printf("%d", (pelicula+posicion)->id);
}

int BorrarPelicula(Emovie *pelicula)
{
  int posicion;
  for (posicion = 0 ; posicion < tamanio ; posicion++)
  {
    posicion = Buscar_posicion_por_id(pelicula);
    (pelicula + posicion)->estado = 0;
  }
  return 0;
}

void generarPagina()
{

}

void Cargar_Pelicula_Nombre(Emovie *pelicula, int posicion)
{
  (pelicula + posicion) -> titulo = (char*)malloc (sizeof(char)*40);
  printf("Ingrese un titulo.\n");
  setbuf(stdin, NULL);
  getchar();
  fgets((pelicula + posicion)-> titulo, 20, stdin);
}

void Cargar_Pelicula_genero(Emovie *pelicula, int posicion)
{
  printf("Ingrese el genero de la pelicula.\n");
  (pelicula + posicion) -> genero = (char*)malloc(sizeof(char)*20);
  setbuf(stdin, NULL);
  fgets((pelicula + posicion) -> genero, 20, stdin);
}

void Cargar_Pelicula_duracion(Emovie *pelicula, int posicion)
{
  printf("Ingrese la duracion de la pelicula (Minutos).\n");
  scanf("%d", &((pelicula+posicion)->duracion));
}

void Cargar_Pelicula_Descripcion(Emovie *pelicula, int posicion)
{
  printf("Ingrese la descripcion de la pelicula.\n");
  (pelicula + posicion) -> descripcion = (char*)malloc(sizeof(char)*200);
  setbuf(stdin,NULL);
  fgets((pelicula + posicion) -> descripcion , 200, stdin);
}

void Cargar_puntaje_pelicula(Emovie *pelicula, int posicion)
{
  printf("Ingrese el puntaje de la pelicula.\n");
  scanf("%d", &((pelicula+posicion)->puntaje));
}

int Modificar_Pelicula(Emovie *pelicula)
 {
    int resultado=0;
    int posicion;
    posicion = Buscar_posicion_por_id(pelicula);
    if(posicion != -2){
    Cargar_Pelicula_Nombre(pelicula, posicion);
    Cargar_Pelicula_genero(pelicula, posicion);
    Cargar_Pelicula_duracion(pelicula, posicion);
    Cargar_Pelicula_Descripcion(pelicula, posicion);
    resultado++;
    }
    else
    {
      printf("Error.");
    }
    return resultado;
 }
