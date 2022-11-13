#include "Grafo.h"
#include "parser.h"
#include <iostream>

using namespace std;

int main() {
    int mapa[TAMANIO_MAPA][TAMANIO_MAPA] = {
        {C, P, T, T},
        {C, C, C, C},
        {M, M, M, T},
        {T, P, P, P},
    };

    Grafo* grafoPonderado = new Grafo(TAMANIO_MAPA * TAMANIO_MAPA);
    cargarGrafo(mapa, grafoPonderado);
    grafoPonderado->floydWarshall();
    grafoPonderado->imprimirMatrizAdyacencia();
    cout << endl;
    grafoPonderado->imprimirMatrizCaminosMinimos();

    delete grafoPonderado;

    return 0;
}