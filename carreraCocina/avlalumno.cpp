#include "avlalumno.h"
#include <stdio.h>
#include "boolean.h"
int alturaAvlAlum(AvlAlum a)
{
    if (a == NULL)
        return 0;
    else
        return a->altura;
}

void rotacionSimpleIzquierda(AvlAlum &t)
{
    AvlAlum t1;
    t1 = t->hIzq;
    t->hIzq = NULL;
    t1->hDer = t;
    t = t1;
}

void rotacionSimpleDerecha(AvlAlum &t)
{
    AvlAlum t1;
    t1 = t->hDer;
    t->hDer = NULL;
    t1->hIzq = t;
    t = t1;
}


void rotacionDobleDerecha(AvlAlum &t)
{

    rotacionSimpleIzquierda(t->hDer);
    rotacionSimpleDerecha(t);

}

void rotacionDobleIzquierda(AvlAlum &t)
{
    rotacionSimpleDerecha(t->hIzq);
    rotacionSimpleIzquierda(t);

}

void balancearAvlAlum(AvlAlum &a)
{
    if (a != NULL)
    {
        if (alturaAvlAlum(a->hIzq) - alturaAvlAlum(a->hDer) == 2)
        {
            if (alturaAvlAlum(a->hIzq->hIzq) >= alturaAvlAlum(a->hIzq->hDer))
                rotacionSimpleIzquierda (a);
            else
                rotacionDobleIzquierda (a);
        }
        else
        {
            if (alturaAvlAlum(a->hDer) - alturaAvlAlum(a->hIzq) == 2)
            {
                if (alturaAvlAlum(a->hDer->hDer) >= alturaAvlAlum(a->hDer->hIzq))
                    rotacionSimpleDerecha (a);
                else
                    rotacionDobleDerecha (a);
            }
        }
    }
}


void crearAvlAlum(AvlAlum &a)
{
    a=NULL;
}
boolean vacioAvlAlum(AvlAlum a)
{
    if(a==NULL)
        return TRUE;
    else
        return FALSE;
}
boolean perteneceAvlAlum(AvlAlum a, int cedula)
{
    boolean esta=FALSE;
    if(vacioAvlAlum(a)==FALSE)
    {
        while(a!=NULL&&esta==FALSE)
        {
            if(cedula==darCedulaAlum(a->alum))
                esta=TRUE;
            else if(cedula<darCedulaAlum(a->alum))
                a=a->hIzq;
            else
                a=a->hDer;
        }
    }
    return esta;
}
void insertarAvlAlum(AvlAlum &a, Alumno alum)
{
    if (a == NULL)
    {
        a = new Nodo;
        a -> alum= alum;
        a -> hIzq = NULL;
        a -> hDer = NULL;
    }
    else if (darCedulaAlum(alum) < darCedulaAlum(a->alum))
        insertarAvlAlum(a->hIzq,alum);
    else
        insertarAvlAlum(a->hDer,alum);
}

void preorden (AvlAlum a)
{
    if (a != NULL)
    {
        mostrarAlum(a->alum);
        preorden (a -> hIzq);
        preorden (a -> hDer);
    }
}

void orden (AvlAlum a)
{
    if (a != NULL)
    {
        orden (a -> hIzq);
        mostrarAlum(a->alum);
        orden (a -> hDer);
    }
}

void postOrden (AvlAlum a)
{
    if (a != NULL)
    {
        postOrden (a -> hIzq);
        postOrden (a -> hDer);
        mostrarAlum(a->alum);
    }
}


//abb no vacio
Alumno obtenerMinimoAvlAlum(AvlAlum a)
{
    if(a->hIzq==NULL)
        return a->alum;
    else
        return obtenerMinimoAvlAlum(a->hIzq);
}

//abb no vacio
Alumno obtenerMaximoAvlAlum(AvlAlum a)
{
    if(a->hDer==NULL)
        return a->alum;
    else
        return obtenerMaximoAvlAlum(a->hDer);
}

Alumno obtenerAvlAlum(AvlAlum a, int cedula)
{
    boolean esta=FALSE;
    Alumno alumRet;
    if(vacioAvlAlum(a)==FALSE)
    {
        while(a!=NULL&&esta==FALSE)
        {
            if(cedula==darCedulaAlum(a->alum))
            {
                alumRet=a->alum;
                esta=TRUE;
            }
            else if(cedula<darCedulaAlum(a->alum))
                a=a->hIzq;
            else
                a=a->hDer;
        }
    }
    return alumRet;
}

AvlAlum unirAvl(AvlAlum izq, AvlAlum der)
{
    if(izq==NULL)
        return der;
    if(der==NULL)
        return izq;

    AvlAlum centro = unirAvl(izq->hDer, der->hIzq);
    izq->hDer = centro;
    der->hIzq = izq;
    return der;
}

void eliminarAvl(AvlAlum &a, int ci)
{
    if(a!=NULL)
    {

        if(ci<darCedulaAlum(a->alum))
            eliminarAvl(a->hIzq, ci);
        else if(ci>darCedulaAlum(a->alum))
            eliminarAvl(a->hDer, ci);

        else
        {
            AvlAlum p = a;
            a = unirAvl(a->hIzq, a->hDer);
            delete p;
        }
    }
}
