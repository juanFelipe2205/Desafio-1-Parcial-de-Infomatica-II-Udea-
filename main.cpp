#include <iostream>
#include <vector>
#include "matriz_module.h"

using namespace std;

void rotarMatrizContraManecillas(vector<vector<int>>& matriz) {
    int tamaño = matriz.size();
    vector<vector<int>> matriz_rotada(tamaño, vector<int>(tamaño));
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            matriz_rotada[tamaño - 1 - j][i] = matriz[i][j];
        }
    }
    matriz = matriz_rotada;
}

void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            if (elemento == 0) {
                cout << "  ";  
            } else {
                cout << elemento << " ";
            }
        }
        cout << endl;
    }
}

void GenerarCerraduras(const vector<int>& tamaños) {
    vector<vector<vector<int>>> matrices_generadas;

    // Generar las matrices
    for (int tamaño : tamaños) {
        matrices_generadas.push_back(generarMatriz(tamaño));
    }

    // Imprimir y rotar las matrices generadas
    for (int i = 0; i < matrices_generadas.size(); ++i) {
        cout << "Matriz " << i + 1 << ":\n";
        for (int rotacion = 0; rotacion < 4; ++rotacion) {
            cout << "Rotacion " << rotacion + 1 << ":\n";
            imprimirMatriz(matrices_generadas[i]);
            cout << endl;
            rotarMatrizContraManecillas(matrices_generadas[i]);
        }
    }
}


int main() {
    vector<int> tamaños = {9, 3, 5, 3};

    GenerarCerraduras(tamaños);

    return 0;
}
