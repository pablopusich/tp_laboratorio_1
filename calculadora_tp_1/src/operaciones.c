/*
 * operaciones.c
 *
 *  Created on: 8 sep. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>

/** \brief Solicita al usuario e inicializa una variable de tipo "float".
* \param Mensaje impreso al usuario.
* \return Numero ingresado por el usuario.
*
*/
float getFloat(char* mensaje)
{
	float bufferFloat;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%f",&bufferFloat);

	return bufferFloat;
}


/** \brief Efectua la suma.
* \param float X Primer parametro.
* \param float Y Segundo parametro .
* \return retorno si la operacion posee errores o no mediante -1/0.
*/
float sumarNum(float X, float Y,float* pResultado){
	int retorno=-1;
	float resultadoSuma;

	if(pResultado!=NULL){
		resultadoSuma = X+Y;
		*pResultado = resultadoSuma;
		retorno=0;
	}
	return retorno;
}

/** \brief Efectua la resta.
* \param float X Primer parametro.
* \param float Y Segundo parametro .
* \return retorno si la operacion posee errores o no mediante -1/0.
*/
float restarNum(float X, float Y,float* pResultado){
	int retorno=-1;
	float resultadoResta;

	if(pResultado!=NULL){
		resultadoResta = X-Y;
		*pResultado = resultadoResta;
		retorno=0;
	}
	return retorno;
}

/** \brief Efectua la multiplicación.
* \param float X Primer parametro.
* \param float Y Segundo parametro .
* \return retorno si la operacion posee errores o no mediante -1/0.
*/
float multiplicarNum(float X, float Y, float* pResultado){
	int retorno=-1;
	float resultadoMultiplicacion;

	if(pResultado!=NULL){
		resultadoMultiplicacion = X*Y;
		*pResultado = resultadoMultiplicacion;
		retorno=0;
	}
	return retorno;
}

/** \brief Efectua la división.
* \param float X Primer parametro.
* \param float Y Segundo parametro .
* \return retorno si la operacion posee errores o no mediante -1/0.
*/
float dividirNum(float X, float Y, float* pResultado){
	int retorno=-1;
	float resultadoDivision;

	if (pResultado!=NULL && Y!=0) {
		resultadoDivision=X/Y;
		*pResultado=resultadoDivision;
		retorno=0;
	}
	return retorno;
}

/**
* \brief Evalua que los operandos ingresados por el usuario que sean diferentes a 0  para poder realizar el factorial
* de dichos parametros.
* \param float X primer numero del usuario.
* \param float Y segundo numero del usuario.
* \param float* pResultado puntero que guarda el valor del primer factorial.
* * \param float* pResultado2 puntero que guarda el valor del segundo factorial.
* \return -1 o 0, si retorna -1 retorna un error ya que el operando es a 0 y no se podra realizar su factorial,
*  si devuelve un 0 la operacion puede ser exitosa y ejecuta el factorial de los dos parametros.
*
*/
int factorialNum(float X, float Y, float* pResultadoUno, float* pResultadoDos)
{
	int retorno=-1;
	float bufferFactorialUno = 1;
	float bufferFactorialDos = 1;
	int i;

		if(X!=0){
			for (i=1;i<=X;i++){
				bufferFactorialUno *=i;
				*pResultadoUno = bufferFactorialUno;
				retorno=0;
			}
		} else if (X==0){
			*pResultadoUno = 1;
		}

		if(Y!=0){
			for (i=1;i<=Y;i++){
				bufferFactorialDos *=i;
				*pResultadoDos  = bufferFactorialDos;
				retorno=0;
			}
		} else if (Y==0){
			*pResultadoDos = 1;
		}

	return retorno;
}


