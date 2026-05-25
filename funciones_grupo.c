#include "funciones_grupo.h"

// Apellido, nombre: Avalos Irrazabal, Joel Antonio
// DNI: 94275736
// Entrega: Si

// Apellido, nombre: Rodriguez, Santiago Rodriguez
// DNI: 47131227
// Entrega: Si

// Apellido, nombre: Gahona, Antonella
// DNI: 45928557
// Entrega: Si

////////////////////////////////////////

int procesar_imagen(int argc, char *argv[])
{
    char* filtros= {"--negativo","--escala-de-grises",
                    "--espejar-horizontal","--espejar-vertical",
                    "--aumentar-contraste","--reducir-contraste",
                    "--tonalidad-azul","--tonalidad-verde",
                    "--tonalidad-roja","--recortar",
                    "--achicar","--rotar-derecha",
                    "--rotar-izquierda","--concatenar-horizontal",
                    "--concatenar-vertical","--comodin"};

    char* utilidades= ("--info, --validar,"
                       "--verbose,--help");

    int i=1;
    if(*(argv+i))
    {

    }

    return EXITO;
}
