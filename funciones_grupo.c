#include "funciones_grupo.h"

// Apellido: Avalos Irrazabal, Joel Antonio
// DNI: 94275736
// Entrega: Si

// Apellido: Rodriguez, Santiago Rodriguez
// DNI: 47131227
// Entrega: Si

// Apellido: Gahona, Antonella
// DNI: 45928557
// Entrega: Si

////////////////////////////////////////

int procesar_imagen(int argc, char *argv[])
{
    const char* filtros[] = {"--negativo","--escala-de-grises",
                    "--espejar-horizontal","--espejar-vertical",
                    "--aumentar-contraste","--reducir-contraste",
                    "--tonalidad-azul","--tonalidad-verde",
                    "--tonalidad-roja","--recortar",
                    "--achicar","--rotar-derecha",
                    "--rotar-izquierda","--concatenar-horizontal",
                    "--concatenar-vertical","--comodin"};

    const char* utilidades[] = {"--info", "--validar",
                       "--verbose","--help"};

    leer_arg(argc,argv,filtros,utilidades);

    return EXITO;
}

int leer_arg(int argc, char* argv[], const char* filtros[], const char* utilidades[])
{
    int i, cant_imagenes=0;

    for(i=1; i<argc;i++)
    {
        if( es_flag (*(argv+i)) ) //empieza por "--"?
        {
            if(funcion_valida(*(argv+i),filtros) ) //es filtro
            {
                printf("El argumento numero %d: %s es un filtro valido\n",i, *(argv+i));
                //guardar_funcion;
            }
            else if(utilidad_valida(*(argv+i),utilidades)) //es utilidad
            {
                printf("El argumento numero %d: %s es una utilidad valida\n",i, *(argv+i));
                //usar_utilidad;
            }
            else
            {
                printf("El argumento numero %d: %s es INVALIDO\n",i,*(argv+i));
            }
        }

        else //es el nombre del bmp??
        {
            if(es_bmp(*(argv+i))) //termina en .bmp?
            {
                if(cant_imagenes<2)
                {
                    printf("El argumento numero %d: %s es una imagen\n",i,*(argv+i));
                    cant_imagenes++;
                }
                else
                {
                    printf("Cantidad maxima de imagenes excedida");
                }
            }
            else
            {
                printf("El argumento numero %d: %s es INVALIDO\n",i,*(argv+i));
            }
        }

    }


    return EXITO;
}

bool es_flag(const char* argumento)
{
    if(argumento==NULL || strlen(argumento)<3)
    {
        return false;
    }
    return( *(argumento) == '-' && *(argumento+1) == '-') ;
}

bool funcion_valida(const char* argumento, const char* filtros[]) //llega un argumento que ya cumple con la flag del "--"
{

    char copia_argumento[40];
    strcpy(copia_argumento,argumento); //copio el argumento

    char* final_filtro = strchr(copia_argumento,'='); //cuando encuentra un = en el argumento (--contraste=10)
    int i=0, num;
    bool encontrado = false;

    if(final_filtro!=NULL) //si al final del filtro hay un igual
    {
        *final_filtro= '\0'; //pongo un \0 para dividir la palabra entre el filtro y la cantidad

        num=atoi(final_filtro+1);
        if( num<1 || num>100) //si el filtro tiene un numero, me fijo que sea valido
        {
            return false;
        }
    }

    while(i<16 && !encontrado) //busco en el vector de filtros si es uno valido
    {

        if(strcmp(copia_argumento,*(filtros+i))==0)
        {

            encontrado=true;
        }
        else
        {
            i++;
        }
    }

    return encontrado;
}

bool utilidad_valida(const char* argumento, const char* utilidades[])
{
    bool encontrado=false;
    int i=0;

    while(!encontrado && i<4)
    {
        if(strcmp(argumento,*(utilidades+i))==0) //busco en el vector de utilidades si es valida
        {
            encontrado=true;
        }
        else
        {
            i++;
        }
    }

    return encontrado;
}

int es_bmp (const char* argumento)
{
    char* extension = strrchr(argumento,'.'); //busco la ultima aparicion de un punto para verificar que sea un bmp

    if(extension!=NULL && strcmp(extension,".bmp")==0)
    {
        return true;
    }
    return false;
}