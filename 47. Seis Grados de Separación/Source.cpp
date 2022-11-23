
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Matriz.h"
#include "EnterosInf.h"
#include <unordered_map>

using namespace std;

/*@ <answer>

 G[i][j] = 0 si i = j
 G[i][j] = Coste si hay arista entre i y j
 G[i][j] = Infinito si no hay arista entre i y j

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void Floyd(Matriz<EntInf> const& G, Matriz<EntInf>& C, Matriz<int>& camino) {
    int n = G.numfils() - 1;
    C = G;
    camino = Matriz<int>(n + 1, n + 1, 0);

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                EntInf temp = C[i][k] + C[k][j];
                if (temp < C[i][j]) {
                    C[i][j] = temp;
                    camino[i][j] = k;
                }
            }
        }
    }
}

bool resuelveCaso() { //Coste O(P ^ 3) en tiempo y O(HashMap) en espacio adicional
    //Lectura de datos
    int P, R; //P = Numero personas / R = Numero de relaciones
    cin >> P >> R;
    if (!cin) return false;
    unordered_map<string, int> relaciones;
    Matriz<EntInf> grafo(P + 1, P + 1, Infinito);
    //Resolucion del problema
    for (int d = 1; d <= P; d++) { //Distancia 0 cada persona con sigo mismo
        grafo[d][d] = 0;
    }
    int id = 1;
    for (int i = 0; i < R; i++) {
        string n1, n2; cin >> n1 >> n2;
        if (relaciones[n1] == 0) {
            relaciones[n1] = id;
            id++;
        }
        if (relaciones[n2] == 0) {
            relaciones[n2] = id;
            id++;
        }
        grafo[relaciones[n1]][relaciones[n2]] = 1;
        grafo[relaciones[n2]][relaciones[n1]] = 1;
    }

    Matriz<EntInf> C(0, 0);
    Matriz<int> camino(0, 0);
    Floyd(grafo, C, camino);

    EntInf max = 0;
    for (int i = 1; i <= P; i++) {
        for (int j = 1; j <= P; j++) {
            max = std::max(max, C[i][j]);
        }
    }

    if (max == Infinito) cout << "DESCONECTADA";
    else cout << max;
    cout << "\n";

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
