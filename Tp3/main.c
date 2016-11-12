#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define SIZE 10
Emovie *lista;
int main()
{
  int opcion = 0;
  char seguir = 'n';
  lista = (Emovie*) malloc(sizeof(Emovie)*SIZE);
  if(lista == NULL)
  {
    exit(-1);
  }
  Inicializar_Estado(lista);
  while(seguir== 'n')
    {
        printf("1- Agregar pelicula.\n");
        printf("2- Borrar pelicula.\n");
        printf("3- Generar pagina web.\n");
        printf("4- Modificar pelicula.\n");
        printf("5- Salir.\n");
        printf("Ingrese la opcion que desee ejecutar: ");
        opcion = Cargar_opcion(opcion);
        setbuf(stdin, NULL);
        switch(opcion)
        {
            case 1:
                agregarPelicula(lista);
                break;
            case 2:
                BorrarPelicula(lista);
                break;
            case 3:
                generarPagina(lista);
                break;
            case 4:
                Modificar_Pelicula(lista);
               break;
            case 5:
                printf("Desea cerrar el menu? [s/n]: ");
                scanf(" %c", &seguir);
                do
                {
                  if (seguir != 's' || seguir != 'n')
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
              printf("ingrese una opcion correcta (opciones de 1 a 5).\n");
              break;
        }
    }

    return 0;
}
