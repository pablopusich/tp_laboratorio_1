/*
 ============================================================================
 Name        : Calculadora_tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "informes.h"
// \n

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	float A;
	float B;

	int respuestaSuma;
	float resultadoSuma;
	int respuestaResta;
	float resultadoResta;
	int respuestaMultiplicacion;
	float resultadoMultiplicacion;
	int respuestaDivision;
	float resultadoDivision;
	int respuestaFactorial;
	float resultadoFactorialUno;
	float resultadoFactorialDos;

	do{
	    printf("\n\n1.Ingrese Primer Numero.(A = %.2f)"
	    	   "\n2.Ingrese Segundo Numero.(B = %.2f)"
	    	   "\n3.Calcular Las Operaciones (todas)."
	    	   "\n4.Informar los Resultados."
	    	   "\n5.Salir.\n" , A, B
	    		);
	    printf("\nIngrese una opcion: ");
		scanf("%d",&opcion);

	      switch(opcion){
	          case 1:
	        	  A = getFloat("Ingrese el Primer Numero: ");
	          break;
	          case 2:
	        	  B = getFloat("Ingrese el Segundo Numero: ");
	          break;
	          case 3:
	        	  respuestaSuma = sumarNum(A,B,&resultadoSuma);
	        	  respuestaResta = restarNum(A,B,&resultadoResta);
	        	  respuestaMultiplicacion = multiplicarNum(A,B,&resultadoMultiplicacion);
	        	  respuestaDivision = dividirNum(A,B,&resultadoDivision);
	        	  respuestaFactorial = factorialNum(A,B,&resultadoFactorialUno,&resultadoFactorialDos);
	        	  printf("Operaciones exitosas.\n");
	          break;
	          case 4:
		        	 if(respuestaSuma == 0){
				        informeResultadoSuma(A,B,resultadoSuma);
		        	 }

		        	 if(respuestaResta == 0){
			        	  informeResultadoResta(A,B,resultadoResta);
		        	 }

		        	 if(respuestaMultiplicacion == 0){
			        	informeResultadoMultiplicacion(A,B,resultadoMultiplicacion);
		        	 }

					 if(respuestaDivision == 0){
						 informeResultadoDivisionExito(A,B,resultadoDivision);
					 }
					 else
					 {
						 informeResultadoDivisionError();
					 }

					 if (respuestaFactorial==0)
					 {
					 printf("El factorial de %.2f es: %.2f\n El factorial de %.2f es: %.2f",A,resultadoFactorialUno,B,resultadoFactorialDos);
					 }
			 break;
	      }

	}while(opcion !=5);

	return EXIT_SUCCESS;
}
