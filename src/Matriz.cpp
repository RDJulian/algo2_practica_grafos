#include <iostream>
#include "Matriz.h"
#include "constantes.h"

using namespace std;

Matriz::Matriz(const size_t& fila, const size_t& columna) {
    if (fila < 1 || columna < 1) {
        throw DimensionesNoValidasException();
    } else {
        this->fila = fila;
        this->columna = columna;
        this->matriz = new int[fila * columna];
    }
}

Matriz::Matriz(const size_t& tamanio) : Matriz(tamanio, tamanio) {}

Matriz::Matriz(const size_t& fila, const size_t& columna, int valor) : Matriz(fila, columna) {
    for (size_t i = 0; i < fila * columna; i++) {
        matriz[i] = valor;
    }
}

Matriz::Matriz(const size_t& tamanio, int valor) : Matriz(tamanio, tamanio, valor) {}

Matriz::Matriz(const Matriz& matriz1) : Matriz(matriz1.fila, matriz1.columna) {
    for (size_t i = 0; i < fila * columna; i++) {
        matriz[i] = matriz1.matriz[i];
    }
}

size_t Matriz::calcularIndice(const size_t& i, const size_t& j) const {
    return i * columna + j;
}

bool Matriz::indiceValido(const size_t& i, const size_t& j) const {
    return (0 <= i && 0 <= j && (size_t) i < fila && (size_t) j < columna);
}

void Matriz::imprimirMatriz() {
    for (size_t i = 0; i < fila; i++) {
        for (size_t j = 0; j < columna; j++) {
            int elemento = matriz[calcularIndice(i, j)];
            string salida = (elemento == INFINITO) ? INFINITO_STR : to_string(elemento);
            cout << salida << "   ";
        }
        cout << endl;
    }
}

int& Matriz::elemento(const size_t& i, const size_t& j) {
    if (!indiceValido(i, j)) {
        throw IndiceNoValidoException();
    } else {
        return matriz[calcularIndice(i, j)];
    }
}

Matriz::~Matriz() {
    delete[] matriz;
}