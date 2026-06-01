#include "filtros.h"

int bucle_filtros(t_Datos datos, tImagenBMP* imagen1, tImagenBMP* imagen2)
{
    int i;

    for(i=0;i<datos.cant_filtros;i++)
    {
        if(strcmp((datos.filtros_pedidos+i)->nombre,"--negativo")==0)
        {
            printf("Aplicando filtro 1 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro1(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--escala-de-grises")==0)
        {
            printf("Aplicando filtro 2 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro2(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--espejar-horizontal")==0)
        {
            printf("Aplicando filtro 3 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro3(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--espejar-vertical")==0)
        {
            printf("Aplicando filtro 4 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro4(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--aumentar-contraste")==0)
        {
            printf("Aplicando filtro 5 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro5(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--reducir-contraste")==0)
        {
            printf("Aplicando filtro 6 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro6(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--tonalidad-azul")==0)
        {
            printf("Aplicando filtro 7 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro7(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--tonalidad-verde")==0)
        {
            printf("Aplicando filtro 8 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro8(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--tonalidad-roja")==0)
        {
            printf("Aplicando filtro 9 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro9(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--recortar")==0)
        {
            printf("Aplicando filtro 10 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro10(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--achicar")==0)
        {
            printf("Aplicando filtro 11 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro11(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--rotar-derecha")==0)
        {
            printf("Aplicando filtro 12 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro12(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--rotar-izquierda")==0)
        {
            printf("Aplicando filtro 13 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro13(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--concatenar-horizontal")==0)
        {
            printf("Aplicando filtro 14 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro14(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--concatenar-vertical")==0)
        {
            printf("Aplicando filtro 15 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro15(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else if(strcmp((datos.filtros_pedidos+i)->nombre,"--comodin")==0)
        {
            printf("Aplicando filtro 16 con parametro %d\n", (datos.filtros_pedidos+i)->parametro);
            //aplicar_filtro16(imagen1, imagen2, (datos.filtros_pedidos+i)->parametro);
        }
        else
        {
            printf("Filtro no reconocido: %s\n", (datos.filtros_pedidos+i)->nombre);
        }
    }

    return EXITO; 
}

