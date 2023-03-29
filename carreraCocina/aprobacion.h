#ifndef APROBACION_H_INCLUDED
#define APROBACION_H_INCLUDED
#include "stdio.h"
#include "stringdinamico.h"
#include "fecha.h"

typedef struct {
int cedulaAlum;
int codigoAsig;
StringDinamico nombreAsig;
Fecha fecha;
int calificacion;
}Aprobacion;

void mostrarAprob(Aprobacion aprob);
void cargarAprob(Aprobacion &aprob, StringDinamico nom, int ced, int codAsig);
int darCodigoAsigAprob(Aprobacion aprob);
void darNombreAsigAprob(Aprobacion aprob, StringDinamico &nombre);
int darCedulaAlumAprob(Aprobacion aprob);
Fecha darFechaAprob(Aprobacion aprob);

#endif // APROBACION_H_INCLUDED
