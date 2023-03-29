#include<stdio.h>
#include "listaaprob.h"
#include "mapeoasig.h"



//crea lista vacia
void crearLista(ListaAprob &lis)
{
    lis = NULL;
}
//dice si la lista esta vacia
boolean vaciaLista(ListaAprob lis)
{
    boolean es = FALSE;
    if (lis == NULL)
        es = TRUE;
    return es;
}
//devuelve el primer elemento de la lista
//PRECOND: lista NO vacía
Aprobacion primero (ListaAprob lis)
{
    return lis -> aprob;
}
//borra el primer elemento de la lista
//PRECOND: lista NO vacía
void resto(ListaAprob &lis)
{
    ListaAprob aux = lis;
    lis = lis -> sig;
    delete aux;
}
//agrega un elemento al principio de la lista
void insFront (ListaAprob &lis, Aprobacion a)
{
    ListaAprob aux = new NodoAprob;
    aux -> aprob = a;
    aux -> sig = lis;
    lis = aux;
}

// Precondición: L no está vacía
ListaAprob ultimoIter (ListaAprob l)
{
    while (l!= NULL && l ->sig != NULL)
    {
        l = l -> sig;
    }

    return (l);
}


void mostrarListaAprob (ListaAprob l)
{
    while (l!= NULL)
    {
        mostrarAprob(l->aprob);
        l = l -> sig;
    }
}


//agrega un elemento al FINAL de la lista
void insBack (ListaAprob &lis, Aprobacion a)
{

    if(lis==NULL)
    {
        //lista vacia
        lis=new NodoAprob;
        lis->aprob=a;
        lis->sig=NULL;
    }
    else
    {
        ListaAprob aux = new NodoAprob;
        aux -> aprob = a;
        aux -> sig = NULL;

        //encadeno al ultimo nodo
        ListaAprob ultimoEle = ultimoIter(lis);
        ultimoEle -> sig = aux;
    }

}


//inserta en orden de fecha en la lista
void insOrdenFecha(ListaAprob &lis, Aprobacion a)
{
    ListaAprob aux = lis;
    ListaAprob itemAnterior;
    crearLista(itemAnterior);
    boolean coloque=FALSE;

    if(lis==NULL)
    {
        //lista vacia
        lis=new NodoAprob;
        lis->aprob=a;
        lis->sig=NULL;
    }
    else
    {
        //lista con elementos
        while (coloque==FALSE)
        {
            if (primeraFechaMayor(darFechaAprob(a), darFechaAprob(aux->aprob))==TRUE)
            {
                coloque=TRUE;
                printf("PRIMERA FECHA MAYOR");
                if(itemAnterior!=NULL)
                {
                    itemAnterior->sig=new NodoAprob;
                    itemAnterior->sig->aprob=a;
                    itemAnterior->sig->sig =aux;
                }
                else
                {
                    itemAnterior=new NodoAprob;
                    itemAnterior->aprob=a;
                    itemAnterior->sig=aux;
                    lis=itemAnterior;
                }

            }
            itemAnterior=aux;
            aux = aux -> sig;
        }
    }
}

boolean perteneceLista (ListaAprob l, int codAsig)
{
    boolean encontre = FALSE;
    while (l != NULL && encontre==FALSE)
    {
        if (darCodigoAsigAprob(l ->aprob) == codAsig)
        {
            encontre = TRUE;
        }
        else
        {
            l = l -> sig;
        }
    }
    return encontre;
}


