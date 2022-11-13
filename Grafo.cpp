#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int tamanio) {
    this->tamanio = tamanio;
    this->matrizAdyacencia = new int*[tamanio];
    for (int i = 0; i < tamanio; i++) {
        this->matrizAdyacencia[i] = new int[tamanio];
    }

    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            if (i != j) {
                this->matrizAdyacencia[i][j] = INFINITO;
            }
        }
    }

    this->matrizCaminosMinimos = new int*[tamanio];
    for (int i = 0; i < tamanio; i++) {
        this->matrizCaminosMinimos[i] = new int[tamanio];
    }
}

void Grafo::agregarAristaPonderada(Arista arista) {
    this->matrizAdyacencia[arista.origen][arista.destino] = arista.peso;
}

void Grafo::imprimirMatrizAdyacencia() {
    for (int i = 0; i < this->tamanio; i++) {
        for (int j = 0; j < this->tamanio; j++) {
            cout << this->matrizAdyacencia[i][j] << " ";
        }
        cout << endl;
    }
}

void Grafo::imprimirMatrizCaminosMinimos() {
    for (int i = 0; i < this->tamanio; i++) {
        for (int j = 0; j < this->tamanio; j++) {
            cout << this->matrizCaminosMinimos[i][j] << " ";
        }
        cout << endl;
    }
}

void Grafo::floydWarshall() {
    for (int i = 0; i < this->tamanio; i++) {
        for (int j = 0; j < this->tamanio; j++) {
            this->matrizCaminosMinimos[i][j] = this->matrizAdyacencia[i][j];
        }
    }

    for (int k = 0; k < this->tamanio; k++) {
        for (int i = 0; i < this->tamanio; i++) {
            for (int j = 0; j < this->tamanio; j++) {
                if (this->matrizCaminosMinimos[i][j] >
                        (this->matrizCaminosMinimos[i][k] +
                         this->matrizCaminosMinimos[k][j]) &&
                    (this->matrizCaminosMinimos[k][j] != INFINITO &&
                     this->matrizCaminosMinimos[i][k] != INFINITO))
                    this->matrizCaminosMinimos[i][j] =
                        this->matrizCaminosMinimos[i][k] +
                        this->matrizCaminosMinimos[k][j];
            }
        }
    }
}

Grafo::~Grafo() {
    for (int i = 0; i < this->tamanio; i++) {
        delete[] this->matrizAdyacencia[i];
    }
    delete[] this->matrizAdyacencia;
    for (int i = 0; i < this->tamanio; i++) {
        delete[] this->matrizCaminosMinimos[i];
    }
    delete[] this->matrizCaminosMinimos;
};