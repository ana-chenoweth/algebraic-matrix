#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

typedef long double tipo;

class Matriz {

public:
    explicit Matriz(int m = 3, int n = 3);
    Matriz(const Matriz &v);
    Matriz &operator=(const Matriz &v);
    ~Matriz();
    void Capturar();
    void Imprimir() const;
    int ObtenerNumRen() const;
    int ObtenerNumCol() const;

private:
    unsigned int m, n;
    tipo **componente = nullptr;
    void EstablecerDim(int m, int n);
};

#endif // MATRIZ_HPP_INCLUDED
