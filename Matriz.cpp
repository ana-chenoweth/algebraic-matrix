#include <math.h>
#include <iomanip>
#include <cstring>
#include <cmath>

#include "Matriz.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::fixed;
using std::setprecision;

//***************************************************
void Matriz::EstablecerDim(int m, int n)
{
    if (m < 1 || n < 1)throw "Valor fuera de rango";
    this->n = n;
    this->m = m;
}

//***********************************
//Constructor
Matriz::Matriz(int m, int n) {
    EstablecerDim(m, n);
    try {
        componente = new tipo*[m];
        componente[0] = new tipo[m * n];
        for (int i = 1; i < m; ++i)
            componente[i] = componente[0] + i * n;

        // Inicializar la matriz con ceros
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                componente[i][j] = 0;
            }
        }
    } catch(std::bad_alloc &) {
        throw "No es posible construir una Matriz";
    }
}

//***********************************
// Constructor de copia
Matriz::Matriz(const Matriz &v) : m(v.m), n(v.n), componente(nullptr) {
    try {
        componente = new tipo*[m];
        componente[0] = new tipo[m * n];
        for (unsigned int i = 1; i < m; ++i)
            componente[i] = componente[0] + i * n;

        // Copiar los elementos de v a la matriz actual
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                componente[i][j] = v.componente[i][j];
            }
        }
    } catch(std::bad_alloc &) {
        throw "No es posible construir una Matriz";
    }
}
//***********************************
// Operador de asignacion
Matriz & Matriz::operator=(const Matriz &v) {
    if (this == &v) return *this;
    try {
        delete[] componente[0];
        delete[] componente;
        componente = nullptr;

        m = v.m;
        n = v.n;

        componente = new tipo*[m];
        componente[0] = new tipo[m * n];
        for (unsigned int i = 1; i < m; ++i) {
            componente[i] = componente[0] + i * n;
        }

        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                componente[i][j] = v.componente[i][j];
            }
        }
    } catch (std::bad_alloc &) {
        throw "No es posible construir una Matriz";
    }

    return *this;
}
//***********************************
// Destructor
Matriz::~Matriz() {
        delete[] componente[0];
        delete[] componente;
        componente = nullptr;
}
//***********************************
void Matriz::Capturar()
{
    for(unsigned int i = 0 ; i < m ; ++i){
        for(unsigned int j = 0; j<n; ++j){
                    cin >> componente[i][j];
        }
    }

}
//***********************************
void Matriz::Imprimir() const
{
    cout << left;
    cout << "┌";
    for(unsigned int j = 0; j < n ; ++j) cout << "\t";
    cout << "┐" << endl;

    for(unsigned int i = 0 ; i < m ; ++i){
        cout << "│";
        for(unsigned int j = 0; j < n ; ++j) {
            if (componente[i][j] - static_cast<int>(componente[i][j]) !=0 || componente[i][j] - round(componente[i][j]) !=0 ) {
                cout << fixed << setprecision(2) << componente[i][j] << "\t" ;
            } else {
                cout << componente[i][j] << "\t" ;
            }
        }
        cout << "│";
        cout << endl;
    }

    cout  << "└";
    for(unsigned int j = 0; j < n ; ++j) cout << "\t";
    cout << "┘";

    cout << endl << endl;
}
//***********************************
int Matriz::ObtenerNumRen() const
{
    return m;
}
//***********************************
int Matriz::ObtenerNumCol() const
{
    return n;
}