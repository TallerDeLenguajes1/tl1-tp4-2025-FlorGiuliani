typedef struct {
    int TareaID; //Numérico autoincremental comenzando en 1000
    char *Descripcion;
    int Duracion; // entre 10 – 100
} Tarea;

typedef Tarea item;

struct Nodo {
    item T;
    struct Nodo * siguiente;
};

typedef struct Nodo * Tnodo;


Tnodo crearLista() {
    return NULL;
}

Tnodo crearTarea(Tnodo L, int cantidadTareas) {
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

    {
        printf("Ingrese la duracion de la tarea: ");
        scanf("%d", &duracion);
        nuevoNodo->T.Duracion = duracion;
    } while (nuevoNodo->T.Duracion < 10 || nuevoNodo->T.Duracion > 100);

    nuevoNodo->siguiente = L;
    L = nuevoNodo;

    return L;
}

void mostrar(Tnodo L) {
    Tnodo aux = L;
    while (aux) {
        printf("\nTarea %d: ", aux->T.TareaID);
        puts(aux->T.Descripcion);
        printf("\nDuración: %d horas\n", aux->T.Duracion);
        aux = aux->siguiente;
    }
}

//Tnodo * Aux = *Start;