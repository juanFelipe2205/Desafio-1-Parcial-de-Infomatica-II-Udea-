#include <iostream>
#include "matriz_operaciones.h"

using namespace std;

bool verificarCondicion(int matriz[MAX_SIZE][MAX_SIZE], int tamaño, int fila, int columna, int relacion) {
    if (fila < 0 || fila >= tamaño || columna < 0 || columna >= tamaño) {
        return false;
    }
    int valor = matriz[fila][columna];
    int siguiente_valor = (relacion == 1) ? valor - 1 : valor + 1;
    return (siguiente_valor >= 1 && siguiente_valor <= tamaño * tamaño);
}

bool validarClave(int matriz[MAX_SIZE][MAX_SIZE], int tamaño, int fila, int columna, int relacion) {
    return verificarCondicion(matriz, tamaño, fila, columna, relacion);
}

void GenerarCerraduras(const int* clave) {
    int tamaño_base = 5;
    int matriz[MAX_SIZE][MAX_SIZE];

    while (true) {
        generarMatriz(matriz, tamaño_base);

        bool cumplido = true;
        for (int r = 0; r < 3; ++r) {
            if (!validarClave(matriz, tamaño_base, clave[r * 3], clave[r * 3 + 1], clave[r * 3 + 2])) {
                cumplido = false;
                break;
            }
        }

        if (cumplido) {
            cout << "X(" << tamaño_base << ")" << endl;
            break;
        }

        rotarMatrizContraManecillas(matriz, tamaño_base);
        tamaño_base += 2;
    }
}
