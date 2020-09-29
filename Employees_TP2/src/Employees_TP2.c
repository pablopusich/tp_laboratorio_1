/*
 ============================================================================
 Name        : Employees_TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define QTY_EMPLOYEES 2




int main(void) {
	setbuf(stdout,NULL);

	eEmployee arrayEmployees[QTY_EMPLOYEES];
	int opcion;
	int id = 0;
	int auxIndice;
	int auxId;
	int auxModificacion;

	 if(initEmployees(arrayEmployees,QTY_EMPLOYEES)==0){
		 printf("Array inicializado Correctamente.\n");
	 }

	do
			{
				if(!utn_getNumberInt(	&opcion,
									"\n1.Alta de Empleado"
									"\n2.Modificar un Empleado"
									"\n3.Dar de baja un Empleado"
									"\n4.Informe"
									"\n5.Salir",
									"\nError opcion incorrecta",1,5,2) )
				{
					switch(opcion)
					{
					case 1:
						        	auxIndice= emp_getEmptyIndex(arrayEmployees,QTY_EMPLOYEES);
						        	if(auxIndice >= 0)
						        		{
						        		if(addEmployees(arrayEmployees,QTY_EMPLOYEES,auxIndice,&id)==0)
						        		{
						        		printf("Carga realizada con exito.\n");
						        		}
						        		else
						        		{
						        		printf("No hay mas lugares libres.\n");
						        	   }
						        	}

					break;
					case 2:

					if(emp_contadorEmployee(arrayEmployees,QTY_EMPLOYEES) > 0 &&
						        	  !emp_printEmployees(arrayEmployees,QTY_EMPLOYEES) &&
						        	  !utn_getNumberInt(&auxId,"Por favor, ingrese el ID del cliente:\n","ID invalido\n",0,id,2) &&
						        	  emp_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxId) > -1 &&
						        	  !utn_getNumberInt(&auxModificacion,"Por favor, ingrese el campo que desea modificar: \n"
						        													"1.-Nombre.\n"
						        													"2.-Apellido.\n"
						        													"3.-Salario.\n"
						        													"4.-Sector.\n","Opcion invalida.\n",1,4,2) &&
						        	!emp_modifEmployee(arrayEmployees,QTY_EMPLOYEES,auxId,auxModificacion))
						        	{
						        		printf("Modificacion exitosa.\n");
						        	}
						        	else
						        	{
						        	  printf("NO HAY EMPLEADOS CARGADOS!!!\n");
						        	}
					break;
					case 3:
									if(	emp_contadorEmployee(arrayEmployees,QTY_EMPLOYEES) > 0 &&
										!emp_printEmployees(arrayEmployees,QTY_EMPLOYEES) &&
										!utn_getNumberInt(&auxId,"Ingrese el ID del cliente a dar de baja:\n","ID invalido\n",0,id,2) &&
										emp_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxId) > -1 &&
										!emp_removeEmployee(arrayEmployees,QTY_EMPLOYEES,auxId))
									{
										printf("Baja de exitosa.\n");
									}
									else
									{
										printf("NO HAY EMPLEADOS CARGADOS!!!\n");
									}
									break;
						        	}
				}



				}while(opcion != 5);

	return EXIT_SUCCESS;
}
