#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#define POSICIONES 19
Persona listado[19];
void Inicializacion()
{
    int incializacion = 0, posicion_aux;
    if (incializacion == 0)
    {
        for (posicion_aux = 0; posicion_aux < 19; posicion_aux++)
        {
            listado[posicion_aux].estado = 0;
            incializacion = 1;
        }
    }
}
void Agregar_Persona()
{
    int posicion = 0;
    printf("Ingrese el nombre de la persona\n");
    scanf(" %s", listado[posicion].nombre);
    printf("Ingrese la edad de la persona\n");
    scanf("%d", &listado[posicion].edad);
    printf("Ingrese el DNI de la persona\n");
    scanf("%d", &listado[posicion].dni);
    listado[posicion].estado = 1;
    posicion++;
    //printf("1");
}
void Borrar_Persona()
{
    Persona auxiliar;
    int posicion;
    printf("Ingrese el DNI de la persona a eliminar:\n");
    scanf("%d", &auxiliar.dni);
    for (posicion = 0; posicion < 19; posicion++)
    {
        if (auxiliar.dni == listado[posicion].dni)
        {
            listado[posicion].estado = 0;
            printf("DNI borrado sastisfactoriamente\n");
            break;
        }
        else
        {
            printf("No se encontro el DNI ingresado\n");
            break;
        }
    }
        //printf("%d", busqueda_dni);
}
void Imprimir_Lista()
{
    int posicion;
    for (posicion = 0; posicion < 19; posicion++)
    {
       if (listado[posicion].estado == 1)
       {
        printf("Nombre: %s \nDNI: %d\nEdad: %d\n", listado[posicion].nombre,listado[posicion].dni, listado[posicion].edad);
       }
    }
}
void Graficar()
{
	    int iteracion_busqueda,i, hasta18 = 5, de19a35 = 4, mayorDe35 = 2, flag=0, mayor;
		/*for (iteracion_busqueda = 0 ; iteracion_busqueda < POSICIONES ; iteracion_busqueda++)
		{
			if (listado[iteracion_busqueda].edad < 18)
			{
				hasta18++;
			}
			else if (listado[iteracion_busqueda].edad > 17 && listado[iteracion_busqueda].edad < 35)
			{
				de19a35++;
			}
			else if (listado[iteracion_busqueda].edad > 34
			{
				mayorDe35++;
			}
		}*/
    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }
    else
        {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
        {
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", hasta18, de19a35, mayorDe35);
    return 0;
}
