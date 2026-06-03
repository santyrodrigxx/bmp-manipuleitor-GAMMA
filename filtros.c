#include "filtros.h"
#include "matriz_tda.h"

int bucle_filtros(t_Datos datos, tImagenBMP* imagen1)
{
    int i;
    int codError = EXITO;

    char nombreFinal[256] = "GAMMA.bmp";

    for(i=0;i<datos.cant_filtros;i++)
    {
        if(datos.con_verbose == true)
        {
            printf("Aplicando filtro %s\n", (datos.filtros_pedidos+i)->nombre);
        }

        //FILTRO: NEGATIVO----------------------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--negativo")==0)
        {   puts("AAA");
            codError = aplicar_negativo(imagen1);
            if(codError != EXITO){
                bmp_destruir_imagen(imagen1);
                return codError;
            }

            adicionar_filtro(nombreFinal,
                             (datos.filtros_pedidos+i)->nombre,
                             (datos.filtros_pedidos+i)->parametro);

        }

        //FILTRO: ESCALA DE GRISES ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--escala-de-grises")==0)
        {
            puts("AAA");
            codError = aplicar_grises(imagen1);
            if(codError != EXITO){
                bmp_destruir_imagen(imagen1);
                return codError;
            }

            adicionar_filtro(nombreFinal,
                             (datos.filtros_pedidos+i)->nombre,
                             (datos.filtros_pedidos+i)->parametro);
        }
        //FILTRO: ESPEJAR HORIZONALMENTE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--espejar-horizontal")==0)//revisar funcion
        {
            puts("AAA");
            //codError =
            espejar_horizontal(imagen1); //DEBERIA DEVOLVER UN ERROR
            /*if(codError != EXITO){
                bmp_destruir_imagen(imagen1);
                return codError;
            }*/
            adicionar_filtro(nombreFinal,
                            (datos.filtros_pedidos+i)->nombre,
                            (datos.filtros_pedidos+i)->parametro);
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

    codError = bmp_escribir_imagen(nombreFinal, imagen1);
    if(codError != EXITO)
    {
        bmp_destruir_imagen(imagen1);
        return codError;
    }


    return EXITO;
}

void adicionar_filtro(char *nombreArchivo, const char *nombreFiltro, int parametro)
{
    strrchr(nombreArchivo, '.')[0] = '\0';//corto antes del .bmp

    strcat(nombreArchivo, "_");
    strcat(nombreArchivo, nombreFiltro+2); //asi no me salen los --

    //agrego el parametro si existe
    if(parametro != 0){
        char param[16];
        sprintf(param, "[%d]", parametro);
        strcat(nombreArchivo, param);
    }
    strcat(nombreArchivo,"_imagen.bmp");
}

int aplicar_negativo (tImagenBMP* imagen)
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;
    int codigo = EXITO;

    tPixelBMP pixel;
    int i,j;

    for(i=0;i<alto;i++) //i=filas
    {
        for(j=0;j<ancho;j++) //j=columnas
        {
            codigo = matriz_get(&imagen->pixeles,i,j,&pixel); //trae los pixeles
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }
            pixel.azul = 255- pixel.azul;
            pixel.rojo = 255- pixel.rojo;
            pixel.verde = 255- pixel.verde;

            codigo = matriz_set(&imagen->pixeles,i,j,&pixel); //cambia los pixeles
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }
        }
    }//fin FOR
    return EXITO;
}

int aplicar_grises (tImagenBMP* imagen)
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;
    int suma;
    unsigned char gris;
    int codigo = EXITO;

    tPixelBMP pixel;
    int i,j;

    for(i=0;i<alto;i++) //i=filas
    {
        for(j=0;j<ancho;j++) //j=columnas
        {
            codigo = matriz_get(&imagen->pixeles,i,j,&pixel); //trae los pixeles
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }

            suma= (pixel.azul + pixel.verde + pixel.rojo);
            gris=(unsigned char) (suma/3);

            pixel.rojo= gris;
            pixel.azul = gris;
            pixel.verde = gris;

            codigo = matriz_set(&imagen->pixeles,i,j,&pixel); //cambia los pixeles
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }
        }

    }
    return EXITO;
}

void espejar_horizontal (tImagenBMP* imagen) //VER: NO SE ESPEJA, QUEDA IGUAL Y NO APLICA NOMBRE
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;
    int col_espejo;

    tPixelBMP pixel, pixel_nuevo;
    int i,j;

    for(i=0;i<alto;i++) //i=filas
    {
        for(j=0;j<ancho/2;j++) //recorro las columnas hasta la mitad e intercambio
        {
            col_espejo=ancho-j-1; //por ej: si ancho=8, en el px0 espejo= 8-0-1 =7

            matriz_get(&imagen->pixeles,i,j,&pixel);
            matriz_get(&imagen->pixeles,i,col_espejo,&pixel_nuevo);

            matriz_set(&imagen->pixeles,i,j,&pixel_nuevo);
            matriz_set(&imagen->pixeles,i,col_espejo,&pixel);

        }
    }
}

void espejar_vertical (tImagenBMP* imagen)
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;
    int fila_espejo,i,j;

    tPixelBMP pixel, pixel_nuevo;

    for(i=0;i<alto/2;i++) //recorro hasta la mitad de las filas
    {
        for(j=0;j<ancho;j++)
        {
            fila_espejo=alto-1-i;

            matriz_get(&imagen->pixeles,i,j,&pixel);
            matriz_get(&imagen->pixeles,fila_espejo,j,&pixel_nuevo);

            matriz_set(&imagen->pixeles,i,j,&pixel_nuevo);
            matriz_set(&imagen->pixeles,fila_espejo,j,&pixel);

        }
    }

}

void aumentar_contraste (tImagenBMP* imagen, const int parametro)
{
    //int alto =imagen->cabecera.info.altoImagen;
    //int ancho =imagen->cabecera.info.anchoImagen;

    //double aumento
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


