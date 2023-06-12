#ifndef ALGO2_PRACTICA_GRAFOS_SUBSETS_H
#define ALGO2_PRACTICA_GRAFOS_SUBSETS_H

#include <vector>

class Subsets {
private:
    static int cantidadElementos(int bitmask);

public:
    static std::vector<std::vector<int>> obtenerSubsets(const std::vector<int>& set, int tamSubset);
};

#endif