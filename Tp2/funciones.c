#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define POSICIONES 19
Persona listado[19];
int Buscar_casilla_desocupada(int pos)
{
    for (pos = 0; pos < 19; pos++)
    {
        if (listado[pos].estado == 0)
        {
            break;
        }
    }
    return pos;
}
void Cargar_Nombre()
{
    char nombre[19], nombre_completo[79];
    int posicion = 0, i, iteracion, flag, lower_case;
    for (i = 0; i <79; i++)
    {
        strcpy(nombre_completo, "\0");
    }
    posicion = Buscar_casilla_desocupada(posicion);
    do
    {
        do
        {
        //fflush(stdin);
            printf("Ingrese el nombre de la persona:\n");
            scanf(" %s", nombre);
            for (iteracion = 0; nombre[19] != '\0'; iteracion++)
            {
                if (!isalpha(nombre[iteracion]))
                {
                    printf("Usted ingreso numeros, ingrese solo letras por favor (En caso de querer ingresar numeros hagalo en romanos).\n");
                    break;
                }
                else
                {
                    for (lower_case = 0; lower_case < 19; lower_case++)
                    {
                        nombre[lower_case] = tolower(nombre[lower_case]);
                    }
                    i = getc(stdin);
                    nombre[0] = toupper(nombre[0]);
                    strcat(nombre_completo, nombre);
                    strcat(nombre_completo, " ");
                    flag = 1;
                    break;
                }
            }
        }while (i == 32);
    }while(flag != 1);
    strcpy(listado[posicion].nombre, nombre_completo);
}
void Cargar_Edad()
{
    int posicion = 0, flag = 0, edads = 0, iteracion;
    char edad [9];
    posicion = Buscar_casilla_desocupada(posicion);
		do
		{
    		printf("Ingrese la edad de la persona\n");
    		scanf (" %s", edad);
        for (iteracion = 0; edad[iteracion] != '\0'; iteracion++)
        {
            if (!isdigit(edad[iteracion]))
            {
                printf("Usted ingresó letras, ingrese solo numeros.\nReingrese un valor.\n");
                break;
            }
            else
            {
                edads = atoi(edad);
                if (  edads > 105 || edads  < 1)
                {
                    printf("Ingrese una edad valida\n");
                    break;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
    }while (flag != 1);
    listado[posicion].edad = edads;
//    printf("%d", asd);
}
void Cargar_DNI()
{
    Persona aux;
    int posicion = 0, largo = 0, flag = 0, iteracion, dni_repeticion;
    long  dni_n;
    char dni[14], fin;
    posicion = Buscar_casilla_desocupada(posicion);
    do
    {
	    printf("Ingrese el DNI de la persona\n");
		scanf(" %s", dni);
		for (iteracion = 0; dni[iteracion] != '\0'; iteracion++)
		{
			if (!isdigit(dni[iteracion]))
			{
				printf("Usted ingreso letras, ingrese numeros por favor.\n");
				break;
			}
			else
			{
                largo = strlen(dni);
                if (largo > 9 || largo < 7)
                {
                    printf("El DNI ingresado no cumple los requisitos (ingrese 9 numeros).\nReingrese el DNI.");
                    break;
                }
                else
                {
                    printf("esta seguro que desea ingresar este DNI? [s/n]");
                    scanf (" %c", &fin);
                    if (fin == 's')
                    {
                        dni_n = atol(dni);
                        aux.dni = dni_n;
                        for (dni_repeticion = 0; dni_repeticion < POSICIONES; dni_repeticion++)
                        {
                            if (aux.dni == listado[dni_repeticion].dni)
                            {
                                printf("Este DNI ya existe en la base de datos, ingrese uno distinto por favor.\n");
                                break;
                            }
                            else
                            {
                                flag = 1;
                                break;
                            }
                        }
                        break;
                    }
                    else
                    {
                        printf("Reingrese el DNI.");
                        break;
                    }
                }
            }
        }
   // scanf("%ld", &listado[posicion].dni);
		}while (flag != 1);
		listado[posicion].dni = dni_n;
}
void Inicializacion()
{
    int posicion_aux;
        for (posicion_aux = 0; posicion_aux < 19; posicion_aux++)
        {
            listado[posicion_aux].estado = 0;
        }
    }
void Agregar_Persona()
{
    int posicion = 0;
    posicion = Buscar_casilla_desocupada(posicion);
    Cargar_Nombre();
    Cargar_DNI();
    Cargar_Edad();

    listado[posicion].estado = 1;
    //printf("1");
}
void Borrar_Persona()
{
    Persona auxiliar;
    int posicion;
    printf("Ingrese el DNI de la persona a eliminar:\n");
    scanf("%ld", &auxiliar.dni);
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
    Persona aux;
    int posicion1, posicion2;
    for (posicion1 = 0; posicion1 < 18; posicion1++)
    {
        for (posicion2 = 1; posicion2 < 19; posicion2++)
        {
            if (listado[posicion1].estado != 0)
            {
                if (strcasecmp(listado[posicion1].nombre, listado[posicion2].nombre) < 0)
                {
                    aux = listado[posicion1];
                    listado[posicion1] = listado[posicion2];
                    listado[posicion2] = aux;
                }
                else if (strcasecmp(listado[posicion1].nombre, listado[posicion2].nombre) == 0)
                {
                   // comparacion = (listado[posicion1].dni listado[posicion2].dni;
                    if (listado[posicion1].dni < listado[posicion2].dni)
                    {
                        aux = listado[posicion1];
                        listado[posicion1] = listado[posicion2];
                        listado[posicion2] = aux;
                    }
                }
            }
        }
    }
    for (posicion1 = 0; posicion1 < 19; posicion1++)
    {
       if (listado[posicion1].estado == 1)
       {
        printf("Nombre: %s \nDNI: %ld\nEdad: %d\n\n", listado[posicion1].nombre,listado[posicion1].dni, listado[posicion1].edad);
       }
    }
}
void Graficar()
{
    int iteracion_busqueda = 0, i, menor_de_edad = 0, adulto = 0, mayor_de_35 = 0, flag=0, mayor;
    while(iteracion_busqueda < 19)
    {
        if (listado[iteracion_busqueda].edad < 19 && listado[iteracion_busqueda].estado == 1)
        {
            menor_de_edad++;
        }
        else if (listado[iteracion_busqueda].edad >18 && listado[iteracion_busqueda].edad < 36 && listado[iteracion_busqueda].estado == 1)
        {
                adulto++;
        }
        else if (listado[iteracion_busqueda].edad > 35 && listado[iteracion_busqueda].estado == 1)
        {
            mayor_de_35++;
        }
        iteracion_busqueda++;
    }
    if (menor_de_edad >= adulto && menor_de_edad >= mayor_de_35)
    {
        mayor = menor_de_edad;
    }
    else
    {
        if(adulto >= menor_de_edad && adulto >= mayor_de_35)
        {
            mayor = adulto;
        }
        else{
        mayor = mayor_de_35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= menor_de_edad)
        {
            printf("*");
        }
        if(i<= adulto)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayor_de_35)
        {
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
    printf("\n   %d\t%d\t%d\n", menor_de_edad, adulto, mayor_de_35);
}
