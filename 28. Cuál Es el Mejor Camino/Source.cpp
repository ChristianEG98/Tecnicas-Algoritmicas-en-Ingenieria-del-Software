
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
    int origen, destino;
    vector<Valor> dist;
    vector<Valor> distBFS;
    vector<Valor> distDijkstra;
    IndexPQ<Valor> pq;

    void relajar(Arista<Valor> a, int v) {
        int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            distDijkstra[w] = distDijkstra[v] + 1;
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor() && distDijkstra[w] > distDijkstra[v] + 1) {
            distDijkstra[w] = distDijkstra[v] + 1;
        }
    }

    bool hayCamino(int v) { return distBFS[v] != INF; }

    void bfs(GrafoValorado<Valor> const& g, int origen) {
        distBFS[origen] = 0;
        queue<Valor> cola; cola.push(origen);
        while (!cola.empty()) {
            int v = cola.front(); cola.pop();
            for (auto aristas : g.ady(v)) {
                int w = aristas.otro(v);
                if (distBFS[w] == INF) {
                    distBFS[w] = distBFS[v] + 1;
                    cola.push(w);
                }
            }
        }
    }

public:
    Dijkstra(GrafoValorado<Valor> const& g, int orig, int dest) : origen(orig), destino(dest), dist(g.V(), INF), distBFS(g.V(), INF), distDijkstra(g.V(), INF), pq(g.V()) {
        bfs(g, orig);
        if (hayCamino(dest)) {
            dist[origen] = 0;
            distDijkstra[origen] = 0;
            pq.push(origen, 0);
            while (!pq.empty()) {
                int v = pq.top().elem; pq.pop();
                for (auto a : g.ady(v)) {
                    relajar(a, v);
                }
            }
        }
    }

    void solucion(int v) {
        if (!hayCamino(v)) cout << "SIN CAMINO";
        else {
            cout << dist[v] << " ";
            if (distBFS[v] == distDijkstra[v]) cout << "SI";
            else cout << "NO";
        }
        cout << "\n";
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
    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        int o, d; cin >> o >> d;
        Dijkstra<int> dijkstra(g, o - 1, d - 1);
        dijkstra.solucion(d - 1);
    }
    //Resolucion del problema
    cout << "---\n";
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
