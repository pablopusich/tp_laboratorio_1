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
	int id;
	int auxIndice;

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
						        }


					}

			}while(opcion != 5);

	return EXIT_SUCCESS;
}
