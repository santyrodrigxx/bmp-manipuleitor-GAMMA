#ifndef FILTROS_H_INCLUDED
#define FILTROS_H_INCLUDED

#include "funciones_grupo.h"
#include "bmp.h"

int bucle_filtros(t_Datos datos, tImagenBMP* imagen1, tImagenBMP* imagen2);
void aplicar_negativo(tImagenBMP* imagen);
void aplicar_grises (tImagenBMP* imagen);


#endif // FILTROS_H_INCLUDED