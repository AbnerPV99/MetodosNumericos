#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <math.h>
#include <iomanip>

// Autor: Abner Andres Perez Villatoro
// Carne: 9490-17-11829
// Fecha: 25 de mayo, 2024
// Descripcion: El programa implementa el metodo Gauss-Seidel para resolver un sistema de ecuaciones lineales.
//n: Indica la cantidad de ecuaciones o incognitas 
//i, j: Indican las filas y columnas de la matriz respectivamente
//k: Itera sobre cada calculo usando el metodo Jacobi hasta que el error sea menor a la tolerancia
//TOL: Tolerancia
//IT: Cantidad maxima de iteraciones
//error: Calcula el error para despues compararlo con la tolerancia
//x0: Es el vector que contiene las aproximaciones iniciales
//b: Es el vector que contiene los terminos independientes
//A: Es la matriz con los coeficientes de las ecuaciones
//x: Es la matriz resultante
int i, j, k, n, IT, respuesta;
double TOL;

// Le pide el ingreso de los datos al usuario
void algoritmoGaussSeidel()
{
    std::cout << "\tMETODO GAUSS-SEIDEL \nIngrese la cantidad n de ecuaciones e incognitas: ";
    std::cin >> n;
    double x0[n];   // Vector de aproximaciones iniciales
    double b[n];    // Vector de terminos independientes
    double A[n][n]; // Matriz de coeficientes
    for (i = 0; i < n; i++)
    {
        std::cout << "\nIngrese el elemento [" << i << "] del vector de aproximaciones x0: ";
        std::cin >> x0[i];
        std::cout << "Ingrese el elemento [" << i << "] del vector b: ";
        std::cin >> b[i];
        for (j = 0; j < n; j++)
        {
            std::cout << "Ingrese el coeficiente [" << i << "][" << j << "] de la matriz A: ";
            std::cin >> A[i][j];
        }
    }
    std::cout << "Ingrese la tolerancia: ";
    std::cin >> TOL;
    std::cout << "Ingrese la cantidad maxima de iteraciones: ";
    std::cin >> IT;

    k = 1;
    while (k <= IT)
    {
		double error = 0.0;
        for (i = 0; i < n; i++)
        {
            double suma = 0.0;
            for (j = 0; j < n; j++)
            {
                if (j != i)
                {
                    suma += A[i][j] * x0[j];
                }
            }
            double x = (b[i] - suma) / A[i][i];
        	// Calculo del error
        	error += pow(x - x0[i], 2);
        	x0[i] = x;
        	std::cout << "\nVector x[" << i << "]: " << x0[i];
        }

        error = sqrt(error);
        std::cout << "\nError: " << error;
        // Si el error es menor a la tolerancia entonces la solucion ha sido encontrada
        if (error < TOL)
        {
            std::cout << "\nSolucion encontrada despues de " << k << " iteraciones: ";
            for (i = 0; i < n; i++)
            {
                std::cout << "\nVector de solucion x[" << i << "] = " << x0[i];
            }
            break;
        }

        k++;
    }
    if (k > IT)
    {
        std::cout << "\nSuperada la cantidad maxima de iteraciones";
    }
}

int main()
{
    do
    {
        algoritmoGaussSeidel(); // Se le pide al usuario que ingrese los datos
        std::cout << "\n¿Desea ingresar nuevos datos? \n 1) Si 0) No \nIngrese un numero: ";
        std::cin >> respuesta;
        system("cls"); // Limpia la consola
    } while (respuesta != 0); // Mientras la respuesta no sea 0 que el programa siga ejecutandose
    return 0;
}
