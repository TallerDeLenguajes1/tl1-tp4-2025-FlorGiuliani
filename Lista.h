#include <stdio.h>
#include <stdlib.h> //para incluir el malloc
#include <string.h> //para incluir strlen, strcpy y strstr
#include <stdbool.h> 

typedef struct {
    int TareaID; //Numérico autoincremental comenzando en 1000
    char *Descripcion;
    int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo{
    Tarea T;
    struct Nodo * siguiente;
} Nodo;

//typedef struct Nodo * Lista;


Nodo * crearLista() {
    return NULL;
}

Nodo * crearNodo() {
    Nodo * nuevoNodo;
    nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    return nuevoNodo;
}

Nodo * crearTarea(Nodo * nuevaTarea, int * cantidadTareas) {
    char * Buff;
    int duracion;
    nuevaTarea->T.TareaID = 1000 + *cantidadTareas;

    Buff = (char *)malloc(100*sizeof(char));
    printf("\nIngrese una descripcion de la tarea: ");
    gets(Buff);
    nuevaTarea->T.Descripcion = (char *)malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(nuevaTarea->T.Descripcion,Buff);
    free(Buff);

    do {
        printf("Ingrese la duracion de la tarea: ");
        scanf("%d", &duracion);
        nuevaTarea->T.Duracion = duracion;
    } while (nuevaTarea->T.Duracion < 10 || nuevaTarea->T.Duracion > 100);
    (*cantidadTareas)++;
    return nuevaTarea;
}

void insertarTarea(Nodo ** Lista, Nodo * Tarea) {
    Tarea->siguiente = *Lista;
    *Lista = Tarea;
}

void ingresarTarea(Nodo ** Lista, int * cantidadTareas) { 
    Nodo * nuevaTarea = crearNodo();
    crearTarea(nuevaTarea, cantidadTareas);
    insertarTarea(Lista,nuevaTarea);
}

void mostrarTarea(Nodo * Tarea) {
    printf("\nTarea %d: ", Tarea->T.TareaID);
    puts(Tarea->T.Descripcion);
    printf("Duracion: %d horas\n", Tarea->T.Duracion);
}

void mostrarLista(Nodo * Lista) {
    Nodo * aux = Lista;
    if (Lista != NULL) {
        while (aux) {
            mostrarTarea(aux);
            aux = aux->siguiente;
        }  
    } else {
        printf("\n--No hay tareas--\n");
    }
}

void mostrarTodasLasTareas(Nodo * listaPendientes, Nodo * listaRealizadas) {
    printf("\nLista de tareas PENDIENTES:\n");
    mostrarLista(listaPendientes);
    printf("\nLista de tareas REALIZADAS:\n");
    mostrarLista(listaRealizadas);
}

void marcarComoRealizada(Nodo ** listaPendientes, Nodo ** listaRealizadas) {
    Nodo * aux = *listaPendientes;
    Nodo * auxAnterior;
    int ID;

    printf("Ingrese el ID de la tarea que desea marcar como REALIZADA: ");
    scanf("%d", &ID);
    getchar();

    if (aux->T.TareaID == ID) { //si solo hay una tarea o la tarea de ese ID es la primera en la lista
        *listaPendientes = aux->siguiente;
        insertarTarea(listaRealizadas, aux);
        return;
    }

    if (aux->siguiente) { //si hay mas de una tarea o no es la primera
        while (aux && aux->T.TareaID != ID) { //avanzo en la lista
            auxAnterior = aux;
            aux = aux->siguiente;
        }
    
        if (aux) {
            auxAnterior->siguiente = aux->siguiente; //me salteo una tarea
            insertarTarea(listaRealizadas, aux);
        }
    } 
}

bool buscarTareaPorID(Nodo * Lista, int ID, char * mensaje) {
    Nodo * aux = Lista;
    while (aux) { 
        if (aux->T.TareaID == ID) {
            mostrarTarea(aux);
            puts(mensaje);
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

bool buscarTareaPorPalabraClave(Nodo * Lista, char * palabraClave, char * mensaje) {
    Nodo * aux = Lista;
    while (aux) { 
        if (strstr(aux->T.Descripcion,palabraClave)) {
            mostrarTarea(aux);
            puts(mensaje);
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

void buscarTarea(Nodo * TareasPendientes, Nodo * TareasRealizadas) {
    int eleccion;
    do {
        printf("\nDeseas buscar la tarea");
        printf("\n1. por ID");
        printf("\n2. por Palabra Clave\n");
        scanf("%d", &eleccion);
        getchar();
        switch (eleccion)
        {
        case 1:
            int id;
            printf("\nIngrese el ID de la tarea a buscar: ");
            scanf("%d", &id);
            getchar();
            if (!buscarTareaPorID(TareasPendientes, id, "Tarea Pendiente")) {
                if (!buscarTareaPorID(TareasRealizadas, id, "Tarea Realizada")) {
                    printf("\nTarea no encontrada\n");
                };
            }
            break;
    
        case 2:
            char * palabraClave;

            char * Buff;
            Buff = (char *)malloc(100*sizeof(char));
            printf("\nIngrese una palabra clave de la tarea a buscar: ");
            gets(Buff);
            palabraClave = (char *)malloc((strlen(Buff)+1)*sizeof(char));
            strcpy(palabraClave,Buff);
            free(Buff);

            if (!buscarTareaPorPalabraClave(TareasPendientes, palabraClave, "Tarea Pendiente")) {
                if (!buscarTareaPorPalabraClave(TareasRealizadas, palabraClave, "Tarea Realizada")) {
                    printf("\nTarea no encontrada\n");
                };
            }
            free(palabraClave);
            break;
    
        default:
            break;
        }
    } while (eleccion != 1 && eleccion != 2);
}

bool preguntaParaRepetir(char * mensaje)
{
    int respuesta;
    printf("\n");
    puts(mensaje);
    printf(" Si(1) No(2): ");
    scanf("%d", &respuesta);
    getchar();
    if (respuesta == 1) {
        return true;
    }
    return false;
}

void liberarMemoria(Nodo * Lista) {
    Nodo * aux = Lista;
    Nodo * auxSiguiente;

    while (aux) {
        auxSiguiente = aux->siguiente;
        if (aux->T.Descripcion) {
            free(aux->T.Descripcion);
        }
        free(aux);
        aux = auxSiguiente;
    }
}
