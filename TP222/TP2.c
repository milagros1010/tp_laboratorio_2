#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "TP2.h"
#define TAM 3
#define EVACIO 0
#define EOCUPADO 1

/** \brief inicializa todo el array 1.
 *
 * \param cantidad de datos .
 * \param estructura de lista.
 * \return no retorna valor.
 *
 */

void inicializarEmpleados(eEmployee vec[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {

        vec[i].isEmpty=EVACIO;

    }


}

/** \brief busca indice vacio donde cargar los datos.
 *
 * \param el tam de la estrutura.
 * \param la estrutura lista.
 * \return el indice que busca esta vacio.
 *
 */

int buscarEspacioLibre(eEmployee vec[],int tam)
{
    int i;
    int index;
    for(i=0; i<tam; i++)
    {

        index=-1;

        if(vec[i].isEmpty==EVACIO)
        {

            index=i;
            break;

        }

    }
    return index;


}



/** \brief busca el indice que guarda un empleado por el id.
 *
 * \param tam de la estructura.
 * \param la estructura lista.
 * \param id de los empledos.
 * \return el indice del id del empleado.
 *
 */

int buscarEmpleado(eEmployee vec[],int tam,int idBuscar)
{
    int i;
    int index;

    index=-1;
    for(i=0; i<tam; i++)
    {

        if(vec[i].id==idBuscar && vec[i].isEmpty == EOCUPADO)
        {

            index = i;
            break;
        }

    }


    return index;

}

/** \brief alta de empleados.Pide los datos.
 *
 * \param recibe el id para guardar el empleado.
 *
 * \return el empleado subido en ese id.
 *
 */

eEmployee altaEmpleado(int idA)
{
    eEmployee emp;

    char nameAux[51];
    char lastNameAux[51];
    char salaryAux[21];
    char sectorAux[21];
    float salaryD;
    int sectorD;

    printf("ID Empleado: %d \n",idA);

    while(!getStringLetras("ingrese nombre: ",nameAux));

    while(!getStringLetras("ingrese apellido: ",lastNameAux));

    while(!getStringNumeros("ingrese sector: ",sectorAux));

    sectorD = atoi(sectorAux);

    while(!getStringNumeros("ingrese salario: ",salaryAux));

    salaryD = atof(salaryAux);

    while(salaryD <= 0 )

    {
        printf("\n El importe debe ser mayor a 0 \n");
        while(!getStringNumeros("\nIngrese nuevo salario:  ",salaryAux));
        if (salaryD<=0)
        {
            salaryD=atof(salaryAux);
            break;
        }
    }

    strcpy(emp.name,nameAux) ;
    strcpy(emp.lastName,lastNameAux);
    emp.sector=sectorD;
    emp.salary=salaryD;

    return emp;


}



//    sectorAux = elegirSector(sectores,5);



/** \brief alta de un empleado.
 *
 * \param la estructura empleados.
 * \param tam de la estructura.
 * \param id de empleados.
 * \return no tiene retorno.
 *
 */

void cargarDatos(eEmployee vec[],int tam,int idA)
{

    int indice;

    system("cls");
    printf("Alta De Empleados \n\n");

    indice = buscarEspacioLibre(vec, tam);

    if (indice == -1 )
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        vec[indice] = altaEmpleado(idA);
        vec[indice].id= idA;
        vec[indice].isEmpty=EOCUPADO;
        printf("\n\nEmpleado dado de alta.\n\n");
        //system("\n\npause");


    }

}

/** \brief da de baja un empleado pidiendo el numero de id.
 *
 * \param estructura lista.
 * \param tam de empleado.
 * \return no tiene retorno.
 *
 */

void bajaEmpleado(eEmployee vec[],int tam)
{

    char idBorrar[10];
    int idBorrarD;
    int todoOk;

    while(!getStringNumeros("\n\ningrese id a borrar ",idBorrar));
    idBorrarD = atoi(idBorrar);
    //index = buscarEmpleado(vec,tam,idBorrar);
    todoOk = borrarEmpleado(vec,tam,idBorrarD);

    if(todoOk==1)
    {
        printf("\n\nBorrado con exito\n\n");

    }
    else
    {
        printf("\n\nError, no pudo ser borrado,legajo inexistente\n\n");

    }



}

/** \brief recibe el numero de id a borrar.
 *
 * \param estructura lista.
 * \param tam de empleado.
 * \return retorna flag.
 *
 */

int borrarEmpleado(eEmployee vec[],int tam,int idBorrar)
{
    int i;
    int flag = -1;
    for(i=0; i<tam; i++)
    {

        if(vec[i].id == idBorrar && vec[i].isEmpty == EOCUPADO)
        {

            vec[i].isEmpty = EVACIO;
            flag = 1;
            break;
        }
    }
    return flag;

}

/** \brief modifica los datos de un empleado.
 *
  * \param la estructura lista.
 * \param tam de la estructura.
 * \return no tiene retorno.
 *
 */

void modificarEmpleado(eEmployee vec[],int tam)
{
    int idModificar;
    int opcionM;
    char nameAux[51];
    char lastNameAux[51];
    char sectorAux[12];
    char salaryAux[12];
    int sectorD;
    float salaryD;
    int indice;

    printf(" \n ingrese  id del empleado que desea modificar: ");
    scanf("%d",&idModificar);

    indice = buscarEmpleado(vec,tam,idModificar);



    if(indice==-2)
    {
        printf("El id ingresado no existe");
    }
    else
    {

        printf("\nID \t\tNOMBRE \t\tAPELLIDO  \tSALARIO \tSECTOR\n ");
        mostrarEmpleado(vec,indice);


        do
        {


            printf("\nMENU MODIFICACION\n");
            printf("\n1.Modificar nombre");
            printf("\n2.Modificar apellido");
            printf("\n3.Modificar salario");
            printf("\n4.Modificar sector");
            printf("\n5.Salir");
            printf("\nIngrese opcion: ");
            scanf("%d",&opcionM);

            switch(opcionM)
            {

            case 1:
                while(!getStringLetras("ingrese nuevo nombre",nameAux));
                strcpy(vec[indice].name,nameAux);
                printf("\nCambiado");
                break;

            case 2:
                while(!getStringLetras("ingrese nuevo apellido",lastNameAux));
                strcpy(vec[indice].lastName,lastNameAux);
                printf("\nCambiado");
                break;

            case 3:
                while(!getStringNumeros("ingrese salario",salaryAux));
                salaryD = atof(salaryAux);
                while(salaryD <= 0 )

                {
                    printf("\n El importe debe ser mayor a 0 \n");
                    while(!getStringNumeros("\nIngrese nuevo salario:  ",salaryAux));
                    if (salaryD<=0)
                    {
                        salaryD=atof(salaryAux);
                        break;
                    }
                }
                vec[indice].salary=salaryD;

                printf("\nCambiado");
                break;

            case 4:
                while(!getStringNumeros("ingrese sector",sectorAux));
                sectorD = atoi(sectorAux);

                vec[indice].sector=sectorD;

                printf("\nCambiado");
                break;
            }

        }
        while(opcionM!=5);


    }





}
/**
/ * * \ brief para mostrar todos los empleados de la estrutura.
 *
 * \ param cantidad de datos del sistema.
 * \ param la estrutura lista.
 * \ return sin valor de retorno.
 *
 * /
**/
void mostrarEmpleado(eEmployee vec[],int indice)
{



    printf("%d\t\t\%s\t\t\%s\t\t\%2.0f\t\t\%d\t\t\n",vec[indice].id,vec[indice].name,vec[indice].lastName,vec[indice].salary,vec[indice].sector);



}

/** \brief realiza informe de datos de ordenamiento y suma de sueldos.
 *
 * \param la estructura lista.
 * \param el tam de la estructura.
 * \return no tiene retorno.
 *
 */

void ordenarEmpleados(eEmployee vec[], int tam)
{

    int opcionO;
    int opcionAyS;



    system("cls");
    printf("\n Informes Empleados\n");
    printf("1.Ordenados alfabeticamente por Apellido y Sector.\n");
    printf("2.Total y promedio de los salarios y cuantos empleados superan el salario promedio.\n");
    printf("\nIngrese opcion :  ");
    scanf("%d", &opcionO);

    switch(opcionO)
    {
    case 1:

        system("cls");
        printf("\n Informes Empleados \n");
        printf("\n1.Ordenar por apellido.");
        printf("\n2.Ordenar por sector.");
        printf("\n\nIngrese una opcion:  ");
        scanf("%d", &opcionAyS);
        {
            switch (opcionAyS)
            {
            case 1:
                ordenarPorApellido(vec, tam);
                break;
            case 2:
                ordenarPorSector(vec,tam);
                system("pause");
                break;
            }

        }
        break;
    case 2:
        salariosEmpleados(vec, tam);
        break;
    }


}

/** \brief ordena por sector y si son iguales los ordena por apellido.
 *
 * \param estructura lista.
 * \param tam de la estructura.
 * \return no tiene retorno.
 *
 */

void ordenarPorSector(eEmployee vec[], int tam )

{
    eEmployee empAux;
    int indice;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( (vec[j].sector < vec[i].sector) && vec[j].isEmpty==EOCUPADO && vec[i].isEmpty==EOCUPADO)
            {


                empAux=vec[i];
                vec[i]=vec[j];
                vec[j]=empAux;
            }
            else if ((vec[j].sector == vec[i].sector) && vec[i].isEmpty==EOCUPADO && vec[j].isEmpty==EOCUPADO)
            {
                if (strcmp(vec[j].lastName,vec[i].lastName)<0)
                {
                    empAux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=empAux;
                }
            }
        }
    }

    system("cls");
    printf("\n\n El orden de empleados por sector fue mostrado.\n");
    printf("\nID \t\tNOMBRE \t\tAPELLIDO  \tSALARIO \tSECTOR\n ");
    for (int i=0; i<tam ; i++)
    {

        if( vec[i].isEmpty ==EOCUPADO)
        {
            indice=i;
            mostrarEmpleado(vec,indice);
        }

    }
}

/** \brief realiza la suma de salarios y promedio.
 *
 * \param la estructura lista.
 * \param el tam de la estructura.
 * \return no tiene retorno.
 *
 */

void salariosEmpleados (eEmployee vec[], int tam)
{


    float totalSalario=0;
    int totalEmpleados=0;
    float promedioSalario=0;
    int contadorSalarioMayorMedia=0;

    for (int i=0; i<tam ; i++)
    {
        if (vec[i].isEmpty==EOCUPADO)
        {
            totalSalario= vec[i].salary + totalSalario;
            totalEmpleados++;

        }

    }

    promedioSalario= totalSalario/totalEmpleados;


    for (int i=0; i<tam ; i++)
    {
        if (vec[i].salary >= promedioSalario  && vec[i].isEmpty== EOCUPADO)

        {
            contadorSalarioMayorMedia++;
        }
    }

    system("cls\n");
    printf("\n - El total de salarios es : %.2f\n", totalSalario );
    printf("\n - EL promedios de salario es de :  %.2f\n", promedioSalario);
    printf("\n - Empleados que superan o igualan el salario promedio : %d\n\n", contadorSalarioMayorMedia);

}





/** \brief ordena de forma ascendete los apellido
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
**/
void ordenarPorApellido(eEmployee vec [], int tam )
{
    eEmployee empAux;
    int indice;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( strcmp(vec[j].lastName,vec[i].lastName )<0 && vec[j].isEmpty==EOCUPADO && vec[i].isEmpty==EOCUPADO)
            {


                empAux=vec[i];
                vec[i]=vec[j];
                vec[j]=empAux;
            }
            else if (strcmp(vec[j].lastName,vec[i].lastName)== 0 && vec[i].isEmpty==EOCUPADO && vec[j].isEmpty==EOCUPADO)
            {
                if (strcmp(vec[j].name,vec[i].name)>0)
                {
                    empAux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=empAux;
                }
            }
        }
    }

    system("cls");
    printf("\n\n El orden de empleados por apellido fue mostrado.\n\n");
    printf("\nID \t\tNOMBRE \t\tAPELLIDO  \tSALARIO \tSECTOR\n ");
    for (int i=0; i<tam ; i++)
    {

        if( vec[i].isEmpty ==EOCUPADO)
        {
            indice = i;
            mostrarEmpleado(vec,indice);
        }

    }

}

/**
 * \brief Solicita un número al usuario y devuelve el resultado.
 * \param mensaje Es el mensaje a ser mostrado.
 * \return El número ingresado por el usuario.
 *
 */

float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    scanf("%f",&aux);
    return aux;
}
/**
 * \brief Solicita un número al usuario y devuelve el resultado.
 * \param mensaje Es el mensaje a ser mostrado.
 * \return El número ingresado por el usuario.
 *
 */

int getInt(char msj[] )
{
    int resultado;
    printf("%s",msj);
    scanf("%d",&resultado);
    return resultado;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado.
 * \param mensaje Es el mensaje a ser mostrado.
 * \return El caracter ingresado por el usuario.
 *
 */

char getChar(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

/**
 * \brief Verifica si el valor recibido es numérico.
 * \param str Array con la cadena a ser analizada.
 * \return 1 si es númerico y 0 si no lo es.
 *
 */

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0' || str[i]!= NULL )
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras.
 * \param str Array con la cadena a ser analizada.
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es.
 *
 */
int soloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else
    {
        while(str[i] != '\0'  )
        {
            if(  (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargará el texto ingresado.
 * \return no tiene retorno.
 */

void getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param input Array donde se cargará el texto ingresado.
 * \return 1 si el texto contiene solo letras.
 */

int getStringLetras(char msj[],char input[])
{
    char aux[256];
    getString(msj,aux);

    if (msj != NULL)
    {
        if(soloLetras(aux))
        {
            strcpy(input,aux);
            return 1;
        }
        else
        {
            printf("\nError!, ingrese solo letras.\n");
        }
    }



    return 0 ;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve.
 * \param mensaje es el mensaje a ser mostrado.
 * \param input Array donde se cargará el texto ingresado.
 * \return 1 si el texto contiene solo números.
 */

int getStringNumeros(char mensaje[],char input[])
{

    char aux[256];
    getString(mensaje,aux);


    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    else
    {
        printf("Error, ingrese solo numeros.");
    }

    return 0;
}


