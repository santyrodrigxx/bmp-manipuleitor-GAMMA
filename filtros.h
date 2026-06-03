#ifndef FILTROS_H_INCLUDED
#define FILTROS_H_INCLUDED

#include "funciones_grupo.h"
#include "bmp.h"

int bucle_filtros(t_Datos datos, tImagenBMP* imagen1);
int aplicar_negativo(tImagenBMP* imagen);
int aplicar_grises (tImagenBMP* imagen);
int espejar_horizontal (tImagenBMP* imagen);
int espejar_vertical (tImagenBMP* imagen);
int aumentar_contraste (tImagenBMP* imagen, const int parametro);
int reducir_contraste (tImagenBMP* imagen, const int parametro);
void aplicar_tonalidad_azul(tImagenBMP* imagen, int porcentaje);
void aplicar_tonalidad_verde(tImagenBMP* imagen, int porcentaje);
void aplicar_tonalidad_roja(tImagenBMP* imagen, int porcentaje);
int aplicar_recortar(tImagenBMP* imagen, int porcentaje);
int aplicar_achicar(tImagenBMP* imagen, int porcentaje);

//Funciones auxiliares
void adicionar_filtro(char *nombreArchivo, const char *nombreFiltro, int parametro);
void acomodar(double* color);



#endif // FILTROS_H_INCLUDED
