/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generarMatriz(int tamaño) {
    vector<vector<int>> matriz(tamaño, vector<int>(tamaño));
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
    for (int tamaño : tamaños) {
        matrices_generadas.push_back(generarMatriz(tamaño));
    }
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




