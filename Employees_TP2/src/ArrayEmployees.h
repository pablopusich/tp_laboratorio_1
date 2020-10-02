/*
 * ArrayEmployees.h
 *
 *  Created on: 27 sept. 2020
 *      Author: Pablo Pusich
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
int emplo_getEmptyIndex(eEmployee list[], int len);
int emplo_printEmployees(eEmployee list[], int len);
int emplo_contadorEmployee(eEmployee list[], int len);
int emplo_findEmployeeById(eEmployee list[], int len,int id);
int emplo_modifEmployee(eEmployee list[], int len, int id, int option);
int emplo_removeEmployee(eEmployee list[], int len, int id);
void emplo_sortEmployees(eEmployee list[], int len);
int emplo_totalSalariosYCantidadQueLoSupera(eEmployee list[], int len);


#endif /* ARRAYEMPLOYEES_H_ */
