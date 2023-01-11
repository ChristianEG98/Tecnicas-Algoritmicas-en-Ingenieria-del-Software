
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

class Guardias {
private:
    vector<bool> colocado;
    vector<bool> visit;
    bool haySolucion;
    int nGuardias;
    int rojos, azules;

    void dfs(Grafo const& g, int v) {
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                if (colocado[v] == false) {
                    colocado[w] = true;
                    rojos++;
                }
                else azules++;
                dfs(g, w);
            }
            else{
                if (colocado[w] == colocado[v]) haySolucion = false;
            }
        }
    }

public:
    Guardias(Grafo const& g) : colocado(g.V(), false), visit(g.V(), false), haySolucion(true), azules(1), rojos(0), nGuardias(0) {
        for (int i = 0; i < g.V(); i++) {
            if (!visit[i]) {
                dfs(g, i);
                nGuardias += min(rojos, azules);
                rojos = 0; azules = 1;
            }
        }
    }

    bool haySol() { return haySolucion; }

    int numGuardias() { return nGuardias; }
};

bool resuelveCaso() {
    //Lectura de datos
    int N, C;
    cin >> N >> C;
    if (!cin) return false;
    //Resolucion del problema
    Grafo g(N);
    for (int i = 0; i < C; i++) {
        int a1, a2; cin >> a1 >> a2;
        g.ponArista(a1 - 1, a2 - 1);
    }
    Guardias sol(g);
    if (sol.haySol()) cout << sol.numGuardias();
    else cout << "IMPOSIBLE";
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
