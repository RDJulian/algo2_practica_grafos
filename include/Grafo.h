#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include "Matriz.h"
#include "constantes.h"

class Grafo {
private:
    Matriz* adyacencia;
    Matriz* pesos;
    Matriz* caminos;
    size_t vertices;
    bool hayCambios;

    void floydWarshall();

    void _floydWarshall();

public:

    explicit Grafo(size_t vertices);

    void agregarAristaPonderada(Arista arista);

    int obtenerPesoMinimo(size_t origen, size_t destino);

    std::vector<size_t> obtenerCaminoMinimo(size_t origen, size_t destino);

    ~Grafo();
};

#endif