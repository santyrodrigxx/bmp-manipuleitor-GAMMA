#include "bmp.h"
#include "matriz_tda.h"

//...las filas de píxeles suelen estar guardadas de abajo hacia arriba,
//pero eso afecta a la matriz de píxeles, no al header.


int bmp_leer_imagen(const char *nombreArchivo, tImagenBMP *imagen) //hasta el .bmp??
{
    FILE *arc_imagen = fopen(nombreArchivo, "rb");

    if (arc_imagen == NULL) { //aca no cargue la matriz, por lo tanto no hace falta destruir nada
        puts("Error al abrir archivo imagen.");
        fclose(arc_imagen);
        return ERROR_ARC;
    }

    //LECTURA Y ALMACENAMIENTO DE INFO ARCHIVO BMP
    fread(&imagen->cabecera.archivo.firma, sizeof(unsigned short), 1, arc_imagen);
    fread(&imagen->cabecera.archivo.tamArchivo, sizeof(unsigned int), 1, arc_imagen);
    fread(&imagen->cabecera.archivo.reservado1, sizeof(unsigned short), 1, arc_imagen);
    fread(&imagen->cabecera.archivo.reservado2, sizeof(unsigned short), 1, arc_imagen);
    fread(&imagen->cabecera.archivo.posPixeles, sizeof(unsigned int), 1, arc_imagen);

    //LECTURA Y ALMACENAMIENTO DE INFO CABECERA
    fread(&imagen->cabecera.info.tamCabecera, sizeof(unsigned int), 1, arc_imagen);
    fread(&imagen->cabecera.info.anchoImagen, sizeof(int), 1, arc_imagen);
    fread(&imagen->cabecera.info.altoImagen, sizeof(int), 1, arc_imagen);
    fread(&imagen->cabecera.info.planos, sizeof(unsigned short), 1, arc_imagen);
    fread(&imagen->cabecera.info.bitsPorPixel, sizeof(unsigned short), 1, arc_imagen);
    fread(&imagen->cabecera.info.compresion, sizeof(unsigned int), 1, arc_imagen);
    fread(&imagen->cabecera.info.tamImagen, sizeof(unsigned int), 1, arc_imagen);
    fread(&imagen->cabecera.info.resolucionHorizontal, sizeof(int), 1, arc_imagen);
    fread(&imagen->cabecera.info.resolucionVertical, sizeof(int), 1, arc_imagen);
    fread(&imagen->cabecera.info.coloresUsados, sizeof(unsigned int), 1, arc_imagen);
    fread(&imagen->cabecera.info.coloresImportantes, sizeof(unsigned int), 1, arc_imagen);

    //VALIDACION DE CONDICIONES (compresion, profundidad, tamaño y tipo de archivo)
    //No valido extension pq puede ser que la extension este mal y sin embargo el archivo sea BMP
    if(!bmp_validar_cabecera(&imagen->cabecera)){
        fclose(arc_imagen);
        return BMP_INVALIDO;
    }

    bmp_imprimir_info(imagen);

    int alto = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;

    int estadoError = matriz_crear(&imagen->pixeles,
                               alto,
                               ancho,
                               sizeof(tPixelBMP));

    if(estadoError != EXITO){
        fclose(arc_imagen);
        bmp_destruir_imagen(imagen);
        return ERROR_MEM;
    }

    tPixelBMP unidadPixel;
    int bytes_filas_sinPadding = ancho * (sizeof(tPixelBMP));
    int padding = (4-(bytes_filas_sinPadding % 4))% 4;
    int filaMatriz;

    fseek(arc_imagen, imagen->cabecera.archivo.posPixeles, SEEK_SET);

    for(int i = 0; i < alto; i++){ //admito imagenes "bottom-up" (de abajo hacia arriba), caso contrario validado en "bmp_validar_cabecera"

        filaMatriz = alto - 1 - i;
        for(int j = 0; j < ancho; j++){

            fread(&unidadPixel.azul, sizeof(unsigned char), 1, arc_imagen);
            fread(&unidadPixel.verde, sizeof(unsigned char), 1, arc_imagen);
            fread(&unidadPixel.rojo, sizeof(unsigned char), 1, arc_imagen);

            estadoError = matriz_set(imagen->pixeles,
                                     filaMatriz,
                                     j,
                                     &unidadPixel);


            if(estadoError != EXITO){
                bmp_destruir_imagen(imagen);
                fclose(arc_imagen);
                return ERROR_MEM;
            }//cierre if
        }//cierre for ancho
        fseek(arc_imagen, padding, SEEK_CUR); //salto el padding (que serian los pixeles de relleno (matriz borde multiplo de 4)

    }//cierre FOR filas

    fclose(arc_imagen);

    return EXITO;
}
