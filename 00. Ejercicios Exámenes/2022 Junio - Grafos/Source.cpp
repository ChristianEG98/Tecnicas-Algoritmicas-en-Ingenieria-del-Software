
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

class DFS {
private:
    vector<bool> visit;
    int oroMinimo;

    void dfs(Grafo const& g, int v, vector<int> const& oro, int & oroAux) {
        visit[v] = true;
        if (oro[v] < oroAux) oroAux = oro[v];
        for (int w : g.ady(v)) {
            if (!visit[w])
                dfs(g, w, oro, oroAux);
        }
    }

public:
    DFS(Grafo const& g, vector<int> const& oro) : visit(g.V(), false), oroMinimo(0) {
        for (int v = 0; v < g.V(); v++) {
            if (!visit[v]) { //Nueva componente conexa
                int oroAux = 10000;
                dfs(g, v, oro, oroAux); //Coste O(V + A)
                oroMinimo += oroAux;
            }
        }
    }

    int oroMin() const {
        return oroMinimo;
    }
};

bool resuelveCaso() {
    //Lectura de datos
    int V, A;
    cin >> V >> A;
    if (!cin) return false;
    vector<int> oro(V);
    for (int i = 0; i < oro.size(); i++) cin >> oro[i];
    Grafo g(V);
    for (int i = 0; i < A; i++) {
        int a1, a2; cin >> a1 >> a2;
        g.ponArista(a1 - 1, a2 - 1);
    }
    //Resolucion del problema
    DFS sol(g, oro);
    cout << sol.oroMin() << "\n";
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
