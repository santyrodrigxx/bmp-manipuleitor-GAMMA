#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

#include "funciones_grupo.h"

/*
    BMP FILE HEADER - 14 bytes
        ------------------------------------------------
        Byte 0-1     firma              2 bytes
        Byte 2-5     tamanioArchivo     4 bytes
        Byte 6-7     reservado1         2 bytes
        Byte 8-9     reservado2         2 bytes
        Byte 10-13   posicionPixeles    4 bytes


    BMP INFO HEADER - 40 bytes
        ------------------------------------------------
        Byte 14-17   tamanioCabecera        4 bytes
        Byte 18-21   anchoImagen            4 bytes
        Byte 22-25   altoImagen             4 bytes
        Byte 26-27   planos                 2 bytes
        Byte 28-29   bitsPorPixel           2 bytes
        Byte 30-33   compresion             4 bytes
        Byte 34-37   tamanioImagen          4 bytes
        Byte 38-41   resolucionHorizontal   4 bytes
        Byte 42-45   resolucionVertical     4 bytes
        Byte 46-49   coloresUsados          4 bytes
        Byte 50-53   coloresImportantes     4 bytes
*/

#pragma pack(push, 1) //para que no haya padding entre los campos de las estructuras

typedef struct
{
    unsigned short firma;
    unsigned int tamArchivo;
    unsigned short reservado1;
    unsigned short reservado2;
    unsigned int posPixeles;
} BMPArcCabecera;

typedef struct
{
    unsigned int tamCabecera;
    int anchoImagen;
    int altoImagen;
    unsigned short planos;
    unsigned short bitsPorPixel;
    unsigned int compresion;
    unsigned int tamImagen;
    int resolucionHorizontal;
    int resolucionVertical;
    unsigned int coloresUsados;
    unsigned int coloresImportantes;
} BMPInfoCabecera;

typedef struct
{
    BMPArcCabecera archivo;
    BMPInfoCabecera info;
} BMPCabecera;


typedef struct
{
    unsigned char azul;
    unsigned char verde;
    unsigned char rojo;
} tPixelBMP;

typedef struct
{
    BMPCabecera cabecera;
    tda_matriz pixeles;
} tImagenBMP;

#pragma pack(pop) //restauro el packing por defecto

int bmp_leer_imagen(const char *, tImagenBMP *);
//llama a matriz crear para reservar la memoria de la matriz de pixeles, y luego lee los pixeles del archivo y los almacena en la matriz

/*int bmp_escribir_pixel(const char *nombreArchivo, const tImagenBMP *imagen, unsigned int fila, unsigned int columna);
aca fume y de la buena, no den bola a esta */

int bmp_escribir_imagen(const char *nombreArchivo, const tImagenBMP *imagen);
//llama a matriz obtener ptr para obtener la direccion de cada pixel en la matriz, 
//y luego escribe los pixeles en el archivo, respetando el formato BMP (bottom-up, padding, etc)

int bmp_validar_cabecera(const BMPCabecera *cabecera);
/*tengo que ver el tema de las imagenes "bottom-up" (de abajo hacia arriba) o "top-down" (de arriba hacia abajo): 
porque eso afecta el orden de lectura de los pixeles, y por lo tanto la validacion de la cabecera.
Si es "top-down" el alto de la imagen es negativo, y si es "bottom-up" el alto de la imagen es positivo, 
entonces tengo que validar que el alto de la imagen sea positivo para admitir solo imagenes "bottom-up", 
o validar que el alto de la imagen sea negativo para admitir solo imagenes "top-down", 
o validar que el alto de la imagen sea diferente de cero para admitir ambas tipos de imagenes*/

void bmp_destruir_imagen(tImagenBMP *imagen);
//llama a matriz destruir para liberar la memoria de la matriz de pixeles, y luego libera la memoria del struct tImagenBMP
//TENGO QUE VER COMO JOEL IMPLEMENTO LA FUNCION DE DESTRUIRMATRIZ, PARA PODER LIBERAR LA MEMORIA DEL STRUCT tImagenBMP

void bmp_imprimir_info(const tImagenBMP *imagen, const char *nombreArchivo);
//poder llamarla en cualquier momento del programa


#endif // BMP_H_INCLUDED

