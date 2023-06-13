#include "Camino.h"

using namespace std;

Camino::Camino(size_t origen, size_t destino, TipoCamino camino) {
    this->origen = origen;
    this->destino = destino;
    this->camino = camino;
}

int Camino::calcularBase() {
    int peso;
    if (camino == piedra || camino == piedraR) {
        peso = PIEDRA;
    } else if (camino == tierra || camino == tierraR) {
        peso = TIERRA;
    } else {
        peso = AGUA;
    }
    return peso;
}

Arista Camino::calcularArista() {
    return {origen, destino, calcularBase()};
}

Arista Camino::calcularAristaRota() {
    Arista arista = calcularArista();
    if (esCaminoRoto()) {
        arista.peso *= PENALIZACION;
    }
    return arista;
}

bool Camino::esCaminoRoto() {
    return camino == piedraR || camino == tierraR || camino == aguaR;
}

bool Camino::operator==(pair<size_t, size_t> vertices) const {
    return origen == vertices.first && destino == vertices.second;
}

pair<vector<size_t>, int> Camino::unirCaminos(Grafo* grafo, Grafo* grafoRoto, size_t nodoFinal) const {
    vector<size_t> caminoUnido, caminoInicial, caminoFinal;
    caminoInicial = grafo->obtenerCaminoMinimo(0, origen);
    caminoFinal = grafoRoto->obtenerCaminoMinimo(destino, nodoFinal);
    caminoUnido.insert(caminoUnido.end(), caminoInicial.begin(), caminoInicial.end());
    caminoUnido.insert(caminoUnido.end(), caminoFinal.begin(), caminoFinal.end());

    int peso = grafo->obtenerPesoMinimo(0, destino) +
               grafoRoto->obtenerPesoMinimo(destino, nodoFinal);

    return {caminoUnido, peso};
}
