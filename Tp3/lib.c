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
  Cargar_Link(pelicula, posicion);
  Cargar_puntaje_pelicula(pelicula, posicion);
  getchar();
  setbuf(stdin, NULL);
  Cargar_Pelicula_duracion(pelicula, posicion);
  (pelicula+posicion)->estado = 1;
  (pelicula + posicion) -> id = posicion + 1;
  //printf("%d", (pelicula+posicion)->id);
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

void generarPagina(Emovie *pelicula)
{
  int pos = 0;
  char *buffer = NULL, *dur = NULL, *punt = NULL;
  buffer = (char*) malloc(sizeof(char)*2000);
  punt = (char*) malloc (sizeof(char)*5);
  dur = (char*) malloc(sizeof(char)*5);
  if (buffer == NULL || punt == NULL || dur == NULL)
  {
    printf("no hay espacio en memoria");
    exit(5);
  }
  FILE *web = NULL;
  if ((web = fopen("index.html", "ab+")) == NULL)
  {
    printf("El archivo no puede abrirse");
    exit(4);
  }
  for (pos = 0 ; pos < tamanio ; pos++)
  {
    sprintf(punt, "%d", (pelicula+pos)->puntaje);
    sprintf(dur, "%d", (pelicula+pos)->duracion);
    strcat(buffer, "<article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='");
    strcat(buffer, (pelicula+pos)->linkImagen);
    strcat(buffer, "'alt=''></a><h3> <a href='#'>");
    strcat(buffer,(pelicula+pos)->titulo);
    strcat(buffer,"</a></h3><ul><li>Género: ");
    strcat(buffer, (pelicula+pos)->genero);
    strcat(buffer,"</li><li>Puntaje: ");
    strcat(buffer, punt);
    strcat(buffer,"</li><li>Duración: ");
    strcat(buffer, dur);
    strcat(buffer, "</li></ul> <p>");
    strcat(buffer, (pelicula+pos)->descripcion);
    strcat(buffer,"</p></article>");
    fwrite(buffer, sizeof(char), 1, web);
  }
  fclose(web);
}

void Cargar_Link(Emovie *pelicula, int posicion)
{
  (pelicula + posicion) -> linkImagen = (char*)malloc (sizeof(char)*1024);
  printf("Ingrese un link.\n");
  setbuf(stdin, NULL);
  getchar();
  fgets((pelicula + posicion)-> linkImagen, 1024, stdin);
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
  scanf(" %d", &((pelicula+posicion)->duracion));
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
  scanf(" %d", &((pelicula+posicion)->puntaje));
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
