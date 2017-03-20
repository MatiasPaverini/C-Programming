 #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
int main()
{
    float num1 = 0, num2 = 0, resultado;
    int opcion, flag = 0;
    char seguir = 'n';
     while (seguir != 's')
     {
         if (flag != 0)
         {
             if ( flag == 1 && opcion == 1)
             {
                 printf("Ingrese un numero para ejecutar una funcion\n1 Ingresar primer operando (A = %f).\n2 Ingresar segundo operando (B).\n3 Sumar.\n4 Restar.\n5 Multiplicar.\n6 Division.\n7 Factoreal.\n8 Hacer todas las operaciones.\n9 Salir.\n", num1);
                 flag++;
             }
                else if ( flag == 1 && opcion == 2)
             {
                 printf("Ingrese un numero para ejecutar una funcion\n1 Ingresar primer operando (A) .\n2 Ingresar segundo operando (B = %f).\n3 Sumar.\n4 Restar.\n5 Multiplicar.\n6 Division.\n7 Factoreal.\n8 Hacer todas las operaciones.\n9 Salir.\n", num2);
                 flag++;
             }
                else if (flag == 2)
             {
                 printf("Ingrese un numero para ejecutar una funcion\n1 Ingresar primer operando (A = %f) .\n2 Ingresar segundo operando (B = %f).\n3 Sumar.\n4 Restar.\n5 Multiplicar.\n6 Division.\n7 Factoreal.\n8 Hacer todas las operaciones.\n9 Salir.\n", num1, num2);
             }
         }
         else
         {
            printf("Ingrese un numero para ejecutar una funcion\n1 Ingresar primer operando (A).\n2 Ingresar segundo operando (B).\n3 Sumar.\n4 Restar.\n5 Multiplicar.\n6 Division.\n7 Factoreal.\n8 Hacer todas las operaciones.\n9 Salir.\n");
            flag++;
         }
       scanf("%d", &opcion);
    	switch(opcion)
    	{
    	  opcion = SeleccionarOpcion(opcion);
        	case 1 :
				 printf ("Ingrese un numero para el primer operando (A):  \n");
				num1 = ingresarNumeros (num1);
				printf("El operando A es: %f\n", num1);
         	   break;
        	case 2 :
				 printf ("Ingrese un numero para el segundo operando (B):  \n");
				num2 = ingresarNumeros(num2);
				printf ("El operando B es: %f\n", num2);
            	break;
        	case 3 :
        	    resultado = sumar (num1, num2);
            	if (resultado != 0)
            	{
            		printf("La suma es: %f\n", resultado);
            	}
            	else
            	{
            		if (num1 ==0 && num2 != 0)
            		{
            		 printf ("No se realizo la suma ya que solo ingreso B = %f.\n", num2);
            		}
            		else if (num1 != 0 && num2 == 0)
            		{
            			printf ("No se realizo la suma ya que solo ingreso A = %f.\n", num1);
            		}
            		else if ( num1 == 0 && num2 == 0)
            		{
            			printf ("No se realizo la suma ya que  no ingreso un valor.\n");
            		}
            	}
           	 break;
        	case 4 :
            	resultado = restar (num1, num2);
            	if (num1 != 0 && num2 != 0)
                {
                    printf ("La resta es: %f\n", resultado);
                }
                else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando A\nSu resultado es: -%f\n", num2);
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando B\nSu resultado es: %f\n", num1);
                }
                else
                {
                        printf("Usted no ingreso numeros validos");
                }
            	break;
        	case 5 :
            	resultado = multiplicar (num1, num2);
                if (num1 != 0 && num2 != 0)
                {
                    printf("La multiplicacion es: %f\n", resultado);
                }
            	else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando A\nSu resultado es: 0");
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando B\nSu resultado es: 0");
                }
                else
                {
                        printf("Usted no ingreso numeros validos");
                }
            	break;
        	case 6 :
            	resultado = dividir(num1, num2);
            	if (num1 != 0 && num2 != 0)
                {
                    printf ("La division es: %f\n", resultado);
                }
                else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted inreso 0 o nada en el operando A\nLa division es: 0");
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("No se puede dividir por 0");
                }
                else
                {
                    printf("No ingreso operandos");
                }
            	break;
        	case 7 :
            	resultado = factorear (num1, num2);
            	if (num1 > 0)
                {
                    printf("El factoreal es: %f\n", resultado);
                }
            	else if (num1 == 0)
                {
                    printf("Usted no ingrenso el operando A o ingreso 0");
                }
                else if ( resultado == -1)
                {
                    printf("No se puede factorizar un numero decimal");
                }
                else
                {
                    printf("Usted ingreso un numero negativo");
                }

            	break;
        	case 8 :
                resultado = sumar (num1, num2);
            	if (resultado != 0)
            	{
            		printf("La suma es: %f\n", resultado);
            	}
            	else
            	{
            		if (num1 ==0 && num2 != 0)
            		{
            		 printf ("No se realizo la suma ya que solo ingreso B = %f.\n", num2);
            		}
            		else if (num1 != 0 && num2 == 0)
            		{
            			printf ("No se realizo la suma ya que solo ingreso A = %f.\n", num1);
            		}
            		else if ( num1 == 0 && num2 == 0)
            		{
            			printf ("No se realizo la suma ya que  no ingreso un valor.\n");
            		}
            	}
            	resultado = restar (num1, num2);
            	if (num1 != 0 && num2 != 0)
                {
                    printf ("La resta es: %f.\n", resultado);
                }
                else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando A\nLa resta es: -%f.\n", num2);
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando B\nLa resta es: %f.\n", num1);
                }
                else
                {
                        printf("No se realizo la resta ya que usted no ingreso numeros validos.\n");
                }
                resultado = multiplicar (num1, num2);
                if (num1 != 0 && num2 != 0)
                {
                    printf("La multiplicacion es: %f.\n", resultado);
                }
            	else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando A\nLa multiplicacion es: 0.\n");
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("Usted solo ingreso un operando o 0 en el operando B\nLa multiplicacion es: 0.\n");
                }
                else
                {
                        printf("No se realizo la multiplicacion ya que usted no ingreso numeros validos.\n");
                }
                resultado = dividir(num1, num2);
            	if (num1 != 0 && num2 != 0)
                {
                    printf ("La division es: %f.\n", resultado);
                }
                else if (num1 == 0 && num2 != 0)
                {
                    printf("Usted inreso 0 o nada en el operando A\nLa division es: 0.\n");
                }
                else if (num1 != 0 && num2 == 0)
                {
                    printf("No se puede dividir por 0.\n");
                }
                else
                {
                    printf("No se realizo la division ya que usted no ingreso numeros validos.\n");
                }
                resultado = factorear (num1, num2);
            	if (num1 > 0)
                {
                    printf("El factorial es: %f.\n", resultado);
                }
            	else if (num1 == 0)
                {
                    printf("Usted no ingrenso el operando A o ingreso 0.\n");
                }
                else
                {
                    printf("Usted ingreso un numero negativo en el operando A.\n");
                }
                break;
        	case 9 :
        		printf("Desea cerrar el programa (s/n)?");
        		//fflush(stdin);
        		getchar();
        		seguir = Respuesta (seguir);
        		break;
        		case default:
        		  printf("La opcion ingresada no existe, ingrese una nueva opcion");
        		  getchar();
        		  opcion = SeleccionarOpcion(opcion);
    	    } printf("1");
     }
    return 0;
}