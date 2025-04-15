#include <stdio.h>
#include <stdlib.h> //para incluir el malloc
#include <string.h> //para incluir strlen y strcpy
#include "Lista.h"
#define empleados 5;

int main ()
{
    Tnodo TareasPendientes;
    Tnodo TareasRealizadas;
    TareasPendientes = crearLista();
    TareasRealizadas = crearLista();

    int respuesta;
    int cantidad = 0;

    {
        printf("-----MENU-----");
        printf("\n1. Ingresar una tarea");
        printf("\n2. Mostrar las tareas pendientes");
        printf("\n3. Mostrar las tareas realizadas");
        printf("\n4. Salir");

        printf("\n\nIngrese la opcion que desee: ");
        scanf("%d", &respuesta);
        getchar();

        switch (respuesta)
        {
        case 1:
            TareasPendientes = crearTarea(TareasPendientes, cantidad);
            cantidad++;
            break;
        
        case 2:
            mostrar(TareasPendientes);
            break;

        case 3:
            mostrar(TareasRealizadas);
            break;

        default:
            break;
        }
    } while (respuesta != 4);
    return 0;
}