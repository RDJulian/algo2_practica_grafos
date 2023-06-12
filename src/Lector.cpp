#include <sstream>
#include <fstream>
#include "Lector.h"

using namespace std;

pair<size_t, vector<Camino*>> Lector::leerArchivo(const std::string& pathArchivoCSV) {
    size_t nodos;
    vector<Camino*> caminos;
    fstream archivo(pathArchivoCSV);
    string linea, origen, destino, tipoCamino;

    getline(archivo, linea);
    nodos = size_t(stoi(linea));

    while (getline(archivo, linea)) {
        stringstream stream(linea);
        getline(stream, origen, ',');
        getline(stream, destino, ',');
        getline(stream, tipoCamino);
        auto* camino = new Camino(size_t(stoi(origen)), size_t(stoi(destino)), TipoCamino(stoi(tipoCamino)));
        caminos.push_back(camino);
    }

    return {nodos, caminos};
}