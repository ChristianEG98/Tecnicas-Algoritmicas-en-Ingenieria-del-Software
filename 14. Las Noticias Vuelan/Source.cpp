
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

class Noticias { 
private:
    vector<bool> visitados;
    vector<int> maximosXUsuario;
    int N;

    int dfs(Grafo const& g, int v, vector<int>& conectados) {
        visitados[v] = true;
        int tam = 1;
        for (int w: g.ady(v)) {
            if (!visitados[w]) {
                tam += dfs(g, w, conectados);
                conectados.push_back(w);
            }
        }
        return tam;
    }


public:
    Noticias(Grafo const& g) : N(g.V()), visitados(g.V(), false), maximosXUsuario(g.V(), 0) {
        for (int i = 0; i < g.V(); ++i) {
            vector<int> conectados;
            if (!visitados[i]) {
                conectados.push_back(i);
                int tam = dfs(g, i, conectados);
                for (int j : conectados) {
                    maximosXUsuario[j] = tam;
                }
            }
        }
    }
    int maximos(int i) const {
        return maximosXUsuario[i];
    }
};

//Coste O(N+M)
bool resuelveCaso() {
    //Lectura de datos
    int N, M; //N = Numero de usuarios de la red / M = Numero de grupos 
    cin >> N >> M;
    if (!cin) return false;
    Grafo g(N);
    int numUsuarios, am1, am2;
    for (int i = 0; i < M; i++) {
        cin >> numUsuarios;
        if (numUsuarios > 0) {
            cin >> am1;
            for (int j = 0; j < numUsuarios - 1; j++) {
                cin >> am2;
                g.ponArista(am1 - 1, am2 - 1);
                am1 = am2;
            }
        }
    }
    //Resolucion del problema
    Noticias n(g);
    for (int i = 0; i < N; i++) {
        cout << n.maximos(i) << " ";
    }
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
