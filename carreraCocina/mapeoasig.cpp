#include "mapeoasig.h"
#include <stdio.h>

void crearMapeoAsig (MapeoAsig &m)
{
    int i;
    for(i=0; i<TAM; i++)
        m[i].existe = FALSE;
}
boolean perteneceMapeoAsig (MapeoAsig m, int pos)
{
    return (m[pos].existe);
}
void insertarMapeoAsig (MapeoAsig &m, Asignatura a, int pos)
{
    m[pos].existe = TRUE;
    m[pos].asig = a;
}

//Precondición: Pertenece(m,pos)
Asignatura obtenerMapeoAsig (MapeoAsig m, int pos)
{
    return m[pos].asig;
}
//Precondición: Pertenece(m,pos)
void eliminarMapeoAsig (MapeoAsig &m, int pos)
{
    m[pos].existe = FALSE;
}

int cantidadElemMapeo (MapeoAsig m)
{
    int i=0;

    while (i<TAM && m[i].existe==TRUE)
    {
        i++;
    }
    return i;
}

boolean completoMapeoAsig(MapeoAsig m)
{
    boolean completo=FALSE;
    int cantElem=cantidadElemMapeo(m);
    if(cantElem==TAM)
    {
        completo=TRUE;
    }
    return completo;
}

void mostrarMapeoAsig(MapeoAsig m)
{
    int i=0;

    while (i<TAM && m[i].existe==TRUE)
    {
        mostrarAsig(m[i].asig);

        i++;
    }
}

boolean salvoPreviasMapeoAsig(MapeoAsig m, int codAsig, ListaAprob lista)
{
    boolean aprobo=TRUE;
    int i=0;
    MapeoAsig mapeoPrevias;
    crearMapeoAsig(mapeoPrevias);
    int codigoCambia=codAsig;
    while(darTienePreviaAsig(m[codAsig].asig)==TRUE
            && i<(TAM+1) && m[i].existe==TRUE)
    {
        Asignatura asigActual=obtenerMapeoAsig(m, codigoCambia);
        Asignatura previa=obtenerMapeoAsig(m, darCodigoPreviaAsig(asigActual));
        codigoCambia=darCodigoAsig(previa);
        if(perteneceMapeoAsig(mapeoPrevias, darCodigoAsig(previa))==FALSE)
            insertarMapeoAsig(mapeoPrevias, previa, darCodigoAsig(previa));
        i++;

    }

    for(int j=0; j<TAM; j++){
        if(mapeoPrevias[j].existe==TRUE &&
           perteneceLista(lista, darCodigoAsig(mapeoPrevias[j].asig))==FALSE){
            aprobo=FALSE;
        }
    }
    return aprobo;
}

boolean generaCicloMapeoAsig(MapeoAsig m, int codAsig)
{
    boolean genera=FALSE;
    int codigoCambia=codAsig;
    int i=0;
    while(darTienePreviaAsig(m[codAsig].asig)==TRUE
            && genera==FALSE && i<(TAM+1) && m[i].existe==TRUE)
    {
        Asignatura asigActual=obtenerMapeoAsig(m, codigoCambia);
        Asignatura previa=obtenerMapeoAsig(m, darCodigoPreviaAsig(asigActual));
        codigoCambia=darCodigoAsig(previa);
        if(codigoCambia==codAsig)
            genera=TRUE;
        i++;

    }

    return genera;
}

void insertarMapeoAsigEntreDos(MapeoAsig &m)
{

    Asignatura a;
    int prevUno;
    int prevDos;
    printf("\nIngrese codigo de previa uno: ");
    scanf("%d", &prevUno);
    printf("\nIngrese codigo de previa dos: ");
    scanf("%d", &prevDos);

    if(perteneceMapeoAsig (m, prevUno)==FALSE)
    {
        printf("Codigo de previatura uno ingresada no existe\n\n");
    }
    else if(perteneceMapeoAsig (m, prevDos)==FALSE)
    {
        printf("Codigo de previatura dos ingresada no existe\n\n");
    }
    else
    {

        cargarAsigConPrev(a, prevUno, cantidadElemMapeo(m));
        insertarMapeoAsig(m, a, cantidadElemMapeo(m));
        Asignatura asigParaPrev=obtenerMapeoAsig(m, prevDos);
        Asignatura asigPrevAnterior=asigParaPrev;
        colocarPrevia(asigParaPrev, darCodigoAsig(a));
        insertarMapeoAsig(m, asigParaPrev, darCodigoAsig(asigParaPrev));

        if(generaCicloMapeoAsig(m, prevUno)==TRUE)
        {
            printf("Asignatura ingresada genera ciclo entre previaturas, se elimina asignatura\n\n");
            eliminarMapeoAsig(m, darCodigoAsig(a));
            insertarMapeoAsig(m, asigPrevAnterior, prevDos);
        }
        else
        {
            printf("Asignatura no genera ciclo, ingresada \n\n");
        }

    }

}

void mostrarPreviasMapeoAsig(MapeoAsig m, int codAsig)
{
    if(perteneceMapeoAsig(m, codAsig)==TRUE && darTienePreviaAsig(m[codAsig].asig)==TRUE)
    {
        Asignatura asigActual=obtenerMapeoAsig(m, codAsig);
        Asignatura previa=obtenerMapeoAsig(m, darCodigoPreviaAsig(asigActual));
        mostrarNombreCodigoAsig(previa);
        mostrarPreviasMapeoAsig(m, darCodigoAsig(previa));
    }

}



