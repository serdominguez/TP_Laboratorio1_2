#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "informes.h"
#include "valida.h"



/** \brief Ordena el vector por sector ascendente o descendente segun parametro
 *
 * \param vec[] es eEmpleado, es vector de empleados
 * \param tam es int, tamaño del vector a recorrer
 * \param orden es int, 0 orden ascendente, 1 orden descendente
 *
 */
void ordenarEmpleados (eEmpleado vec[], int tam, int orden )
{

    eEmpleado auxiliar;

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (orden == 0)
            {
                if (vec[i].sector > vec[j].sector)
                {
                    auxiliar = vec[j];
                    vec[j] = vec[i];
                    vec[i] = auxiliar;
                } else if (vec[i].sector == vec[j].sector && strcmp(vec[i].apellido,vec[j].apellido)>0) {
                    auxiliar = vec[j];
                    vec[j] = vec[i];
                    vec[i] = auxiliar;
                }
            }
            if (orden == 1)
            {

                if (vec[i].sector<vec[j].sector)
                {
                    auxiliar = vec[j];
                    vec[j] = vec[i];
                    vec[i] = auxiliar;

                } else if (vec[i].sector == vec[j].sector && strcmp(vec[i].apellido,vec[j].apellido)>0) {
                    auxiliar = vec[j];
                    vec[j] = vec[i];
                    vec[i] = auxiliar;
                }
            }

        }

    }
    mostrarEmpleados(vec, tam);
}


/** \brief Muestra opciones de informes
 *
 * \return opcion es int, valor seleccionado por el usuario
 *
 */
int menuInformes ()
{
    int opcion;
    do
    {
        system("cls");
        printf("- - - - - INFORMES - - - - -\n");
        printf("Menu de opciones:\n");
        printf("1. Listar empleados por sector y apellido (ascendente)\n");
        printf("2. Listar empleados por sector y apellido (descendente)\n");
        printf("3. Listar toal y promedio de los salarios y empleados que superan el promedio\n");
        printf("4. Salir\n\n");
        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    while (opcion > 4);

    return opcion;

}

/** \brief muestra informes seleccionaso por el usuario a traves del menu
 *
 * \param vec[] es eEmpleado, es vector de empleados
 * \param tam es int, tamaño del vector a recorrer
 *
 */
void informes (eEmpleado vec[], int tam)
{
    char salir = 'n';
    int promedio;

    do {

    switch (menuInformes())
    {
    case 1:
        ordenarEmpleados(vec,tam,0);
        break;
    case 2:
        ordenarEmpleados(vec,tam,1);
        break;
    case 3:

        promedio = mostrarSueldosYPromedio(vec, tam);
        mostrarEmpleadosSobrePromedio(vec, tam, promedio);

        break;
    case 4:
        salir = validaChar2("Confirme salida (S/N): ", "ERROR, debe ingresar S o N ", 's', 'n');
        break;
    }
    } while (salir != 's');

}


/** \brief Calcula total de sueldos y el promedio de los mismos
 *
 * \param vec[] es eEmpleado, es vector de empleados
 * \param tam es int, tamaño del vector a recorrer
 * \return promedioSueldo es float, se utilizara para la funcion mostrarEmpleadosSobrePromedio;
 *
 */
float mostrarSueldosYPromedio (eEmpleado vec[], int tam) {

    float totalSueldos = 0;
    int contEmpleados = 0;
    float promedioSueldos;

    for (int i=0; i<tam; i++) {
        if (vec[i].isEmpty == 0) {
            totalSueldos += vec[i].sueldo;
            contEmpleados ++;
        }
    }
    promedioSueldos = totalSueldos/contEmpleados;


    printf("\nEl total de los sueldos de la nomina es: %.2f\n", totalSueldos);
    printf("El promedio de los sueldos es: %.2f\n",promedioSueldos);

    return promedioSueldos;

 }

 /** \brief Muestra los empleados de la lista que superen un valor
  *
  * \param vec[] es eEmpleado, es vector de empleados
  * \param tam es int, tamaño del vector a recorrer
  * \param promedio es int, es el sueldo que debe ser superado para que se muestre el empleado
  *
  */
 void mostrarEmpleadosSobrePromedio (eEmpleado vec[], int tam, int promedio) {

    printf("\nLos siguientes empleados superan el sueldo promedio: \n");
    printf("  ID\t    Nombre\t\t  Apellido\t\tSueldo\t\tSector\n");
    printf("------------------------------------------------------------------------------\n");

    ordenarEmpleadosId(vec, tam);

    for (int i=0; i<tam; i++) {
        if (vec[i].sueldo > promedio && vec[i].isEmpty == 0) {
            mostrarEmpleado(vec[i]);
        }
    }
    printf("\n\n");
    system("pause");
 }
