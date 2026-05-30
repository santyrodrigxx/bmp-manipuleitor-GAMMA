#include "matriz_tda.h"
#include "funciones_grupo.h"


int matriz_crear(tda_matriz *matriz, unsigned int filas, unsigned int columnas, size_t tamElemento)
{
    int estado = EXITO;
    unsigned int i = 0;

    if (matriz == NULL || filas == 0 || columnas == 0 || tamElemento == 0)
    {
        estado = ERROR_ARGUMENTOS;
    }
    else
    {
        matriz->filas = filas;
        matriz->columnas = columnas;
        matriz->tamElemento = tamElemento;

        // Reservamos memoria para el vector de punteros a filas
        matriz->datos = (void **)malloc(filas * sizeof(void *));

        if (matriz->datos == NULL)
        {
            estado = ERROR_MEMORIA;
        }
        else
        {
            // Reservamos memoria para cada fila
            while (i < filas && estado == EXITO)
            {
                matriz->datos[i] = malloc(columnas * tamElemento);

                if (matriz->datos[i] == NULL)
                {
                    estado = ERROR_MEMORIA;
                }
                else
                {
                    i++;
                }
            }

            // Si hubo error destruimos todo
            if (estado == ERROR_MEMORIA)
            {
                matriz->filas = i;
                matriz_destruir(matriz);
            }
        }
    }

    return estado;
}
void matriz_destruir(tda_matriz *matriz)
{
    unsigned int i = 0;

    if (matriz != NULL && matriz->datos != NULL)
        {
        while (i < matriz->filas)
        {
            free(matriz->datos[i]);
            i++;
        }
        free(matriz->datos);

        matriz->datos = NULL;
        matriz->filas = 0;
        matriz->columnas = 0;
        matriz->tamElemento = 0;
    }
}

int matriz_set(tda_matriz *matriz, unsigned int fila, unsigned int columna, const void *elemento)
{
    int estado = ERROR_ARGUMENTOS;
    void *destino = NULL;

    if (matriz != NULL && fila < matriz->filas && columna < matriz->columnas && elemento != NULL)
    {
        //guardamos dato
        destino = (char *)matriz->datos[fila] + (columna * matriz->tamElemento);
        memcpy(destino, elemento, matriz->tamElemento);
        estado = EXITO;
    }

    return estado;
}

int matriz_get(const tda_matriz *matriz, unsigned int fila, unsigned int columna, void *elemento)
{
    int estado = ERROR_ARGUMENTOS;
    const void *origen = NULL;

    if (matriz != NULL && fila < matriz->filas && columna < matriz->columnas && elemento != NULL)
    {

        origen = (const char *)matriz->datos[fila] + (columna * matriz->tamElemento);
        memcpy(elemento, origen, matriz->tamElemento);
        estado = EXITO;
    }

    return estado;
}
void *matriz_obtener_ptr(tda_matriz *matriz, unsigned int fila, unsigned int columna)
{
    void *ptr = NULL;

    if (matriz != NULL && fila < matriz->filas && columna < matriz->columnas)
    {
        ptr = (char *)matriz->datos[fila] + (columna * matriz->tamElemento);
    }

    return ptr;
}

const void *matriz_obtener_ptr_const(const tda_matriz *matriz, unsigned int fila, unsigned int columna)
{
    const void *ptr = NULL;

    if (matriz != NULL && fila < matriz->filas && columna < matriz->columnas)
    {
        ptr = (const char *)matriz->datos[fila] + (columna * matriz->tamElemento);
    }

    return ptr;
}

unsigned int matriz_filas(const tda_matriz *matriz)
{
    unsigned int filas = 0;

    if (matriz != NULL)
    {
        filas = matriz->filas;
    }

    return filas;
}

unsigned int matriz_columnas(const tda_matriz *matriz)
{
    unsigned int columnas = 0;

    if (matriz != NULL)
    {
        columnas = matriz->columnas;
    }

    return columnas;
}

size_t matriz_tam_elemento(const tda_matriz *matriz)
{
    size_t tam = 0;

    if (matriz != NULL)
    {
        tam = matriz->tamElemento;
    }

    return tam;
}



