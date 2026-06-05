#ifndef FILTROS_H_INCLUDED
#define FILTROS_H_INCLUDED

#include "funciones_grupo.h"
#include "bmp.h"

int bucle_filtros(t_Datos datos, tImagenBMP* imagen1, tImagenBMP* imagen2);
int aplicar_negativo(tImagenBMP* imagen);
int aplicar_grises (tImagenBMP* imagen);
int espejar_horizontal (tImagenBMP* imagen);
int espejar_vertical (tImagenBMP* imagen);
int aumentar_contraste (tImagenBMP* imagen, const int parametro);
int reducir_contraste (tImagenBMP* imagen, const int parametro);
int aplicar_tonalidad_azul(tImagenBMP* imagen, int porcentaje);
int aplicar_tonalidad_verde(tImagenBMP* imagen, int porcentaje);
int aplicar_tonalidad_roja(tImagenBMP* imagen, int porcentaje);
int aplicar_recortar(tImagenBMP* imagen, int porcentaje);
int aplicar_achicar(tImagenBMP* imagen, int porcentaje);
int rotar_derecha(tImagenBMP *imagen);
int rotar_izquierda(tImagenBMP *imagen);
int concatenar_horizontal(tImagenBMP *imagen1, tImagenBMP *imagen2);
int concatenar_vertical(tImagenBMP *imagen1, tImagenBMP *imagen2);

//Funciones auxiliares
void modificar_nombre_filtro(char *nombreArchivo, t_Datos info, int cont);
void acomodar(double* color);



#endif // FILTROS_H_INCLUDED
