#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "valida.h"
#include "informes.h"
#include "empleado.h"

#define TAM 1000


int main()
{
    char salir = 'n';
    int id = 1;
    int flag = 0;


    eEmpleado nomina[TAM];    //inicializa array de empleados con TAM posiciones


    iniciaEmpleados(nomina,TAM);   //pone el flag isEmpty en true para todas las posiciones

    //CARGADOS EMPLEADOS DE PRUEBA
    //id = id + harcodeEmpleados(nomina, TAM, 9);


    do
    {
        switch (menuPrincipal())
        {
        case 1:
            //alta empleado
            altaEmpleado(nomina, TAM, id);
            id ++;
            break;
        case 2:
            //modificacion empleado
            for (int i=0; i<TAM; i++)
            {
                if (nomina[i].isEmpty == 0)
                {
                    modificarEmpleado(nomina, TAM);
                    flag = 1;
                    break;
                }

            }
            if (flag == 0)
            {
                printf("No hay empleados activos para modificar\n");
                system("pause");
                break;
            }
            flag = 0;
            break;
        case 3:
            //Baja de empleado
            for (int i=0; i<TAM; i++)
            {
                if (nomina[i].isEmpty == 0)
                {
                    bajaempleado(nomina, TAM);
                    flag = 1;

                    break;
                }

            }

            if (flag == 0)
            {
                printf("No hay empleados activos para modificar\n");
                system("pause");
                break;
            }

            flag = 0;
            break;

        case 4:
            // mostrarEmpleados(nomina,TAM);
            //INFORMES
            for (int i=0; i<TAM; i++)
            {
                if (nomina[i].isEmpty == 0)
                {
                    informes(nomina,TAM);
                    flag = 1;

                    break;
                }

            }
            if (flag == 0)
            {

                printf("No hay empleados activos para mostrar\n");
                system("pause");
                break;
            }

            flag = 0;

            break;

        case 5:
            salir = validaChar2("Confirme salida (S/N): ", "ERROR, debe ingresar S o N ", 's', 'n');

        }

    }
    while (salir !='s');


    return 0;
}

