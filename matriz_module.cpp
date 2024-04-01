#include "matriz_module.h"
using namespace std;

vector<vector<int>> generarMatriz(int tamaño) {
    vector<vector<int>> matriz(tamaño, std::vector<int>(tamaño));
    int valor = 1;
    int centro = tamaño / 2;

    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            matriz[i][j] = valor++;
            if (i == centro && j == centro) {
                valor -= 1;
            }
        }
    }
    matriz[centro][centro] = 0;

    return matriz;
}
