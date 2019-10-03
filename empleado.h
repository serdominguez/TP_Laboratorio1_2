#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;
} eEmpleado;

#endif // EMPLEADO_H_INCLUDED

//ABM empleado
int menuPrincipal();
int harcodeEmpleados (eEmpleado vec[], int tam, int cant);
void iniciaEmpleados(eEmpleado list[], int tam);
int altaEmpleado (eEmpleado list[], int tam, int id);
void mostrarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado empleado);
int buscarIndiceLibre (eEmpleado vec[], int tam);
int menuModificarEmpleado();
int modificarEmpleado (eEmpleado vec[], int tam);
int elegirEmpleado (eEmpleado vec[], int tam, int id, char* accion);
int bajaempleado (eEmpleado vec[], int tam);
void ordenarEmpleadosId(eEmpleado vec[], int tam);
