#ifndef FILTROS_H_INCLUDED
#define FILTROS_H_INCLUDED

#include "funciones_grupo.h"
#include "bmp.h"

int bucle_filtros(t_Datos datos, tImagenBMP* imagen1, tImagenBMP* imagen2);
void aplicar_negativo(tImagenBMP* imagen);
void aplicar_grises (tImagenBMP* imagen);
void espejar_horizontal (tImagenBMP* imagen);
void espejar_vertical (tImagenBMP* imagen);
void aumentar_contraste (tImagenBMP* imagen, const int parametro);



#endif // FILTROS_H_INCLUDED