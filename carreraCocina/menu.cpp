#include<stdio.h>
#include "menu.h"

void mostrarMenu(int &opcion)
{
    printf("\n\n\n-------------MENU PRINCIPAL---------------\n\n\n");
    printf("1- Registrar los nombres de todas las asignaturas que componen la carrera. Al momento de registrar cada una, se le asignara tambien un numero que la identificara posteriormente \n\n");
    printf("2- Listar numero y nombre de todas las asignaturas registradas en el sistema, ordenadas por numero de asignatura de menor a mayor \n\n");
    printf("3- Dados los numeros que identifican a dos asignaturas, agregar una previatura entre ellas \n\n");
    printf("4- Dado el numero que identifica a una asignatura, obtener un listado conteniendo numero y nombre de todas sus previas\n\n");
    printf("5- Ingresar un nuevo alumno a la academia, chequeando que no existiera previamente \n\n");
    printf("6- Listar los datos basicos de todos los alumnos de la academia, ordenados por cedula de menor a mayor \n\n");
    printf("7- Agregar una nueva aprobacion a la escolaridad de un alumno, verificando que el alumno este registrado en el sistema, que no tenga la asignatura aprobada de antes y tambien que tenga salvadas sus previas inmediatas\n\n");
    printf("8- Dada la cedula de un alumno, listar su escolaridad, ordenada cronologicamente por fecha de aprobacion. Se debe verificar que el alumno este registrado en el sistema \n\n");
    printf("9- Salir del programa \n\n\n\n\n");
    scanf("%d", &opcion);
}
