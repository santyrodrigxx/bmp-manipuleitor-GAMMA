#include "funciones_grupo.h"
#include "filtros.h"
#include "bmp.h"

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

    t_Datos datos;
    datos.cant_filtros=0;
    datos.cant_imagenes=0;
    datos.con_help=false;
    datos.con_info=false;
    datos.con_validar=false;
    datos.con_verbose=false;
    *datos.imagen1= '\0';
    *datos.imagen2= '\0';

    if(leer_arg(argc,argv,filtros,utilidades,&datos)==1)
    {
        return ERROR_ARGUMENTOS;
    }

    for(int j=0;j<datos.cant_filtros;j++)
    {
        printf("\n%s", (datos.filtros_pedidos+j)->nombre);
        printf("\n%d", (datos.filtros_pedidos+j)->parametro);
    }

    printf("\nIMAGENES: %d", datos.cant_imagenes);
    printf("\nFILTROS: %d", datos.cant_filtros); // DEBUG

    tImagenBMP imagen1;
    tImagenBMP imagen2;
    int estado;

    estado=bmp_leer_imagen(datos.imagen1, &imagen1);
    if(estado!=EXITO)
    {
        printf("Error al cargar la primer imagen");
        return estado;
    }

    if(datos.cant_imagenes==2)
    {
        estado=bmp_leer_imagen(datos.imagen2, &imagen2);
        if(estado!=EXITO)
        {
            printf("Error al cargar la segunda imagen");
            bmp_destruir_imagen(&imagen1);
            return estado;
        }
    }

    printf("\n\nAPLICADO DE FILTROS ----\n");

    int codError = bucle_filtros(datos,&imagen1);
    if(codError != EXITO){//por el momento lo pongo asi, dps me fijo bien
        return codError;
    }

    return EXITO;
}

int leer_arg(int argc, char* argv[], const char* filtros[], const char* utilidades[], t_Datos* datos)
{
    int i, parametro_extraido=0;
    bool dos_imagenes=false;
    char copia[40];

    for(i=1; i<argc;i++)
    {
        parametro_extraido=0; //se reinicia la variable en cada vuelta para limpiar basura
        if( es_flag (*(argv+i)) ) //empieza por "--"?
        {
            if(funcion_valida(*(argv+i),filtros,&parametro_extraido) ) //es filtro
            {
                //sacamos el numero para guardarlo
                strcpy(copia,*(argv+i));
                char* pos_igual = strchr(copia,'=');
                if(pos_igual!=NULL) //si hay algo despues del nombre del filtro(numero)
                {
                    *pos_igual='\0';
                }
                if(!filtro_ya_guardado(datos,copia)) //si el filtro no esta guardado
                {
                    //guardo en el vector de filtros respetando orden de aparicion
                    strcpy( (datos->filtros_pedidos + datos->cant_filtros)->nombre, copia ); //guardo el nombre
                    (datos->filtros_pedidos + datos->cant_filtros)->parametro = parametro_extraido; //guardo el parametro
                    datos->cant_filtros++; //aumento el contador

                    printf("El argumento numero %d: %s es un filtro valido, guardado\n",i, *(argv+i));

                    if(necesita_dos_imagenes(copia)) //se fija si son necesarias dos imagenes
                    {
                        dos_imagenes=true;
                    }

                }
                else{
                    printf("El argumento numero %d: %s es un filtro duplicado, ignorado\n",i, *(argv+i));
                }


            }
            else if(utilidad_valida(*(argv+i),utilidades)) //es utilidad
            {
                if (strcmp(*(argv+i), "--verbose") == 0) datos->con_verbose = true;
                if (strcmp(*(argv+i), "--help") == 0)    datos->con_help = true;
                if (strcmp(*(argv+i), "--info") == 0)    datos->con_info = true;
                if (strcmp(*(argv+i), "--validar") == 0) datos->con_validar = true;
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
                if(datos->cant_imagenes<2) //si todavia no hay dos imagenes
                {
                    printf("El argumento numero %d: %s es una imagen\n",i,*(argv+i));
                    if(datos->cant_imagenes==0)
                    {
                        strcpy(datos->imagen1,*(argv+i));
                    }
                    if(datos->cant_imagenes==1)
                    {
                        strcpy(datos->imagen2,*(argv+i));
                    }
                    datos->cant_imagenes++;
                }
                else
                {
                    printf("Cantidad maxima de imagenes excedida");
                    return ERROR_ARGUMENTOS;
                }
            }
            else
            {
                printf("El argumento numero %d: %s es INVALIDO\n",i,*(argv+i));
                //return ERROR_ARGUMENTOS;
            }
        }

    }

    if(datos->cant_filtros>0)
    {
        if(dos_imagenes && datos->cant_imagenes!=2)
        {
            printf("Error de argumentos, se necesitan dos imagenes");
            return ERROR_ARGUMENTOS;
        }
    }

    if(datos->cant_imagenes==0)
    {
        printf("Error de argumentos, no se ingresaron imagenes");
        return ERROR_ARGUMENTOS;
    }


    return EXITO;
}

bool es_flag(const char* argumento) //revisa si empieza por "--"
{
    if(argumento==NULL || strlen(argumento)<2)
    {
        return false;
    }
    return( *(argumento) == '-' && *(argumento+1) == '-') ;
}

bool funcion_valida(const char* argumento, const char* filtros[], int* parametro) //llega un argumento que ya cumple con la flag del "--"
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
        *parametro=num;
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

    if(encontrado && i<= 3 && final_filtro!=NULL)
    {
        return false;
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

bool filtro_ya_guardado(t_Datos* datos, const char* nombre) //si un filtro ya fue guardado ret true, sino false
{
    for(int i=0; i<datos->cant_filtros; i++)
    {
        if(strcmp( (datos->filtros_pedidos+i)->nombre, nombre) ==0 ) //Si ya esta registrado
        {
            return true;
        }
    }

    return false;
}

bool necesita_dos_imagenes (const char* nombre) //Se fija si necesita dos imagenes
{
    return (strcmp(nombre, "--concatenar-horizontal") == 0 || strcmp(nombre, "--concatenar-vertical") == 0);
}
