#include <stdio.h>
#include "menu.h"
#include "mapeoasig.h"
#include "asignatura.h"
#include "avlalumno.h"


using namespace std;

int main()
{
    int opcion=0;
    MapeoAsig mapeoAsig;
    AvlAlum avlAlum;
    crearMapeoAsig(mapeoAsig);
    crearAvlAlum(avlAlum);


    do
    {
        mostrarMenu(opcion);
        switch(opcion)
        {
        case 1:
            printf("1- Registrar los nombres de todas las asignaturas que componen la carrera. Al momento de registrar cada una, se le asignara tambien un numero que la identificara posteriormente \n\n");
            if(completoMapeoAsig(mapeoAsig)==TRUE)
            {
                printf("Ya ha ingresado todas las materias de la carrera \n\n");
            }
            else
            {
                boolean insertar=TRUE;
                Asignatura asig;
                cargarAsig(asig, cantidadElemMapeo(mapeoAsig));
                if(darTienePreviaAsig(asig)==TRUE)
                {
                    if(darCodigoAsig(asig)==darCodigoPreviaAsig(asig))
                    {
                        printf("Una asignatura no puede ser previa de si misma \n\n");
                        insertar=FALSE;
                    }
                    else if(perteneceMapeoAsig(mapeoAsig, darCodigoPreviaAsig(asig))==FALSE)
                    {
                        printf("Codigo de asignatura previa no existe \n\n");
                        insertar=FALSE;
                    }
                }
                if(insertar==TRUE)
                {
                    insertarMapeoAsig(mapeoAsig, asig, cantidadElemMapeo(mapeoAsig));
                    printf("Asignatura con codigo %d insertada \n\n", darCodigoAsig(asig));
                }
            }
            break;
        case 2:
            printf("2- Listar numero y nombre de todas las asignaturas registradas en el sistema, ordenadas por numero de asignatura de menor a mayor \n\n");
            mostrarMapeoAsig(mapeoAsig);
            break;
        case 3:
            printf("3- Dados los numeros que identifican a dos asignaturas, agregar una previatura entre ellas \n\n");
            insertarMapeoAsigEntreDos(mapeoAsig);
            break;
        case 4:
            printf("4- Dado el numero que identifica a una asignatura, obtener un listado conteniendo numero y nombre de todas sus previas\n\n");
            int codAsig;
            printf("Ingrese codigo de asignatura: ");
            scanf("%d", &codAsig);
            printf("\n");
            mostrarPreviasMapeoAsig(mapeoAsig, codAsig);
            break;

        case 5:
            printf("5- Ingresar un nuevo alumno a la academia, chequeando que no existiera previamente \n\n");
            int cedula;
            printf("Ingrese cedula para el alumno\n");
            scanf("%d", &cedula);

            while(cedula < 0)
            {
                printf("La cedula debe ser un valor entero mayor/igual que 0.\nCedula: ");
                scanf("%d", &cedula);
            }


            if(perteneceAvlAlum(avlAlum, cedula)==FALSE)
            {

                Alumno alumno;
                cargarAlum(alumno, cedula);
                insertarAvlAlum(avlAlum, alumno);
                balancearAvlAlum(avlAlum);
            }
            else
            {
                printf("La cedula ya existe\n");
            }
            break;

        case 6:
            printf("6- Listar los datos basicos de todos los alumnos de la academia, ordenados por cedula de menor a mayor \n\n");
            orden(avlAlum);
            break;

        case 7:
            printf("7- Agregar una nueva aprobacion a la escolaridad de un alumno, verificando que el alumno este registrado en el sistema, que no tenga la asignatura aprobada de antes y tambien que tenga salvadas sus previas inmediatas\n\n");
            printf("Ingrese cedula de alumno\n");
            int ced;
            scanf("%d", &ced);
            if(perteneceAvlAlum(avlAlum, ced)==TRUE)
            {
                printf("Ingrese codigo de asignatura\n");
                int codAsig;
                scanf("%d", &codAsig);

                if(perteneceMapeoAsig(mapeoAsig, codAsig)==TRUE)
                {

                    Asignatura asignatura=obtenerMapeoAsig(mapeoAsig, codAsig);
                    StringDinamico nomAsig;
                    strcrear(nomAsig);
                    darNombreAsig(asignatura, nomAsig);

                    Aprobacion aprob;
                    cargarAprob(aprob, nomAsig, ced, codAsig);

                    Alumno alum=obtenerAvlAlum(avlAlum, ced);
                    ListaAprob lista=darListaAprob(alum);

                    if(perteneceLista(lista, codAsig)==FALSE)
                    {
                        if(salvoPreviasMapeoAsig(mapeoAsig, codAsig, lista)==TRUE)
                        {
                            insOrdenFecha(lista, aprob);
                            colocarListaAprobAlum(alum, lista);
                            eliminarAvl(avlAlum, ced);
                            insertarAvlAlum(avlAlum, alum);
                            balancearAvlAlum(avlAlum);
                        }
                        else
                        {
                            printf("No aprobo las previas de la asignatura\n");
                        }
                    }
                    else
                    {
                        printf("Asignatura previamente aprobada\n");
                    }
                }
                else
                {
                    printf("El codigo de la asignatura no existe\n");
                }
            }
            else
            {
                printf("La cedula ingresada no existe\n");
            }
            break;

        case 8:
            printf("8- Dada la cedula de un alumno, listar su escolaridad, ordenada cronologicamente por fecha de aprobacion. Se debe verificar que el alumno este registrado en el sistema \n\n");

            printf("Ingrese cedula de alumno\n");
            int ci;
            scanf("%d", &ci);
            if(perteneceAvlAlum(avlAlum, ci)==TRUE)
            {
                Alumno al=obtenerAvlAlum(avlAlum, ci);
                ListaAprob lis=darListaAprob(al);
                mostrarListaAprob(lis);

            }
            else
            {
                printf("La cedula ingresada no existe\n");
            }
            break;
        }

    }
    while(opcion!=9);

    return 0;
}
