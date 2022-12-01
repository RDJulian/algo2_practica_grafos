#ifndef CONSTANTES_H
#define CONSTANTES_H

const int T = 2;
const int C = 1;
const int P = 40;
const int M = 5;
const int TAMANIO_MAPA = 3; // TODO: Hacer que todo funcione de forma generica
                            // sin hardcodear el tamanio
const int INFINITO = 99;

struct Arista {
    int origen;
    int destino;
    int peso;

    Arista(int origen, int destino, int peso) {
        this->origen = origen;
        this->destino = destino;
        this->peso = peso;
    }
};

#endif