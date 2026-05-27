#ifndef FUNCIONES_GRUPO_H_INCLUDED
#define FUNCIONES_GRUPO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define EXITO 0
#define ERROR_ARGUMENTOS 1
#define ERROR_ARCHIVO 2
#define ERROR_MEMORIA 3
#define BMP_INVALIDO 4


int procesar_imagen(int argc, char *argv[]);
int leer_arg(int argc, char* argv[], const char* filtros[], const char* utilidades[]);
bool es_flag(const char* argumento);
bool funcion_valida(const char* argumento, const char* filtros[]);
bool utilidad_valida(const char* argumento, const char* utilidades[]);
int es_bmp (const char* argumento);


#endif // FUNCIONES_GRUPO_H_INCLUDED
