#ifndef ALGO2_PRACTICA_GRAFOS_CAMINODD2_H
#define ALGO2_PRACTICA_GRAFOS_CAMINODD2_H

#include "Grafo.h"
#include "Camino.h"

const std::string PATH_ARCHIVO_CSV = "caminos.csv";

class CaminoDD2 {
private:
    std::vector<Camino*> caminos;
    size_t nodos;
    Grafo* grafo;
    Grafo* grafoRoto;

    Camino* buscarCamino(size_t origen, size_t destino);

public:

    CaminoDD2();

    std::pair<std::vector<size_t>, int> obtenerCaminoMinimo();

    ~CaminoDD2();
};

#endif
