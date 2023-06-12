#include "CaminoDD2.h"
#include <iostream>

using namespace std;

int main() {
    auto* dd2 = new CaminoDD2();

    pair<vector<size_t>, int> camino = dd2->obtenerCaminoMinimo();
    cout << "El camino minimo es: ";
    for (size_t i: camino.first) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Se llega con un costo de: " << camino.second << endl;

    delete dd2;
    return 0;
}