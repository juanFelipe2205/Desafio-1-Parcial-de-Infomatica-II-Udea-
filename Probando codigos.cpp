/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generarMatriz(int filas, int columnas, int valor_inicial) {
    vector<vector<int>> matriz(filas, std::vector<int>(columnas));
    int valor = valor_inicial;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = valor++;
        }
    }

    return matriz;
}

void rotarMatrizContraManecillas(vector<vector<int>>& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    vector<vector<int>> matriz_rotada(columnas, vector<int>(filas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz_rotada[j][filas - 1 - i] = matriz[i][j];
        }
    }
    matriz = matriz_rotada;
}

void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

bool verificarCondicion(const vector<vector<int>>& matriz, int fila, int columna, int valor) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
        return false;
    }
    return matriz[fila][columna] == valor;
}

bool validarClave(const vector<vector<vector<int>>>& matrices, const vector<int>& clave) {
    for (int i = 0; i < clave.size() - 2; ++i) {
        int fila = clave[i];
        int columna = clave[i + 1];
        int valor = clave[i + 2];

        if (!verificarCondicion(matrices[i], fila, columna, valor)) {
            return false;
        }
    }
    return true;
}


void GenerarCerraduras(const vector<int>& clave) {
    vector<vector<vector<int>>> matrices_generadas;
    vector<int> tamaños;
    int tamaño_base = 3; 

    for (int i = 0; i < clave.size() - 2; ++i) {
        int filas = tamaño_base + i;
        int columnas = tamaño_base + i + 1;
        tamaños.push_back(filas);
        matrices_generadas.push_back(generarMatriz(filas, columnas, 1));
    }

    bool clave_valida = false;
    while (!clave_valida) {
        clave_valida = validarClave(matrices_generadas, clave);
        if (!clave_valida) {
            tamaño_base += 2; 
            tamaños.clear();
            matrices_generadas.clear();
            for (int i = 0; i < clave.size() - 2; ++i) {
                int filas = tamaño_base + i;
                int columnas = tamaño_base + i + 1;
                tamaños.push_back(filas);
                matrices_generadas.push_back(generarMatriz(filas, columnas, 1));
            }
        }
    }

    cout << "Matrices finales que cumplen con la clave K:\n";
    for (int i = 0; i < matrices_generadas.size(); ++i) {
        cout << "Matriz " << i + 1 << ":\n";
        imprimirMatriz(matrices_generadas[i]);
        cout << endl;
    }
}

int main() {
    vector<int> clave;
    int valor;
    cout << "Ingrese la clave K: ";
    while (cin >> valor) {
        clave.push_back(valor);
        if (clave.size() >= 2 && clave.size() % 3 == 0) {
            break;
        }
    }

    GenerarCerraduras(clave);

    return 0;
}
