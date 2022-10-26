
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
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

class Rumor { 
private:
    vector<bool> visitados;
    vector<int> precio;
    int oro;

    void bfs(Grafo const& g, int v, vector<int>& conectados) {
        queue<int> q;
        visitados[v] = true;
        q.push(v);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visitados[w]) {
                    visitados[w] = true;
                    conectados.push_back(w);
                    q.push(w);
                }
            }
        }
    }

    void oroMinimo(vector<int> const& c) {
        int min = INT_MAX;
        for (int i = 0; i < c.size(); i++) {
            if (precio[c[i]] < min) min = precio[c[i]];
        }
        oro += min;
    }

public:
    Rumor(Grafo const& g, vector<int> const& _p) : visitados(g.V(), false), precio(_p), oro(0) {
        for (int i = 0; i < g.V(); i++) { //Si hay mas de una componente conexa
            vector<int> conectados;
            if (!visitados[i]) {
                conectados.push_back(i);
                bfs(g, i, conectados);
                oroMinimo(conectados);
            }
        }
    }
    int cantidadOro() {
        return oro;
    }
};

//Coste O(N+M)
bool resuelveCaso() {
    //Lectura de datos
    int N, M; //N = Numero de personajes / M = Pares de amigos
    cin >> N >> M;
    if (!cin) return false;

    vector<int> precio(N);
    for (int i = 0; i < N; i++) cin >> precio[i]; //Monedas personajes

    Grafo g(N);
    for (int i = 0; i < M; i++) {
        int p1, p2; cin >> p1 >> p2;
        g.ponArista(p1 - 1, p2 - 1);
    }
    //Resolucion del problema
    Rumor r(g, precio);
    cout << r.cantidadOro();
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
