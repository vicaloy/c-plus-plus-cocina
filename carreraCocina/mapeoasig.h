#ifndef MAPEOASIG_H_INCLUDED
#define MAPEOASIG_H_INCLUDED
#include "listaaprob.h"
#include "stdio.h"
#include "asignatura.h"
#include "boolean.h"
#include "aprobacion.h"


const int TAM=10;
typedef struct {
    boolean existe;
Asignatura asig;
 } T;
typedef T MapeoAsig [TAM];


boolean salvoPreviasMapeoAsig(MapeoAsig m, int codigo, ListaAprob l);
void crearMapeoAsig (MapeoAsig &m);
boolean perteneceMapeoAsig (MapeoAsig m, int pos);
void insertarMapeoAsig (MapeoAsig &m, Asignatura a, int pos);
int cantidadElemMapeo (MapeoAsig m);
//Precondición: Pertenece(m,pos)
Asignatura obtenerMapeoAsig (MapeoAsig m, int pos);
//Precondición: Pertenece(m,pos)
void eliminarMapeoAsig (MapeoAsig &m, int pos);
void mostrarMapeoAsig(MapeoAsig m);
void insertarMapeoAsigEntreDos(MapeoAsig &m);
void mostrarPreviasMapeoAsig(MapeoAsig m, int codAsig);
boolean completoMapeoAsig(MapeoAsig m);
boolean generaCicloMapeoAsig(MapeoAsig m, int codAsig);



#endif // MAPEOASIG_H_INCLUDED
