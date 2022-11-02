
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"

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

class Reparto {
private:
    vector<bool> visit;

    void dfs(GrafoValorado<int> const& gv, int v, int anchura) { //O(V + E)
        visit[v] = true;
        for (auto a : gv.ady(v)) {
            if (a.valor() >= anchura) {
                int w = a.otro(v);
                if (!visit[w]) {
                    dfs(gv, w, anchura);
                }
            }
        }
    }

public:
    Reparto(GrafoValorado<int> const& gv, int origen, int anchura) : visit(gv.V(), false) {
        dfs(gv, origen, anchura);
    }

    bool valeCamion(int destino) {
        return visit[destino];
    }
};

bool resuelveCaso() {
    //Lectura de datos
    int V, E; //V = Numero de intersecciones / E = Numero de calles entre intersecciones
    cin >> V >> E;
    if (!cin) return false;
    GrafoValorado<int> gv(V);
    for (int i = 0; i < E; i++) {
        int v1, v2, valor; cin >> v1 >> v2 >> valor;
        gv.ponArista({ v1 - 1, v2 - 1, valor });
    }
    int K; // K = Numero de consultas
    cin >> K;
    //Resolucion del problema
    for (int i = 0; i < K; i++) {
        int origen, destino, anchura; cin >> origen >> destino >> anchura;
        Reparto r(gv, origen - 1, anchura);
        if (r.valeCamion(destino - 1)) cout << "SI";
        else cout << "NO";
        cout << "\n";
    }
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
