#include "filtros.h"
#include "matriz_tda.h"

int bucle_filtros(t_Datos datos, tImagenBMP* imagen1, tImagenBMP* imagen2)
{
    int i;

    for(i=0;i<datos.cant_filtros;i++)
    {
        if(datos.con_verbose == true)
        {
            printf("Aplicando filtro %s\n", (datos.filtros_pedidos+i)->nombre);
        }

        if(strcmp((datos.filtros_pedidos+i)->nombre,"--negativo")==0)
        {
            //aplicar_filtro1(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--escala-de-grises")==0)
        {
            //aplicar_filtro2(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--espejar-horizontal")==0)
        {
            //aplicar_filtro3(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--espejar-vertical")==0)
        {
            //aplicar_filtro4(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--aumentar-contraste")==0)
        {
            //aplicar_filtro5(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--reducir-contraste")==0)
        {
            //aplicar_filtro6(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--tonalidad-azul")==0)
        {
            //aplicar_filtro7(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--tonalidad-verde")==0)
        {
            //aplicar_filtro8(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--tonalidad-roja")==0)
        {
            //aplicar_filtro9(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--recortar")==0)
        {
            //aplicar_filtro10(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--achicar")==0)
        {
            //aplicar_filtro11(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--rotar-derecha")==0)
        {
            //aplicar_filtro12(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--rotar-izquierda")==0)
        {
            //aplicar_filtro13(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--concatenar-horizontal")==0)
        {
            //aplicar_filtro14(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--concatenar-vertical")==0)
        {
            //aplicar_filtro15(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--comodin")==0)
        {
            //aplicar_filtro16(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else
        {
            printf("Filtro no reconocido: %s\n", (datos.filtros_pedidos+i)->nombre);
        }
    }

    return EXITO; 
}


void aplicar_negativo (tImagenBMP* imagen)
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;

    tPixelBMP pixel;
    int i,j;

    for(i=0;i<alto;i++) //i=filas
    {
        for(j=0;j<ancho;j++) //j=columnas
        {
            matriz_get(&imagen->pixeles,i,j,&pixel); //trae los pixeles

            pixel.azul = 255- pixel.azul;
            pixel.rojo = 255- pixel.rojo;
            pixel.verde = 255- pixel.verde;

            matriz_set(&imagen->pixeles,i,j,&pixel); //cambia los pixeles
        }
    }
}

void aplicar_grises (tImagenBMP* imagen)
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;
    int suma;
    unsigned char gris;

    tPixelBMP pixel;
    int i,j;

    for(i=0;i<alto;i++) //i=filas
    {
        for(j=0;j<ancho;j++) //j=columnas
        {
            matriz_get(&imagen->pixeles,i,j,&pixel); //trae los pixeles

            suma= (pixel.azul + pixel.verde + pixel.rojo);
            gris=(unsigned char) (suma/3);

            pixel.rojo= gris;
            pixel.azul = gris;
            pixel.verde = gris;

            matriz_set(&imagen->pixeles,i,j,&pixel); //cambia los pixeles
        }

    }
}

/* "--negativo","--escala-de-grises",
    "--espejar-horizontal","--espejar-vertical",     SANTY
    "--aumentar-contraste"
    
    "--reducir-contraste", "--tonalidad-azul",
    "--tonalidad-verde",
    "--tonalidad-roja","--recortar",

    "--achicar","--rotar-derecha",
    "--rotar-izquierda","--concatenar-horizontal",
    "--concatenar-vertical","--comodin"*/

