#include "parser.h"

bool aristaValida(int columna, int fila) {
    return (columna != -1 && columna != TAMANIO_MAPA && fila != -1 &&
            fila != TAMANIO_MAPA);
}

int indice(int columna, int fila) { return columna * 4 + fila; }

void cargarGrafo(int mapa[4][4], Grafo* grafo) { // Se deberia poder achicar
    for (int i = 0; i < TAMANIO_MAPA; i++) {
        for (int j = 0; j < TAMANIO_MAPA; j++) {
            if (aristaValida(i, j + 1)) {
                Arista aristaIda(indice(i, j), indice(i, j + 1),
                                 mapa[i][j + 1]);
                Arista aristaVuelta(indice(i, j + 1), indice(i, j), mapa[i][j]);
                grafo->agregarAristaPonderada(aristaIda);
                grafo->agregarAristaPonderada(aristaVuelta);
            }
            if (aristaValida(i, j - 1)) {
                Arista aristaIda(indice(i, j), indice(i, j - 1),
                                 mapa[i][j - 1]);
                Arista aristaVuelta(indice(i, j - 1), indice(i, j), mapa[i][j]);
                grafo->agregarAristaPonderada(aristaIda);
                grafo->agregarAristaPonderada(aristaVuelta);
            }
            if (aristaValida(i + 1, j)) {
                Arista aristaIda(indice(i, j), indice(i + 1, j),
                                 mapa[i + 1][j]);
                Arista aristaVuelta(indice(i + 1, j), indice(i, j), mapa[i][j]);
                grafo->agregarAristaPonderada(aristaIda);
                grafo->agregarAristaPonderada(aristaVuelta);
            }
            if (aristaValida(i - 1, j)) {
                Arista aristaIda(indice(i, j), indice(i - 1, j),
                                 mapa[i - 1][j]);
                Arista aristaVuelta(indice(i - 1, j), indice(i, j), mapa[i][j]);
                grafo->agregarAristaPonderada(aristaIda);
                grafo->agregarAristaPonderada(aristaVuelta);
            }
        }
    }
}