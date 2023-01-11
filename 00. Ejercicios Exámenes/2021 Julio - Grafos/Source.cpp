
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"
#include "IndexPQ.h"

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

#define INFINITO 10000000

class BarroCity { //O(A log V)
private:
    int coste;
    IndexPQ<int> pq;
    vector<int> distTo;
    vector<int> marked;
    vector<Arista<int>> edgeTo;

    void visit(GrafoValorado<int> const& gv, int v, int & vVisitados) {
        marked[v] = true;
        vVisitados++;
        for (auto a : gv.ady(v)) {
            int w = a.otro(v);
            if (!marked[w]) {
                if (a.valor() < distTo[w]) {
                    edgeTo[w] = a;
                    distTo[w] = a.valor();
                    pq.update(w, a.valor());
                }
            }
        }
    }

    void prim(GrafoValorado<int> const& gv) {
        distTo[0] = 0;
        pq.push(0, 0);
        int vVisitados = 0;
        while (!pq.empty()) {
            int aux = pq.top().elem;
            pq.pop();
            visit(gv, aux, vVisitados);
        }
        if (vVisitados == gv.V()) {
            for (int i = 0; i < distTo.size(); i++) {
                coste += distTo[i];
            }
        }
        else coste = -1;
    }

public:
    BarroCity(GrafoValorado<int> const& gv) : pq(gv.V()), edgeTo(gv.V()), distTo(gv.V(), INFINITO),
        marked(gv.V(), false), coste(0) {
        if (gv.V() > 1) prim(gv);
    }

    int getCoste() const {
        return coste;
    }
};

bool resuelveCaso() {
    //Lectura de datos
    int V, A;
    cin >> V >> A;
    if (!cin) return false;
    GrafoValorado<int> gv(V);
    for (int i = 0; i < A; i++) {
        int a1, a2, v; cin >> a1 >> a2 >> v;
        gv.ponArista({ a1 - 1, a2 - 1, v });
    }
    //Resolucion del problema
    BarroCity bc(gv);
    if (bc.getCoste() == -1) cout << "Imposible";
    else cout << bc.getCoste();
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
