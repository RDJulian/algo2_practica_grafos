#ifndef PARSER_H
#define PARSER_H
#include "Grafo.h"

bool aristaValida(int columna, int fila);
int indice(int columna, int fila);
void cargarGrafo(int mapa[4][4], Grafo* grafo);

#endif