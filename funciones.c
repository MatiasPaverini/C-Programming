#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "funciones.h"


float ingresarNumeros(float x)
{
	int flag = 0;// validacion para que no sea una letra
	char cad[20];
	int val;
		while (flag == 0)
		{
			scanf("%s", cad);
			val = isdigit(cad[0]);
			if (val != 0)
			{
				x = atof(cad);
				flag++;
			}
			else
			{
				printf (" Reingrese un valor correcto (Numeros):\n");
			}
		}
	return x;
}

float sumar (float x, float y)
{
	float z;
	if (x == 0 || y == 0)
	{
		z = 0;
	}
	else
	{
		z = x + y;
	}
	return z;
}

float restar(float x, float y)
{
	float z;
	if (x == 0 || y == 0)
	{
		if (y == 0)
        {
            z = x;
        }
        else
        {
            z = y;
        }
	}
	else
    {
        z = x - y;
    }
	return z;
}


float multiplicar(float x, float y)
{
	float z;
	if (x == 0 || y == 0)
	{
		z = 0;
	}
	else
    {
	z = x * y;
    }
	return z;
}

float dividir(float x, float y)
{
    float z;
		 if ( y != 0 )
         {
            z = x / y;
            return z;
         }
        else
            {
                z = 0;
                return z;
            }
}


float factorear(float x, float y)
{
    int z;
    z = x;
	if (x > 0 && x - z == 0)
    {
        y = z - 1;
        do
        {
            z = z * y;
            y--;
        }
        while (y > 0);
    }
    else if ( x > 0 && x - z != 0)
    {
        z = -1;
    }
    else if (x == 0)
	{
		z = 1;
	}
	else
	{
	    z = 0;
	}
	return z;
}
