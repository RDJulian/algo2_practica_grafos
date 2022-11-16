#ifndef PARSER_H
#define PARSER_H
#include "Grafo.h"

bool verticeValido(int columna, int fila);
int indice(int columna, int fila);
void cargarGrafo(int mapa[TAMANIO_MAPA][TAMANIO_MAPA], Grafo* grafo);

#endif