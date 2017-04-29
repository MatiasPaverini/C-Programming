#include "lib.h"

int BuscarPosicionPorId(Emovie *pelicula, int tamanio)
{
  int id = 0, iteracion = 0;
  int resultado = -2;

  printf("Ingrese el id (numero) de la pelicula.\n");
  scanf("%d", &id);

  for (iteracion = 0 ; iteracion < tamanio ; iteracion++)
  {
    if (id == (pelicula + iteracion)->id)
    {
      resultado = iteracion;
    }
  }
  return resultado;
}

int CargarOpcion(int opc)
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

void InicializarEstado(Emovie *pelicula, int tamanio)
{
	int pos = 0;
	for (pos = 0; pos < tamanio ; pos++)
	{
    if ((pelicula + pos)->estado == 1)
    {
      continue;
    }
    (pelicula+pos)->estado = 0;
  }
}

int BuscarPosicion(Emovie *pelicula, int tam)
{
  int pos;
  for (pos = 0 ; pos < tam ; pos ++)
  {
    if ((pelicula + pos)->estado == 0)
    {
      break;
    }
  }
	return pos;
}

void AgregarPelicula(Emovie *pelicula, int tam)
{
  int posicion;
  posicion = BuscarPosicion(pelicula, tam);
  CargarPeliculaNombre(pelicula, posicion);
  CargarPeliculaDescripcion(pelicula, posicion);
  CargarPeliculaGenero(pelicula, posicion);
  CargarPuntajePelicula(pelicula, posicion);
  CargarPeliculaDuracion(pelicula, posicion);
  CargarLinkImagen(pelicula, posicion);
  (pelicula+posicion)->estado = 1;
  (pelicula + posicion) -> id = posicion + 1;
}

void BorrarPelicula(Emovie *pelicula, int tam)
{
  int posicion;
  posicion = BuscarPosicionPorId(pelicula, tam);
  if (posicion != -2)
  {
    (pelicula + posicion)->estado = 0;
    printf("Borrado exitoso.\n");
  }

  else
    printf("No existe pelicula con el ID ingresado.\n");
}

void GenerarPagina(FILE *ptr, Emovie *pelicula, int tam)
{
  int posicion;
  if ((ptr = fopen("index.html", "w+")) == NULL)
  {
    printf("ERROR.\n");
    exit(5);
  }
  for (posicion = 0; posicion < tam; posicion++)
  {
    if ((pelicula + posicion)->estado == 1)
    {
      fprintf(ptr,"<article class='col-md-4 article-intro'> <a  href='#'> <img class ='img-responsive- img-rounded' src='%s' atl=''> </a> <h3> <a href='#'>%s</a> </h3> <ul> <li>Género: %s</li> <li>Puntaje: %.02f</li> <li>Duracion: %d</li> </ul> <p> %s </p> </article>", (pelicula + posicion)->linkImagen, (pelicula + posicion)->titulo, (pelicula + posicion)->genero, (pelicula + posicion)->puntaje, (pelicula + posicion)->duracion, (pelicula + posicion)->descripcion);
    }
  }
  fclose(ptr);
}

void CargarLinkImagen(Emovie *pelicula, int posicion)
{
  printf("Ingrese el link de la imagen para la pelicula.\n");
  setbuf(stdin, NULL);
  gets((pelicula + posicion)->linkImagen);
}

void CargarPeliculaNombre(Emovie *pelicula, int posicion)
{
  printf("Ingrese un titulo.\n");
  setbuf(stdin, NULL);
  gets((pelicula + posicion)->titulo);
}

void CargarPeliculaGenero(Emovie *pelicula, int posicion)
{
  printf("Ingrese el genero de la pelicula.\n");
  setbuf(stdin, NULL);
  gets((pelicula + posicion)->genero);
}

void CargarPeliculaDuracion(Emovie *pelicula, int posicion)
{
  printf("Ingrese la duracion de la pelicula (Minutos).\n");
  scanf("%d", &((pelicula+posicion)->duracion));
}

void CargarPeliculaDescripcion(Emovie *pelicula, int posicion)
{
  printf("Ingrese la descripcion de la pelicula.\n");
  setbuf(stdin,NULL);
  gets((pelicula + posicion)->descripcion);
}

void CargarPuntajePelicula(Emovie *pelicula, int posicion)
{
  printf("Ingrese el puntaje de la pelicula.\n");
  scanf("%f", &((pelicula+posicion)->puntaje));
}

void ModificarPelicula(Emovie *pelicula, int tam)
 {
    int posicion;
    posicion = BuscarPosicionPorId(pelicula, tam);
    if(posicion != -2)
    {
      CargarPeliculaNombre(pelicula, posicion);
      CargarPeliculaDescripcion(pelicula, posicion);
      CargarPeliculaGenero(pelicula, posicion);
      CargarPuntajePelicula(pelicula, posicion);
      CargarPeliculaDuracion(pelicula, posicion);
      CargarLinkImagen(pelicula, posicion);
      printf("Modificacion exitosa.\n");
    }
    else
    {
      printf("No se encontró una pelicula con el ID ingresado.\n");
    }
 }

void GuardarEnArchivoBinario(Emovie *peliList, FILE *ptr, int tam)
{
  int posicion;
  if ((ptr = fopen("Peliculas.bin", "wb")) == NULL)
  {
    printf("ERROR.\n");
    exit(9);
  }
  for(posicion = 0; posicion < tam; posicion++)
  {
    if((peliList + posicion)->estado == 1)
    {
      fwrite((peliList + posicion), sizeof(Emovie), 1, ptr);
    }
  }
  fclose(ptr);
}

int MostrarPeliculas(Emovie *peliculas, int tam)
{
  int posicion, contador = 0, resultado = 0;
  for(posicion = 0; posicion < tam; posicion++)
  {
    if ((peliculas + posicion)->estado == 1)
    {
      printf("%d - %s\nGenero: %s\nDuracion: %d min\nPuntaje: %.02f\nDescripcion: %s\n\n", (peliculas + posicion)->id, (peliculas + posicion)->titulo, (peliculas + posicion)->genero, (peliculas + posicion)->duracion, (peliculas + posicion)->puntaje,(peliculas + posicion)->descripcion);
    }
    else
    {
      contador++;
      resultado = 1;
    }
  }
  if (contador == tam)
  {
    printf("No se encontraron peliculas");
  }
  return resultado;
}

void CargarArchivo(FILE *ptr)
{
  ptr = fopen("Peliculas.bin", "rb");
  if (ptr == NULL)
  {
    ptr = fopen("Peliculas.bin", "wb");
    if (ptr == NULL)
    {
      printf("No se pudo crear el archivo.\n");
      exit(1);
    }
    fclose(ptr);
  }

  if (ptr == NULL)
  {
    printf("No se pudo leer el archivo.\n");
    exit(2);
  }
}

void ExpandirEstructura(Emovie *pelicula, int tamanio)
{
  Emovie *aux = NULL;
  tamanio+= SIZE;
  aux = (Emovie*) realloc(pelicula, sizeof(Emovie)*(tamanio));
  if (aux == NULL)
  {
    printf("Error.\n");
    exit(3);
  }
  pelicula = aux;
  free(aux);
}

void LeerArchivoBinario(FILE *ptr, Emovie *pelicula, int tamanio)
{
  int posicion, contador = 0, resultado = 0;
  ptr = fopen("Peliculas.bin", "rb");
  if (ptr == NULL)
  {
    printf("No se pudo abrir el archivo.\n");
    exit(3);
  }
  for(posicion = 0; !feof(ptr); posicion++)
  {
    contador = fread(pelicula, sizeof(Emovie), 1, ptr);
    if(contador - tamanio == 0)
    {
      ExpandirEstructura(pelicula, tamanio);
    }
  }
  if (contador - tamanio == tamanio)
  {
    printf("El Archivo está vacío, agregue películas.\n");
  }
  fclose(ptr);
}


