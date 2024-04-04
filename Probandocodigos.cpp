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

bool verificarCondicion(const vector<vector<int>>& matriz, int fila, int columna, int relacion) {
    int tamaño = matriz.size();
    if (fila < 0 || fila >= tamaño || columna < 0 || columna >= tamaño) {
        return false;
    }
    int valor = matriz[fila][columna];
    int siguiente_valor = (relacion == 1) ? valor - 1 : valor + 1;
    return (siguiente_valor >= 1 && siguiente_valor <= tamaño * tamaño);
}

bool validarClave(const vector<vector<int>>& matriz, int fila, int columna, int relacion) {
    return verificarCondicion(matriz, fila, columna, relacion);
}

void GenerarCerraduras(const vector<int>& clave) {
    vector<int> X;
    vector<int> rotaciones;
    int tamaño_base = 5; 

    while (true) {
        int rotaciones_contador = 0;
        vector<vector<vector<int>>> matrices;
        for (int i = 0; i < clave.size(); i += 3) {
            matrices.push_back(generarMatriz(tamaño_base));
        }

        bool cumplido = true;
        for (int r = 0; r < matrices.size(); ++r) {
            if (!validarClave(matrices[r], clave[r * 3], clave[r * 3 + 1], clave[r * 3 + 2])) {
                cumplido = false;
                break;
            }
        }

        if (cumplido) {
            X.push_back(tamaño_base);
            rotaciones.push_back(rotaciones_contador);
            break;
        }

        for (auto& matriz : matrices) {
            rotarMatrizContraManecillas(matriz);
        }
        rotaciones_contador++;
        tamaño_base += 2; 
    }

    cout << "X(";
    for (int i = 0; i < X.size(); ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << X[i];
    }
    cout << ")" << endl;

    for (int i = 0; i < rotaciones.size(); ++i) {
        cout << "Rotaciones de la matriz " << i + 1 << ": " << rotaciones[i] << endl;
    }
}

int main() {
    vector<int> clave = {4, 3, 1, -1, 1};
    GenerarCerraduras(clave);

    return 0;
}
