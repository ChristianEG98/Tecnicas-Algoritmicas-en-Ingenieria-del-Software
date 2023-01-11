
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
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

class Autonomia {
private:
    vector<bool> visit;

    void dfs(GrafoValorado<int> const& gv, int v) { //O(V + A)
        visit[v] = true;
        for (auto a : gv.ady(v)) {
            int w = a.otro(v);
            if (!visit[w])
                dfs(gv, w);
        }
    }

public:
    Autonomia(GrafoValorado<int> const& gv) : visit(gv.V(), false) {
        dfs(gv, 0);
    }

    int Kruskal(GrafoValorado<int> const& gv) { //O(A log A) en tiempo y O(A) en espacio
        int size = 0, autMinima = 0;
        PriorityQueue<Arista<int>> pq(gv.aristas());
        ConjuntosDisjuntos cjtos(gv.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                size++;
                if (a.valor() > autMinima) autMinima = a.valor();
                if (size == gv.V() - 1) break;
            }
        }
        return autMinima;
    }

    bool esConexo() const {
        bool conexo = true;
        for (int i = 0; i < visit.size(); i++) {
            if (!visit[i])
                conexo = false;
        }
        return conexo;
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
    Autonomia sol(gv);
    if (sol.esConexo()) cout << sol.Kruskal(gv);
    else cout << "Imposible";
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
