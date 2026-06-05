#include "filtros.h"
#include "matriz_tda.h"

int bucle_filtros(t_Datos datos, tImagenBMP* imagen1, tImagenBMP* imagen2)
{
    //BORRO TODOS LOS BMP DESTRUIR, PQ SI TENGO ERROR (INT DE BUCLE_FILTROS), YA HACE ESTE PROCESO
    int i;
    int codError = EXITO;

    char nombreFinal[256] = "GAMMA";

    for(i=0;i<datos.cant_filtros;i++)
    {
        if(datos.con_verbose == true)
        {
            printf("[INFO] Aplicando filtro: %s\n", (datos.filtros_pedidos+i)->nombre);
        }

        //FILTRO: NEGATIVO----------------------------------------------------------------------
        if(strcmp((datos.filtros_pedidos+i)->nombre,"--negativo")==0)
        {
            //puts("Aplicando filtro de negativo...");
            codError = aplicar_negativo(imagen1);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de negativo.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;

        }

        //FILTRO: ESCALA DE GRISES ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--escala-de-grises")==0)
        {
            //puts("Aplicando filtro de escala de grises...");
            codError = aplicar_grises(imagen1);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de escala de grises");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;

        }
        //FILTRO: ESPEJAR HORIZONALMENTE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--espejar-horizontal")==0)
        {
            //puts("Aplicando filtro de espejar horizontal...");
            codError= espejar_horizontal(imagen1);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de espejar horizontal.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        //FILTRO: ESPEJAR VERTICALMENTE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--espejar-vertical")==0)
        {
            //puts("Aplicando filtro de espejar vertical...");
            codError= espejar_vertical(imagen1);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de espejar vertical.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        //FILTRO: AUMENTAR CONTRASTE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--aumentar-contraste")==0)
        {
            //puts("Aplicando filtro de aumentar contraste...");
            codError= aumentar_contraste(imagen1,(datos.filtros_pedidos+i)->parametro);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de aumentar contraste.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        //FILTRO: REDUCIR CONTRASTE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--reducir-contraste")==0)
        {
            //puts("Aplicando filtro de reducir contraste...");
            codError= reducir_contraste(imagen1,(datos.filtros_pedidos+i)->parametro);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de reducir contraste.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;

        }
        //FILTRO: TONALIDAD AZUL ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--tonalidad-azul")==0)
        {
            //puts("Aplicando filtro de tonalidad azul...");
            codError = aplicar_tonalidad_azul(imagen1, (datos.filtros_pedidos+i)->parametro);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de tonalidad azul.");
                return codError;
            }

            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            

        }
        //FILTRO: TONALIDAD VERDE ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--tonalidad-verde")==0)
        {
            //puts("Aplicando filtro de tonalidad verde...");
            codError = aplicar_tonalidad_verde(imagen1, (datos.filtros_pedidos+i)->parametro);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de tonalidad verde.");
                return codError;
            }

            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        //FILTRO: TONALIDAD ROJA ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--tonalidad-roja")==0)
        {
            //puts("Aplicando filtro de tonalidad roja...");
            codError = aplicar_tonalidad_roja(imagen1, (datos.filtros_pedidos+i)->parametro);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de tonalidad roja.");
                return codError;
            }

            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;

        }
        //FILTRO: RECORTAR ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--recortar")==0)
        {
            //puts("Aplicando filtro de recortar...");
            codError = aplicar_recortar(imagen1, (datos.filtros_pedidos+i)->parametro);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de recortar.");
                return codError;
            }

            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;

        }
        //FILTRO: ACHICAR ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--achicar")==0)
        {
            //puts("Aplicando filtro de achicar...");
            codError = aplicar_achicar(imagen1, (datos.filtros_pedidos+i)->parametro);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de achicar.");
                return codError;
            }

            modificar_nombre_filtro(nombreFinal, datos, i);

            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        //FILTRO: ROTAR DERECHA ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--rotar-derecha")==0)//ANTO
        {
            //puts("Aplicando filtro de rotar derecha...");
            codError = rotar_derecha(imagen1);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de rotar derecha.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);
            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        //FILTRO: ROTAR IZQUIERDA ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--rotar-izquierda")==0)
        {
            //puts("Aplicando filtro de rotar izquierda...");
            codError = rotar_izquierda(imagen1);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de rotar izquierda.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);
            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        //FILTRO: CONCATENAR HORIZONTAL ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--concatenar-horizontal")==0)
        {
            //puts("Aplicando filtro de concatenar horizontal...");
            codError = concatenar_horizontal(imagen1, imagen2);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de concatenar horizontal.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);
            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        //FILTRO: CONCATENAR VERTICAL ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--concatenar-vertical")==0)
        {
            //puts("Aplicando filtro de concatenar vertical...");
            codError = concatenar_vertical(imagen1, imagen2);
            if(codError != EXITO){
                puts("Error al aplicar el filtro de concatenar vertical.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);
            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        //FILTRO: COMODIN ----------------------------------------------------------
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--comodin")==0)
        {
            //puts("Aplicando filtro comodin...");
            codError = aplicar_chroma(imagen1,imagen2);
            if(codError != EXITO){
                puts("Error al aplicar el filtro comodin.");
                return codError;
            }
            modificar_nombre_filtro(nombreFinal, datos, i);
            codError = bmp_escribir_imagen(nombreFinal, imagen1);
            if(codError != EXITO)
                return codError;
            
        }
        else
        {
            printf("Filtro no reconocido: %s\n", (datos.filtros_pedidos+i)->nombre);
        }

        if(datos.con_verbose == true)
        {
            printf("[INFO] Guardando resultado: GAMMA_%s_%s\n", (datos.filtros_pedidos+i)->nombre,datos.imagen1);
            printf("[INFO] Filtro %s aplicado exitosamente\n", (datos.filtros_pedidos+i)->nombre);
        }
    }


    codError = bmp_escribir_imagen(nombreFinal, imagen1);
    if(codError != EXITO)
        return codError;

    return EXITO;
}

void modificar_nombre_filtro(char *nombreArchivo, t_Datos info, int cont)
{
    //puts("Generando nombre del archivo ...");
    strcpy(nombreArchivo, "GAMMA");

    strcat(nombreArchivo, "_");
    strcat(nombreArchivo, info.filtros_pedidos[cont].nombre + 2);

    if(info.filtros_pedidos[cont].parametro != 0)
    {
        char parametroAux[20];
        sprintf(parametroAux, "[%d]", info.filtros_pedidos[cont].parametro);
        strcat(nombreArchivo, parametroAux);
    }

    strcat(nombreArchivo, "_");
    strcat(nombreArchivo, info.imagen1);
    //printf("Archivo %s generado correctamente.\n", nombreArchivo);
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

int aplicar_tonalidad_azul(tImagenBMP* imagen, int porcentaje)
{
    int alto = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;
    tPixelBMP pixel;
    int i, j, nuevo_valor;
    int codigo = EXITO;

    for(i = 0; i < alto; i++) // i=filas
    {
        for(j = 0; j < ancho; j++) // j=columnas
        {
            matriz_get(&imagen->pixeles, i, j, &pixel);
            if(codigo != EXITO)
                return codigo;

            nuevo_valor = pixel.azul + (pixel.azul * porcentaje / 100);
            if(nuevo_valor > 255)
            {
                nuevo_valor = 255;
            }
            pixel.azul = (unsigned char)nuevo_valor;

            matriz_set(&imagen->pixeles, i, j, &pixel);
            if (codigo != EXITO)
                return codigo;
        }
    }
    return EXITO;
}

int aplicar_tonalidad_verde(tImagenBMP* imagen, int porcentaje)
{
    int alto = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;
    tPixelBMP pixel;
    int i, j, nuevo_valor;
    int codigo = EXITO;

    for(i = 0; i < alto; i++)
    {
        for(j = 0; j < ancho; j++)
        {
            matriz_get(&imagen->pixeles, i, j, &pixel);
            if (codigo != EXITO)
                return codigo;

            nuevo_valor = pixel.verde + (pixel.verde * porcentaje / 100);
            if(nuevo_valor > 255)
            {
                nuevo_valor = 255;
            }
            pixel.verde = (unsigned char)nuevo_valor;

            matriz_set(&imagen->pixeles, i, j, &pixel);
            if(codigo != EXITO)
                return codigo;
        }
    }
    return EXITO;
}

int aplicar_tonalidad_roja(tImagenBMP* imagen, int porcentaje)
{
    int alto = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;
    tPixelBMP pixel;
    int i, j, nuevo_valor;
    int codigo = EXITO;

    for(i = 0; i < alto; i++)
    {
        for(j = 0; j < ancho; j++)
        {
            matriz_get(&imagen->pixeles, i, j, &pixel);
            if(codigo != EXITO)
                return codigo;

            nuevo_valor = pixel.rojo + (pixel.rojo * porcentaje / 100);
            if(nuevo_valor > 255)
            {
                nuevo_valor = 255;
            }
            pixel.rojo = (unsigned char)nuevo_valor;

            matriz_set(&imagen->pixeles, i, j, &pixel);
            if(codigo != EXITO)
                return codigo;
        }
    }
    return EXITO;
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

int rotar_derecha(tImagenBMP *imagen)
{
    if(imagen == NULL){
        puts("Error: no existe la imagen.");
        return ERROR_ARGUMENTOS;
    }

    int i, j, codigo = EXITO;
    int alto  = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;
    tda_matriz nueva_matriz;
    tPixelBMP pixel;

    //nueva matriz con dimensiones invertidas
    codigo = matriz_crear(&nueva_matriz, ancho, alto, sizeof(tPixelBMP));
    if(codigo != EXITO) return codigo;


    for(i = 0; i < alto; i++)//la fila i de la imagen original se convierte en la columna i de la nueva matriz, pero invertida
    {
        for(j = 0; j < ancho; j++)
        {
            codigo = matriz_get(&imagen->pixeles, i, j, &pixel);
            if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }

            codigo = matriz_set(&nueva_matriz, j, alto - 1 - i, &pixel);
            if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }
        }
    }

    //reemplazo la matriz original
    matriz_destruir(&imagen->pixeles);
    codigo = matriz_crear(&imagen->pixeles, ancho, alto, sizeof(tPixelBMP));
    if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }

    for(i = 0; i < ancho; i++)
    {
        for(j = 0; j < alto; j++)
        {
            codigo = matriz_get(&nueva_matriz, i, j, &pixel);
            if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }

            codigo = matriz_set(&imagen->pixeles, i, j, &pixel);
            if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }
        }
    }

    //actualizo dimensiones en la cabecera
    imagen->cabecera.info.altoImagen  = ancho;
    imagen->cabecera.info.anchoImagen = alto;

    matriz_destruir(&nueva_matriz);
    return EXITO;
}

int rotar_izquierda(tImagenBMP *imagen)
{
    if(imagen == NULL){
        puts("Error: no existe la imagen.");
        return ERROR_ARGUMENTOS;
    }

    int i, j, codigo = EXITO;
    int alto  = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;
    tda_matriz nueva_matriz;
    tPixelBMP pixel;

    //nueva matriz con dimensiones invertidas
    codigo = matriz_crear(&nueva_matriz, ancho, alto, sizeof(tPixelBMP));
    if(codigo != EXITO) return codigo;


    for(i = 0; i < alto; i++)//hago lo mismo, pero la fila i de la imagen original se convierte en la columna i de la nueva matriz, sin invertir
    {
        for(j = 0; j < ancho; j++)
        {
            codigo = matriz_get(&imagen->pixeles, i, j, &pixel);
            if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }

            codigo = matriz_set(&nueva_matriz, ancho - 1 - j, i, &pixel);
            if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }
        }
    }

    //reemplazo la matriz original
    matriz_destruir(&imagen->pixeles);
    codigo = matriz_crear(&imagen->pixeles, ancho, alto, sizeof(tPixelBMP));
    if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }

    for(i = 0; i < ancho; i++)
    {
        for(j = 0; j < alto; j++)
        {
            codigo = matriz_get(&nueva_matriz, i, j, &pixel);
            if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }

            codigo = matriz_set(&imagen->pixeles, i, j, &pixel);
            if(codigo != EXITO){ matriz_destruir(&nueva_matriz); return codigo; }
        }
    }

    //actualizo dimensiones en la cabecera
    imagen->cabecera.info.altoImagen  = ancho;
    imagen->cabecera.info.anchoImagen = alto;

    matriz_destruir(&nueva_matriz);
    return EXITO;
}

int concatenar_horizontal(tImagenBMP *imagen1, tImagenBMP *imagen2)
{
    if(imagen1 == NULL || imagen2 == NULL)
    {
        puts("Error: no existe una de las imágenes.");
        return ERROR_ARGUMENTOS;
    }

    int codigo = EXITO;

    int alto1  = imagen1->cabecera.info.altoImagen;
    int ancho1 = imagen1->cabecera.info.anchoImagen;
    int alto2  = imagen2->cabecera.info.altoImagen;
    int ancho2 = imagen2->cabecera.info.anchoImagen;

    int nuevo_alto  = alto1 > alto2 ? alto1 : alto2;
    int nuevo_ancho = ancho1 + ancho2;

    tda_matriz nueva_matriz;

    codigo = matriz_crear(&nueva_matriz, nuevo_alto, nuevo_ancho, sizeof(tPixelBMP));
    if(codigo != EXITO)
        return codigo;

    tPixelBMP pixel;
    tPixelBMP negro = {0, 0, 0};

    for(int i = 0; i < nuevo_alto; i++)
    {
        for(int j = 0; j < nuevo_ancho; j++)
        {
            if(j < ancho1)
            {/*Zona de imagen1
                Si la fila existe en imagen1 copio el pixel.
                Si no existe completo con negro.*/
                if(i < alto1)
                {
                    codigo = matriz_get(&imagen1->pixeles, i, j, &pixel);
                    if(codigo != EXITO)
                    {
                        matriz_destruir(&nueva_matriz);
                        return codigo;
                    }
                }
                else
                {
                    pixel = negro;
                }
            }
            else
            {
                //Zona de imagen2
                //La columna real dentro de imagen2 es j - ancho1
                int columna_img2 = j - ancho1;

                if(i < alto2)
                {
                    codigo = matriz_get(&imagen2->pixeles, i, columna_img2, &pixel);
                    if(codigo != EXITO)
                    {
                        matriz_destruir(&nueva_matriz);
                        return codigo;
                    }
                }
                else
                {
                    pixel = negro;
                }
            }

            codigo = matriz_set(&nueva_matriz, i, j, &pixel);
            if(codigo != EXITO)
            {
                matriz_destruir(&nueva_matriz);
                return codigo;
            }
        }
    }

    matriz_destruir(&imagen1->pixeles);

    codigo = matriz_crear(&imagen1->pixeles, nuevo_alto, nuevo_ancho, sizeof(tPixelBMP));
    if(codigo != EXITO)
    {
        matriz_destruir(&nueva_matriz);
        return codigo;
    }

    for(int i = 0; i < nuevo_alto; i++)
    {
        for(int j = 0; j < nuevo_ancho; j++)
        {
            codigo = matriz_get(&nueva_matriz, i, j, &pixel);
            if(codigo != EXITO)
            {
                matriz_destruir(&nueva_matriz);
                return codigo;
            }

            codigo = matriz_set(&imagen1->pixeles, i, j, &pixel);
            if(codigo != EXITO)
            {
                matriz_destruir(&nueva_matriz);
                return codigo;
            }
        }
    }

    int padding = (4 - ((nuevo_ancho * sizeof(tPixelBMP)) % 4)) % 4;

    imagen1->cabecera.info.anchoImagen   = nuevo_ancho;
    imagen1->cabecera.info.altoImagen    = nuevo_alto;
    imagen1->cabecera.info.tamImagen     = (nuevo_ancho * sizeof(tPixelBMP) + padding) * nuevo_alto;
    imagen1->cabecera.archivo.tamArchivo = sizeof(BMPCabecera) + imagen1->cabecera.info.tamImagen;

    matriz_destruir(&nueva_matriz);

    return EXITO;
}

int concatenar_vertical(tImagenBMP *imagen1, tImagenBMP *imagen2)
{
    if(imagen1 == NULL || imagen2 == NULL)
    {
        puts("Error: no existe una de las imágenes.");
        return ERROR_ARGUMENTOS;
    }

    int codigo = EXITO;

    int alto1  = imagen1->cabecera.info.altoImagen;
    int ancho1 = imagen1->cabecera.info.anchoImagen;
    int alto2  = imagen2->cabecera.info.altoImagen;
    int ancho2 = imagen2->cabecera.info.anchoImagen;

    int nuevo_alto  = alto1 + alto2;
    int nuevo_ancho = ancho1 > ancho2 ? ancho1 : ancho2;

    tda_matriz nueva_matriz;

    codigo = matriz_crear(&nueva_matriz, nuevo_alto, nuevo_ancho, sizeof(tPixelBMP));
    if(codigo != EXITO)
        return codigo;

    tPixelBMP pixel;
    tPixelBMP negro = {0, 0, 0};

    for(int i = 0; i < nuevo_alto; i++)
    {
        for(int j = 0; j < nuevo_ancho; j++)
        {
            if(i < alto1)
            {/* Zona de imagen1
                Si la columna existe copio
                Si no existe completo con negro*/
                if(j < ancho1)
                {
                    codigo = matriz_get(&imagen1->pixeles, i, j, &pixel);
                    if(codigo != EXITO)
                    {
                        matriz_destruir(&nueva_matriz);
                        return codigo;
                    }
                }
                else
                {
                    pixel = negro;
                }
            }
            else
            {
                //Zona de imagen2
                //La fila real dentro de imagen2 es i - alto1
                int fila_img2 = i - alto1;

                if(j < ancho2)
                {
                    codigo = matriz_get(&imagen2->pixeles, fila_img2, j, &pixel);
                    if(codigo != EXITO)
                    {
                        matriz_destruir(&nueva_matriz);
                        return codigo;
                    }
                }
                else
                {
                    pixel = negro;
                }
            }

            codigo = matriz_set(&nueva_matriz, i, j, &pixel);
            if(codigo != EXITO)
            {
                matriz_destruir(&nueva_matriz);
                return codigo;
            }
        }
    }

    matriz_destruir(&imagen1->pixeles);

    codigo = matriz_crear(&imagen1->pixeles, nuevo_alto, nuevo_ancho, sizeof(tPixelBMP));
    if(codigo != EXITO)
    {
        matriz_destruir(&nueva_matriz);
        return codigo;
    }

    for(int i = 0; i < nuevo_alto; i++)
    {
        for(int j = 0; j < nuevo_ancho; j++)
        {
            codigo = matriz_get(&nueva_matriz, i, j, &pixel);
            if(codigo != EXITO)
            {
                matriz_destruir(&nueva_matriz);
                return codigo;
            }

            codigo = matriz_set(&imagen1->pixeles, i, j, &pixel);
            if(codigo != EXITO)
            {
                matriz_destruir(&nueva_matriz);
                return codigo;
            }
        }
    }

    int padding = (4 - ((nuevo_ancho * sizeof(tPixelBMP)) % 4)) % 4;

    imagen1->cabecera.info.anchoImagen   = nuevo_ancho;
    imagen1->cabecera.info.altoImagen    = nuevo_alto;
    imagen1->cabecera.info.tamImagen     = (nuevo_ancho * sizeof(tPixelBMP) + padding) * nuevo_alto;
    imagen1->cabecera.archivo.tamArchivo = sizeof(BMPCabecera) + imagen1->cabecera.info.tamImagen;

    matriz_destruir(&nueva_matriz);

    return EXITO;
}

int aplicar_chroma(tImagenBMP* img_original, const tImagenBMP* img_fondo)
{
    if (img_original == NULL || img_fondo == NULL)
    {
        return ERROR_ARGUMENTOS;
    }

    int ancho_orig = img_original->cabecera.info.anchoImagen;
    int alto_orig = img_original->cabecera.info.altoImagen;
    int ancho_fondo = img_fondo->cabecera.info.anchoImagen;
    int alto_fondo = img_fondo->cabecera.info.altoImagen;

    //configuración del chroma
    int umbral_verde_minimo = 35;
    int dominancia_verde = 20;

    tPixelBMP pixel_actual;
    tPixelBMP pixel_fondo;

    //recorre la matriz de la imagen original
    for (int i = 0; i < alto_orig; i++)
    {
        for (int j = 0; j < ancho_orig; j++)
        {
            // tomo el píxel actual (el que tiene la pantalla verde)
            matriz_get(&img_original->pixeles, i, j, &pixel_actual);

            //calcula si hay una buena proporcion de verde como para aplicar el chroma
            if (pixel_actual.verde > umbral_verde_minimo &&
                (pixel_actual.verde - pixel_actual.rojo) > dominancia_verde &&
                (pixel_actual.verde - pixel_actual.azul) > dominancia_verde)
            {
                // uso double para no perder precisión en la división y luego casteamos a entero
                int fondo_i = (int)((double)i / alto_orig * alto_fondo);
                int fondo_j = (int)((double)j / ancho_orig * ancho_fondo);

                // evito desbordar los límites por redondeo
                if (fondo_i >= alto_fondo) fondo_i = alto_fondo - 1;
                if (fondo_j >= ancho_fondo) fondo_j = ancho_fondo - 1;
                if (fondo_i < 0) fondo_i = 0;
                if (fondo_j < 0) fondo_j = 0;

                //saco el pixel proporcional de la otra imagen
                matriz_get(&img_fondo->pixeles, fondo_i, fondo_j, &pixel_fondo);

                //guardo ese píxel en la imagen original en la posición (i, j)
                matriz_set(&img_original->pixeles, i, j, &pixel_fondo);
            }
        }
    }

    return EXITO;
}



