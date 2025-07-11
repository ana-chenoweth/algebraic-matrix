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
//*******************************************************************
void Matriz::Redimensionar(unsigned int nuevo_m, unsigned int nuevo_n)
{
    if (nuevo_m < 1 || nuevo_n < 1) {
        throw "Valor fuera de rango para las dimensiones de la matriz";
    }
    if (nuevo_m == m && nuevo_n == n) {
        return;
    }
    try {
        tipo** nueva_componente = new tipo*[nuevo_m];
        nueva_componente[0] = new tipo[nuevo_m * nuevo_n];
        for (unsigned int i = 1; i < nuevo_m; ++i) {
            nueva_componente[i] = nueva_componente[0] + i * nuevo_n;
        }

        for (unsigned int i = 0; i < nuevo_m; ++i) {
            for (unsigned int j = 0; j < nuevo_n; ++j) {
                nueva_componente[i][j] = 0;
            }
        }
        // Copiar los valores de la matriz original que siguen siendo v�lidos
        for (unsigned int i = 0; i < std::min(m, nuevo_m); ++i) {
            for (unsigned int j = 0; j < std::min(n, nuevo_n); ++j) {
                nueva_componente[i][j] = componente[i][j];
            }
        }

        // Liberar la memoria de la matriz original
        delete[] componente[0];
        delete[] componente;

        // Asignar la nueva matriz redimensionada
        componente = nueva_componente;
        m = nuevo_m;
        n = nuevo_n;

    } catch (std::bad_alloc &) {
        throw "No es posible construir una Matriz";
    }
}

/***************************************************************************

/* OPERACIONES CON MATRICES */
//***********************************
Matriz Matriz::operator+(const Matriz &v) const
{
    if (m != v.m || n != v.n)
        throw "Dimensiones incompatibles para sumar";

    Matriz s(m, n);

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            s.componente[i][j] = componente[i][j] + v.componente[i][j];
        }
    }

    return s;
}
//***********************************
Matriz Matriz::operator-(const Matriz &v) const
{
    if (m != v.m || n != v.n)
        throw "Dimensiones incompatibles para sumar";

    Matriz s(m, n);

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            s.componente[i][j] = componente[i][j] - v.componente[i][j];
        }
    }

    return s;
}
//***********************************
Matriz Matriz::operator*(const Matriz &v) const
{
    if (m != v.m || n != v.n)
        throw "Dimensiones incompatibles para sumar";

    Matriz s(m, n);

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            s.componente[i][j] = componente[i][j] * v.componente[i][j];
        }
    }

    return s;
}
//***********************************
Matriz Matriz::operator*(double escalar) const
{
    Matriz s(m, n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            s.componente[i][j] = componente[i][j] * escalar;
        }
    }

    return s;
}

/* FUNCIONES EXTERNAS*/
//*****************************************************************
std::ostream & operator<<(std::ostream &out,const Matriz &v)
{
    out << left;
    out << "┌";
    for(unsigned int j = 0; j < v.n ; ++j) out << "\t";
    out << "┐" << endl;

    for(unsigned int i = 0 ; i < v.m ; ++i){
        out << "│";
        for(unsigned int j = 0; j < v.n ; ++j) {
            if (v.componente[i][j] - static_cast<int>(v.componente[i][j]) !=0 || v.componente[i][j] - round(v.componente[i][j]) !=0 ) {
                out << fixed << setprecision(2) << v.componente[i][j] << "\t" ;
            } else {
                out << v.componente[i][j] << "\t" ;
            }
        }
        out << "│";
        out << endl;
    }

    out  << "└";
    for(unsigned int j = 0; j < v.n ; ++j) out << "\t";
    out << "┘";

    out << endl << endl;

    return out;
}
//**************************************************************
std::istream & operator>>(std::istream &in,Matriz &v)
{
    for(unsigned int i = 0 ; i < v.m ; ++i){
        for(unsigned int j = 0; j<v.n; ++j){
                    in >>v.componente[i][j];
        }
    }
    return in;
}
//*************************************************************
Matriz operator*(double escalar, const Matriz &v)
{
    Matriz s(v.m, v.n);
    for (unsigned int i = 0; i < v.m; i++) {
        for (unsigned int j = 0; j < v.n; j++) {
            s.componente[i][j] = escalar * v.componente[i][j];
        }
    }

    return s;
}