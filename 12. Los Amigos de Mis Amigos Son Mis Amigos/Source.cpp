
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

class MaximaCompConexa { 
private:
    vector<bool> visitados;
    int maxim;

    int dfs(Grafo const& g, int v) {
        visitados[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visitados[w]) {
                tam += dfs(g, w);
            }
        }
        return tam;
    }

public:
    MaximaCompConexa(Grafo const& g) : visitados(g.V(), false), maxim(0) {
        for (int v = 0; v < g.V(); ++v) {
            if (!visitados[v]) { //Para recorrer nuevas componentes conexas
                int tam = dfs(g, v);
                maxim = max(maxim, tam);
            }
        }
    }
    int maximo() const {
        return maxim;
    }
};

//Coste O(N + M)
void resuelveCaso() {
    //Lectura de datos
    int N, M;
    cin >> N >> M;
    Grafo g(N);
    int v, w;
    for (int i = 0; i < M; ++i) {
        cin >> v >> w;
        g.ponArista(v - 1, w - 1);
    }
    //Resolucion del problema
    MaximaCompConexa mcc(g);
    cout << mcc.maximo();
    cout << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
       resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
