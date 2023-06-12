#include "Subsets.h"

using namespace std;

int Subsets::cantidadElementos(int bitmask) {
    int cantidad = 0;
    while (bitmask > 0) {
        cantidad += bitmask & 1;
        bitmask >>= 1;
    }
    return cantidad;
}

vector<vector<int>> Subsets::obtenerSubsets(const vector<int>& set, int tamSubset) {
    vector<vector<int>> subsets;
    int totalSubsets = 1 << set.size();
    for (int bitmask = 0; bitmask < totalSubsets; bitmask++) {
        if (cantidadElementos(bitmask) == tamSubset) {
            vector<int> subset;
            for (size_t i = 0; i < set.size(); i++) {
                if (bitmask & (1 << i))
                    subset.push_back(set[i]);
            }
            subsets.push_back(subset);
        }
    }
    return subsets;
}