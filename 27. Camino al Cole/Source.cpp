
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
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

template <typename Valor>
class Dijkstra {
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    vector<Valor> dist;
    IndexPQ<Valor> pq;
    vector<Valor> numCaminos;

    void relajar(Arista<Valor> a, int v) {
        int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            numCaminos[w] = numCaminos[v];
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor()) {
            numCaminos[w] += numCaminos[v];
        }
    }
public:
    Dijkstra(GrafoValorado<Valor> const& g, int orig) : origen(orig), dist(g.V(), INF), pq(g.V()), numCaminos(g.V(), 0) {
        dist[origen] = 0;
        numCaminos[origen] = 1;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v)){
                relajar(a, v);
            }
        }
    }

    void cuantosCaminos(int v) const {
        cout << numCaminos[v - 1];
    }
};

bool resuelveCaso() { //Coste en tiempo O(C log N) y un espacio adicional en O(N)
    //Lectura de datos
    int N, C; //N = Numero de intersecciones / C = Numero de calles
    cin >> N >> C;
    if (!cin) return false;
    GrafoValorado<int> g(N);
    for (int i = 0; i < C; i++) {
        int a1, a2, valor; cin >> a1 >> a2 >> valor;
        g.ponArista({ a1 - 1, a2 - 1, valor });
    }
    //Resolucion del problema
    Dijkstra<int> d(g, 0);
    d.cuantosCaminos(N);
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
