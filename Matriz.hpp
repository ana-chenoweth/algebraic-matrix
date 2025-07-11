#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

typedef long double tipo;

class Matriz {
    friend std::ostream &operator<<(std::ostream &out, const Matriz &v);
    friend std::istream &operator>>(std::istream &in, Matriz &v);
    friend Matriz operator*(double escalar, const Matriz &v);

public:
    explicit Matriz(int m = 3, int n = 3);
    Matriz(const Matriz &v);
    Matriz &operator=(const Matriz &v);
    ~Matriz();
    void Capturar();
    void Redimensionar(unsigned int nuevo_m, unsigned int nuevo_n);
    void Imprimir() const;
    int ObtenerNumRen() const;
    int ObtenerNumCol() const;
    Matriz operator+(const Matriz &v) const;
    Matriz operator-(const Matriz &v) const;
    Matriz operator*(const Matriz &v) const;
    Matriz operator*(double escalar) const;
    Matriz Transpuesta() const;

private:
    unsigned int m, n;
    tipo **componente = nullptr;
    void EstablecerDim(int m, int n);
};

#endif // MATRIZ_HPP_INCLUDED
