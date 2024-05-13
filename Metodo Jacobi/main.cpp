#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <math.h>
#include <iomanip>

// Autor: Abner Andres Perez Villatoro
// Carne: 9490-17-11829
// Fecha: 18 de mayo, 2024
// Descripcion: El programa implementa el metodo Jacobi para resolver un sistema de ecuaciones lineales.
//n: Indica la cantidad de ecuaciones o incognitas 
//i, j: Indican las filas y columnas de la matriz respectivamente
//k: Itera sobre cada calculo usando el metodo Jacobi hasta que el error sea menor a la tolerancia
//TOL: Tolerancia
//IT: Cantidad maxima de iteraciones
//error: Calcula el error para despues compararlo con la tolerancia
//x0: Es el vector que contiene las aproximaciones iniciales
//b: Es el vector que contiene los terminos independientes
//A: Es la matriz con los coeficientes de las ecuaciones
//xi: Es el vector solucion que ira almacenando los calculos
int i, j, k, n, IT, respuesta;
double TOL;

// Le pide el ingreso de los datos al usuario
void algoritmoJacobi()
{
    std::cout << "\tMETODO JACOBI \nIngrese la cantidad n de ecuaciones e incognitas: ";
    std::cin >> n;
    double x0[n];   // Vector de aproximaciones
    double b[n];    // Vector de terminos independientes
    double A[n][n]; // Matriz de coeficientes
    double xi[n];   // Vector solucion
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
            xi[i] = (b[i] - suma) / A[i][i];
            std::cout << "\nxi[" << i << "] = " << xi[i];
        }
        // Calculo del error
        double error = 0.0;
        for (i = 0; i < n; i++)
        {
            error += pow((xi[i] - x0[i]), 2);
        }
        error = sqrt(error);
        std::cout << "\nError: " << error;
        // Si el error es menor a la tolerancia entonces la solucion ha sido encontrada
        if (error < TOL)
        {
            std::cout << "\nSolucion encontrada despues de " << k << " iteraciones: ";
            for (i = 0; i < n; i++)
            {
                std::cout << "\nVector de solucion xi[" << i << "] = " << xi[i];
            }
            break;
        }

        for (i = 0; i < n; i++)
        {
            x0[i] = xi[i];
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
        algoritmoJacobi(); // Se le pide al usuario que ingrese los datos
        std::cout << "\n¿Desea ingresar nuevos datos? \n 1) Si 0) No \nIngrese un numero: ";
        std::cin >> respuesta;
        system("cls"); // Limpia la consola
    } while (respuesta != 0); // Mientras la respuesta no sea 0 que el programa siga ejecutandose
    return 0;
}
