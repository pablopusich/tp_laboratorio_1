/*
 * ArrayEmployees.c
 *
 *  Created on: 27 sept. 2020
 *      Author: Usuario
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
 * \brief Busca la primer posici�n vacia en el array de empleados.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \return Retorna el indice de la posicion vacia si encontr� uno y -1 si obtuvo alg�n error o no existen indices vacios.
 *
 */
int emp_getEmptyIndex(eEmployee list[], int len)
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
int emp_printEmployees(eEmployee list[], int len)
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
 * \return Retorna contador Retorna la cantidad de empleados encontrada y -1 si tuvo alg�n error.
 *
 */
int emp_contadorEmployee(eEmployee list[], int len)
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


