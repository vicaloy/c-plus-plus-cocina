#ifndef ASIGNATURA_H_INCLUDED
#define ASIGNATURA_H_INCLUDED
#include "stdio.h"
#include "stringdinamico.h"
#include "boolean.h"

typedef struct {
int codigo;
StringDinamico nombre;
boolean tienePrevia;
union{
    int codigoPrevia;
} DiscriminantePrevia;
}Asignatura;

void mostrarAsig(Asignatura asig);
void cargarAsig(Asignatura &asig, int codAsig);
void cargarAsigConPrev(Asignatura &asig, int codPrev, int codAsig);
int darCodigoAsig(Asignatura asig);
void darNombreAsig(Asignatura asig, StringDinamico &nombre);
boolean darTienePreviaAsig(Asignatura asig);
int darCodigoPreviaAsig(Asignatura asig);
void colocarCodigoAsig(Asignatura &asig, int codigo);
void colocarPrevia(Asignatura &a, int previa);
void mostrarNombreCodigoAsig(Asignatura a);


#endif // ASIGNATURA_H_INCLUDED
