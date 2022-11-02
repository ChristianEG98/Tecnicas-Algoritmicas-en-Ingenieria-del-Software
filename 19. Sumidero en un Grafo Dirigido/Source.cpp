
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

class Sumidero {
private:
    vector<bool> visit, apilado;
    vector<int> gEntrada, gSalida;

    void dfs(Digrafo const& d, int v) { //O(V + A)
        visit[v] = true;
        apilado[v] = true;
        for (int w : d.ady(v)) {
            gSalida[v]++;
            if (!visit[w]) {
                dfs(d, w);
            }
            if (!apilado[w]) {
                gEntrada[w]++;
            }
        }
        apilado[v] = false;
    }

public:
    Sumidero(Digrafo const& d): visit(d.V(), false), apilado(d.V(), false), gEntrada(d.V(), 0), gSalida(d.V(), 0) {
        for (int i = 0; i < d.V(); i++) {
            if (!visit[i]) {
                dfs(d, i);
            }
        }
    }

    void vertice() const {
        int i = 0;
        bool existe = false;
        while (i < gEntrada.size() && !existe) {
            if (gSalida[i] == 0 && gEntrada[i] == gEntrada.size() - 1) {
                existe = true;
            }
            else i++;
        }
        if (existe) cout << "SI " << i;
        else cout << "NO";
    }

};

bool resuelveCaso() {
    //Lectura de datos
    int V, A;
    cin >> V >> A;
    if (!cin) return false;
    Digrafo d(V);
    for (int i = 0; i < A; i++) {
        int a1, a2; cin >> a1 >> a2;
        d.ponArista(a1, a2);
    }
    //Resolucion del problema
    Sumidero s(d);
    s.vertice();
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
