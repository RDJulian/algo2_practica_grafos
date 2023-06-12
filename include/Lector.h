#ifndef ALGO2_PRACTICA_GRAFOS_LECTOR_H
#define ALGO2_PRACTICA_GRAFOS_LECTOR_H

#include <vector>
#include "Camino.h"

class Lector {
public:
    static std::pair<size_t, std::vector<Camino* >> leerArchivo(const std::string& pathArchivoCSV);
};

#endif
