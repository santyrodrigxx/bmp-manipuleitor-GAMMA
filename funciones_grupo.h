#ifndef FUNCIONES_GRUPO_H_INCLUDED
#define FUNCIONES_GRUPO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "bmp.h"
#include "matriz_tda.h"
#include <stddef.h>

#define EXITO 0
#define ERROR_ARGUMENTOS 1
#define ERROR_ARCHIVO 2
#define ERROR_MEMORIA 3
#define BMP_INVALIDO 4

typedef struct{
    char nombre[40];
    char parametro;
}t_Filtro;

typedef struct{
    t_Filtro filtros_pedidos[16];
    int cant_filtros;
    char imagen1[256];
    char imagen2[256];
    int cant_imagenes;
    bool con_verbose;
    bool con_help;
    bool con_validar;
    bool con_info;
}t_Datos;


int procesar_imagen(int argc, char *argv[]);
int leer_arg(int argc, char* argv[], const char* filtros[], const char* utilidades[], t_Datos* datos);
bool es_flag(const char* argumento);
bool funcion_valida(const char* argumento, const char* filtros[], int* parametro); 
bool utilidad_valida(const char* argumento, const char* utilidades[]);
int es_bmp (const char* argumento);
bool filtro_ya_guardado(t_Datos* datos, const char* nombre);
bool necesita_dos_imagenes (const char* nombre);


#endif // FUNCIONES_GRUPO_H_INCLUDED
