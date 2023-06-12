#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

const int INFINITO = 99999;
const std::string INFINITO_STR = "∞";

const int PIEDRA = 10;
const int TIERRA = 20;
const int AGUA = 30;

const int PENALIZACION = 5;

enum TipoCamino {
    piedra = 0,
    tierra,
    agua,
    piedraR,
    tierraR,
    aguaR
};

struct Arista {
    size_t origen;
    size_t destino;
    int peso;

    Arista(size_t origen, size_t destino, int peso) {
        this->origen = origen;
        this->destino = destino;
        this->peso = peso;
    }
};

#endif