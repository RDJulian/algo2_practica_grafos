#ifndef GRAFO_H
#define GRAFO_H
#include "constantes.h"

class Grafo {
  private:
    int** adyacencia;
    int** pesos;
    int** caminos;
    int tamanio;

  public:
    Grafo(int tamanio);
    void agregarAristaPonderada(Arista arista);
    void imprimirMatrizAdyacencia();
    void imprimirMatrizCaminosMinimos();
    void imprimirMatrizPesosMinimos();
    void floydWarshall();
    ~Grafo();
};

#endif