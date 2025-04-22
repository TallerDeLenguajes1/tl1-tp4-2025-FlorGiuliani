#include <stdio.h>
#include <stdlib.h> //para incluir el malloc
#include <string.h> //para incluir strlen y strcpy

#define empleados 5;
#include "Lista.h"

int main ()
{
    Tnodo TareasPendientes;
    Tnodo TareasRealizadas;
    TareasPendientes = crearLista();
    TareasRealizadas = crearLista();

    int respuesta;
    int cantidadTareas = 0;

    do {
        printf("\n\n-----MENU-----");
        printf("\n1. Ingresar una tarea");
        printf("\n2. Mostrar las tareas pendientes");
        printf("\n3. Mostrar las tareas realizadas");
        printf("\n4. Marcar una tarea como realizada");
        printf("\n5. Salir");

        printf("\n\nIngrese la opcion que desee: ");
        scanf("%d", &respuesta);
        getchar();

        switch (respuesta)
        {
        case 1:
            do {
            crearTarea(&TareasPendientes, cantidadTareas);
            cantidadTareas++;
            printf("\nDesea ingresar una nueva tarea? Si(1) No(2): ");
            scanf("%d", &respuesta);
            getchar();
            } while (respuesta == 1);
            break;
        
        case 2:
            printf("\nLista de tareas PENDIENTES:");
            mostrar(TareasPendientes);
            break;

        case 3:
            printf("\nLista de tareas REALIZADAS:");
            mostrar(TareasRealizadas);
            break;

        case 4:
            do {
                printf("Ingrese el ID de la tarea que desea marcar como REALIZADA: ");
                scanf("%d", &respuesta);
                getchar();
                marcarComoRealizada(&TareasPendientes, &TareasRealizadas, respuesta);

                printf("\nDesea marcar otra tarea como realizada? Si(1) No(2): ");
                scanf("%d", &respuesta);
                getchar();
            } while (respuesta == 1);
            break;

        default:
            break;
        }
    } while (respuesta != 5);
    return 0;
}