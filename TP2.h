#ifndef TP2_H_INCLUDED
#define TP2_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

eEmployee altaEmpleado(int idA);
int buscarEspacioLibre(eEmployee vec[],int tam);
int buscarEmpleado(eEmployee vec[],int tam,int idBuscar);
int getStringLetras(char msj[],char input[]);
int soloLetras(char str[]);
int getStringNumeros(char mensaje[],char input[]);
int esNumerico(char str[]);
int borrarEmpleado(eEmployee vec[],int tam,int idBorrar);
void inicializarEmpleados(eEmployee vec[],int tam);
void getString (char msj[],char input[]);
void cargarDatos(eEmployee vec[],int tam,int idA);
void bajaEmpleado(eEmployee vec[],int tam);
void mostrarEmpleado(eEmployee vec[],int indice);
void ordenarEmpleados(eEmployee vec[], int tam);
void ordenarPorApellido(eEmployee vec [], int tam);
void ordenarPorSector(eEmployee vec[], int tam );
void salariosEmpleados (eEmployee vec[], int tam);
void modificarEmpleado(eEmployee vec[],int tam);


#endif // TP2_H_INCLUDED
