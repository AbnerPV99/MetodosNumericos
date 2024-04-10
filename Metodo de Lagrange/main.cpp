#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <math.h>
#include <iomanip>
//Autor: Abner Andres Perez Villatoro
//Carne: 9490-17-11829
int i, j, n, respuesta;
double x[100], y[100], FP, z, v, valor;

//Le pide el ingreso de los datos al usuario
void ingresoDatos(){
	std::cout << "\tMETODO DE LAGRANGE \nIngrese la cantidad n de elementos: ";
	std::cin >> n;
	for (i = 0; i < n; i++){
		std::cout << "Ingrese el valor de x[" << i << "]: ";
		std::cin >> x[i];
		std::cout << "Ingrese el valor de y[" << i << "]: ";
		std::cin >> y[i];
	}
	std::cout << "Ingrese el valor de x a evaluar: ";
	std::cin >> z;
}
//Ejecuta el algoritmo aplicando el metodo de Lagrange
void algoritmoLagrange(){
	valor = 0;
	for (i = 0; i <= n-1; i++){
		v = y[i];
		std::cout << "----------------------------------\n\tL"<< i << "(x):\n"; //Muestra en que iteracion de L esta el algoritmo
		for (j = 0; j <= n-1; j++){
			if (j != i){
				std::cout << "k(" << j << "): " << v << " * ("<< z << "-" << x[j] << ")/(" << x[i] << "-" << x[j] <<")"; //Representacion visual de la formula
				v = v * ((z-x[j])/(x[i] - x[j]));
				std::cout << " = " << v << "\n"; //Nos muestra visualmente cuanto vale v
			}
		}
		valor = valor + v;
		std::cout << "P(x) = "<< valor << "\n"; //Nos muestra el resultado de valor en cada iteracion de L
	}
	std::cout << "La Y interpolada en P(x) = " << valor << "\n";
}

int main() {
	do {
		ingresoDatos(); //Se le pide al usuario que ingrese los datos
		algoritmoLagrange(); //Evalua el algoritmo y va mostrando en pantalla los datos de cada iteracion
		std::cout << "\n¿Desea ingresar nuevos datos? \n 1) Si 0) No \nIngrese un numero: ";
		std::cin >> respuesta;
		system("cls"); //Limpia la consola
	}while (respuesta != 0); //Mientras la respuesta no sea 0 que el programa siga ejecutandose
	return 0;
}
