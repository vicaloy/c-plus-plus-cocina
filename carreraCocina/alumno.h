#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include "stdio.h"
#include "stringdinamico.h"
#include "listaaprob.h"

typedef struct {
int cedula;
StringDinamico nombre;
StringDinamico apellido;
int telefono;
ListaAprob listaAprob;
}Alumno;

void mostrarAlum(Alumno alum);
void cargarAlum(Alumno &alum, int cedula);
int darCedulaAlum(Alumno alum);
void darNombreAlum(Alumno alum, StringDinamico &nombre);
void darApellidoAlum(Alumno alum, StringDinamico &nombre);
int darTelefonoAlum(Alumno alum);
void colocarListaAprobAlum(Alumno &alum, ListaAprob lista);
ListaAprob darListaAprob(Alumno alum);

#endif // ALUMNO_H_INCLUDED
