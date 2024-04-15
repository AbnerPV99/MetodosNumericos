#include <iostream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <math.h>
#include <iomanip>
//Autor: Abner Andres Perez Villatoro
//Carne: 9490-17-11829
int i, n, respuesta;
double x[100], y[100], sumaX, sumaY, sumaXY, sumaX2, m, b, valorDeflexion, z;
//Agrega y alinea los titulos de cada columna para la tabla que se va a mostrar
void cabecera(){
	std::cout << std::left << std::setw(15) << "\n n" //Se usa la funcion setw() y left para alinear los datos a la izquierda
	<< std::left << std::setw(25) << "|x"
	<< std::left << std::setw(25) << "|y"
	<< std::left << std::setw(25) << "|xy"
	<< "|x^2\n";
}
//Muestra los datos de cada iteracion en una nueva linea.
void tabla(double x, double y){
	std::cout << std::left << std::setw(15) << i+1 
	<< std::left << std::setw(25) << std::setprecision(16) << x //Se usa la funcion setprecision() para que los datos muestren una cantidad especifica de decimales
	<< std::left << std::setw(25) << std::setprecision(16) << y
	<< std::left << std::setw(25) << std::setprecision(16) << x*y
	<< std::left << std::setw(25) << std::setprecision(16) << x*x << "\n"; //Se inserta una nueva linea para que muestre los datos de la siguiente iteracion
}
//Muestra la sumatoria de todas las columnas
void filaSumatoria(){
	std::cout << std::left << std::setw(15) << std::setprecision(16) << "Sumatorias: "
	<< std::left << std::setw(25) << std::setprecision(16) << sumaX
	<< std::left << std::setw(25) << std::setprecision(16) << sumaY
	<< std::left << std::setw(25) << std::setprecision(16) << sumaXY
	<< std::left << std::setw(25) << std::setprecision(16) << sumaX2 << "\n";
}
//Le pide el ingreso de los datos al usuario
void ingresoDatos(){
	std::cout << "\tMETODO DE MINIMOS CUADRADOS \nIngrese la cantidad n de elementos: ";
	std::cin >> n;
	for (i = 0; i < n; i++){
		std::cout << "Ingrese el valor de x[" << i << "]: ";
		std::cin >> x[i];
		std::cout << "Ingrese el valor de y[" << i << "]: ";
		std::cin >> y[i];
	}
	std::cout << "Ingrese el valor de deflexion x a evaluar: ";
	std::cin >> z;
}
//Ejecuta el algoritmo aplicando el metodo de Lagrange
void algoritmoMinimosCuadrados(){
	cabecera();
	sumaX = 0;
	sumaY = 0;
	sumaXY = 0;
	sumaX2 = 0;
	for (i = 0; i <= n-1; i++){
		tabla(x[i], y[i]); //Llama a la funcion tabla y rellena los datos conforme al indice de X y Y
		sumaX += x[i]; //Guarda la suma de x
		sumaY += y[i]; //Guarda la suma de y
		sumaXY += x[i] * y[i]; // Guarda la suma de la multiplicacion de XY
		sumaX2 += pow(x[i],2); //Guarda la suma de la potencia cuadrada de x
	}
	filaSumatoria();
	m = ((n * sumaXY) - (sumaX*sumaY)) / ((n * sumaX2) - (pow(sumaX, 2))); //Calcula m usando las variables en donde se guardaron las sumatorias
	b = (sumaY / n) -m * (sumaX / n); //Calcula b
	std::cout << "\nLa ecuacion de la recta es: " << m << "x + " << b << "\n";
	valorDeflexion = m*z + b;
	std::cout << "El valor de deflexion aproximado es: " << valorDeflexion << "\n";
}

int main() {
	do {
		ingresoDatos(); //Se le pide al usuario que ingrese los datos
		algoritmoMinimosCuadrados(); //Evalua el algoritmo y va mostrando en pantalla los datos de cada iteracion
		std::cout << "\n¿Desea ingresar nuevos datos? \n 1) Si 0) No \nIngrese un numero: ";
		std::cin >> respuesta;
		system("cls"); //Limpia la consola
	}while (respuesta != 0); //Mientras la respuesta no sea 0 que el programa siga ejecutandose
	return 0;
}
