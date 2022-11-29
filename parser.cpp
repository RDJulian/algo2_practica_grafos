#include "parser.h"
#include <vector>

using namespace std;

bool verticeValido(int columna, int fila) {
    return (columna != -1 && columna != TAMANIO_MAPA && fila != -1 &&
            fila != TAMANIO_MAPA);
}

int indice(int columna, int fila) { return columna * TAMANIO_MAPA + fila; }

void cargarGrafo(int mapa[TAMANIO_MAPA][TAMANIO_MAPA], Grafo* grafo) {
    vector<Arista> aristasValidas;

    // Cargo todas las aristas validas a un vector.
    for (int i = 0; i < TAMANIO_MAPA; i++) {
        for (int j = 0; j < TAMANIO_MAPA; j++) {
            if (verticeValido(i, j + 1)) {
                aristasValidas.push_back(
                    Arista(indice(i, j), indice(i, j + 1), mapa[i][j + 1]));
            }
            if (verticeValido(i, j - 1)) {
                aristasValidas.push_back(
                    Arista(indice(i, j), indice(i, j - 1), mapa[i][j - 1]));
            }
            if (verticeValido(i + 1, j)) {
                aristasValidas.push_back(
                    Arista(indice(i, j), indice(i + 1, j), mapa[i + 1][j]));
            }
            if (verticeValido(i - 1, j)) {
                aristasValidas.push_back(
                    Arista(indice(i, j), indice(i - 1, j), mapa[i - 1][j]));
            }
        }
    }

    for (Arista arista : aristasValidas) {
        grafo->agregarAristaPonderada(arista);
    }
}