#ifndef AVLALUMNO_H_INCLUDED
#define AVLALUMNO_H_INCLUDED
#include "stdio.h"
#include "alumno.h"

typedef struct nodoA {
    Alumno alum;
nodoA * hIzq;
nodoA * hDer;
int altura;
 } Nodo;
typedef Nodo * AvlAlum;

int alturaAvlAlum(AvlAlum a);
void balancearAvlAlum(AvlAlum &a);
void rotacionSimpleIzquierda(AvlAlum &t);
void rotacionSimpleDerecha(AvlAlum &t);
void rotacionDobleDerecha(AvlAlum &t);
void rotacionDobleIzquierda(AvlAlum &t);
void crearAvlAlum(AvlAlum &a);
boolean vacioAvlAlum(AvlAlum a);
boolean perteneceAvlAlum(AvlAlum a, int cedula);
void insertarAvlAlum(AvlAlum &a, Alumno alum);
void postOrden (AvlAlum a);
void orden (AvlAlum a);
void preorden (AvlAlum a);
Alumno obtenerMinimoAvlAlum(AvlAlum a);
Alumno obtenerMaximoAvlAlum(AvlAlum a);
Alumno obtenerAvlAlum(AvlAlum a, int cedula);
void eliminarAvl(AvlAlum &a, int ci);
AvlAlum unirAvl(AvlAlum izq, AvlAlum der);



#endif // AVLALUMNO_H_INCLUDED
