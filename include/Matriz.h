#ifndef ALGO2_DOBLE_PUNTEROS_MATRIZ_H
#define ALGO2_DOBLE_PUNTEROS_MATRIZ_H

#include <exception>

class DimensionesNoValidasException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: el contacto no tiene el formato correcto.";
    }
};

class IndiceNoValidoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: el indice ingresado no es valido.";
    }
};

class Matriz {
private:
    int* matriz;
    size_t fila;
    size_t columna;

    //pre: -
    //post: Devuelve true si el indice es valido (0 <= i < filas, 0 <= j < columnas).
    bool indiceValido(const size_t& i, const size_t& j) const;

    //pre: El indice bidimensional debe ser valido.
    //post: Devuelve el indice unidimensional equivalente al ingresado.
    size_t calcularIndice(const size_t& i, const size_t& j) const;

public:
    //pre: Ninguna de las dimesiones puede ser menor que 1.
    //post: Genera una matriz con las dimensiones indicadas.
    Matriz(const size_t& fila, const size_t& columna);

    //pre: Ninguna de las dimesiones puede ser menor que 1.
    //post: Genera una matriz cuadrada con el tamaño indicado.
    explicit Matriz(const size_t& tamanio);

    //pre: Ninguna de las dimesiones puede ser menor que 1.
    //post: Genera una matriz con las dimensiones indicadas, inicializada con el valor ingresado.
    Matriz(const size_t& fila, const size_t& columna, int valor);

    //pre: Ninguna de las dimesiones puede ser menor que 1.
    //post: Genera una matriz cuadrada con el tamaño indicado, inicializada con el valor ingresado.
    Matriz(const size_t& tamanio, int valor);

    //Constructor por copia.
    Matriz(const Matriz& matriz1);

    //pre: -
    //post: Imprime por pantalla la matriz.
    void imprimirMatriz();

    //pre: El indice debe ser valido, es decir, 0 <= i < filas, 0 <= j < columnas.
    //post: Devuelve la referecia al elemento accedido.
    int& elemento(const size_t& i, const size_t& j);

    //pre: -
    //post: Libera la memoria reservada por la matriz.
    ~Matriz();
};

#endif