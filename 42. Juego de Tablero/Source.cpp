
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

using namespace std;

/*@ <answer>

    - tablero[i][j] = valor maximo hasta la fila i y la columna j del mismo.

    - tablero[i][j] = maximo(tablero[i-1][j-1], tablero[i-1][j], tablero[i-1][j+1]) + tablero[i][j]

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tSol {
    int maxValor;
    int celda;
};

tSol resolver(Matriz<int> & tablero) {
    int t = tablero.numfils() - 1;
    tSol sol; sol.celda = 0; sol.maxValor = 0;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= t; j++) {
            tablero[i][j] = std::max(tablero[i - 1][j - 1], std::max(tablero[i - 1][j], tablero[i - 1][j + 1])) + tablero[i][j];
        }
    }

    for (int j = 1; j <= t; j++) {
        if (tablero[t][j] > sol.maxValor) {
            sol.maxValor = tablero[t][j];
            sol.celda = j;
        }
    }
    return sol;
}

bool resuelveCaso() { //Coste O(N*N + N) en tiempo y O(N * N) en espacio
    //Lectura de datos
    int N;
    cin >> N;
    if (!cin) return false;
    Matriz<int> tablero(N + 1, N + 2, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tablero[i][j];
        }
    }
    //Resolucion del problema
    tSol sol = resolver(tablero);
    cout << sol.maxValor << " " << sol.celda << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while(resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
