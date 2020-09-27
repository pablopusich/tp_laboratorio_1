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
#define QTY_EMPLOYEES 1000


int main(void) {
	setbuf(stdout,NULL);

	eEmployee arrayEmployees[QTY_EMPLOYEES];
	int opcion;

	do
			{
				if(!utn_getNumberInt(	&opcion,
									"\n1.Dar de alta un Cliente"
									"\n2.Modificar un Clientes"
									"\n3.Dar de baja un Cliente"
									"\n4.Informe"
									"\n5.Salir",
									"\nError opcion invalida",1,5,2) )
				{
					switch(opcion)
					{


					}
					}
			}while(opcion != 5);

	return EXIT_SUCCESS;
}
