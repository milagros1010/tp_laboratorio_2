#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "TP2.h"
#define TAM 3
#define EVACIO 0
#define EOCUPADO 1


int main()
{


    eEmployee lista[TAM];

    int opcion;

    int idA=1;

    inicializarEmpleados(lista,TAM);


    do
    {
        system("cls");
        printf("ABM");
        printf("\n 1.Alta");
        printf("\n 2.Baja");
        printf("\n 3.Modificar empleado");
        printf("\n 4.Informar");
        printf("\n 5.Salir");
        printf("\n Seleccionar opcion\n");
        scanf("%d",&opcion);


        switch(opcion)
        {

        case 1:

            printf("Alta empleados");
            cargarDatos(lista,TAM,idA);
            idA++;
            system("pause");
            break;

        case 2:
            printf("Baja empleados");
            bajaEmpleado(lista,TAM);
            system("pause");
            break;

        case 3:
            printf("Modificar empleado");
            modificarEmpleado(lista,TAM);
            system("pause");
            break;

        case 4:
            printf("Informar");
            ordenarEmpleados(lista,TAM);
            system("pause");
            break;

        case 5:
            printf("Listar empleados");
            system("pause");
            break;


        }


    }
    while(opcion!=5);

    return 0;

}
