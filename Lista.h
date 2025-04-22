typedef struct {
    int TareaID; //Numérico autoincremental comenzando en 1000
    char *Descripcion;
    int Duracion; // entre 10 – 100
} Tarea;

//typedef Tarea item;

struct Nodo {
    //item T;
    Tarea T;
    struct Nodo * siguiente;
};

typedef struct Nodo * Tnodo;


Tnodo crearLista() {
    return NULL;
}

/*Tnodo insertar(Tnodo L, Tarea x) {
    Tnodo nuevoNodo;
    nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = x;
    nuevoNodo->siguiente = L;
    L = nuevoNodo;
    return L;
}*/

void crearTarea(Tnodo * L, int cantidadTareas) { //doble puntero
    Tnodo nuevoNodo;
    nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    
    char * Buff;
    int duracion;
    
    nuevoNodo->T.TareaID = 1000 + cantidadTareas;

    Buff = (char *)malloc(100*sizeof(char));
    printf("\nIngrese una descripcion de la tarea: ");
    gets(Buff);
    nuevoNodo->T.Descripcion = (char *)malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(nuevoNodo->T.Descripcion,Buff);
    free(Buff);

    do {
        printf("Ingrese la duracion de la tarea: ");
        scanf("%d", &duracion);
        nuevoNodo->T.Duracion = duracion;
    } while (nuevoNodo->T.Duracion < 10 || nuevoNodo->T.Duracion > 100);

    nuevoNodo->siguiente = *L;
    *L = nuevoNodo;
}

void mostrar(Tnodo L) {
    Tnodo aux = L;
    if (L == NULL) {
        printf("\n--No hay tareas--");
    } else {
        while (aux) {
        printf("\nTarea %d: ", aux->T.TareaID);
        puts(aux->T.Descripcion);
        printf("Duracion: %d horas\n", aux->T.Duracion);
        aux = aux->siguiente;
        }
    }
}

void marcarComoRealizada(struct Nodo ** ListaPendientes, struct Nodo ** ListaRealizadas, int ID) {
    Tnodo aux = *ListaPendientes;
    Tnodo auxAnterior;

    while (aux && aux->T.TareaID != ID) {
        auxAnterior = aux;
        aux = aux->siguiente;
    }

    if (aux != NULL) {
        if (!auxAnterior) {
            auxAnterior = *ListaPendientes;
        }
        auxAnterior->siguiente = aux->siguiente;
        aux->siguiente = *ListaRealizadas;
        *ListaRealizadas = aux;
    }
}

//Tnodo * Aux = *Start;