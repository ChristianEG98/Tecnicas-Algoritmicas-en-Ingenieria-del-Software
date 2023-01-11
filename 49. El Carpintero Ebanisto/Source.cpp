 /*@ <answer>
  *
  * Nombre y Apellidos: Christian Esteban
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include "EnterosInf.h"

using namespace std;

/*@ <answer>

 Caso base: f(i, i + 1) = 0 si los cortes son consecutivos e indivisibles
 Caso recursivo: f(i, j) = min(f(i, k) + f(k, j) + 2 * M[j] - M[i])

 Llamada inicial: f(0, numMarcas - 1)

 Coste O(numMarcas ^ 3) en tiempo y O(numMarcas ^ 2) en espacio

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

EntInf cortesMinimo(vector<int> & tabla) {
    int numMarcas = tabla.size();
    Matriz<EntInf> sol(numMarcas, numMarcas, Infinito);
    for (int i = 0; i < numMarcas - 1; i++) {
        sol[i][i + 1] = 0; //Diagonal
    }
    for (int d = 2; d <= numMarcas; d++) {
        for (int i = 0; i < numMarcas - d; i++) {
            int j = i + d;
            EntInf minimo = Infinito;
            for (int k = i + 1; k < j; k++) {
                minimo = std::min(minimo, sol[i][k] + sol[k][j] + 2 * (tabla[j] - tabla[i]));
            }
            sol[i][j] = minimo;
        }
    }
    return sol[0][numMarcas - 1];
}

bool resuelveCaso() {
    // leemos la entrada
    int L, N;
    cin >> L >> N;
    if (L == 0 || N == 0) return false;
    vector<int> tabla(N + 2);
    tabla[0] = 0; tabla[N + 1] = L;
    for (int i = 1; i <= N; i++) {
        cin >> tabla[i];
    }
    // resolver el caso
    cout << cortesMinimo(tabla);
    cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
