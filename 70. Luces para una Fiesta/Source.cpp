 /*@ <answer>
  *
  * Nombre y Apellidos: Christian Esteban
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "EnterosInf.h"

using namespace std;

/*@ <answer>

 costeBombillas(i, P) = Coste minimo de una instalacion con una potencia P utilizando tantas bombillas como queramos de cada modelo que tengamos.

 - Casos base:
 costeBombillas(0, P) = Infinito si P > 0
 costeBombillas(i, 0) = 0 si P = 0
 - Casos rescursivos:
 costeBombillas(i, P) = min(costeBombillas(i, P), costeBombillas(i, P - bombillas[i].potencia + bombillas[i].coste)) si bombillas[i].potencia <= P

 Coste O(N * PMax) en tiempo y O(PMax) en espacio

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tBombilla {
    int potencia;
    int coste;
};

pair<EntInf, int> resolver(vector<tBombilla> const& B, int const& pMax, int const& pMin) {
    int n = B.size();
    vector<EntInf> sol(pMax + 1, Infinito);
    sol[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= pMax; j++) {
            if (B[i].potencia <= j) {
                sol[j] = std::min(sol[j], sol[j - B[i].potencia] + B[i].coste);
            }
        }
    }
    EntInf costeMin = sol[pMin];

    int potencia = pMin;
    for (int j = pMin; j <= pMax; j++) {
        if (costeMin > sol[j]) {
            costeMin = sol[j];
            potencia = j;
        }
    }

    return { costeMin, potencia };
}

bool resuelveCaso() {
    // leemos la entrada
    int N, pMax, pMin;
    cin >> N >> pMax >> pMin;
    if (!cin) return false;
    vector<tBombilla> bombillas(N);
    for (int i = 0; i < N; i++) {
        cin >> bombillas[i].potencia;
    }
    for (int i = 0; i < N; i++) {
        cin >> bombillas[i].coste;
    }
    // resolver el caso
    pair<EntInf, int> sol = resolver(bombillas, pMax, pMin);
    if (sol.first == Infinito) cout << "IMPOSIBLE";
    else cout << sol.first << " " << sol.second;
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
