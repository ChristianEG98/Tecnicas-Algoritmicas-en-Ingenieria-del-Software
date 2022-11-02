
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
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
    int origen;
    vector<Valor> dist;
    IndexPQ<Valor> pq;
    vector<Valor> msCarga;

    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + msCarga[w]) {
            dist[w] = dist[v] + a.valor() + msCarga[w];
            pq.update(w, dist[w]);
        }
    }
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, vector<Valor> const& v) : origen(orig), dist(g.V(), INF),
        pq(g.V()), msCarga(v) {
        dist[origen] = msCarga[orig];
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v)){
                relajar(a);
            }
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    void navegar(int v) const {
        if (!hayCamino(v - 1)) cout << "IMPOSIBLE";
        else cout << distancia(v - 1);
    }
};

bool resuelveCaso() { //Coste en tiempo O(E log N) y un espacio adicional en O(N)
    //Lectura de datos
    int N; //N = Numero de paginas
    cin >> N;
    if (N == 0) return false;
    vector<int> msCarga(N);
    for (int i = 0; i < N; i++) cin >> msCarga[i];
    int E; cin >> E;
    DigrafoValorado<int> g(N);
    for (int i = 0; i < E; i++) {
        int a1, a2, valor; cin >> a1 >> a2 >> valor;
        g.ponArista({ a1 - 1, a2 - 1, valor });
    }
    //Resolucion del problema
    Dijkstra<int> d(g, 0, msCarga);
    d.navegar(N);
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
