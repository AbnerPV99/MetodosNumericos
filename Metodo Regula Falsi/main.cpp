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
double q0, q1, q, p0, p1, p, TOL, errAbs;
//Funcion f(x)
double f(double x){
	//return pow(x,3) - 2*pow(x,2) - 5; //f(x) = x^3 – 2x^2 – 5 = 0
	//return x - cos(x); //f(x) = x - cos(x) = 0
	//return pow(x,3) + 3*pow(x,2) - 1; //f(x) = x^3 + 3x^2 - 1 = 0
	return x - 0.8 - 0.2*sin(x); //f(x) = x - 0.8 - 0.2sen(x)
}
//Le pide el ingreso de los datos al usuario
void ingresoDatos(){
	std::cout << "\tMETODO REGULA FALSI \nIngrese la aproximacion inicial p0: ";
	std::cin >> p0;
	std::cout << "Ingrese la aproximacion inicial p1: ";
	std::cin >> p1;
	std::cout << "Ingrese la Tolerancia: ";
	std::cin >> TOL;
	std::cout << "Ingrese la cantidad maxima de iteraciones: ";
	std::cin >> IT;
}
//Agrega y alinea los titulos de cada columna para la tabla que se va a mostrar
void cabecera(){
	std::cout << std::left << std::setw(15) << "\nIteracion" //Se usa la funcion setw() y left para alinear los datos a la izquierda
	<< std::left << std::setw(25) << "|q0"
	<< std::left << std::setw(25) << "|q1"
	<< std::left << std::setw(25) << "|p0"
	<< std::left << std::setw(25) << "|p1"
	<< std::left << std::setw(25) << "|p"
	<< std::left << std::setw(25) << "|q"
	<< "|Error Absoluto\n";
}
//Muestra los datos de cada iteracion en una nueva linea.
void tabla(){
	std::cout << std::left << std::setw(15) << i 
	<< std::left << std::setw(25) << std::setprecision(16) << q0 //Se usa la funcion setprecision() para que los datos muestren una cantidad especifica de decimales
	<< std::left << std::setw(25) << std::setprecision(16) << q1
	<< std::left << std::setw(25) << std::setprecision(16) << p0
	<< std::left << std::setw(25) << std::setprecision(16) << p1
	<< std::left << std::setw(25) << std::setprecision(16) << p
	<< std::left << std::setw(25) << std::setprecision(16) << q
	<< std::left << std::setw(25) << std::setprecision(16) << errAbs << "\n"; //Se inserta una nueva linea para que muestre los datos de la siguiente iteracion
}
//Ejecuta el algoritmo aplicando el metodo Regula Falsi
void algoritmoRegulaFalsi(){
	i = 2;
	q0 = f(p0); //Valua la funcion en p0 y lo almacena en q0
	q1 = f(p1); //Valua la funcion en p1 y lo almacena en q1
	while (i <= IT){
		p = p1 - q1*((p1-p0)/(q1-q0));
		q = f(p); //Valua la funcion en p y lo almacena en q
		errAbs = fabs(p-p1); //Calcula el error absoluto
		if (errAbs < TOL){ //Si el error es menor a la tolerancia
			tabla(); //Muestra en pantalla los datos de la iteracion
			std::cout << "\n\tSOLUCION: Iteraciones: " << i << " p = " << p << " f(p) = " << q;
			break; //Sale del bucle
		}
		tabla(); //Muestra en pantalla los datos de la iteracion
		i++;
		if ((q * q1) < 0){ //Si q multiplicado por q1 es menor a 0
			p0 = p1; 
			q0 = q1; 
		}
		p1 = p;
		q1 = q;
	}
	if(i > IT){
		std::cout << "El metodo fallo despues de " << IT << " iteraciones";
	}
}

int main() {
	do {
		ingresoDatos(); //Se le pide al usuario que ingrese los datos
		cabecera(); //Muestra en pantalla los titulos de cada columna
		algoritmoRegulaFalsi(); //Evalua el algoritmo y va mostrando en pantalla los datos de cada iteracion
		std::cout << "\nDesea realizar otra busqueda? \n 1) Si 0) No \nIngrese un numero: ";
		std::cin >> respuesta;
		system("cls"); //Limpia la consola
	}while (respuesta != 0); //Mientras la respuesta no sea 0 que el programa siga ejecutandose
	return 0;
}
