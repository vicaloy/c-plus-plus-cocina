#include "alumno.h"
#include "stdio.h"
#include "listaaprob.h"


void mostrarAlum(Alumno alum)
{
    printf("Cedula: %d \n", alum.cedula);
    printf("Nombre: ");
    print(alum.nombre);
    printf("\n");
    printf("Apellido: ");
    print(alum.apellido);
    printf("\n");
    printf("Telefono: %d \n", alum.telefono);
    printf("\n");

}
void cargarAlum(Alumno &alum, int cedula)
{
    printf("Ingrese a continuacion los valores para un nuevo Alumno.\n");
    alum.cedula=cedula;

    printf("Nombre: ");
    strcrear(alum.nombre);
    scan(alum.nombre);
    while (strlar(alum.nombre) < 1)
    {
        printf("El nombre debe contener al menos una letra.\nNombre: ");
        scan(alum.nombre);
    }

    printf("Apellido: ");
    strcrear(alum.apellido);
    scan(alum.apellido);
    while (strlar(alum.apellido) < 1)
    {
        printf("El apellido debe contener al menos una letra.\nNombre: ");
        scan(alum.apellido);
    }

    printf("Telefono: ");
    scanf("%d",&alum.telefono);

    crearLista(alum.listaAprob);

}

int darCedulaAlum(Alumno alum)
{
    return alum.cedula;
}
void darNombreAlum(Alumno alum, StringDinamico &nombre)
{
    strcop(nombre, alum.nombre);
}

void darApellidoAlum(Alumno alum, StringDinamico &nombre)
{
    strcop(nombre, alum.apellido);
}

int darTelefonoAlum(Alumno alum)
{
    return alum.telefono;
}

void colocarListaAprobAlum(Alumno &alum, ListaAprob lista){
    alum.listaAprob=lista;
}

ListaAprob darListaAprob(Alumno alum){
    return alum.listaAprob;
}
