#include <stdio.h>
#include <stdlib.h> //para incluir el malloc
#include <string.h> //para incluir strlen, strcpy y strstr
#include <stdbool.h> //para incluir un dato booleano

//#define empleados 5;
#include "Lista.h"

int main ()
{
    Nodo * TareasPendientes = crearLista();
    Nodo * TareasRealizadas= crearLista();
    int eleccion;
    int cantidadTareas = 0;

    do {
        printf("\n\n-----MENU-----");
        printf("\n1. Ingresar una tarea");
        printf("\n2. Marcar una tarea como realizada");
        printf("\n3. Mostrar todas las tareas");
        printf("\n4. Buscar tarea");
        printf("\n5. Salir");

        printf("\n\nIngrese la operación que desee realizar: ");
        scanf("%d", &eleccion);
        getchar();

        switch (eleccion)
        {
        case 1:
            do {
                ingresarTarea(&TareasPendientes, &cantidadTareas);
            } while (preguntaParaRepetir("Desea ingresar una nueva tarea?"));
            break;
        
        case 2:
            do {
                marcarComoRealizada(&TareasPendientes, &TareasRealizadas);
            } while (preguntaParaRepetir("Desea marcar otra tarea como realizada?"));
            break;

        case 3:
            mostrarTodasLasTareas(TareasPendientes,TareasRealizadas);
            break;

        case 4:
            do {
                buscarTarea(TareasPendientes, TareasRealizadas);
            } while (preguntaParaRepetir("Desea buscar otra tarea?"));
            break;

        default:
            break;
        }
    } while (eleccion != 5);

    liberarMemoria(TareasPendientes);
    liberarMemoria(TareasRealizadas);
    return 0;
}