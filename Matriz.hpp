#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

/** \class Matriz
 *
 * Permite manipular matrices y realizar diversas operaciones matriciales, incluyendo suma, resta, multiplicaci�n,
 * multiplicaci�n por un escalar, determinante, inversa, cofactores, transposici�n y redimensionamiento.
 *
 * \note Esta clase se dise�� para manejar matrices de tipo long double.
 * 
 *
 */

typedef long double tipo;

class Matriz {
    /** \brief Funci�n amiga para la sobrecarga del operador de inserci�n.
     *
     * Permite imprimir una matriz mediante un flujo de salida.
     *
     * \param out El flujo de salida.
     * \param v La matriz a imprimir.
     * \return El flujo de salida. Permite la aplicaci�n en cascada del operador.
     *
     */
    friend std::ostream &operator<<(std::ostream &out, const Matriz &v);
    /** \brief Funci�n amiga para la sobrecarga del operador de extracci�n.
     *
     * Permite capturar una matriz mediante un flujo de entrada.
     *
     * \param in El flujo de entrada.
     * \param v La matriz a capturar.
     * \return El flujo de entrada. Permite la aplicaci�n en cascada del operador.
     *
     */
    friend std::istream &operator>>(std::istream &in, Matriz &v);
    /** \brief Funci�n amiga para la sobrecarga del operador de multiplicaci�n por escalar.
     *
     * Permite multiplicar una matriz por un escalar.
     *
     * \param escalar El n�mero por el que se multiplica la matriz.
     * \param v La matriz a multiplicar.
     * \return La matriz resultante de la multiplicaci�n por escalar.
     *
     */
    friend Matriz operator*(double escalar, const Matriz &v);

public:
    /** \brief Constructor.
     *
     *  Versi�n 1: Constructor de una matriz de 3x3 por omisi�n.
     *
     *  Versi�n 2: Constructor de una matriz de las dimensiones indicadas por \b m y \b n.
     *
     * \param m N�mero de filas de la matriz.
     * \param n N�mero de columnas de la matriz.
     *
     * \pre \b m y \b n deben ser n�meros positivos.
     *
     * \exception const <b>char *</b> La matriz no puede ser creada o las dimensiones no son positivas.
     */
    explicit Matriz(int m = 3, int n = 3);
    /** \brief Constructor de copias.
     *
     * \param v La matriz a copiar.
     *
     * \exception const <b>char *</b> La matriz copia no puede ser creada.
     */
    Matriz(const Matriz &v);
    /** \brief Operador de asignaci�n. Copia una matriz en otra matriz.
     *
     * \param v La matriz a copiar.
     * \return La matriz copia. Permite la aplicaci�n en cascada del operador.
     *
     * \exception const <b>char *</b> La matriz copia no puede ser creada.
     */
    Matriz &operator=(const Matriz &v);
    /** \brief Destructor.
     *
     */
    ~Matriz();
    /** \brief Captura los elementos de una matriz por teclado.
     *
     */
    void Capturar();
    /** \brief Obtiene el n�mero de filas de una matriz.
     *
     * \return El n�mero de filas de la matriz.
     *
     */
    void Redimensionar(unsigned int nuevo_m, unsigned int nuevo_n);
    /** \brief Imprime una matriz en pantalla.
     *
     */
    void Imprimir() const;
    /** \brief Obtiene el n�mero de filas de una matriz.
     *
     * \return El n�mero de filas de la matriz.
     *
     */
    int ObtenerNumRen() const;
    /** \brief Obtiene el n�mero de columnas de una matriz.
     *
     * \return El n�mero de columnas de la matriz.
     *
     */
    int ObtenerNumCol() const;
    // OPERACIONES

    /** \brief Operador para sumar dos matrices.
     *
     * \param v La matriz a sumar.
     * \return La matriz resultante de la suma.
     *
     * \pre Las matrices a sumar deben tener las mismas dimensiones.
     *
     * \exception const <b>char *</b> Las matrices a sumar tienen dimensiones incompatibles o la matriz resultante no puede ser creada.
     */
    Matriz operator+(const Matriz &v) const;
    /** \brief Operador para restar dos matrices.
     *
     * \param v La matriz a restar.
     * \return La matriz resultante de la resta.
     *
     * \pre Las matrices a restar deben tener las mismas dimensiones.
     *
     * \exception const <b>char *</b> Las matrices a restar tienen dimensiones incompatibles o la matriz resultante no puede ser creada.
     */
    Matriz operator-(const Matriz &v) const;
    /** \brief Operador para multiplicar dos matrices.
     *
     * \param v La matriz a multiplicar.
     * \return La matriz resultante de la multiplicaci�n.
     *
     * \pre Las matrices a multiplicar deben tener las mismas dimensiones.
     *
     * \exception const <b>char *</b> Las matrices a multiplicar tienen dimensiones incompatibles o la matriz resultante no puede ser creada.
     */
    Matriz operator*(const Matriz &v) const;
    /** \brief Operador para multiplicar una matriz por un escalar.
     *
     * \param escalar El n�mero por el que se multiplica la matriz.
     * \return La matriz resultante de la multiplicaci�n por escalar.
     *
     * \exception const <b>char *</b> La matriz resultante no puede ser creada.
     */
    Matriz operator*(double escalar) const;
    /** \brief Calcula la transpuesta de una matriz.
     *
     * \return La matriz transpuesta.
     *
     */
    Matriz Transpuesta() const;
    /** \brief Calcula el determinante de una matriz.
     *
     * \return El determinante de la matriz.
     *
     * \exception const <b>char *</b> La matriz no es cuadrada o el determinante no puede ser calculado.
     */
    tipo Determinante() const;
    /** \brief Calcula la matriz de cofactores de una matriz.
     *
     * \return La matriz de cofactores.
     *
     * \exception const <b>char *</b> La matriz no es cuadrada o la matriz de cofactores no puede ser calculada.
     */
    Matriz Cofactores() const;
    /** \brief Calcula la matriz inversa de una matriz.
     *
     * \return La matriz inversa.
     *
     * \exception const <b>char *</b> La matriz no es cuadrada, singular o la matriz inversa no puede ser calculada.
     */
    Matriz Inversa() const;

private:
    unsigned int m, n;
    tipo **componente = nullptr;
    void EstablecerDim(int m, int n);
};

#endif // MATRIZ_HPP_INCLUDED
