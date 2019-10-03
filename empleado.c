#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "empleado.h"
#include "valida.h"


/** \brief Mustra menu de opciones
 *
 * \return int opcion elegida por el usuario
 *
 */
int menuPrincipal()
{
    int opcion;
    do
    {
        system("cls");
        printf("------------------------------------------------------------\n");
        printf("-------TRABAJO PRACTICO NUMERO 2----------------------------\n");
        printf("------------------------------------------------------------\n");
        printf("-------------------ABM DE USUARIOS--------------------------\n");
        printf("------------------------------------------------------------\n");
        printf("------------------------------------------------------------\n");
        printf("--Sergio Dominguez-----------------------leg: 109290--------\n");
        printf("------------------------------------------------------------\n");
        printf("------------------------------------------------------------\n");
        printf("Menu de opciones:\n");
        printf("1. Alta de empleado\n");
        printf("2. Modificacion de empleado\n");
        printf("3. Baja de empleado\n");
        printf("4. Informar\n");
        printf("5. Salir\n\n");
        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    while (opcion > 5);

    return opcion;
}


/** \brief Pone el flag isEmpty en true
 *
 * \param list[] eEmpleado vector de empleados
 * \param tam int temaño del vector de empleados
 * \return void
 *
 */
void iniciaEmpleados(eEmpleado list[], int tam)
{

    for (int i=0; i<tam; i++)
    {
        list[i].isEmpty = 1;

    }

}


int altaEmpleado (eEmpleado list[], int tam, int id)
{
    int todoOk = 0;
    int indice;
    char auxiliar[51];
    float auxFloat;
    int auxInt;
    eEmpleado temporal;

    indice = buscarIndiceLibre(list,tam);

    system("cls");
    printf("- - - - - ALTA DE EMPLEADO - - - - -\n");
    if (indice == -1)
    {

        printf("Nomina llena, el maximo permitido es 1000 empleados") ;

    }
    else
    {

        //INGRESA NOMBRE
        validaString("Ingrese nombre: ", "Nombre muy largo, ingrese nombre: ", 51, auxiliar);
        poneMayuscula(auxiliar);
        strcpy(temporal.nombre,auxiliar);

        //INGRESA APELLIDO
        validaString("Ingrese apellido: ", "Apelido muy largo, ingrese apellido: ",51, auxiliar);
        poneMayuscula(auxiliar);
        strcpy(temporal.apellido,auxiliar);

        //INGRESA SUELDO
        validaFloat("Ingrese sueldo: ", "DATO INVALIDO. Debe ser un numero porsitivo.\nIngrese sueldo ", 0, &auxFloat);
        temporal.sueldo = auxFloat;

        //INGRESA SECTOR
        validaInt("Ingrese numero de sector: ", "DATO INVALIDO. Debe ser un numero porsitivo.\nIngrese numero de sector: ", 0,&auxInt);
        temporal.sector = auxInt;

        //ASIGNA ID AUTOMATICAMENTE
        temporal.id = id;

        //CAMBIA BANDERA
        temporal.isEmpty = 0;

        /*
        printf("\nNombre: %s \nApellido: %s \nSueldo :%.2f \nSector: %d \nId: %d",
               temporal.nombre, temporal.apellido, temporal.sueldo, temporal.sector, temporal.id);
        printf("\n\n");
        system("pause");
        */

        list[indice] = temporal;

        printf("\nNombre: %s \nApellido: %s \nSueldo :%.2f \nSector: %d \nId: %d",
               list[indice].nombre, list[indice].apellido, list[indice].sueldo, list[indice].sector, list[indice].id);
        printf("\n\n");
        system("pause");

    }

    return todoOk;
}

/** \brief recorre array y busca indice libre
 *
 * \param vec es vector de estructura eEmpleado, es el array que se va a recorrer
 * \param tam es int, es el tamaño del vector a recorrer
 * \return prier indice libre (isEmpty = TRUE)
 *
 */
int buscarIndiceLibre (eEmpleado vec[], int tam)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief recorre vector completo y llama a funcion mostrarEmpleado en los indices que tengan el falg isEmpty = true
 *
 * \param vec es vector de estructura eEmpleado, es el array que se va a recorrer
 * \param tam es int, es el tamaño del vector a recorrer
 *
 */
void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int flag = 0;

    system("cls");
    printf("****** L I S T A  D E  E M P L E A D O S ******\n\n");

    printf("  ID\t    Nombre\t\t  Apellido\t\tSueldo\t\tSector\n");
    printf("------------------------------------------------------------------------------\n");
    for(int i=0; i < tam; i++)
    {
        if (vec[i].isEmpty == 0)
        {
            mostrarEmpleado(vec[i]);
            flag = 1;
        }

    }

    if (flag == 0)
    {
        //system("cls");
        printf("No hay empleados para mostar");


    }

    system("pause");

    printf("\n\n");
}

/** \brief muestra un solo indice de vector de eEmpleados
 *
 * \param indice a mostrar
 */
void mostrarEmpleado(eEmpleado empleado)
{
    printf("%3d\t%10s\t\t%10s\t\t%.2f\t%5d\n",empleado.id,empleado.nombre,empleado.apellido,empleado.sueldo,empleado.sector);

}


/** \brief Carga en el vector eEmpleado vec[] empleados de prueba
 *
 * \param vec es vector de eEmpleados
 * \param tam es int, el tamaño del vector de eEpleados
 * \param cant es int, cantidad de empleados de prueba para cargar
 * \return devuelve int de total de empleados cargados
 *
 */
int harcodeEmpleados (eEmpleado vec[], int tam, int cant)
{

    int cargados = 0;

    eEmpleado nominaPrueba[10] =
    {
        {1,"Juan", "Diaz", 25000, 2, 0},
        {2,"Maria", "Perez", 12300, 4, 0},
        {3,"Laura", "Gomez", 33400, 3, 0},
        {4,"Manuel", "Fuentes", 65500, 1, 0},
        {5,"Pablo", "Garcia", 23400, 4, 0},
        {6,"Ema", "Rodriguez", 15600, 5, 0},
        {7,"Susana", "Valinotti", 44900, 1, 0},
        {8,"Gerardo", "Gutierrez", 55645, 3, 0},
        {9,"Javier", "Pelizza", 88900, 1, 0},
        {10,"Roxana", "Giraca", 33450, 2, 0}
    };

    if (cant<=tam)
    {

        for (int i=0; i<cant; i++)
        {

            vec[i] = nominaPrueba[i];
            cargados ++;
        }

    }
    else
    {
        printf("no hay suficientes empleados de prueba para cargar");

    }
    return cargados;
}

/** \brief modifica una de las variables de un eEmpleado, pide Id del empleado a modificar
 *
 * \param vec es eEmpleado, el vector de empeados de la nomnia
 * \param tam es int, el tamaño del vector a recorrer
 * \return devuelve 1 si pudo realizar el cambio
 *
 */
int modificarEmpleado (eEmpleado vec[], int tam)
{
    int todoOk = 0;
    int id;
    int indice;
    char salir;
    char auxiliar[51];
    float auxFloat;
    int auxInt;

    system("cls");
    printf("- - - - - MODIFICACION DE EMPLEADO - - - - -\n");
    validaInt("Ingrese ID del empleado a modificar o 0 para ver nomina completa: ",
              "Error, debe ingresar un numero positivo\nIngrese ID del empleado a modificar o 0 para ver nomina completa: ",0, &id);


    indice = elegirEmpleado(vec, tam, id, "modificar");

    if (indice>=0)
    {
        do
        {
            switch (menuModificarEmpleado())
            {
            case 1:
                //Modificar nombre
                if (validaString("Ingrese nuevo nombre: ", "Nombre muy largo, ingrese nombre: ", 51, auxiliar))
                {
                    poneMayuscula(auxiliar);
                    strcpy(vec[indice].nombre,auxiliar);
                    todoOk = 1;
                }
                break;

            case 2:
                //modificar apellido
                if (validaString("Ingrese nuevo apellido: ", "Apelido muy largo, ingrese apellido: ",51, auxiliar))
                {
                    poneMayuscula(auxiliar);
                    strcpy(vec[indice].apellido,auxiliar);
                    todoOk = 1;
                }
                break;

            case 3:
                //modificar sueldo
                if (validaFloat("Ingrese sueldo: ", "DATO INVALIDO. Debe ser un numero porsitivo.\nIngrese sueldo ", 0, &auxFloat))
                {
                    vec[indice].sueldo = auxFloat;
                    todoOk = 1;
                }
                break;

            case 4:
                //modificar sector
                if (validaInt("Ingrese numero de sector: ", "DATO INVALIDO. Debe ser un numero porsitivo.\nIngrese numero de sector: ", 0,&auxInt))
                {
                    vec[indice].sector = auxInt;
                    todoOk = 1;
                }
                break;

            case 5:
                salir = validaChar2("Confirme salida (S/N): ", "ERROR, debe ingresar S o N: ", 's', 'n');

            }

        }
        while (salir !='s');
    }



    return todoOk;
}

/** \brief Busca un ID en el vector
 *
 * \param vec[] es eEmpleado, es vector de empleados
 * \param tam es int, tamaño del vector a recorrer
 * \param id a buscar en el vector
 * \return devuelve indice int, el indice del vector del ID recibido.
 *
 */
int buscarEmpleado (eEmpleado vec[], int tam, int id)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (id == vec[i].id && !vec[i].isEmpty)
        {
            indice = i;
            break;
        }


    }

    return indice;
}

/** \brief valida el id del empleado ingresado por el usuario, o muestra vector completo
 *
 * \param vec[] es eEmpleado, es vector de empleados
 * \param tam es int, tamaño del vector a recorrer
 * \param id es int, es el id que se buscara en vec[]
 * \param  accion es puntero a char, es la accion que se realizara sobre el empleado
 * \return devuelve el indice de vec[] donde esta el empleado seleccionado
 *
 */
int elegirEmpleado (eEmpleado vec[], int tam, int id, char* accion)
{
    int indice = -1;
    char opcion;

    if (id == 0)
    {
        ordenarEmpleadosId(vec, tam);
        mostrarEmpleados(vec, tam);
        validaInt("Ingrese ID: ", "ERROR, el ID debe ser un numero positivo.\nIngrese ID: ", 0, &id);
    }

    indice = buscarEmpleado(vec, tam, id);
    if (indice == -1)
    {
        printf("NO HAY EMPLEADO REGISTRADO EN EL ID INFORMADO O FUE DADO DE BAJA\n\n");
        system("pause");
    }
    else
    {
        printf("\n");
        printf("ID\t    Nombre\t\t  Apellido\t\tSueldo\t\tSector\n");
        mostrarEmpleado(vec[indice]);
        printf("\n");
        printf("Se va a %s a %s %s\n\n",accion, vec[indice].nombre, vec[indice].apellido);

        //system("pause");
        opcion = validaChar2("Es correcto (S/N)", "ERROR, debe ingresr S/N", 's', 'n');
    }

    if (opcion == 'n')
    {
        printf("\nSe cancela la accion\n");
        indice = -1;
        system("pause");
    }
    return indice;
}

/** \brief Menu para elegir que parametro del eEmpleado modificar
 *
 * \return int opcion, la opcion elegida por el usuario
 *
 */
int menuModificarEmpleado()
{

    int opcion;
    do
    {
        system("cls");
        printf("- - - - - MODIFICACION DE EMPLEADO - - - - -\n");
        printf("Menu de opciones:\n");
        printf("1. Modificar nombre\n");
        printf("2. Modificar apellido\n");
        printf("3. Modificar sueldo\n");
        printf("4. Modificar sector\n");
        printf("5. Salir\n\n");
        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    while (opcion > 5);

    return opcion;

}

/** \brief Pone el flag isEmpty en true de un elemento del vector seleccionado por ID
 *
 * \param vec[] es eEmpleado, es vector de empleados
 * \param tam es int, tamaño del vector a recorrer
 * \return devuelve 1 si pudo hacer la baja
 *
 */
int bajaempleado (eEmpleado vec[], int tam)
{
    int todoOk = 0;
    int id;
    int indice;

    system("cls");
    printf("- - - - - BAJA DE EMPLEADO - - - - -\n");
    validaInt("Ingrese ID del empleado a borrar o 0 para ver nomina completa: ",
              "Error, debe ingresar un numero positivo\nIngrese ID del empleado a borrar o 0 para ver nomina completa: ",0, &id);

    indice = elegirEmpleado(vec, tam, id, "dar de baja");

    if (indice >= 0)
    {
        vec[indice].isEmpty = 1;
        printf("Se dio de baja el empleado\n");
        system("pause");
        todoOk = 1;
    }

    return todoOk;
}



/** \brief Ordena el vector de empleados segun su ID
 *
 * \param vec[] es eEmpleado, es vector de empleados
 * \param tam es int, tamaño del vector a recorrer
 *
 */
void ordenarEmpleadosId(eEmpleado vec[], int tam)
{

    eEmpleado auxiliar;

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (vec[i].id >vec[j].id)
            {
                auxiliar = vec[i];
                vec[i] = vec[j];
                vec[j] = auxiliar;
            }
        }
    }
}
