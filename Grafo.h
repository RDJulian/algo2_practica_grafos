#ifndef GRAFO_H
#define GRAFO_H
#include "constantes.h"

class Grafo {
  private:
    int** matrizAdyacencia;
    int** matrizCaminosMinimos;
    int tamanio;

  public:
    Grafo(int tamanio);
    void agregarAristaPonderada(Arista arista);
    void imprimirMatrizAdyacencia();
    void imprimirMatrizCaminosMinimos();
    void floydWarshall();
    ~Grafo();
};

#endif