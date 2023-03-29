#include "aprobacion.h"
#include "stdio.h"


void mostrarAprob(Aprobacion aprob)
{
    printf("Cedula alumno: %d \n", aprob.cedulaAlum);
    printf("Codigo asignatura: %d \n", aprob.codigoAsig);
    printf("Nombre asignatura: ");
    print(aprob.nombreAsig);
    printf("\n");
    printf("Calificacion: %d \n", aprob.calificacion);
    printf("Fecha: ");
    mostrarFecha(aprob.fecha);
    printf("\n");
    printf("\n");
}
void cargarAprob(Aprobacion &aprob, StringDinamico nom, int ced, int codAsig)
{
    printf("Ingrese a continuacion los valores para una nueva Aprobacion.\n");
    strcrear(aprob.nombreAsig);
    strcop(aprob.nombreAsig, nom);
    strdestruir(nom);
    aprob.cedulaAlum=ced;
    aprob.codigoAsig=codAsig;

    /*printf("Cedula alumno: ");
    scanf("%d",&aprob.cedulaAlum);
    while(aprob.cedulaAlum < 0)
    {
        printf("La cedula debe ser un valor entero mayor/igual que 0.\nCedula: ");
        scanf("%d",&aprob.cedulaAlum);
    }

    printf("Codigo asignatura: ");
    scanf("%d",&aprob.codigoAsig);
    while(aprob.codigoAsig < 0)
    {
        printf("El codigo debe ser un valor entero mayor/igual que 0.\nCodigo: ");
        scanf("%d",&aprob.codigoAsig);
    }*/

    /*printf("Nombre asignatura: ");
    scan(aprob.nombreAsig);
    while (strlar(aprob.nombreAsig) < 1)
    {
        printf("El nombre debe contener al menos una letra.\nNombre: ");
        scan(aprob.nombreAsig);
    }*/

    printf("Calificacion: ");
    scanf("%d",&aprob.calificacion);
    while(aprob.calificacion < 0)
    {
        printf("La calificacion debe ser un valor entero mayor/igual que 0.\nCalificacion: ");
        scanf("%d",&aprob.calificacion);
    }

    printf("Fecha: ");
    cargarFecha(aprob.fecha);

}

int darCodigoAsigAprob(Aprobacion aprob)
{
    return aprob.codigoAsig;
}
void darNombreAsigAprob(Aprobacion aprob, StringDinamico &nombre)
{
    strcop(nombre, aprob.nombreAsig);
}

int darCedulaAlumAprob(Aprobacion aprob){
    return aprob.cedulaAlum;
}

Fecha darFechaAprob(Aprobacion aprob){
    return aprob.fecha;
}
