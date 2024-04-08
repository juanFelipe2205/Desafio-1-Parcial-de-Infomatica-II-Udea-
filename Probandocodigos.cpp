#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> generarMatriz(int tamaño) {
    vector<vector<int>> matriz(tamaño, vector<int>(tamaño));
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            matriz[i][j] = i * tamaño + j + 1;
        }
    }
    matriz[tamaño / 2][tamaño / 2] = 0; 
    return matriz;
}

void rotarMatrizContraManecillas(vector<vector<int>>& matriz, int tamaño) {
    vector<vector<int>> matriz_rotada(tamaño, vector<int>(tamaño));
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            matriz_rotada[i][j] = matriz[tamaño - 1 - j][i];
        }
    }
    matriz = matriz_rotada;
}

void imprimirMatriz(const vector<vector<int>>& matriz, int tamaño) {
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            if (matriz[i][j] == 0) {
                cout << "  ";
            } else {
                cout << matriz[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void GenerarCerraduras(int tamañoPrimeraMatriz, const vector<int>& claveK) {
    vector<vector<vector<int>>> matrices_generadas;
    int tamaño = tamañoPrimeraMatriz;
    vector<vector<int>> matriz_actual = generarMatriz(tamaño);
    int fila_clave = claveK[0];
    int columna_clave = claveK[1];

    for (int i = 2; i < claveK.size(); ++i) {
        int valor_clave = claveK[i];
        for (int j = 0; j < valor_clave; ++j) {
            if (matriz_actual[fila_clave][columna_clave] < matriz_actual[fila_clave + 1][columna_clave]) {
                rotarMatrizContraManecillas(matriz_actual, tamaño);
            } else if (matriz_actual[fila_clave][columna_clave] > matriz_actual[fila_clave + 1][columna_clave]) {
                tamaño += 2;
                matriz_actual = generarMatriz(tamaño);
                j = -1; 
            } else {
          
                ++fila_clave;
                if (fila_clave >= tamaño - 1) {
                    cout << "Se ha alcanzado el final de la matriz sin cumplir la condición." << endl;
                    break;
                }
            }
        }
        matrices_generadas.push_back(matriz_actual);

        cout << "Matriz " << i - 1 << ":\n";
        imprimirMatriz(matriz_actual, tamaño);
        cout << endl;
    }
}

int main() {
    int tamañoPrimeraMatriz;
    cout << "Ingrese el tamaño de la primera matriz: ";
    cin >> tamañoPrimeraMatriz;

    vector<int> claveK = {4, 3, 1, -1, 1};

    GenerarCerraduras(tamañoPrimeraMatriz, claveK);

    return 0;
}

