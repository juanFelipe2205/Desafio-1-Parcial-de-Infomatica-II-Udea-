/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

// Función para generar una matriz con el centro vacío
vector<vector<int>> generarMatriz(int tamaño) {
    vector<vector<int>> matriz(tamaño, vector<int>(tamaño));

    // Llenar la matriz con valores del 1 al tamaño^2
    int valor = 1;
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            matriz[i][j] = valor++;
        }
    }

    // Vaciar el centro
    int centro = tamaño / 2;
    matriz[centro][centro] = 0;

    return matriz;
}

// Función para rotar una matriz en sentido contrario a las manecillas del reloj
void rotarMatrizContraManecillas(vector<vector<int>>& matriz) {
    int tamaño = matriz.size();
    vector<vector<int>> matriz_rotada(tamaño, vector<int>(tamaño));

    // Rotar la matriz en sentido contrario a las manecillas del reloj
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            matriz_rotada[i][j] = matriz[j][tamaño - 1 - i];
        }
    }

    // Copiar la matriz rotada a la matriz original
    matriz = matriz_rotada;
}

// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            if (elemento == 0) {
                cout << "  ";  // Imprimir dos espacios en blanco en lugar de 0
            } else {
                cout << elemento << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<int> tamaños = {5, 9, 3, 7};
    vector<vector<vector<int>>> matrices_generadas;

    // Generar las matrices de acuerdo a los tamaños dados
    for (int tamaño : tamaños) {
        matrices_generadas.push_back(generarMatriz(tamaño));
    }

    // Mostrar las matrices generadas y sus rotaciones
    for (int i = 0; i < matrices_generadas.size(); ++i) {
        cout << "Matriz " << i + 1 << ":\n";
        for (int rotacion = 0; rotacion < 4; ++rotacion) {
            cout << "Rotacion " << rotacion + 1 << ":\n";
            imprimirMatriz(matrices_generadas[i]);
            cout << endl;
            rotarMatrizContraManecillas(matrices_generadas[i]);
        }
    }

    return 0;
}
