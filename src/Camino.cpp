#include "Camino.h"

using namespace std;

Camino::Camino(size_t origen, size_t destino, TipoCamino camino) {
    this->origen = origen;
    this->destino = destino;
    this->camino = camino;
}

Arista Camino::calcularArista() {
    int peso;
    if (camino == piedra || camino == piedraR) {
        peso = PIEDRA;
    } else if (camino == tierra || camino == tierraR) {
        peso = TIERRA;
    } else {
        peso = AGUA;
    }
    return {origen, destino, peso};
}

Arista Camino::calcularAristaRota() {
    int peso;
    switch (camino) {
        case piedra:
            peso = PIEDRA;
            break;
        case tierra:
            peso = TIERRA;
            break;
        case agua:
            peso = AGUA;
            break;
        case piedraR:
            peso = PIEDRA * PENALIZACION;
            break;
        case tierraR:
            peso = TIERRA * PENALIZACION;
            break;
        case aguaR:
            peso = AGUA * PENALIZACION;
            break;
    }
    return {origen, destino, peso};
}

bool Camino::esCaminoRoto() {
    return camino == piedraR || camino == tierraR || camino == aguaR;
}

bool Camino::operator==(pair<size_t, size_t> vertices) const {
    return origen == vertices.first && destino == vertices.second;
}