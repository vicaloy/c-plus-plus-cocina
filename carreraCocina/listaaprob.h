#ifndef LISTAAPROB_H_INCLUDED
#define LISTAAPROB_H_INCLUDED
#include "aprobacion.h"
#include "boolean.h"

typedef struct nodo {
Aprobacion aprob;
nodo * sig;
} NodoAprob;
typedef NodoAprob * ListaAprob;

//crea lista vacia
void crearLista(ListaAprob &lis);
//dice si la lista esta vacia
boolean vaciaLista(ListaAprob lis);
//devuelve el primer elemento de la lista
//PRECOND: lista NO vacía
Aprobacion primero (ListaAprob lis);
//borra el primer elemento de la lista
//PRECOND: lista NO vacía
void resto(ListaAprob &lis);
//agrega un elemento al principio de la lista
void insFront (ListaAprob &lis, Aprobacion a);
//inserta en orden de fecha en la lista
void insOrdenFecha(ListaAprob &lis, Aprobacion a);
void mostrarListaAprob (ListaAprob l);
boolean perteneceLista (ListaAprob l, int codAsig);
void insBack (ListaAprob &lis, Aprobacion a);


#endif // LISTAAPROB_H_INCLUDED
