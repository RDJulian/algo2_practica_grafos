#include "Grafo.h"
#include "parser.h"
#include <iostream>

using namespace std;

int main() {
    int mapa[TAMANIO_MAPA][TAMANIO_MAPA] = {
        {C, T, T},
        {C, C, P},
        {T, C, C},
    };

    Grafo* grafoPonderado = new Grafo(TAMANIO_MAPA * TAMANIO_MAPA);
    cargarGrafo(mapa, grafoPonderado);
    grafoPonderado->floydWarshall();
    grafoPonderado->imprimirMatrizAdyacencia();
    cout << endl;
    grafoPonderado->imprimirMatrizPesosMinimos();
    cout << endl;
    grafoPonderado->imprimirMatrizCaminosMinimos();

    delete grafoPonderado;

    return 0;
}