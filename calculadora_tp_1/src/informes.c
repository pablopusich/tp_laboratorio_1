/*
 * informes.c
 *
 *  Created on: 8 sep. 2020
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>


/** \brief Efectua informe de la suma.
* \param float X Primer parametro ,primer numero ingresado por el usuario.
* \param float Y Segundo parametro, segundo numero ingresado por el usuario.
* \param float informeResultadoSuma tercer parametro, resultado de la suma efectuada en el programa.
*/
void informeResultadoSuma(float X ,float Y ,float parResultadoSuma){
	printf("El resultado de la suma entre %.2f y %.2f es: %.2f \n" , X, Y, parResultadoSuma);
}

/** \brief Efectua informe de la resta.
* \param float X Primer parametro ,primer numero ingresado por el usuario.
* \param float Y Segundo parametro, segundo numero ingresado por el usuario.
* \param float parametroResutadoResta tercer parametro, resultado de la resta efectuada en el programa.
*/
void informeResultadoResta(float X, float Y, float parResutadoResta){
	printf("El resultado de la resta entre %.2f y %.2f es: %.2f \n" , X, Y, parResutadoResta);
}


/** \brief Efectua informe de la multiplicacion.
* \param float X Primer parametro ,primer numero ingresado por el usuario.
* \param float Y Segundo parametro, segundo numero ingresado por el usuario.
* \param float parametroResutadoResta tercer parametro, resultado de la multiplicacion efectuada en el programa.
*/
void informeResultadoMultiplicacion(float X, float Y, float parResutadoMultiplicacion){
	printf("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f \n" , X, Y, parResutadoMultiplicacion);
}

/** \brief Efectua informe de la division.
  	 con dichos parametros.
* \param float X Primer parametro ,primer numero ingresado por el usuario.
* \param float Y Segundo parametro, segundo numero ingresado por el usuario.
* \param float parametroResutadoResta tercer parametro, resultado de la division efectuada en el programa.
*/
void informeResultadoDivisionExito(float X, float Y, float parResutadoMultiplicacion){
	printf("El resultado de la division entre %.2f y %.2f es: %.2f \n" , X, Y, parResutadoMultiplicacion);
}

/** \brief Efectua el mensaje del resultado de la operacion division si esta misma da error(Segundo parametro es igual a 0),
  	 con dichos parametros.
*/
void informeResultadoDivisionError(){
	printf("ERROR! imposible dividir por 0 \n");
}


/** \brief Efectua el mensaje del resultado de la operacion division si esta misma da error(Segundo parametro es igual a 0),
  	 con dichos parametros.
* \param float X Primer parametro ,primer numero ingresado por el usuario.
* \param float Y Segundo parametro, segundo numero ingresado por el usuario.
* \param float parametroNumeroUno tercer parametro, resultado del factorial del primer numero ingresado efectuado en el programa.
* \param float parametroNumeroDos cuarto parametro, resultado del factorial del segundo numero ingresado efectuado en el programa.
*/
void informeResultadosFactoriales(float X, float Y, float parametroNumeroUno, float parametroNumeroDos){
	printf("El Factorial de %.2f es: %.2f\n"
		   "El factorial de %.2f es: %.2f\n\n",X,parametroNumeroUno,Y,parametroNumeroDos);
}
