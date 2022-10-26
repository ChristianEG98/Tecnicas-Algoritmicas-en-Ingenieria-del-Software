
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

//Coste O(V + A)
class ArbolLibre { //Arbol libre = Todos los V visitados y V - 1 aristas
private:
    vector<bool> visitados;
    int numVisitados, V, A;

    void dfs(Grafo const& g, int v) {
        visitados[v] = true;
        numVisitados++;
        for (int w : g.ady(v)) {
            if (!visitados[w]) {
                dfs(g, w);
            }
        }
    }

public:
    ArbolLibre(Grafo const& g): visitados(g.V(), false), numVisitados(0), V(g.V()), A(g.A()) {
        dfs(g, 0);
    }
    bool esLibre() const {
        return (numVisitados == V && A == V - 1);
    }
};

bool resuelveCaso() {
    //Lectura de datos
    Grafo g(cin);
    if (!cin)
        return false;
    
    //Resolucion del problema
    ArbolLibre l(g);
    if (l.esLibre()) cout << "SI";
    else cout << "NO";
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
