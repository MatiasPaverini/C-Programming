#include "lib.h"

int main()
{
  int opcion = 0, tamanio = 10;
  char seguir = 'n';
  Emovie *lista;
  lista = (Emovie*) malloc(sizeof(Emovie)*tamanio);
  FILE *web = NULL;
  FILE *bin = NULL;
  InicializarEstado(lista, tamanio);
  CargarArchivo(bin);
  LeerArchivoBinario(bin, lista, tamanio);
  while(seguir== 'n')
    {
        printf("1- Agregar pelicula.\n");
        printf("2- Borrar pelicula.\n");
        printf("3- Modificar pelicula.\n");
        printf("4- Generar pagina web.\n");
        printf("5- Salir.\n");
        printf("Ingrese la opcion que desee ejecutar: ");
        opcion = CargarOpcion(opcion);
        setbuf(stdin, NULL);
        switch(opcion)
        {
            case 1:
                AgregarPelicula(lista, tamanio);
                break;
            case 2:
                if (MostrarPeliculas(lista, tamanio) == 0)
                  break;
                else
                  BorrarPelicula(lista, tamanio);
                break;
            case 3:
                if (MostrarPeliculas(lista, tamanio) == 0)
                  break;
                else
                  ModificarPelicula(lista, tamanio);
                break;
            case 4:
                GenerarPagina(web, lista, tamanio);
               break;
            case 5:
                printf("Desea cerrar el menu? [s/n]: ");
                scanf(" %c", &seguir);
                seguir = tolower(seguir);
                do
                {
                  if (seguir != 's' && seguir != 'n')
                  {
                    printf("\nReingrese una opcion correcta [s/n]: ");
                    scanf(" %c", &seguir);
                    break;
                  }
                  else
                  {
                    if (seguir == 's')
                    {
                      break;
                    }
                   }
                }while(seguir != 's' || seguir != 'n');

                break;
            default:
              printf("ingrese una opcion correcta (opciones de 1 a 4).\n");
              break;
        }
    }
  GuardarEnArchivoBinario(lista, bin, tamanio);
  free(lista);
  free(bin);
  free(web);
  return 0;
}
