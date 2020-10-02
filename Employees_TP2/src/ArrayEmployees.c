/*
 * ArrayEmployees.c
 *
 *  Created on: 27 sept. 2020
 *      Author: Pablo Pusich
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee list[], int len)
{
	int retorno = -1;
	int i;

		if(list!=NULL && len>0)
		{
			for(i=0;i<len;i++)
			{
				list[i].isEmpty = 1;
			}
			retorno = 0;
		}
	return retorno;
}

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param array Array de empleado a ser actualizado
 * \param limite Limite del array de empleados
 * \param len Posicion a ser actualizada
 * \param id Identificador asignado al empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int addEmployees(eEmployee* array,int len, int indice, int* id)
{
	int retorno = -1;
	eEmployee auxiliar;

	if(array != NULL && len > 0 && indice <= len)
		{
			if(	utn_getNameOrSurname(auxiliar.name, QTY_NAME, "Ingrese Nombre:\n", "Nombre invalido\n",2) == 0 &&
				utn_getNameOrSurname(auxiliar.lastName, QTY_SURNAME, "Ingrese Apellido: \n", "Apellido invalido\n",2) == 0 &&
				utn_getNumberFloat(&auxiliar.salary,"Ingrese salario:\n","Salario  invalido\n",0,500000,2) == 0 &&
				utn_getNumberInt(&auxiliar.sector, "Ingrese sector: \n" , "Sector  invalido\n", 1, 5, 2) == 0)
			{
				retorno = 0;
				array[indice] = auxiliar;
							array[indice].isEmpty = 0;
							array[indice].id = *id;
							*id = *id + 1;
						}
					}
					return retorno;
				}

/**
 * \brief Busca la primer posición vacia en el array de empleados.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \return Retorna el indice de la posicion vacia si encontró uno y -1 si obtuvo algún error o no existen indices vacios.
 *
 */
int emplo_getEmptyIndex(eEmployee list[], int len)
{
	int retorno = -1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;

}
/** \brief print the content of employees array.
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int emplo_printEmployees(eEmployee list[], int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)//Recorre el array para buscar empleados cargados.
		{
			if(list[i].isEmpty == 0)//Verifica que el indice se encuentre cargado.
			{
							printf("%s, %s - Salario: %.2f - Sector: %d - ID: %d\n",list[i].lastName,list[i].name,list[i].salary,list[i].sector,list[i].id);
						}
					}
					retorno = 0;
				}
				return retorno;
			}

/**
 * \brief Cuenta la cantidad de empleados existentes.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \return Retorna contador Retorna la cantidad de empleados encontrada y -1 si tuvo algún error.
 *
 */
int emplo_contadorEmployee(eEmployee list[], int len)
{
	int i;
	int contadorEmpleados = 0;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				contadorEmpleados++;
			}
		}
	}
	return contadorEmpleados;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int emplo_findEmployeeById(eEmployee list[], int len,int id)
{
	int retorno = -1;
	int i;
		if(list != NULL && len > 0 && id > -1)
		{
			for(i=0;i<len;i++)
			{
				if( list[i].id == id &&
					list[i].isEmpty == 0)
				{
					retorno = i;
					break;
				}
			}
		}
		return retorno;
}
/**
 * \brief Modifica los datos ingresados de un empleado por ID.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \param id Identificacion del cliente a modificar.
 * \param option para verificar que campo desea modificar.
 * \return Retorna 0 si modifico los datos del cliente correctamente y -1 si tuvo algún error.
 *
 */
int emplo_modifEmployee(eEmployee list[], int len, int id, int option)
{
	int retorno = -1;
	int i;
	eEmployee auxiliarEmpleado;
	if(list != NULL && len > 0 && id >= 0 && option > 0 && option < 5)
	{
		for(i=0;i<len;i++)
		{
			if( list[i].id == id &&
				list[i].isEmpty == 0)
			{
				if( option == 1 &&
					!utn_getNameOrSurname(auxiliarEmpleado.name,QTY_NAME,"Ingrese nombre: \n","Nombre incorrecto.\n",2))
				{
					retorno = 0;
					strncpy(list[i].name,auxiliarEmpleado.name,QTY_NAME);
					break;
				}
				else if( option == 2 &&
						 !utn_getNameOrSurname(auxiliarEmpleado.lastName,QTY_SURNAME,"Ingrese apellido: \n","Apellido incorrecto.\n",2))
				{
					retorno = 0;
					strncpy(list[i].lastName,auxiliarEmpleado.lastName,QTY_SURNAME);
					break;
				}
				else if( option == 3 &&
						!utn_getNumberFloat(&auxiliarEmpleado.salary,"Ingrese salario limite de 500.000: \n","Salario incorrecto.\n",0,500000,2))
				{
					retorno = 0;
					list[i].salary = auxiliarEmpleado.salary;
					break;
				}
				else if(option == 4 &&
						!utn_getNumberInt(&auxiliarEmpleado.sector,"Ingrese sector (1 a 5): \n","Sector incorrecto.\n",1,5,2))
				{
					retorno = 0;
					list[i].sector = auxiliarEmpleado.sector;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int emplo_removeEmployee(eEmployee list[], int len, int id)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0)
	{
		for(i=0;i<len;i++)
		{
			if( list[i].id == id &&
				list[i].isEmpty == 0)
			{
				retorno = 0;
				list[i].isEmpty = 1;
				break;
			}
		}
	}
	return retorno;
}
/** \brief Sort the elements in the array of employees, LastName and Sector
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [2] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void emplo_sortEmployees(eEmployee list[], int len)
{
	int swap;
	int i;
	eEmployee auxiliar;
	int auxiliarCmpEmpleados;

if(list!=NULL && len>0)
	{
		do{
			swap = 0;
			for(i=0;i<len-1;i++)
			{
				auxiliarCmpEmpleados = strncmp(list[i].lastName,list[i+1].lastName,QTY_SURNAME);
				if(auxiliarCmpEmpleados > 0 || (auxiliarCmpEmpleados == 0 && list[i].sector > list[i+1].sector))
				{
					swap = 1;
					auxiliar = list[i];
					list[i] = list[i+1];
					list[i+1]=auxiliar;
				}
			}
			len--;
		}while(swap);
	printf("Lista ordenada por Apellido y Sector.\n");
	}
}

int emplo_totalSalariosYCantidadQueLoSupera(eEmployee list[], int len)
{
	int retorno = -1;
	int i;
	float acumuladorSalarios;
	int contadorEmployees;
	int contadorEmpleadosSalarioSuperior;
	float promedioSalarios;
contadorEmployees = 0;
	acumuladorSalarios = 0;
	contadorEmpleadosSalarioSuperior = 0;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				acumuladorSalarios += list[i].salary;
				contadorEmployees++;
			}
		}
if(contadorEmployees > 0)
		{
			promedioSalarios = acumuladorSalarios / (float)contadorEmployees;
		}

		for(i=0;i<len;i++)
		{
			if( list[i].isEmpty == 0 &&
				list[i].salary > promedioSalarios)
			{
				contadorEmpleadosSalarioSuperior++;
			}
		}
		retorno = 0;
	}
	printf("El total es: %.2f - El promedio es: %.2f\n",acumuladorSalarios,promedioSalarios);
		printf("La cantidad de empleados que superan el salario promedio es: %d\n",contadorEmpleadosSalarioSuperior);
		return retorno;
	}
