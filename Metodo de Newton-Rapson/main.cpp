#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <math.h>
#include <iomanip>
//Autor: Abner Andres Perez Villatoro
int i, IT, respuesta;
double p0, p, TOL, FP, FP0, errAbs;

double f(double p){
	//return pow(p,4) - 3*pow(p,2) - 3; //f(x) = x^4 - 3x^2 - 3
	//return pow(p,3) -2*pow(p,2) - 5; //f(x) =x^3 - 2x^2 -5
	//return pow(2,p) - 6*cos(p); //f(x) =2^x - 6cos(x)
	return 230*pow(p,4) + 18*pow(p,3) + 9*pow(p,2) - 221*p -9; //f(x) =230x^4 + 18x^3 + 9x^2 - 221x - 9
}

double fderivado(double p){
	//return 4*pow(p,3) - 6*p; //f'(x) = 4x^3 - 6x
	//return 3*pow(p,2) - 4*p; //f'(x) = 3x^2 - 4x
	//return pow(2,p)*log(2) + 6*sin(p); //f'(x) = 2^x * Ln(2) + 6sen(x)
	return 920*pow(p,3) + 54*pow(p,2) + 18*p - 221; //f'(x) = 920x^3 + 54x^2 + 18x - 221
}

void ingresoDatos(){
	std::cout << "\tMETODO DE NEWTON-RAPSON \nIngrese el valor inicial p0: ";
	std::cin >> p0;
	std::cout << "Ingrese la Tolerancia: ";
	std::cin >> TOL;
	std::cout << "Ingrese la cantidad maxima de iteraciones: ";
	std::cin >> IT;
}
//Agrega y alinea los titulos de cada columna para la tabla que se va a mostrar
void cabecera(){
	std::cout << std::left << std::setw(15) << "\nIteracion" //Se usa la funcion setw() y left para alinear los datos a la izquierda
	<< std::left << std::setw(25) << "|p0" 
	<< std::left << std::setw(25) << "|f(p0)" 
	<< std::left << std::setw(25) << "|p" 
	<< std::left << std::setw(25) << "|f(p)" 
	<< "|Error Absoluto\n";
}
//Muestra los datos de cada iteracion en una nueva linea.
void tabla(){
	std::cout << std::left << std::setw(15) << i 
	<< std::left << std::setw(25) << std::setprecision(16) << p0 //Se usa la funcion setprecision() para que los datos muestren una cantidad especifica de decimales
	<< std::left << std::setw(25) << std::setprecision(16) << FP0 
	<< std::left << std::setw(25) << std::setprecision(16) << p
	<< std::left << std::setw(25) << std::setprecision(16) << FP
	<< std::left << std::setw(25) << std::setprecision(16) << errAbs << "\n"; //Se inserta una nueva linea para que muestre los datos de la siguiente iteracion
}

void algoritmoNewtonRapson(){
	i = 1;
	while (i <= IT){
		p = (p0 - (f(p0)/fderivado(p0))); //Calcula el valor de p
		errAbs = fabs((p - p0)/p); //Calcula el error absoluto
		FP = f(p); //Evalua p en la funcion original f(x)
		FP0 = f(p0); //Evalua p0 en la funcion original f(x)
		if (fabs(p - p0) < TOL){
			tabla(); //Muestra en pantalla los datos de la iteracion
			std::cout << "\n\tSOLUCION: p = " << p << " f(p) = " << FP;
			break; //Sale del bucle
		}
		tabla(); //Muestra en pantalla los datos de la iteracion
		i++;
		p0 = p; //El valor de p se convierte en el siguiente valor inicial
	}
	if(i > IT){
		std::cout << "El metodo fracaso";
	}
}

int main() {
	do {
		ingresoDatos(); //Se le pide al usuario que ingrese los datos
		cabecera(); //Muestra en pantalla los titulos de cada columna
		algoritmoNewtonRapson(); //Evalua el algoritmo y va mostrando en pantalla los datos de cada iteracion
		std::cout << "\nDesea realizar otra busqueda? \n 1) Si 0) No \nIngrese un numero: ";
		std::cin >> respuesta;
		system("cls"); //Limpia la consola
	}while (respuesta != 0); //Mientras la respuesta no sea 0 que el programa siga ejecutandose
	return 0;
}
