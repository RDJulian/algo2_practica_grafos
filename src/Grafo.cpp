#include "Grafo.h"

using namespace std;

Grafo::Grafo(size_t vertices) {
    this->vertices = vertices;
    hayCambios = true;
    adyacencia = new Matriz(vertices, INFINITO);
    pesos = nullptr;
    caminos = new Matriz(vertices, INFINITO);

    for (size_t i = 0; i < vertices; i++) {
        for (size_t j = 0; j < vertices; j++) {
            if (i == j) {
                adyacencia->elemento(i, j) = 0;
                caminos->elemento(i, j) = int(j);
            }
        }
    }
}

void Grafo::agregarAristaPonderada(Arista arista) {
    adyacencia->elemento(arista.origen, arista.destino) = arista.peso;
    caminos->elemento(arista.origen, arista.destino) = int(arista.destino);
    hayCambios = true;
}

void Grafo::_floydWarshall() {
    pesos = new Matriz(*adyacencia);
    for (size_t k = 0; k < vertices; k++) {
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                if (pesos->elemento(i, j) > (pesos->elemento(i, k) + pesos->elemento(k, j))) {
                    pesos->elemento(i, j) = pesos->elemento(i, k) + pesos->elemento(k, j);
                    caminos->elemento(i, j) = caminos->elemento(i, k);
                }
            }
        }
    }
}

void Grafo::floydWarshall() {
    if (hayCambios) {
        _floydWarshall();
    }
    hayCambios = false;
}

vector<size_t> Grafo::obtenerCaminoMinimo(size_t origen, size_t destino) {
    floydWarshall();
    vector<size_t> camino;
    size_t vertice = origen;
    camino.push_back(vertice);
    while (vertice != destino) {
        vertice = size_t(caminos->elemento(vertice, destino));
        camino.push_back(vertice);
    }
    return camino;
}

int Grafo::obtenerPesoMinimo(size_t origen, size_t destino) {
    floydWarshall();
    return pesos->elemento(origen, destino);
}

Grafo::~Grafo() {
    delete adyacencia;
    delete pesos;
    delete caminos;
}