#include "matriz_operaciones.h"

void generarMatriz(int matriz[MAX_SIZE][MAX_SIZE], int tamaño) {
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
}

void rotarMatrizContraManecillas(int matriz[MAX_SIZE][MAX_SIZE], int tamaño) {
    int matriz_rotada[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            matriz_rotada[tamaño - 1 - j][i] = matriz[i][j];
        }
    }

    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            matriz[i][j] = matriz_rotada[i][j];
        }
    }
}
