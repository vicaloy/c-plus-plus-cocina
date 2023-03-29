#include<stdio.h>
#include "boolean.h"
//precond: se ingresa por entrada estandar (0-1)
void cargarBoolean(boolean &b)
{
    int valor;
    printf("Ingrese 0-Falso, 1-Verdadero: ");
    scanf("%d", &valor);
    if(valor==0)
    {
        b=FALSE;
    }
    else
    {
        b=TRUE;
    }
}
//precond: b no vacio
void mostrarBoolean(boolean b)
{
    if(b==FALSE)
    {
        printf("Falso");
    }
    else
    {
        printf("Verdadero");
    }
}
