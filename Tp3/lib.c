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
  int resultado = NULL;

  printf("Ingrese el numero de la pelicula.\n");
  scanf("%d", &id);

  for (iteracion = 0 ; iteracion < tamanio ; iteracion++);
  {
    if (id == (pelicula + iteracion)->id)
    {
      //resultado = pelicula[iteracion];
      printf("exito");
    }
    else
    {
      printf("Error");
      exit(1);
    }
  }
  return resultado;
}

int Cargar_opcion(int opc)
{
  char opci;
  do
  {
    getchar();
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
 // Emovie *aux;
  int pos, flag_realloc = -1;
  //aux = (Emovie*) realloc(pelicula, sizeof(Emovie)*SIZE);
  do
  {
    for (pos = 0 ; pos < tamanio ; pos ++)
    {
      if ((pelicula + pos)->estado == 0)
      {
        break;
      }
      /*else
      {
        if (pos == tamanio)
        {
          tamanio = SIZE + tamanio;
          aux = (Emovie*) realloc(pelicula, sizeof(Emovie)*tamanio);
        }
      }
        if (aux == NULL)
        {
          printf("No se puede conseguir mas espacio.");
          exit (2);
        }
        pelicula = aux;
        free(aux);
        Inicializar_Estado(pelicula);
        flag_realloc = 1;
        break;
        //printf("No hay posiciones");
        //exit(1);
      //}*/
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
  int posicion, id, resultado = 0;
    printf("Ingrese el id de la pelicula que busca.\n");
    setbuf(stdin, NULL);
    scanf("%d", &id);
  for (posicion = 0 ; posicion < tamanio ; posicion++)
  {
    //posicion = Buscar_posicion_por_id(pelicula);
    if (id == pelicula[posicion].id)
    {
      (pelicula + posicion)->estado = 0;
      resultado = 1;
      break;
    }
  }
  return resultado;
}

void generarPagina(Emovie *pelicula)
{
  FILE *pArchPelis = NULL;
  FILE *pArchHTML = NULL;
  char nombre[2000];
  pArchPelis = fopen("Pelis.bin", "wb+");
  if(pArchPelis == NULL)
    {
      printf("error");
      exit(4);
    }
  pArchHTML = fopen(nombre,"w+");
  if(pArchPelis == NULL)
    {
      printf("error");
      exit(5);
    }
  while(!feof(pArchPelis))
    {
      fflush(pArchPelis);
      fflush(pArchHTML);
      fscanf(pArchPelis,"%[^,],%[^,],%[^,],%d,%d,%[^,]\n", pelicula->titulo, pelicula->genero, pelicula->descripcion, pelicula->duracion, pelicula->puntaje,pelicula->linkImagen);
      printf("\n%s\n%s\n%s\n%d\n%d\n%s\n\n", pelicula->titulo, pelicula->genero, pelicula->descripcion, pelicula->duracion, pelicula->puntaje, pelicula->linkImagen);
      fprintf(pArchHTML,"<article class='col-md-4 article-intro'>\n");
      fprintf(pArchHTML,"\t<a href='#'>\n");
      fprintf(pArchHTML,"\t\t<img class=''alt='%s'\n>", pelicula->linkImagen);
      fprintf(pArchHTML,"\t</a>\n");
      fprintf(pArchHTML,"\t<h3>\n");
      fprintf(pArchHTML,"\t\t<a href='#'>%s</a>\n", pelicula->titulo);
      fprintf(pArchHTML,"\t</h3>\n");
      fprintf(pArchHTML,"\t<ul>");
      fprintf(pArchHTML,"\t\t<li>Género:%s</li>\n", pelicula->genero);
      fprintf(pArchHTML,"\t<li>Puntaje:%d</li>\n", pelicula->puntaje);
      fprintf(pArchHTML,"\t<li>Duración:%d</li>\n", pelicula->duracion);
      fprintf(pArchHTML,"\t</ul>\n");
      fprintf(pArchHTML,"\t<p>%s</p>\n", pelicula->descripcion);
    }
  fclose(pArchPelis);
  fclose(pArchHTML);
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
  (pelicula + posicion) -> titulo = (char*)malloc (sizeof(char)*60);
  printf("Ingrese un titulo.\n");
  setbuf(stdin, NULL);
  getchar();
  fgets((pelicula + posicion)-> titulo, 60, stdin);
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
  (pelicula + posicion) -> descripcion = (char*)malloc(sizeof(char)*500);
  setbuf(stdin,NULL);
  fgets((pelicula + posicion) -> descripcion , 500, stdin);
}

void Cargar_puntaje_pelicula(Emovie *pelicula, int posicion)
{
  printf("Ingrese el puntaje de la pelicula.\n");
  scanf(" %d", &((pelicula+posicion)->puntaje));
}

int Modificar_Pelicula(Emovie *pelicula)
 {
    int resultado= 0;
    int posicion, id;
  //  posicion = Buscar_posicion_por_id(pelicula);
    printf("Ingrese el id de la pelicula que busca.\n");
    setbuf(stdin, NULL);
    scanf("%d", &id);
    for (posicion = 0 ; posicion < tamanio ; posicion++)
    {
      if(id == pelicula[posicion].id && pelicula[posicion].estado == 1)
      {
        Cargar_Pelicula_Nombre(pelicula, posicion);
        Cargar_Pelicula_Descripcion(pelicula, posicion);
        Cargar_Pelicula_genero(pelicula, posicion);
        Cargar_Link(pelicula, posicion);
        Cargar_Pelicula_duracion(pelicula, posicion);
        Cargar_puntaje_pelicula(pelicula,posicion);
        resultado++;
        break;
      }
      else
      {
        printf("Error.");
        exit(6);
      }
    }
    printf("Se ha modificado la pelicula con exito");
    return resultado;
 }
