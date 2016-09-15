#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    char nombre[80];
    int dni;
    int estado;
    int edad;
}Persona;
void Agregar_Persona();
void Borrar_Persona();
void Imprimir_Lista();
void Graficar();
void Inicializacion();
#endif // FUNCIONES_H_INCLUDED
