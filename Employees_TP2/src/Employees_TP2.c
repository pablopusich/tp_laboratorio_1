/*
 ============================================================================
 Name        : Employees_TP2.c
 Author      : Pablo Pusich
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
	int auxiliarInformes;

	 if(initEmployees(arrayEmployees,QTY_EMPLOYEES)==0){
		 printf("Array inicializado\n");
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
						        	auxIndice= emplo_getEmptyIndex(arrayEmployees,QTY_EMPLOYEES);
						        	if(auxIndice >= 0)
						        		{
						        		if(addEmployees(arrayEmployees,QTY_EMPLOYEES,auxIndice,&id)==0)
						        		{
						        		printf("registro efectuado con exito.\n");
						        		}
						        		else
						        		{
						        		printf("No hay lugares disponibles.\n");
						        	   }
						        	}

					break;
					case 2:

					if(emplo_contadorEmployee(arrayEmployees,QTY_EMPLOYEES) > 0 &&
						        	  !emplo_printEmployees(arrayEmployees,QTY_EMPLOYEES) &&
						        	  !utn_getNumberInt(&auxId,"ingrese el ID del cliente:\n","ID incorrecto\n",0,id,2) &&
						        	  emplo_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxId) > -1 &&
						        	  !utn_getNumberInt(&auxModificacion,"ingrese el campo que desea cambiar: \n"
						        													"1.-Nombre.\n"
						        													"2.-Apellido.\n"
						        													"3.-Salario.\n"
						        													"4.-Sector.\n","Opcion incorrecta\n",1,4,2) &&
						        	!emplo_modifEmployee(arrayEmployees,QTY_EMPLOYEES,auxId,auxModificacion))
						        	{
						        		printf("Modificacion exitosa.\n");
						        	}
						        	else
						        	{
						        	  printf("no hay empleados registrados\n");
						        	}
					break;
					case 3:
									if(	emplo_contadorEmployee(arrayEmployees,QTY_EMPLOYEES) > 0 &&
										!emplo_printEmployees(arrayEmployees,QTY_EMPLOYEES) &&
										!utn_getNumberInt(&auxId,"Ingrese ID del cliente a dar de baja:\n","ID invalido\n",0,id,2) &&
										emplo_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxId) > -1 &&
										!emplo_removeEmployee(arrayEmployees,QTY_EMPLOYEES,auxId))
									{
										printf("Baja de exitosa.\n");
									}
									else
									{
										printf("no hay empleados registrados\n");
									}

					break;
					case 4:
									if(emplo_contadorEmployee(arrayEmployees,QTY_EMPLOYEES) > 0 &&
							        	  !utn_getNumberInt(&auxiliarInformes,"Informes: \n"
							        				        							  "1.Lista de empleados ordenados alfabéticamente por Apellido y Sector.\n"
							        				        							  "2.Lista de salarios o.\n","Opcion Incorrecta",1,2,2))
							        	{

									if(auxiliarInformes == 1)
							        	{
							        		emplo_sortEmployees(arrayEmployees,QTY_EMPLOYEES);
							        		emplo_printEmployees(arrayEmployees,QTY_EMPLOYEES);
							        	}
							        	else {
							        		if(auxiliarInformes == 2)
							        		{
							        			emplo_totalSalariosYCantidadQueLoSupera(arrayEmployees,QTY_EMPLOYEES);
							        		}
							        	}
							        	}
							        	else{
							        		printf("No hay empleados registrados \n");
							        	}
					break;
									}

								}

					}while(opcion != 5);

	return EXIT_SUCCESS;
}
