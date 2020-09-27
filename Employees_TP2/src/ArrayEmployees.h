/*
 * ArrayEmployees.h
 *
 *  Created on: 27 sept. 2020
 *      Author: Usuario
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define QTY_SURNAME 51
#define QTY_NAME 51



typedef struct
{
	 int id;
	 char name[QTY_NAME];
	 char lastName[QTY_SURNAME];
	 float salary;
	 int sector;
	 int isEmpty;
}eEmployee;

int initEmployees(eEmployee list[], int len);
int addEmployees(eEmployee* array,int len, int indice, int* id);
int emp_getEmptyIndex(eEmployee list[], int len);
int emp_printEmployees(eEmployee list[], int len);
int emp_contadorEmployee(eEmployee list[], int len);

#endif /* ARRAYEMPLOYEES_H_ */
