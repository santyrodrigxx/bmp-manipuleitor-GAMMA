#ifndef MATRIZ_TDA_H_INCLUDED
#define MATRIZ_TDA_H_INCLUDED

// VARIAS FUNCIONES DEBERIAN OPERAR CON TDA MATRIZ
// se va a encargar de manipular los pixeles en mem

#include "funciones_grupo.h"

typedef struct
{
    void **datos;
    unsigned int filas;
    unsigned int columnas;
    size_t tamElemento;
} tda_matriz;

int matriz_crear(tda_matriz *matriz,
                 unsigned int filas,
                 unsigned int columnas,
                 size_t tamElemento);

void matriz_destruir(tda_matriz *matriz);

int matriz_set(tda_matriz *matriz,
               unsigned int fila,
               unsigned int columna,
               const void *elemento);

int matriz_get(const tda_matriz *matriz,
               unsigned int fila,
               unsigned int columna,
               void *elemento);

void *matriz_obtener_ptr(tda_matriz *matriz,
                         unsigned int fila,
                         unsigned int columna);

const void *matriz_obtener_ptr_const(const tda_matriz *matriz,
                                     unsigned int fila,
                                     unsigned int columna);

unsigned int matriz_filas(const tda_matriz *matriz); //para que el procesador (grupo) trabaje con la matriz, no solo se ate a bmp

unsigned int matriz_columnas(const tda_matriz *matriz);

size_t matriz_tam_elemento(const tda_matriz *matriz);

#endif // MATRIZ_TDA_H_INCLUDED
