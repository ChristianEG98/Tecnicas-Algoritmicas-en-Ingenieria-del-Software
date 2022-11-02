
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "Digrafo.h"

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

class Tareas {
private:
    vector<bool> visit;
    vector<bool> apilado;
    deque<int> ordenTopol; //Ordenacion topologica
    bool hayCiclo;
    int visitados, V;

    void dfs(Digrafo const& d, int v) { //O(V + A)
        visit[v] = true;
        apilado[v] = true;
        visitados++;
        for (int w : d.ady(v)) {
            if (!visit[w]) { //Si no hemos visitado el vertice
                dfs(d, w);
            }
            else if (apilado[w]) { //Si hay ciclo
                hayCiclo = true;
                return;
            }
        }
        ordenTopol.push_front(v);
        apilado[v] = false;
    }

public:
    Tareas(Digrafo const& d): visit(d.V(), false), visitados(0), V(d.V()), apilado(d.V(), false), hayCiclo(false) {
        for (int i = 0; i < d.V(); i++) {
            if (!visit[i]) {
                dfs(d, i);
            }
        }
    }
    void orden() const {
        if (esPosible()) {
            for (int i : ordenTopol) {
                cout << i + 1 << " ";
            }
        }
        else cout << "IMPOSIBLE";

    }
    bool esPosible() const {
        if (visitados == V && !hayCiclo) return true;
        else return false;
    }
};

bool resuelveCaso() {
    //Lectura de datos
    int V, A; //V = Numero de tareas y A = Numero de relaciones entre tareas
    cin >> V >> A;
    if (!cin) return false;
    Digrafo d(V);
    for (int i = 0; i < A; i++) {
        int a1, a2; cin >> a1 >> a2;
        d.ponArista(a1 - 1, a2 - 1);
    }
    //Resolucion del problema
    Tareas t(d);
    t.orden();
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
