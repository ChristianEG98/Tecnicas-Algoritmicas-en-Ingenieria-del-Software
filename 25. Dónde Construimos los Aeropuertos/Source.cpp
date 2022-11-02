
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

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

class ARM_Kruskal {
private:
    vector<Arista<int>> _ARM;
    GrafoValorado<int> g;
    int coste, numAeropuertos;

    void costeMin(int A) {
        auto ar = g.aristas();
        priority_queue<Arista<int>, vector<Arista<int>>, greater<Arista<int>>> pq(ar.begin(), ar.end()); //De menor a mayor valor de aristas
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w) && a.valor() < A) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste += a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        numAeropuertos = cjtos.num_cjtos();
        coste += numAeropuertos * A;
    }

public:
    ARM_Kruskal(GrafoValorado<int> const& _g) : coste(0), numAeropuertos(0), g(_g) { }

    void costeARM(int A) {
        costeMin(A);
        cout << coste << " " << numAeropuertos;
    }
    vector<Arista<int>> const& ARM() const {
        return _ARM;
    }
};

bool resuelveCaso() { //Coste O(M logM)
    //Lectura de datos
    int N, M, A; //N = Numero de localidades / M = Numero de caminos / A = Coste aeropuerto
    cin >> N >> M >> A;
    if (!cin) return false;
    GrafoValorado<int> gv(N);
    for (int i = 0; i < M; i++) {
        int v1, v2, valor; cin >> v1 >> v2 >> valor;
        gv.ponArista({ v1 - 1, v2 - 1, valor });
    }
    //Resolucion del problema
    ARM_Kruskal kruskal(gv);
    kruskal.costeARM(A);
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
