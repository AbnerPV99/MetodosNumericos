#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <math.h>
#include <iomanip>
//Autor: Abner Andres Perez Villatoro
//Carne: 9490-17-11829
int i, IT, respuesta;
double x0, x1, x2, h1, h2, s1, s2, d, b, D, E, h, p, FP, TOL, errAbs;
//Funcion f(x)
double f(double x){
	//return pow(x,5) +11*pow(x,4) -21*pow(x,3) -10*pow(x,2) -21*x -5; //f(x) = x^5 + 11x^4 - 21x³ - 10x² - 21x - 5
	return pow(x, 4) + pow(x, 3) + 3*pow(x, 2) + 2*x + 2; //f(x) =x^4 + x³ + 3x² + 2x + 2
	//return pow(x, 3) - 9*pow(x, 2) + 12; //f(x) = x³ - 9x² + 12
}
//Le pide el ingreso de los datos al usuario
void ingresoDatos(){
	std::cout << "\tMETODO DE MULLER \nIngrese el valor inicial x0: ";
	std::cin >> x0;
	std::cout << "Ingrese el valor inicial x1: ";
	std::cin >> x1;
	std::cout << "Ingrese el valor inicial x2: ";
	std::cin >> x2;
	std::cout << "Ingrese la Tolerancia: ";
	std::cin >> TOL;
	std::cout << "Ingrese la cantidad maxima de iteraciones: ";
	std::cin >> IT;
}
//Agrega y alinea los titulos de cada columna para la tabla que se va a mostrar
void cabecera(){
	std::cout << std::left << std::setw(15) << "\nIteracion" //Se usa la funcion setw() y left para alinear los datos a la izquierda
	<< std::left << std::setw(25) << "|p"
	<< std::left << std::setw(25) << "|f(p)"
	<< "|Error Absoluto\n";
}
//Muestra los datos de cada iteracion en una nueva linea.
void tabla(){
	std::cout << std::left << std::setw(15) << i 
	<< std::left << std::setw(25) << std::setprecision(16) << p //Se usa la funcion setprecision() para que los datos muestren una cantidad especifica de decimales
	<< std::left << std::setw(25) << std::setprecision(16) << FP
	<< std::left << std::setw(25) << std::setprecision(16) << errAbs << "\n"; //Se inserta una nueva linea para que muestre los datos de la siguiente iteracion
}
//Ejecuta el algoritmo aplicando el metodo de Muller
void algoritmoMuller(){
	i = 3;
	h1 = x1 - x0;
	h2 = x2 - x1;
	s1 = (f(x1) - f(x0)) / h1;
	s2 = (f(x2) - f(x1)) / h2;
	d = (s2 - s1) / (h2 + h1); 
	while (i <= IT){
		b = s2 + h2*d;
		D = sqrt((pow(b,2) - 4*f(x2)*d));
		if (fabs(b - D) < fabs(b + d)){
			E = b + D;
		}
		else{
			E = b - D;
		}
		h = (-2*f(x2)) / E;
		p = x2 + h;
		FP = f(p); //Valua la funcion f en p
		errAbs = fabs((p - x2) / p); //Calcula el error absoluto
		if (fabs(h) < TOL){
			tabla(); //Muestra en pantalla los datos de la iteracion
			std::cout << "\n\tSOLUCION: p = " << p << " f(p) = " << FP;
			break; //Sale del bucle
		}
		tabla(); //Muestra en pantalla los datos de la iteracion
		x0 = x1; 
		x1 = x2; 
		x2 = p;
		h1 = x1 - x0;
		h2 = x2 - x1;
		s1 = (f(x1) - f(x0)) / h1;
		s2 = (f(x2) - f(x1)) / h2;
		d = (s2 - s1) / (h2 + h1);
		i++;
	}
	if(i > IT){
		std::cout << "El metodo fallo despues de " << IT << " iteraciones";
	}
}

int main() {
	do {
		ingresoDatos(); //Se le pide al usuario que ingrese los datos
		cabecera(); //Muestra en pantalla los titulos de cada columna
		algoritmoMuller(); //Evalua el algoritmo y va mostrando en pantalla los datos de cada iteracion
		std::cout << "\nDesea realizar otra busqueda? \n 1) Si 0) No \nIngrese un numero: ";
		std::cin >> respuesta;
		system("cls"); //Limpia la consola
	}while (respuesta != 0); //Mientras la respuesta no sea 0 que el programa siga ejecutandose
	return 0;
}
