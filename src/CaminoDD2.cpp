#include "CaminoDD2.h"
#include "Lector.h"

using namespace std;

const int NO_ENCONTRADO = -1;

CaminoDD2::CaminoDD2() {
    pair<size_t, vector<Camino*>> data = Lector::leerArchivo(PATH_ARCHIVO_CSV);
    nodos = data.first;
    caminos = data.second;

    grafo = new Grafo(nodos);
    grafoRoto = new Grafo(nodos);

    for (Camino* camino: caminos) {
        grafo->agregarAristaPonderada(camino->calcularArista());
        grafoRoto->agregarAristaPonderada(camino->calcularAristaRota());
    }
}

Camino* CaminoDD2::buscarCamino(size_t origen, size_t destino) {
    size_t i = 0;
    bool encontrado = false;
    while (!encontrado) {
        if (*caminos[i] == std::pair<size_t, size_t>(origen, destino)) {
            encontrado = true;
        } else {
            i++;
        }
    }
    return caminos[i];
}

int CaminoDD2::buscarCaminoRoto(const vector<size_t>& caminoInicial) {
    int indice = NO_ENCONTRADO;
    size_t i = 0;
    while (indice == NO_ENCONTRADO && i < caminoInicial.size() - 1) {
        if (buscarCamino(caminoInicial[i], caminoInicial[i + 1])->esCaminoRoto()) {
            indice = int(i);
        } else {
            i++;
        }
    }
    return indice;
}

pair<std::vector<size_t>, int> CaminoDD2::obtenerCaminoMinimo() {
    vector<size_t> caminoInicial = grafo->obtenerCaminoMinimo(0, nodos - 1);
    int pesoInicial = grafo->obtenerPesoMinimo(0, nodos - 1);
    int i = buscarCaminoRoto(caminoInicial);

    if (i != NO_ENCONTRADO) {
        vector<size_t> caminoFinal, caminoAlternativo;
        caminoAlternativo = grafoRoto->obtenerCaminoMinimo(caminoInicial[size_t(i) + 1], nodos - 1);
        caminoFinal.insert(caminoFinal.end(), caminoInicial.begin(), caminoInicial.begin() + i + 1);
        caminoFinal.insert(caminoFinal.end(), caminoAlternativo.begin(), caminoAlternativo.end());

        int pesoFinal = grafo->obtenerPesoMinimo(0, caminoInicial[size_t(i) + 1]) +
                        grafoRoto->obtenerPesoMinimo(caminoInicial[size_t(i) + 1], nodos - 1);

        return {caminoFinal, pesoFinal};
    } else {
        return {caminoInicial, pesoInicial};
    }
}

CaminoDD2::~CaminoDD2() {
    for (Camino* camino: caminos) {
        delete camino;
    }
    delete grafo;
    delete grafoRoto;
}