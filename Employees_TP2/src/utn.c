/*
 * utn.c
 *
 *  Created on: 27 sept. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int getDescription(char* cadena, int len);
static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int getNameOrSurname(char* cadena, int len);
static int getString(char* cadena, int len);
static int isNameOrSurname(char* cadena, int len);
static int isNumericInt(char* cadena, int len);
static int isNumericFloat(char* cadena, int len);
static int isDescription(char* cadena, int len);


/**
 * \brief Solicita un nombre o apellido al usuario, luego de su verificaci�n devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria, donde se alojar� el resultado de la funci�n.
 * \param len Es la longitud del array resultado.
 * \param mensaje Mensaje a mostrar al usuario para el ingreso del nombre o apellido.
 * \param mensajeError Mensaje de error, en caso de que el nombre o apellido ingresado por el usuario sea err�neo.
 * \param reintentos Cantidad de reintentos.
 * \return Retorna 0 si obtuvo el nombre o apellido y -1 si tuvo alg�n error.
 *
 */
int utn_getNameOrSurname(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[4096];

	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos > -1)//Valida los datos de la funcion.
	{
		do{
			printf("%s", mensaje); //Mensaje a mostrar al usuario.
			if( !getNameOrSurname(bufferString,sizeof(bufferString))) //Si la funcion getNameorSurname obtiene un string valido como nombre, lo copia en buffer String
			{
				retorno = 0;
				strncpy(pResultado,bufferString,len);//Copia el resultado de la funcion getNameorSurname en el puntero de resultado.
				break;
			}
			else
			{
				printf("%s", mensajeError);//Mensaje a mostrar, si no obtiene un string valido como nombre o apellido.
				reintentos--; //Disminuye la cantidad de reintentos.
			}
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Obtiene una cadena v�lida como nombre o apellido.
 * \param pResultado Puntero al espacio de memoria, donde se alojar� el resultado de la funci�n.
 * \param len Define el tama�o de la cadena.
 * \return Retorna 0 si obtuvo el nombre o apellido y -1 si tuvo algun error.
 *
 */
static int getNameOrSurname(char* cadena, int len)
{
    int retorno=-1;
    char bufferString[4096];

    if( cadena != NULL && //Valida que el puntero sea valido.
    	len > 0 && //Valida que el tama�ano de cadena sea razonable.
    	!getString(bufferString,sizeof(bufferString)) && //Obtiene una cadena de stdin valida como String.
		isNameOrSurname(bufferString,sizeof(bufferString)) && //valida que bufferString sea valido como nombre o apellido.
		strnlen(bufferString,sizeof(bufferString)) < len)//Valida que el tama�o de bufferString sea menor que la longitud de cadena.
    	{
    		strncpy(cadena,bufferString,len); //Si cumple las validaciones, copia la informacion de bufferString en cadena.
			retorno = 0;
		}
    return retorno;
}
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un m�ximo de 'len - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida.
 * \param len Define el tama�o de la cadena.
 * \return Retorna 0 si se obtiene una cadena y -1 si tuvo alg�n error.
 *
 */
static int getString(char* cadena, int len)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && len > 0) //Valida que el puntero sea valido y que el tama�ano de cadena sea razonable.
	{
		fflush(stdin);//"Limpia" de datos basura a stdin.
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)//Obtiene la informacion de stdin.
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')//Si la anteultima posicion de bufferString es '\n' entra al IF.
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';//Cambia a \n por \0.
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)//Si el tama�o de bufferString es menor o mayor a la longitud de cadena entra al IF.
			{
				strncpy(cadena,bufferString,len); //Si cumple las validaciones, copia la informacion de bufferString en cadena.
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre o apellido v�lido.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tama�o de la cadena.
 * \return Retorna 1 si la cadena es v�lida y 0 si no lo es.
 *
 */
static int isNameOrSurname(char* cadena, int len)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tama�ano de cadena sea razonable.
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)//Itera 'i' hasta mientras sea distinta de '\0' y respetando el tama�o del array.
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))//Valida que cadena sea solo letras(Mayus y Minus).
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un CUIT al usuario, luego de su verificaci�n devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria, donde se alojar� el resultado de la funci�n.
 * \param len Es la longitud del array resultado.
 * \param mensaje mensaje Mensaje a mostrar al usuario para el ingreso del CUIT.
 * \param mensajeError Mensaje de error, en caso de que el CUIT ingresado por el usuario sea err�neo.
 * \param reintentos Cantidad de reintentos.
 * \return Retorna 0 si obtuvo el nombre o apellido y -1 si tuvo alg�n error.
 *
 */

/**
 * \brief Solicita un numero al usuario, luego de su verificaci�n devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria, donde se alojar� el resultado de la funci�n.
 * \param mensaje Mensaje a mostrar al usuario para el ingreso del numero.
 * \param mensajeError Mensaje de error, en caso de que el n�mero ingresado por el usuario sea err�neo.
 * \param minimo Es el numero maximo a ser aceptado.
 * \param maximo Es el minimo minimo a ser aceptado.
 * \return Retorna 0 si obtuvo el nombre o apellido y -1 si tuvo alg�n error.
 *
 */
int utn_getNumberInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos > -1)//Valida los datos de la funcion.
	{
		do
		{
			printf("%s",mensaje);
			if(	!getInt(&bufferInt) && //Obtiene un numero entero.
				bufferInt >= minimo && //Valida que el buffer sea mayor o igual al minimo.
				bufferInt <= maximo) //Valida que el buffer sea menor o igual al maximo.
			{
				retorno = 0;
				*pResultado = bufferInt;//Si cumple las validaciones, copia la informacion de bufferInt al puntero de resultado.
				break;
			}
			else
			{
				printf("%s",mensajeError);//Mensaje a mostrar, si no obtiene un string valido como numero entero.
				reintentos--;//Disminuye la cantidad de reintentos.
			}
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Obtiene una cadena v�lida como un numero entero.
 * \param pResultado Puntero al espacio de memoria, donde se alojar� el resultado de la funci�n.
 * \return Retorna 0 si obtuvo el numero entero y -1 si tuvo alg�n error.
 *
 */
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];//*************************************

    if(	pResultado != NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&//Obtiene una cadena de stdin valida como String.
		isNumericInt(bufferString,sizeof(bufferString)))//valida que bufferString sea valido como numerico entero.
	{
		retorno=0;
		*pResultado = atoi(bufferString);//Transforma a tipo de variable entero a bufferString y se lo asigna al puntero de resultado.
	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un numero entero v�lido.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tama�o de la cadena.
 * \return Retorna 1 si la cadena es un numero entero y 0 si no lo es.
 *
 */
static int isNumericInt(char* cadena, int len)
{
	int retorno = 0;
	int i;
	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tama�ano de cadena sea razonable.
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))//Valida que la primer posicion de la cadena pueda ser - o +
			{
				continue;//Itera una vez mas.
			}
			if(cadena[i] < '0'||cadena[i] > '9')//Valida que el contenido sea numerico.
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una descripci�n al usuario, luego de su verificaci�n devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria, donde se alojar� el resultado de la funci�n.
 * \param len Es la longitud del array resultado.
 * \param mensaje Mensaje a mostrar al usuario para el ingreso de la descripci�n.
 * \param mensajeError Mensaje de error, en caso de que la descripci�n ingresada por el usuario sea err�nea.
 * \param reintentos Cantidad de reintentos.
 * \return Retorna 0 si obtuvo la descripci�n y -1 si tuvo alg�n error.
 *
 */
int utn_getDescription(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[4096];

	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos > -1)//Valida los datos de la funcion.
	{
		do{
			printf("%s", mensaje);
			if( !getDescription(bufferString,sizeof(bufferString)) )//Obtiene una descripcion en bufferString.
			{
				retorno = 0;
				strncpy(pResultado,bufferString,len);//Si cumple las validaciones, copia la informacion de bufferString al puntero de resultado.
				break;
			}
			else
			{
				printf("%s", mensajeError);//Mensaje a mostrar, si no obtiene un string valido descripcion.
				reintentos--;//Disminuye la cantidad de reintentos.
			}
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Obtiene una cadena v�lida como una descripci�n.
 * \param pResultado Puntero al espacio de memoria, donde se alojar� el resultado de la funci�n.
 * \param len Define el tama�o de la cadena.
 * \return Retorna 0 si obtuvo la descripci�n y -1 si tuvo algun error.
 *
 */
static int getDescription(char* cadena, int len)
{
    int retorno=-1;
    char bufferString[4096];

    if( cadena != NULL &&//Valida que el puntero sea valido.
    	len > 0 &&//Valida que el tama�ano de cadena sea razonable.
    	!getString(bufferString,sizeof(bufferString)) &&//Obtiene una cadena de stdin valida como String.
		isDescription(bufferString,sizeof(bufferString)) &&//valida que bufferString sea valido como descripcion.
		strnlen(bufferString,sizeof(bufferString)) < len)//Valida que el tama�o de bufferString sea menor que la longitud de cadena.
    	{
    		strncpy(cadena,bufferString,len);//Si cumple las validaciones, copia la informacion de bufferString en cadena.
			retorno = 0;
		}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripci�n.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tama�o de la cadena.
 * \return Retorna 1 si la cadena es v�lida y 0 si no lo es.
 *
 */
static int isDescription(char* cadena, int len)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tama�ano de cadena sea razonable.
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if( cadena[i] != '.' &&
				cadena[i] != ',' &&
				cadena[i] != ' ' &&
				(cadena[i] < 'A' || cadena[i] > 'Z' ) &&
				(cadena[i] < 'a' || cadena[i] > 'z' ) &&
				(cadena[i] < '0' || cadena[i] > '9' ) )//Valida que lo recibido en cadena, sean '.', ',', ' ', letras o numeros.
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, luego de su verificaci�n devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria, donde se alojar� el resultado de la funci�n.
 * \param mensaje Mensaje a mostrar al usuario para el ingreso del numero.
 * \param mensajeError Mensaje de error, en caso de que el n�mero ingresado por el usuario sea err�neo.
 * \param minimo Es el numero maximo a ser aceptado.
 * \param maximo Es el minimo minimo a ser aceptado.
 * \return Retorna 0 si obtuvo el numero entero y -1 si tuvo alg�n error.
 *
 */
int utn_getNumberFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos > -1)//Valida los datos de la funcion.
	{
		do
		{
			printf("%s",mensaje);
			if(	!getFloat(&bufferFloat) && //Obtiene un numero flotante.
				bufferFloat >= minimo && //Valida que el buffer sea mayor o igual al minimo.
				bufferFloat <= maximo) //Valida que el buffer sea menor o igual al maximo.
			{
				retorno = 0;
				*pResultado = bufferFloat;//Si cumple las validaciones, copia la informacion de bufferInt al puntero de resultado.
				break;
			}
			else
			{
				printf("%s",mensajeError);//Mensaje a mostrar, si no obtiene un string valido como numero entero.
				reintentos--;//Disminuye la cantidad de reintentos.
			}
		}while(reintentos>=0);
	}
	return retorno;
}

/**
 * \brief Obtiene una cadena v�lida como un numero flotante.
 * \param pResultado Puntero al espacio de memoria, donde se alojar� el resultado de la funci�n.
 * \return Retorna 0 si obtuvo el numero flotante y -1 si tuvo alg�n error.
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[50];//*************************************

    if(	pResultado != NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&//Obtiene una cadena de stdin valida como String.
		isNumericFloat(bufferString,sizeof(bufferString)))//valida que bufferString sea valido como numerico flotante.
	{
		retorno=0;
		*pResultado = atof(bufferString);//Transforma a tipo de variable flotante a bufferString y se lo asigna al puntero de resultado.
	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un numero flotante v�lido.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tama�o de la cadena.
 * \return Retorna 1 si la cadena es un numero flotante y 0 si no lo es.
 *
 */
static int isNumericFloat(char* cadena, int len)
{
	int retorno = 0;
	int i;
	int contadorPuntos = 0;
	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tama�ano de cadena sea razonable.
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))//Valida que la primer posicion de la cadena pueda ser - o +
			{
				continue;//Itera una vez mas.
			}
			if(cadena[i] < '0'||cadena[i] > '9')//Valida que el contenido sea numerico.
			{
				if(cadena[i] == '.' && contadorPuntos == 0)//Valida que solo exista un punto (Separador de decimales).
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
