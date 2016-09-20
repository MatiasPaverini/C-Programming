#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
int main()
{
    char seguir = 'n';
    int opcion = 0;
    Inicializacion();
    while (seguir == 'n')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        scanf(" %d",&opcion);
        switch (opcion)
        {
            case 1:
                Agregar_Persona();
                break;
            case 2:
                Borrar_Persona();
                break;
            case 3:
                Imprimir_Lista();
                break;
            case 4:
                Graficar();
                break;
            case 5:
                printf("Desea cerrar el menu? [s/n]\n");
                scanf(" %c", &seguir);
                if (seguir == 's')
                {
                    break;
                }
            default:
                  if (!isdigit(opcion))
            {
                printf("Introduzca una opcion valida\n");
                break;
            }
            else
            {
                printf("Reingrese una opcion valida");
                break;
            }
        }
    }
        return 0;
}
