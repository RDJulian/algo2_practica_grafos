#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int tamanio) {
    this->tamanio = tamanio;
    adyacencia = new int*[tamanio];
    pesos = new int*[tamanio];
    caminos = new int*[tamanio];

    for (int i = 0; i < tamanio; i++) {
        adyacencia[i] = new int[tamanio];
        pesos[i] = new int[tamanio];
        caminos[i] = new int[tamanio];
    }

    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            if (i == j) {
                adyacencia[i][j] = 0;
            }
            if (i != j) {
                adyacencia[i][j] = INFINITO;
            }
        }
    }
}

void Grafo::agregarAristaPonderada(Arista arista) {
    adyacencia[arista.origen][arista.destino] = arista.peso;
}

void Grafo::imprimirMatrizAdyacencia() {
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            cout << adyacencia[i][j] << " ";
        }
        cout << endl;
    }
}

void Grafo::imprimirMatrizPesosMinimos() {
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            cout << pesos[i][j] << " ";
        }
        cout << endl;
    }
}

void Grafo::imprimirMatrizCaminosMinimos() {
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            cout << caminos[i][j] << " ";
        }
        cout << endl;
    }
}

void Grafo::floydWarshall() {
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            pesos[i][j] = adyacencia[i][j];
            caminos[i][j] = j;
        }
    }

    for (int k = 0; k < tamanio; k++) {
        for (int i = 0; i < tamanio; i++) {
            for (int j = 0; j < tamanio; j++) {
                if (pesos[i][j] > (pesos[i][k] + pesos[k][j]) &&
                    (pesos[k][j] != INFINITO && pesos[i][k] != INFINITO)) {
                    pesos[i][j] = pesos[i][k] + pesos[k][j];
                    caminos[i][j] = caminos[i][k];
                }
            }
        }
    }
}

Grafo::~Grafo() {
    for (int i = 0; i < tamanio; i++) {
        delete[] adyacencia[i];
    }
    delete[] adyacencia;

    for (int i = 0; i < tamanio; i++) {
        delete[] pesos[i];
    }
    delete[] pesos;

    for (int i = 0; i < tamanio; i++) {
        delete[] caminos[i];
    }
    delete[] caminos;
};