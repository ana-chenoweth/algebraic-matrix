#include <iostream>
#include "Matriz.hpp"

int main() {
    try {
        std::cout << "=== PRUEBA DE FUNCIONALIDADES DE LA CLASE MATRIZ ===\n" << std::endl;

        // Crear dos matrices 3x3
        Matriz A(3, 3), B(3, 3);

        std::cout << "Ingrese los elementos de la matriz A (3x3):" << std::endl;
        std::cin >> A;

        std::cout << "\nIngrese los elementos de la matriz B (3x3):" << std::endl;
        std::cin >> B;

        std::cout << "\nMatriz A:\n" << A;
        std::cout << "Matriz B:\n" << B;

        // Suma
        Matriz suma = A + B;
        std::cout << "A + B:\n" << suma;

        // Resta
        Matriz resta = A - B;
        std::cout << "A - B:\n" << resta;

        // Multiplicación elemento a elemento
        Matriz multiplicacion = A * B;
        std::cout << "A * B (elemento a elemento):\n" << multiplicacion;

        // Multiplicación por escalar
        Matriz escalar = 2.5 * A;
        std::cout << "2.5 * A:\n" << escalar;

        // Transpuesta
        Matriz transpuesta = A.Transpuesta();
        std::cout << "Transpuesta de A:\n" << transpuesta;

        // Determinante
        tipo det = A.Determinante();
        std::cout << "Determinante de A: " << det << std::endl;

        // Cofactores
        Matriz cof = A.Cofactores();
        std::cout << "Matriz de cofactores de A:\n" << cof;

        // Inversa
        Matriz inv = A.Inversa();
        std::cout << "Inversa de A:\n" << inv;

        // Redimensionar
        std::cout << "\nRedimensionando A a 2x2..." << std::endl;
        A.Redimensionar(2, 2);
        std::cout << "Matriz A redimensionada:\n" << A;

    } catch (const char *msn) {
        std::cerr << "Error: " << msn << std::endl;
    } catch (...) {
        std::cerr << "Error inesperado" << std::endl;
    }

    return 0;
}
