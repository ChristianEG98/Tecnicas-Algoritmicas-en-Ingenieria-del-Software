
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
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

//Coste en tiempo O(A log V) siendo A = nCaminos y V = nCasas
//Coste en espacio O(V) siendo V = nCasas

const int INF = std::numeric_limits<int>::max();

class Paquetes {
private:
    vector<int> dist;
    IndexPQ<int> pq;

public:
    Paquetes(DigrafoValorado<int> const& dv, const int oficina) : pq(dv.V()), dist(dv.V(), INF) {
        dist[oficina] = 0;
        pq.push(oficina, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : dv.ady(v)){
                int v = a.desde(), w = a.hasta();
                if (dist[w] > dist[v] + a.valor()) {
                    dist[w] = dist[v] + a.valor();
                    pq.update(w, dist[w]);
                }
            }
        }
    }

    int distancia(int v) {
        return dist[v];
    }

    bool haySolucion(int v) {
        return dist[v] != INF;
    }
};

bool resuelveCaso() {
    //Lectura de datos
    int nCasas, nCaminos;
    cin >> nCasas >> nCaminos;
    if (!cin) return false;
    DigrafoValorado<int> dv(nCasas);
    for (int i = 0; i < nCaminos; i++) {
        int a1, a2, esf; cin >> a1 >> a2 >> esf;
        dv.ponArista({ a1 - 1, a2 - 1, esf });
    }
    int oficina, paquetes;
    cin >> oficina >> paquetes;
    //Resolucion del problema
    Paquetes p(dv, oficina - 1);
    Paquetes pInv(dv.inverso(), oficina - 1);
    int esfuerzoMin = 0; bool esPosible = true;
    for (int i = 0; i < paquetes; i++) {
        int casa; cin >> casa; casa--;
        if (p.haySolucion(casa) && pInv.haySolucion(casa)) {
            esfuerzoMin += p.distancia(casa);
            esfuerzoMin += pInv.distancia(casa);
        }
        else esPosible = false;
    }
    if (esPosible) cout << esfuerzoMin;
    else cout << "Imposible";
    cout << '\n';
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
