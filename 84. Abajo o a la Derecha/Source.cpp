
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Matriz.h"

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool dentroLimites(int f, int c, int fi, int cj) {
    return fi < f && cj < c;
}

int numCaminos(Matriz<int> const& celdas) {
    int f = celdas.numfils();
    int c = celdas.numcols();
    Matriz<int> sol(f, c, 0);
    sol[0][0] = 1;
    int fi, cj;
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if (sol[i][j] != 0) {
                fi = i + celdas[i][j];
                cj = j + celdas[i][j];
                if (dentroLimites(f, c, fi, j)) {
                    sol[fi][j] += sol[i][j];
                }
                if (dentroLimites(f, c, i, cj)) {
                    sol[i][cj] += sol[i][j];
                }
            }
        }
    }
    return sol[f - 1][c - 1];
}

bool resuelveCaso() {
    //Lectura de datos
    int N, M;
    cin >> N >> M;
    if (!cin) return false;
    Matriz<int> celdas(N, M);
    for(int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> celdas[i][j];
    //Resolucion del problema
    cout << numCaminos(celdas) << "\n";
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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
