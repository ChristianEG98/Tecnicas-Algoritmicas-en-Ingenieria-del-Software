
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "DigrafoValorado.h"
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

template <typename Valor>
class Dijkstra {
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    vector<Valor> dist;
    IndexPQ<Valor> pq;

    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }
    }

public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, int seg) : dist(g.V(), INF), pq(g.V()) {
        dist[orig] = 0;
        pq.push(orig, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v)) {
                relajar(a);
            }
        }
    }

    int hanSalido(int orig, int seg) {
        int ratones = 0;
        for (int i = 0; i < dist.size(); i++) {
            if (i != orig && dist[i] <= seg) ratones++;
        }
        return ratones;
    }
};

bool resuelveCaso() { //Coste de tiempo O(P log N) y coste en espacio O(N)
    //Lectura de datos
    int N, S, T, P; //N = Numero de celdas / S = Celda de salida / T = Segundos / P = Numero de pasadizos
    cin >> N >> S >> T >> P;
    if (!cin) return false;
    DigrafoValorado<int> g(N);
    for (int i = 0; i < P; i++) {
        int a1, a2, valor; cin >> a1 >> a2 >> valor;
        g.ponArista({ a2 - 1, a1 - 1, valor });
    }
    //Resolucion del problema
    Dijkstra<int> dij(g, S - 1, T);
    cout << dij.hanSalido(S - 1, T);
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
