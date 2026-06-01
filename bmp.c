#include "bmp.h"
#include "funciones_grupo.h"
#include "matriz_tda.h"

//...las filas de p�xeles suelen estar guardadas de abajo hacia arriba,
//pero eso afecta a la matriz de p�xeles, no al header.


int bmp_leer_imagen(const char *nombreArchivo, tImagenBMP *imagen) //hasta el .bmp??
{
    if (imagen == NULL) {
        puts("Error: imagen nula.");
        return ERROR_MEMORIA;
    }

    FILE *arc_imagen = fopen(nombreArchivo, "rb");

    if (arc_imagen == NULL) { //aca no cargue la matriz, por lo tanto no hace falta destruir nada
        puts("Error al abrir archivo imagen.");
        return ERROR_ARCHIVO;
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

    //con #pragma pack(push, 1) en el header, no hace falta validar el tamaño de la cabecera, porque se va a leer exactamente lo que ocupa la cabecera, sin bytes de relleno (padding
    //Capaz se puede simplificar la lectura de la cabecera leyendo todo el bloque de la cabecera de una sola vez, pero lo hice asi para entender mejor cada campo de la cabecera

    //VALIDACION DE CONDICIONES (compresion, profundidad, tama�o y tipo de archivo)
    //No valido extension pq puede ser que la extension este mal y sin embargo el archivo sea BMP
    if(bmp_validar_cabecera(&imagen->cabecera) != EXITO){
        fclose(arc_imagen);
        return BMP_INVALIDO;
    }

    bmp_imprimir_info(imagen, nombreArchivo);

    int alto = imagen->cabecera.info.altoImagen;
    int ancho = imagen->cabecera.info.anchoImagen;

    int estadoError = matriz_crear(&imagen->pixeles,
                               alto,
                               ancho,
                               sizeof(tPixelBMP));

    if(estadoError != EXITO){
        fclose(arc_imagen);
        //bmp_destruir_imagen(imagen); no se destruye porque no se creo la matriz, por lo tanto no se asigno memoria para la matriz, y el struct tImagenBMP se asigna en el main, por lo tanto tampoco se libera memoria del struct
        return ERROR_MEMORIA;
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

            estadoError = matriz_set(&imagen->pixeles,
                                     filaMatriz,
                                     j,
                                     &unidadPixel);


            if(estadoError != EXITO){
                bmp_destruir_imagen(imagen);
                fclose(arc_imagen);
                return ERROR_MEMORIA;

            }//cierre if
        }//cierre for ancho

        fseek(arc_imagen, padding, SEEK_CUR); //salto el padding, que serian los pixeles de relleno (matriz borde multiplo de 4)

    }//cierre FOR filas

    fclose(arc_imagen);

    return EXITO;
}


int bmp_validar_cabecera(const BMPCabecera *cabecera){

    unsigned char *dato = (unsigned char*)&cabecera->archivo.firma; //va -> pq lo llamo como puntero
    int comp = cabecera->info.compresion;
    int profundidad = cabecera->info.bitsPorPixel;

    if (dato[0] != 'B' || dato [1] != 'M'){
        puts("Error: el archivo no es un BMP válido (firma incorrecta).");
        return BMP_INVALIDO;
    }

    if (comp != 0){
        puts("Error: el archivo BMP no es válido (compresión no soportada).");
        return BMP_INVALIDO;
    }

    if (profundidad != 24){
        puts("Error: el archivo BMP no es válido (profundidad de color no soportada).");
        return BMP_INVALIDO;
    }

    return EXITO;
}


void bmp_imprimir_info(const tImagenBMP *imagen, const char *nombreArchivo)
{
    int padding = (4 - ((imagen->cabecera.info.anchoImagen * sizeof(tPixelBMP)) % 4)) % 4;

    printf("Informacion del archivo BMP:\n"
           "  Nombre:               %s\n"
           "  Tamanio del archivo:  %u bytes\n"
           "  Dimensiones:          %dx%d pixeles\n"
           "  Profundidad de color: %u bits\n"
           "  Compresion:           No comprimido\n"
           "  Offset de datos:      %u bytes\n"
           "  Tamanio de imagen:    %u bytes\n"
           "  Padding por fila:     %d bytes\n",
           nombreArchivo,
           imagen->cabecera.archivo.tamArchivo,
           imagen->cabecera.info.anchoImagen,
           imagen->cabecera.info.altoImagen,
           imagen->cabecera.info.bitsPorPixel,
           imagen->cabecera.archivo.posPixeles,
           imagen->cabecera.info.tamImagen,
           padding);
}


int bmp_escribir_imagen(const char *nombreArchivo, const tImagenBMP *imagen, modoBMP escritura)
{
    FILE *nueva_imagen = fopen(nombreArchivo, "r+b");
    if(nueva_imagen == NULL){
        puts("Error al crear el archivo de imagen.");
        return ERROR_ARCHIVO;
    }

    switch (escritura)
    {
        case CABECERA:
        {
            //CABECERA ARCHIVO
            fwrite(&imagen->cabecera.archivo.firma, sizeof(unsigned short), 1, nueva_imagen);
            fwrite(&imagen->cabecera.archivo.tamArchivo, sizeof(unsigned int), 1, nueva_imagen);
            fwrite(&imagen->cabecera.archivo.reservado1, sizeof(unsigned short), 1, nueva_imagen);
            fwrite(&imagen->cabecera.archivo.reservado2, sizeof(unsigned short), 1, nueva_imagen);
            fwrite(&imagen->cabecera.archivo.posPixeles, sizeof(unsigned int), 1, nueva_imagen);

            //CABECERA INFO
            fwrite(&imagen->cabecera.info.tamCabecera, sizeof(unsigned int), 1, nueva_imagen);
            fwrite(&imagen->cabecera.info.anchoImagen, sizeof(int), 1, nueva_imagen);
            fwrite(&imagen->cabecera.info.altoImagen, sizeof(int), 1, nueva_imagen);
            fwrite(&imagen->cabecera.info.planos, sizeof(unsigned short), 1, nueva_imagen);
            fwrite(&imagen->cabecera.info.bitsPorPixel, sizeof(unsigned short), 1,  nueva_imagen);
            fwrite(&imagen->cabecera.info.compresion, sizeof(unsigned int), 1,  nueva_imagen);
            fwrite(&imagen->cabecera.info.tamImagen, sizeof(unsigned int), 1,  nueva_imagen);
            fwrite(&imagen->cabecera.info.resolucionHorizontal, sizeof(int), 1,  nueva_imagen);
            fwrite(&imagen->cabecera.info.resolucionVertical, sizeof(int), 1,  nueva_imagen);
            fwrite(&imagen->cabecera.info.coloresUsados, sizeof(unsigned int), 1,  nueva_imagen);
            fwrite(&imagen->cabecera.info.coloresImportantes, sizeof(unsigned int), 1,  nueva_imagen);

            fclose(nueva_imagen);
            return EXITO;
            break;

        }
        case PIXELES:
        {
                    int alto  = imagen->cabecera.info.altoImagen;
            int ancho = imagen->cabecera.info.anchoImagen;
            int padding = (4 - ((ancho * sizeof(tPixelBMP)) % 4)) % 4;
            unsigned char cero = 0;

            tPixelBMP px;

            fseek(nueva_imagen, sizeof(BMPCabecera), SEEK_SET);  // salteo la cabecera

            for (int i = 0; i < alto; i++) {
                int filaMatriz = alto - 1 - i;  // bottom-up, igual que en la lectura

                for (int j = 0; j < ancho; j++) { //recorro cada pixel de la fila

                    if(matriz_get(&imagen->pixeles, filaMatriz, j, &px) != EXITO){
                        fclose(nueva_imagen);
                        return ERROR_MEMORIA;
                    }
                    fwrite(&px.azul,  sizeof(unsigned char), 1, nueva_imagen);
                    fwrite(&px.verde, sizeof(unsigned char), 1, nueva_imagen);
                    fwrite(&px.rojo,  sizeof(unsigned char), 1, nueva_imagen);
                }

                for (int p = 0; p < padding; p++) //escribo el padding, que serian los pixeles de relleno (matriz borde multiplo de 4)
                    fwrite(&cero, sizeof(unsigned char), 1, nueva_imagen);
            }//cierre FOR anidado
        
            fclose(nueva_imagen);
            return EXITO;
            break;
    
        }//cierre case pixeles
        default:
            puts("Error. Modo de escritura no válido.");
            fclose(nueva_imagen);
            return ERROR_ARGUMENTOS;

     }//cierre switch

}

void bmp_destruir_imagen(tImagenBMP *imagen){
    matriz_destruir(&imagen->pixeles);
}
