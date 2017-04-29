#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
int main()
{
    Persona listaPersona[SIZE_STRUCTURE_ARRAY];
    char opcion2[1] = "";
    int opcion = 0;
    Inicializacion(listaPersona);
    char seguir = 'n';
    while (seguir == 'n')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        do
        {
          gets(opcion2);
          //getchar();
            opcion = atoi(opcion2);
          switch (opcion)
          {
              case 1:
                  Agregar_Persona(listaPersona);
                  break;
              case 2:
                  Borrar_Persona(listaPersona);
                  break;
              case 3:
                  Imprimir_Lista(listaPersona);
                  break;
              case 4:
                  Graficar(listaPersona);
                  break;
              case 5:
                  printf("Desea cerrar el menu? [s/n]\n");
                  scanf(" %c", &seguir);
                  if (seguir == 's')
                  {
                    break;
                  }
              default:
                  if (!isdigit(opcion2[0]))
                  {
                    printf("Introduzca una opcion valida\n");
                    break;
                  }
          }
        }while(!isdigit(opcion2[0]));
    }
        return 0;
}
