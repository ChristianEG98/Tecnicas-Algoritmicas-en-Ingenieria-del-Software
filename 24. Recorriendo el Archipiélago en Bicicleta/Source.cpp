
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
#include "ConjuntosDisjuntos.h"

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

class ARM_Kruskal {
private:
    vector<Arista<int>> _ARM;
    GrafoValorado<int> g;
    int coste;

    int costeMin() {
        auto ar = g.aristas();
        priority_queue<Arista<int>, vector<Arista<int>>, greater<Arista<int>>> pq(ar.begin(), ar.end()); //De menor a mayor valor de aristas
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste += a.valor();
                if (_ARM.size() == g.V() - 1) return coste;
            }
        }
        return -1;
    }

public:
    ARM_Kruskal(GrafoValorado<int> const& _g) : coste(0), g(_g) { }

    int costeARM() { 
        if (g.V() == 1) return 0;
        else return costeMin();
    }
    vector<Arista<int>> const& ARM() const {
        return _ARM;
    }
};

bool resuelveCaso() { 
    //Lectura de datos
    int I, P; //I = Numero de islas / P = Numero de puentes
    cin >> I >> P;
    if (!cin) return false;
    GrafoValorado<int> gv(I);
    for (int i = 0; i < P; i++) {
        int v1, v2, valor; cin >> v1 >> v2 >> valor;
        gv.ponArista({ v1 - 1, v2 - 1, valor });
    }
    //Resolucion del problema
    ARM_Kruskal kruskal(gv);
    int coste = kruskal.costeARM();
    if (coste == -1) cout << "No hay puentes suficientes";
    else cout << coste;
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
