#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


int Buscar_casilla_desocupada(Persona listado[], int pos)
{
    for (pos = 0; pos < SIZE_STRUCTURE_ARRAY; pos++)
    {
        if (listado[pos].estado == 0)
        {
            break;
        }
    }
    return pos;
}

char OrdenarLetras(char *nombre)
{
  int iteracion;
  nombre[0] = toupper(nombre[0]);
  for(iteracion = 1; iteracion < SIZE_CHAR_ARRAY; iteracion++)
  {
    if (nombre[iteracion] == ' ')
    {
      nombre[iteracion+1] = toupper(nombre[iteracion+1]);
    }
    else
    {
      nombre[iteracion] = tolower(nombre[iteracion]);
    }
  }
  return *nombre;
}

int ValidarLetras(char *cadenaDeLetras)
{
  int iteracion = 0, result = -1;
  while(!(cadenaDeLetras[iteracion] == '\0'))
  {
    if(isalpha(cadenaDeLetras[iteracion]) || cadenaDeLetras[iteracion] == '\n' || cadenaDeLetras[iteracion] == ' ')
    {
      result = 0;
    }
    else if (!isalpha(cadenaDeLetras[iteracion]))
    {
      fputs("Usted ingreso caracteres no validos.\n", stdout);
      break;
    }
    iteracion++;
  }
  return result;
}

void Cargar_Nombre(Persona listado[])
{
    char nombre[SIZE_CHAR_ARRAY],i;
    int posicion = 0;
   /* for (i = 0; i <SIZE_CHAR_ARRAY; i++)
    {
        strcpy(nombre, "\0");
    }*/
    posicion = Buscar_casilla_desocupada(listado, posicion);
    do
    {
      printf("Ingrese el nombre: ");
      getchar();
      fgets(nombre, SIZE_CHAR_ARRAY, stdin);
    }while(ValidarLetras(nombre) == -1);
    OrdenarLetras(nombre);
    strcpy(listado[posicion].nombre, nombre);
}

int ValidarEdad(char *edad)
{
  int edads = -1, iteracion;
  for (iteracion = 0; edad[iteracion] != '\0'; iteracion++)
  {
    if (!isdigit(edad[iteracion]))
    {
      printf("Usted ingresó letras, ingrese solo numeros.\n");
      break;
    }
    else
    {
      edads = atoi(edad);
      if (  edads > 105 || edads  < 1)
      {
        printf("Ingrese una edad valida.\n");
        break;
      }
    }
  }
  return edads;
}
void Cargar_Edad(Persona listado[])
{
    int posicion = 0, edadz;
    char edad [4];
    posicion = Buscar_casilla_desocupada(listado, posicion);
		do
		{
      printf("Ingrese la edad de la persona.\n");
      scanf (" %s", edad);
      if (ValidarEdad(edad) != -1)
      {
        ValidarEdad(edad);edadz = ValidarEdad(edad);
        break;
      }
    }while (ValidarEdad(edad)!= -1);
    listado[posicion].edad = edadz;
}
void Cargar_DNI(Persona listado[])
{
    Persona aux;
    int posicion = 0, largo = 0, flag = 0, iteracion, dni_repeticion;
    long  dni_n;
    char dni[14], fin;
    posicion = Buscar_casilla_desocupada(listado, posicion);
    do
    {
	    printf("Ingrese el DNI de la persona:\n");
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
                    printf("El DNI ingresado no cumple los requisitos (ingrese entre 7 y 9 numeros).\n");
                    break;
                }
                else
                {
                    printf("esta seguro que desea ingresar este DNI? [s/n]");
                   // scanf (" %c", &fin);
                   getchar();
                   fin = getc(stdin);
                    if (fin == 's')
                    {
                        dni_n = atol(dni);
                        aux.dni = dni_n;
                        for (dni_repeticion = 0; dni_repeticion < SIZE_STRUCTURE_ARRAY; dni_repeticion++)
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
                        printf("Error.\n");
                        break;
                    }
                }
            }
        }
		}while (flag != 1);
		listado[posicion].dni = dni_n;

}
void Inicializacion(Persona listado[])
{
    int posicion_aux;
        for (posicion_aux = 0; posicion_aux < SIZE_STRUCTURE_ARRAY; posicion_aux++)
        {
            listado[posicion_aux].estado = 0;
        }
    }
void Agregar_Persona(Persona listado[])
{
    int posicion = 0;
    posicion = Buscar_casilla_desocupada(listado, posicion);
    Cargar_Nombre(listado);
    Cargar_DNI(listado);

    Cargar_Edad(listado);


    listado[posicion].estado = 1;
    //printf("1");
}
void Borrar_Persona(Persona listado[])
{
    Persona auxiliar;
    int posicion;
    printf("Ingrese el DNI de la persona a eliminar:\n");
    scanf("%ld", &auxiliar.dni);
    for (posicion = 0; posicion < SIZE_STRUCTURE_ARRAY; posicion++)
    {
        if (auxiliar.dni == listado[posicion].dni)
        {
            listado[posicion].estado = 0;
            printf("DNI borrado sastisfactoriamente.\n");
            break;
        }
        else
        {
            printf("No se encontro el DNI ingresado.\n");
            break;
        }
    }
        //printf("%d", busqueda_dni);
}
void Imprimir_Lista(Persona listado[])
{
    Persona aux;
    int posicion1, posicion2;
    for (posicion1 = 0; posicion1 < SIZE_STRUCTURE_ARRAY-1; posicion1++)
    {
        for (posicion2 = 1; posicion2 < SIZE_STRUCTURE_ARRAY; posicion2++)
        {
                if (strcasecmp(listado[posicion1].nombre, listado[posicion2].nombre) < 0)
                {
                    aux = listado[posicion1];
                    listado[posicion1] = listado[posicion2];
                    listado[posicion2] = aux;
                }
                /*else if (strcasecmp(listado[posicion1].nombre, listado[posicion2].nombre) == 0)
                {
                   // comparacion = (listado[posicion1].dni listado[posicion2].dni;
                    if (listado[posicion1].dni < listado[posicion2].dni)
                    {
                        aux = listado[posicion1];
                        listado[posicion1] = listado[posicion2];
                        listado[posicion2] = aux;
                    }
                }*/
        }
    }
    for (posicion1 = 0; posicion1 < SIZE_STRUCTURE_ARRAY; posicion1++)
    {
       if (listado[posicion1].estado == 1)
       {
         printf("Nombre: %s\nDNI: %ld\nEdad: %d\n\n",listado[posicion1].nombre, listado[posicion1].dni, listado[posicion1].edad);
       }
    }
}
void Graficar(Persona listado[])
{
    int iteracion_busqueda = 0, i, menor_de_edad = 0, adulto = 0, mayor_de_35 = 0, flag=0, mayor;
    while(iteracion_busqueda < SIZE_STRUCTURE_ARRAY)
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
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", menor_de_edad, adulto, mayor_de_35);
}
