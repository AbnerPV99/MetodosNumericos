#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<cmath>
#include <iomanip>
//Autor: Abner Andres Perez Villatoro
//Carne: 9490-17-11829
int respuesta, n;
float xint;

float metodoNeville(int n, float *x, float *y, float xint){
	float matrizQ[n][n];
	//Ingresa los valores de y en la primera columna de la matriz
	for (int i = 0; i <= n-1; i++){
		matrizQ[i][0] = y[i];
	}
	//Hace los calculos de X, Xj, Xi y Pi,j
	for(int i = 1;i <= n-1; i++){
		
        for(int j = 1; j <= i; j++){
            matrizQ[i][j] = ((xint - x[i-j]) * matrizQ[i][j-1] - (xint - x[i]) * matrizQ[i-1][j-1]) / (x[i] - x[i-j]);
        }
    }   
    //Muestra en pantalla cada valor almacenado en la matriz
    for (int i = 0; i <= n-1; i++){
		for (int j = 0; j <= n-1; j++){
			std::cout << std::setw(5) << "P(" << i << ")" << "(" << j << "): " << matrizQ[i][j];
		}
		std::cout << "\n";
	}
	return matrizQ[n-1][n-1]; //Retorna el valor de la ultima fila y columna que es la aproximacion mas cercana
}

int main(){
	do{
		std::cout << "\tMETODO DE NEVILLE \nIngrese la cantidad n de elementos: ";
		std::cin >> n;
		float x[n];
		float y[n];
		for (int i = 0; i <= n-1; i++){
			std::cout << "Ingrese el valor de x[" << i << "]: ";
			std::cin >> x[i];
			std::cout << "Ingrese el valor de y[" << i << "]: ";
			std::cin >> y[i];
		}
		std::cout << "Ingrese el valor de x a interpolar: ";
		std::cin >> xint;
		float resultado = metodoNeville(n, x, y, xint);
		std::cout << "\nEl valor interpolado para x = " << xint << " es " << resultado;
		std::cout << "\nDesea ingresar nuevos datos? \n 1) Si 0) No \nIngrese un numero: ";
		std::cin >> respuesta;
		system("cls"); //Limpia la consola
	}while (respuesta != 0);
}
