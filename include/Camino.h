#ifndef ALGO2_PRACTICA_GRAFOS_CAMINO_H
#define ALGO2_PRACTICA_GRAFOS_CAMINO_H

#include <cstddef>
#include "constantes.h"

class Camino {
private:
    size_t origen;
    size_t destino;
    TipoCamino camino;
public:
    Camino(size_t origen, size_t destino, TipoCamino camino);

    Arista calcularArista();

    Arista calcularAristaRota();

    bool esCaminoRoto();

    bool operator==(std::pair<size_t, size_t> vertices) const;
};


#endif