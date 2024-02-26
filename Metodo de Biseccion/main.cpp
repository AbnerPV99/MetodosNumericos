//Autor: Abner Andres Perez Villatoro
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <math.h>
#include <iomanip>

int i, IT, respuesta;
double a, b, p, TOL, FP, FA, error;

//Evalua la funcion f(x) = xcos(x) - 2x^2 + 3x - 1 y devuelve una variable double
double f(double x){
	//return (x*cos(x) - 2*(pow(x,2)) + (3*x) - 1);
	return pow(2,p) - 6*cos(p);
}
//Se ingresan los valores de los limites inferiores y superiores junto con la Tolerancia y se calcula f(a)
void ingresoDatos(){
	std::cout << "Metodo de Biseccion \nIngrese el limite inferior a: ";
	std::cin >> a;
	std::cout << "Ingrese el limite superior b: ";
	std::cin >> b;
	std::cout << "Ingrese la Tolerancia: ";
	std::cin >> TOL;
	std::cout << "Ingrese la cantidad maxima de iteraciones: ";
	std::cin >> IT;
	FA = f(a);
}
//Agrega y alinea los titulos de cada columna para la tabla que se va a mostrar
void cabecera(){
	std::cout << std::left << std::setw(15) << "\nIteracion" 
	<< std::left << std::setw(20) << "|a" 
	<< std::left << std::setw(20) << "|b" 
	<< std::left << std::setw(20) << "|p" 
	<< std::left << std::setw(25) << "|f(p)" 
	<< "|Error\n";
}
//Muestra los datos de cada iteracion en una nueva linea. 
void tabla(){
	std::cout << std::left << std::setw(15) << i //Se usa la funcion setw() para alinear los datos a la izquierda
	<< std::left << std::setw(20) << std::setprecision(16) << a //Se usa la funcion setprecision() para que los datos muestren una cantidad especifica de decimales
	<< std::left << std::setw(20) << std::setprecision(16) << b 
	<< std::left << std::setw(20) << std::setprecision(16) << p 
	<< std::left << std::setw(25) << std::setprecision(16) << FP 
	<< std::left << std::setw(20) << std::setprecision(16) << error << "\n"; //Se inserta una nueva linea para que muestre los datos de la siguiente iteracion
}
//Esta funcion aplica el Metodo de la Biseccion
void algoritmoBiseccion(){
	i = 1;
	while (i <= IT){
		p = (a + b)/2; //Calcula el punto p
		FP = f(p); //Evalua la funcion en el punto p
		error = fabs((b-a)/2);
		if (FP == 0 || fabs((b-a)/2) < TOL){
			tabla(); //Si es exitoso que muestre los datos de la iteracion actual
			std::cout << "\nAproximacion alcanzada con exito: " << p << "\nf(p) = " << FP << "\nIntentos: " << i; //Procedmiento finalizado con exito
			break; //Sale del ciclo While
		}
		tabla(); //Muestra los datos de la iteracion actual antes de pasar a la siguiente iteracion
		i++;
		if (FA * FP > 0){
			a = p;
			FA = FP;
		}
		else{
			b = p;
		}
	}
	//Si el contador sobrepasa el numero de iteraciones, que muestre este mensaje
	if (i > IT){
			std::cout << "El metodo fracaso despues de " << i << " iteraciones";
	}
}
int main() {
	do {
		ingresoDatos(); //Se le pide al usuario que ingrese los datos
		cabecera(); //Muestra en pantalla los titulos de cada columna
		algoritmoBiseccion(); //Evalua el algoritmo y va mostrando en pantalla los datos de cada iteracion
		std::cout << "\nDesea realizar otra busqueda? \n 1) Si 0) No \nIngrese un numero: ";
		std::cin >> respuesta;
		system("cls"); //Limpia la consola
	}while (respuesta != 0); //Mientras la respuesta no sea 0 que el programa siga ejecutandose
	return 0;
}
