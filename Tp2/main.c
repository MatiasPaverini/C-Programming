#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main()
{
    Persona listado[19];
    char seguir = 's';
    int opcion = 0;
    Inicializacion(listado);
    while (seguir == 's')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        switch (opcion)
        {
            case 1:
                Agregar_Persona(listado);
                break;
            case 2:
                Borrar_Persona(listado);
                break;
            case 3:
                Imprimir_Lista(listado);
                break;
            case 4:
                Graficar(listado);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
