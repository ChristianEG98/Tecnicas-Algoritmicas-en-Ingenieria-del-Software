
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "Grafo.h"

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

class Nodos { 
private:
    vector<bool> visitados;
    vector<int> distancias;

    void bfs(Grafo const& g, int v) {
        queue<int> q;
        visitados[v] = true;
        distancias[v] = 0;
        q.push(v);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visitados[w]) {
                    distancias[w] = distancias[v] + 1;
                    visitados[w] = true;
                    q.push(w);
                }
            }
        }
    }

public:
    Nodos(Grafo const& g, int const inicio) : visitados(g.V(), false), distancias(g.V(), -1) {
        bfs(g, inicio);
    }
    int inalcanzable(int ttl) const {
        int in = 0;
        for (int i = 0; i < distancias.size(); i++) {
            if (distancias[i] > ttl || distancias[i] == -1) in++;
        }
        return in;
    }
};

//Coste O(N+C)
bool resuelveCaso() {
    //Lectura de datos
    int N, C; //N = Numero de nodos de la red / C = Conexiones entre nodos
    cin >> N >> C;
    if (!cin) return false;
    Grafo g(N);
    for (int i = 0; i < C; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        g.ponArista(n1 - 1, n2 - 1);
    }
    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        int inicio, ttl; cin >> inicio >> ttl;
        Nodos n(g, inicio - 1);
        cout << n.inalcanzable(ttl) << "\n";
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
