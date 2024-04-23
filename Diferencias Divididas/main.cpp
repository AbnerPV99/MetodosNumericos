#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <math.h>
#include <iomanip>
//Autor: Abner Andres Perez Villatoro
//Carne: 9490-17-11829
int i, j, m, n, respuesta;
double p, g, a, xint;
//Le pide el ingreso de los datos al usuario
void ingresoDatos(){
	std::cout << "\tDIFERENCIAS DIVIDIDAS \nIngrese la cantidad n de elementos: ";
	std::cin >> n;
	double x[n];
	double y[n];
	double matrizT[n][n];
	for (i = 0; i < n; i++){
		std::cout << "Ingrese el valor de x[" << i << "]: ";
		std::cin >> x[i];
		std::cout << "Ingrese el valor de y[" << i << "]: ";
		std::cin >> y[i];
	}
	std::cout << "Ingrese el valor de x a interpolar: ";
	std::cin >> xint;
	//Carga de tabla de diferencias divididas
	m = n-1;
	for (i = 0; i <= m-1; i++){
		matrizT[i][0] = (y[i+1] - y[i]) / (x[i+1] - x[i]);	
	}
	
	for (j = 1; j <= m - 1; j++){
	
		for (i = j; i <= m - 1; i++){
			matrizT[i][j] = (matrizT[i][j-1] - matrizT[i-1][j-1]) / (x[i+1] - x[i-j]);			
		}
	}
	
	a = y[0];
	std::cout << "a(0) = " << a << "\n"; //Muestra el valor de a0
	for (i = 0; i < n-1; i++){
		p = 1;
		for (j = 0; j <= i; j++){
			p = p * (xint - x[j]);
		}
		std::cout << "a(" << i + 1 << ") = "<< matrizT[i][i] << "\n"; //Muestra los siguientes valores de a
		a = a + matrizT[i][i] * p;
	}
	
	std::cout << "El valor interpolado para x = " << xint << " es " << a;
}

int main() {
	do {
		ingresoDatos(); //Se le pide al usuario que ingrese los datos
		std::cout << "\n¿Desea ingresar nuevos datos? \n 1) Si 0) No \nIngrese un numero: ";
		std::cin >> respuesta;
		system("cls"); //Limpia la consola
	}while (respuesta != 0); //Mientras la respuesta no sea 0 que el programa siga ejecutandose
	return 0;
}
