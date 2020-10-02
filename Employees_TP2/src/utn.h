/*
 * utn.h
 *
 *  Created on: 27 sept. 2020
 *      Author: Pablo Pusich
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNameOrSurname(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);
int utn_getNumberInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumberFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getDescription(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);


#endif /* UTN_H_ */
