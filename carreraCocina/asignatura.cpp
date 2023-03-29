#include "asignatura.h"
#include "stdio.h"


void mostrarAsig(Asignatura asig)
{
    printf("Codigo: %d \n", asig.codigo);
    printf("Nombre: ");
    print(asig.nombre);
    printf("\n");
    printf("Tiene previa: ");
    mostrarBoolean(asig.tienePrevia);
    printf("\n");
    if(asig.tienePrevia==TRUE)
    {
        printf("Codigo previa: %d", asig.DiscriminantePrevia.codigoPrevia);
    }

    printf("\n\n\n");
}

void cargarAsigConPrev(Asignatura &asig, int codPrev, int codAsig)
{
    printf("Ingrese asignatura con codigo de previa ingresado\n\n");
    asig.codigo=codAsig;
    asig.tienePrevia=TRUE;
    asig.DiscriminantePrevia.codigoPrevia=codPrev;

    printf("Nombre: ");
    strcrear(asig.nombre);
    scan(asig.nombre);
    while (strlar(asig.nombre) < 1)
    {
        printf("El nombre debe contener al menos una letra.\nNombre: ");
        scan(asig.nombre);
    }

    printf("\n");

    printf("Asignatura ingresada con previa codigo %d \n\n", codPrev);

}
void cargarAsig(Asignatura &asig, int codAsig)
{
    printf("Ingrese a continuacion los valores para una nueva Asignatura.\n");

    /*printf("Codigo: ");
    scanf("%d",&asig.codigo);
    while(asig.codigo < 0)
    {
        printf("El codigo debe ser un valor entero mayor/igual que 0.\nCodigo: ");
        scanf("%d",&asig.codigo);
    }*/

    asig.codigo=codAsig;
    printf("Nombre: ");
    strcrear(asig.nombre);
    scan(asig.nombre);
    while (strlar(asig.nombre) < 1)
    {
        printf("El nombre debe contener al menos una letra.\nNombre: ");
        scan(asig.nombre);
    }

    printf("Ingrese si tiene previa: ");
    cargarBoolean(asig.tienePrevia);

    if(asig.tienePrevia==TRUE)
    {
        printf("Ingrese codigo de previa: ");
        scanf("%d", &asig.DiscriminantePrevia.codigoPrevia);
    }
}

void colocarCodigoAsig(Asignatura &asig, int codigo)
{
    asig.codigo=codigo;
}

int darCodigoAsig(Asignatura asig)
{
    return asig.codigo;
}
void darNombreAsig(Asignatura asig, StringDinamico &nombre)
{
    strcop(nombre, asig.nombre);
}

void mostrarNombreCodigoAsig(Asignatura a)
{
    printf("Nombre previa: ");
    print(a.nombre);
    printf("\n");
    printf("Codigo previa: %d", a.codigo);
    printf("\n");
}

boolean darTienePreviaAsig(Asignatura asig)
{
    return asig.tienePrevia;
}

int darCodigoPreviaAsig(Asignatura asig)
{
    return asig.DiscriminantePrevia.codigoPrevia;
}

void colocarPrevia(Asignatura &a, int previa)
{
    a.tienePrevia=TRUE;
    a.DiscriminantePrevia.codigoPrevia=previa;
}


