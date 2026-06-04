#include "filtros.h"
#include "matriz_tda.h"

int bucle_filtros(t_Datos datos, tImagenBMP* imagen1, tImagenBMP* imagen2)
{
    int i;
    int codError = EXITO;

    char nombreFinal[256] = "GAMMA";

    for(i=0;i<datos.cant_filtros;i++)
    {
        if(datos.con_verbose == true)
        {
            printf("Aplicando filtro %s\n", (datos.filtros_pedidos+i)->nombre);
        }

        //FILTRO: NEGATIVO----------------------------------------------------------------------
        if(strcmp((datos.filtros_pedidos+i)->nombre,"--negativo")==0)
        {
            puts("Aplicando filtro de negativo...");
            codError = aplicar_negativo(imagen1);
            if(codError != EXITO){
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al aplicar el filtro de negativo.");
                return codError;
            }

            /*if(!adicionar_nombre_filtro(nombreFinal,
                            (datos.filtros_pedidos+i)->nombre,
                            (datos.filtros_pedidos+i)->parametro))
            {
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al generar el nombre del archivo final. Sin espacio suficiente para agregar el nombre del filtro.");
                return ERROR_ARCHIVO;
            }*/

        }

        //FILTRO: ESCALA DE GRISES ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--escala-de-grises")==0)
        {
            puts("Aplicando filtro de escala de grises...");
            codError = aplicar_grises(imagen1);
            if(codError != EXITO){
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al aplicar el filtro de escala de grises");
                return codError;
            }

            /*if(!adicionar_nombre_filtro(nombreFinal,
                            (datos.filtros_pedidos+i)->nombre,
                            (datos.filtros_pedidos+i)->parametro))
            {
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al generar el nombre del archivo final. Sin espacio suficiente para agregar el nombre del filtro.");
                return ERROR_ARCHIVO;
            }*/
        }
        //FILTRO: ESPEJAR HORIZONALMENTE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--espejar-horizontal")==0)
        {
            puts("Aplicando filtro de espejar horizontal...");
            codError= espejar_horizontal(imagen1);
            if(codError != EXITO){
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al aplicar el filtro de espejar horizontal.");
                return codError;
            }

            /*if(!adicionar_nombre_filtro(nombreFinal,
                            (datos.filtros_pedidos+i)->nombre,
                            (datos.filtros_pedidos+i)->parametro))
            {
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al generar el nombre del archivo final. Sin espacio suficiente para agregar el nombre del filtro.");
                return ERROR_ARCHIVO;
            }*/
        }
        //FILTRO: ESPEJAR VERTICALMENTE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--espejar-vertical")==0)
        {
            puts("Aplicando filtro de espejar vertical...");
            codError= espejar_vertical(imagen1);
            if(codError != EXITO){
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al aplicar el filtro de espejar vertical.");
                return codError;
            }

            /*if(!adicionar_nombre_filtro(nombreFinal,
                            (datos.filtros_pedidos+i)->nombre,
                            (datos.filtros_pedidos+i)->parametro))
            {
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al generar el nombre del archivo final. Sin espacio suficiente para agregar el nombre del filtro.");
                return ERROR_ARCHIVO;
            }*/
        }
        //FILTRO: AUMENTAR CONTRASTE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--aumentar-contraste")==0)
        {
            puts("Aplicando filtro de aumentar contraste...");
            codError= aumentar_contraste(imagen1,(datos.filtros_pedidos+i)->parametro);
            if(codError != EXITO){
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al aplicar el filtro de aumentar contraste.");
                return codError;
            }

            /*if(!adicionar_nombre_filtro(nombreFinal,
                            (datos.filtros_pedidos+i)->nombre,
                            (datos.filtros_pedidos+i)->parametro))
            {
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al generar el nombre del archivo final. Sin espacio suficiente para agregar el nombre del filtro.");
                return ERROR_ARCHIVO;
            }*/
        }
        //FILTRO: REDUCIR CONTRASTE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--reducir-contraste")==0)
        {
            puts("Aplicando filtro de reducir contraste...");
            codError= reducir_contraste(imagen1,(datos.filtros_pedidos+i)->parametro);
            if(codError != EXITO){
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al aplicar el filtro de reducir contraste.");
                return codError;
            }

            /*if(!adicionar_nombre_filtro(nombreFinal,
                            (datos.filtros_pedidos+i)->nombre,
                            (datos.filtros_pedidos+i)->parametro))
{
                bmp_destruir_imagen(imagen1);
                bmp_destruir_imagen(imagen2);
                puts("Error al generar el nombre del archivo final. Sin espacio suficiente para agregar el nombre del filtro.");
                return ERROR_ARCHIVO;
            }*/
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
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--rotar-derecha")==0)//ANTO
        {
            //aplicar_filtro12(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--rotar-izquierda")==0)//ANTO
        {
            //aplicar_filtro13(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--concatenar-horizontal")==0)//ANTO
        {
            //aplicar_filtro14(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--concatenar-vertical")==0)//ANTO
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

    if(!modificar_nombre_filtro(nombreFinal, datos))
    {
        bmp_destruir_imagen(imagen1);
        bmp_destruir_imagen(imagen2);
        puts("Error al generar el nombre del archivo final. Sin espacio suficiente para agregar el nombre de los filtros.");
        return codError;
    }

    codError = bmp_escribir_imagen(nombreFinal, imagen1);
    if(codError != EXITO)
    {
        bmp_destruir_imagen(imagen1);
        bmp_destruir_imagen(imagen2);
        return codError;
    }

    bmp_destruir_imagen(imagen1); //destruyo la imagen procesada porque ya se guardo el resultado en un nuevo archivo, por lo que ya no se necesita
    bmp_destruir_imagen(imagen2); //destruyo la segunda imagen porque ya no se va a usar

    return EXITO;
}

bool modificar_nombre_filtro(char *nombreArchivo, t_Datos info)
{
    int ce = info.cant_filtros;
    int i  = 0;

    //valido todos los nombres antes de modificar nada
    for(int k = 0; k < ce; k++)
    {
        if((info.filtros_pedidos+k)->nombre == NULL)
            return false;
    }

    while(i < ce && (strlen(nombreArchivo) + strlen((info.filtros_pedidos+i)->nombre) + 30) < 255)
    {
        strcat(nombreArchivo, "_");
        strcat(nombreArchivo, (info.filtros_pedidos+i)->nombre + 2); //saco el --

        if((info.filtros_pedidos+i)->parametro != 0)
        {
            char parametroAux[20];
            sprintf(parametroAux, "[%d]", (info.filtros_pedidos+i)->parametro);
            strcat(nombreArchivo, parametroAux);
        }

        i++;
    }

    strcat(nombreArchivo, "_imagen.bmp");
    return true;
}

//FILTROS
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

int espejar_horizontal (tImagenBMP* imagen)
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;
    int col_espejo, codigo= EXITO;

    tPixelBMP pixel, pixel_nuevo;
    int i,j;

    for(i=0;i<alto;i++) //i=filas
    {
        for(j=0;j<ancho/2;j++) //recorro las columnas hasta la mitad e intercambio
        {
            col_espejo=ancho-j-1; //por ej: si ancho=8, en el px0 espejo= 8-0-1 =7

            //Obtener pixeles a intercambiar
            codigo= matriz_get(&imagen->pixeles,i,j,&pixel);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }
            codigo= matriz_get(&imagen->pixeles,i,col_espejo,&pixel_nuevo);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }

            //Intercambiar pixeles
            codigo= matriz_set(&imagen->pixeles,i,j,&pixel_nuevo);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }
            codigo= matriz_set(&imagen->pixeles,i,col_espejo,&pixel);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }

        }
    }
    return EXITO;
}

int espejar_vertical (tImagenBMP* imagen)
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;
    int fila_espejo,i,j, codigo=EXITO;

    tPixelBMP pixel, pixel_nuevo;

    for(i=0;i<alto/2;i++) //recorro hasta la mitad de las filas
    {
        for(j=0;j<ancho;j++)
        {
            fila_espejo=alto-1-i;

            //Obtener pixeles a intercambiar
            codigo= matriz_get(&imagen->pixeles,i,j,&pixel);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }
            codigo= matriz_get(&imagen->pixeles,fila_espejo,j,&pixel_nuevo);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }

            //Intercambiar pixeles
            codigo= matriz_set(&imagen->pixeles,i,j,&pixel_nuevo);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }
            codigo= matriz_set(&imagen->pixeles,fila_espejo,j,&pixel);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }

        }
    }
    return EXITO;

}

void acomodar(double* color)
{
    if( *(color)>255.0 )
    {
        *(color)=255.0;
    }
    else if( *(color)<0.0 )
    {
        *(color)=0.0;
    }
}

int aumentar_contraste (tImagenBMP* imagen, const int parametro)
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;
    double nuevo_rojo, nuevo_azul, nuevo_verde;

    double factor = (259.0 * (parametro + 255.0)) / (255.0 * (259.0 - parametro));
    tPixelBMP pixel;
    int i,j, codigo=EXITO;

    for(i=0;i<alto;i++)
    {
        for(j=0;j<ancho;j++)
        {
            codigo = matriz_get(&imagen->pixeles,i,j, &pixel);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }

            nuevo_rojo= factor* (pixel.rojo-128) + 128;
            acomodar(&nuevo_rojo);

            nuevo_azul= factor* (pixel.azul-128) + 128;
            acomodar(&nuevo_azul);

            nuevo_verde= factor* (pixel.verde-128) + 128;
            acomodar(&nuevo_verde);

            pixel.rojo= (unsigned char)(nuevo_rojo);
            pixel.azul= (unsigned char)(nuevo_azul);
            pixel.verde= (unsigned char)(nuevo_verde);

            codigo = matriz_set(&imagen->pixeles,i,j,&pixel);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }
        }
    }
    return EXITO;
}

int reducir_contraste (tImagenBMP* imagen, const int parametro)
{
    int alto =imagen->cabecera.info.altoImagen;
    int ancho =imagen->cabecera.info.anchoImagen;
    double nuevo_rojo, nuevo_azul, nuevo_verde;

    double factor = (259.0 * (255.0 - parametro)) / (255.0 * (259.0 + parametro));
    tPixelBMP pixel;
    int i,j, codigo=EXITO;

    for(i=0;i<alto;i++)
    {
        for(j=0;j<ancho;j++)
        {
            codigo = matriz_get(&imagen->pixeles,i,j, &pixel);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }

            nuevo_rojo= factor* (pixel.rojo-128) + 128;
            acomodar(&nuevo_rojo);

            nuevo_azul= factor* (pixel.azul-128) + 128;
            acomodar(&nuevo_azul);

            nuevo_verde= factor* (pixel.verde-128) + 128;
            acomodar(&nuevo_verde);

            pixel.rojo= (unsigned char)(nuevo_rojo);
            pixel.azul= (unsigned char)(nuevo_azul);
            pixel.verde= (unsigned char)(nuevo_verde);

            codigo = matriz_set(&imagen->pixeles,i,j,&pixel);
            if(codigo != EXITO){
                bmp_destruir_imagen(imagen);
                return codigo;
            }
        }
    }
    return EXITO;
}

void aplicar_tonalidad_azul(tImagenBMP* imagen, int porcentaje)
{
    int alto = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;
    tPixelBMP pixel;
    int i, j, nuevo_valor;

    for(i = 0; i < alto; i++) // i=filas
    {
        for(j = 0; j < ancho; j++) // j=columnas
        {
            matriz_get(&imagen->pixeles, i, j, &pixel);

            nuevo_valor = pixel.azul + (pixel.azul * porcentaje / 100);
            if(nuevo_valor > 255)
            {
                nuevo_valor = 255;
            }
            pixel.azul = (unsigned char)nuevo_valor;

            matriz_set(&imagen->pixeles, i, j, &pixel);
        }
    }
}

void aplicar_tonalidad_verde(tImagenBMP* imagen, int porcentaje)
{
    int alto = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;
    tPixelBMP pixel;
    int i, j, nuevo_valor;

    for(i = 0; i < alto; i++)
    {
        for(j = 0; j < ancho; j++)
        {
            matriz_get(&imagen->pixeles, i, j, &pixel);

            nuevo_valor = pixel.verde + (pixel.verde * porcentaje / 100);
            if(nuevo_valor > 255)
            {
                nuevo_valor = 255;
            }
            pixel.verde = (unsigned char)nuevo_valor;

            matriz_set(&imagen->pixeles, i, j, &pixel);
        }
    }
}

void aplicar_tonalidad_roja(tImagenBMP* imagen, int porcentaje)
{
    int alto = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;
    tPixelBMP pixel;
    int i, j, nuevo_valor;

    for(i = 0; i < alto; i++)
    {
        for(j = 0; j < ancho; j++)
        {
            matriz_get(&imagen->pixeles, i, j, &pixel);

            nuevo_valor = pixel.rojo + (pixel.rojo * porcentaje / 100);
            if(nuevo_valor > 255)
            {
                nuevo_valor = 255;
            }
            pixel.rojo = (unsigned char)nuevo_valor;

            matriz_set(&imagen->pixeles, i, j, &pixel);
        }
    }
}

int aplicar_recortar(tImagenBMP* imagen, int porcentaje)
{
    int estado = EXITO;

    if (porcentaje > 0 && porcentaje <= 100)
    {
        int alto = imagen->cabecera.info.altoImagen;
        int ancho = imagen->cabecera.info.anchoImagen;

        int nuevo_alto = (alto * porcentaje) / 100;
        int nuevo_ancho = (ancho * porcentaje) / 100;

        if (nuevo_alto > 0 && nuevo_ancho > 0)
        {
            tda_matriz nueva_matriz;
            estado = matriz_crear(&nueva_matriz, nuevo_alto, nuevo_ancho, sizeof(tPixelBMP));

            if (estado == EXITO)
            {
                tPixelBMP pixel;
                int i, j, fila_orig;

                for (i = 0; i < nuevo_alto; i++)
                {
                    fila_orig = i + (alto - nuevo_alto);
                    for (j = 0; j < nuevo_ancho; j++)
                    {
                        matriz_get(&imagen->pixeles, fila_orig, j, &pixel);
                        matriz_set(&nueva_matriz, i, j, &pixel);
                    }
                }

                matriz_destruir(&imagen->pixeles);
                imagen->pixeles = nueva_matriz;

                // actualiza la cabecera con las nuevas dimensioness
                imagen->cabecera.info.anchoImagen = nuevo_ancho;
                imagen->cabecera.info.altoImagen = nuevo_alto;

                int padding = (4 - ((nuevo_ancho * sizeof(tPixelBMP)) % 4)) % 4;
                imagen->cabecera.info.tamImagen = (nuevo_ancho * sizeof(tPixelBMP) + padding) * nuevo_alto;
                imagen->cabecera.archivo.tamArchivo = imagen->cabecera.archivo.posPixeles + imagen->cabecera.info.tamImagen;
            }
        }
        else
        {
            estado = ERROR_ARGUMENTOS;
        }
    }
    else
    {
        estado = ERROR_ARGUMENTOS;
    }

    return estado;
}
int aplicar_achicar(tImagenBMP* imagen, int porcentaje)
{
    int estado = EXITO;

    if (porcentaje > 0 && porcentaje <= 100)
    {
        int alto = imagen->cabecera.info.altoImagen;
        int ancho = imagen->cabecera.info.anchoImagen;

        int nuevo_alto = (alto * porcentaje) / 100;
        int nuevo_ancho = (ancho * porcentaje) / 100;

        if (nuevo_alto > 0 && nuevo_ancho > 0)
        {
            tda_matriz nueva_matriz;
            estado = matriz_crear(&nueva_matriz, nuevo_alto, nuevo_ancho, sizeof(tPixelBMP));

            if (estado == EXITO)
            {
                tPixelBMP pixel;
                int i, j, fila_orig, col_orig;

                for (i = 0; i < nuevo_alto; i++)
                {
                    for (j = 0; j < nuevo_ancho; j++)
                    {
                        // proporcional a la matriz original
                        fila_orig = (i * alto) / nuevo_alto;
                        col_orig = (j * ancho) / nuevo_ancho;

                        matriz_get(&imagen->pixeles, fila_orig, col_orig, &pixel);
                        matriz_set(&nueva_matriz, i, j, &pixel);
                    }
                }

                matriz_destruir(&imagen->pixeles);
                imagen->pixeles = nueva_matriz;

                // actualizaci�n de los datos del archivo
                imagen->cabecera.info.anchoImagen = nuevo_ancho;
                imagen->cabecera.info.altoImagen = nuevo_alto;

                int padding = (4 - ((nuevo_ancho * sizeof(tPixelBMP)) % 4)) % 4;
                imagen->cabecera.info.tamImagen = (nuevo_ancho * sizeof(tPixelBMP) + padding) * nuevo_alto;
                imagen->cabecera.archivo.tamArchivo = imagen->cabecera.archivo.posPixeles + imagen->cabecera.info.tamImagen;
            }
        }
        else
        {
            estado = ERROR_ARGUMENTOS;
        }
    }
    else
    {
        estado = ERROR_ARGUMENTOS;
    }

    return estado;
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


