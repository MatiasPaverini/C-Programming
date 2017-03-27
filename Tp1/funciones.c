#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "funciones.h"


float ingresarNumeros(float numero)
{
	int flag = 0;// validacion para que no sea una letra
	char cadena[20];
	int valor;
		while (flag == 0)
		{
			scanf("%s", cadena);
			valor = isdigit(cadena[0]);
			if (valor != 0)
			{
				numero = atof(cadena);
				flag++;
			}
			else
			{
				printf (" Reingrese un valor correcto (Numeros):\n");
			}
		}
	return numero;
}

float sumar (float numero1, float numero2)
{
	float resultado;
	if (numero1 == 0 || numero2 == 0)
	{
		resultado = 0;
	}
	else
	{
		resultado = numero1 + numero2;
	}
	return resultado;
}

float restar(float numero1, float numero2)
{
	float resultado;
	if (numero1 == 0 || numero2 == 0)
	{
		if (numero2 == 0)
        {
            resultado = numero1;
        }
        else
        {
             resultado = numero2;
        }
	}
	else
    {
        resultado = numero1 - numero2;
    }
	return resultado;
}


float multiplicar(float numero1, float numero2)
{
	float resultado;
	if (numero1 == 0 || numero2 == 0)
	{
		resultado = 0;
	}
	else
    {
	resultado = numero1 * numero2;
    }
	return resultado;
}

float dividir(float numero1, float numero2)
{
    float resultado;
		 if ( numero2 != 0 )
         {
            resultado = numero1 / numero2;
            return resultado;
         }
        else
        {
                resultado = 0;
                return resultado;
        }
}


float factorear(float numero1, float numero2)
{
    int resultado;
    resultado = numero1;
	if (numero1 > 0 && numero1 - resultado == 0)
    {
        numero2 = resultado - 1;
        do
        {
            resultado = resultado * numero2;
            numero2--;
        }
        while (numero2 > 0);
    }
    else if ( numero1 > 0 && numero1 - resultado != 0)
    {
        resultado = -1;
    }
    else if (numero1 == 0)
	{
		resultado = 1;
	}
	else
	{
	    resultado = 0;
	}
	return resultado;
}

int SeleccionarOpcion(int numero)
{
  int flag = 0;// validacion para que no sea una letra
	char cadena[20];
	int valor;
		while (flag == 0)
		{
			scanf("%s", cadena);
			valor = isdigit(cadena[0]);
			if (valor != 0)
			{
				numero = atof(cadena);
				flag++;
			}
			else
			{
				printf (" Reingrese una opcion correcta:\n");
			}
		}
	return numero;
	}