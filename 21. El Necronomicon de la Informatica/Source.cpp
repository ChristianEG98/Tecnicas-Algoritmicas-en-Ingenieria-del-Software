
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
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

class CicloDirigido {
private:
    vector<bool> visit, apilado;
    bool hayCiclo;
    int V;

    void dfs(Digrafo const& d, int v) { //O(V + A)
        visit[v] = true;
        apilado[v] = true;
        for (int w : d.ady(v)) {
            if (!visit[w]) {
                dfs(d, w);
            }
            else if (apilado[w]) { //Hemos encontrado un ciclo
                hayCiclo = true;
            }
        }
        apilado[v] = false;
    }

public:
    CicloDirigido(Digrafo const& d) : visit(d.V(), false), apilado(d.V(), false), hayCiclo(false), V(d.V()) {
        dfs(d, 0);
    }

    void termina() const {
        if (!hayCiclo && visit[V - 1]) cout << "SIEMPRE";
        else if (hayCiclo && visit[V - 1]) cout << "A VECES";
        else cout << "NUNCA";
    }
};

bool resuelveCaso() {
    //Lectura de datos
    int L; //L = Numero de instrucciones
    cin >> L;
    if (!cin) return false;
    Digrafo d(L + 1);
    char inst;
    for (int i = 0; i < L; i++) {
        cin >> inst;
        if (inst == 'A') {
            d.ponArista(i, i + 1);
        }
        else if (inst == 'J') {
            int a; cin >> a;
            d.ponArista(i, a - 1);
        }
        else {
            int a; cin >> a;
            d.ponArista(i, i + 1);
            d.ponArista(i, a - 1);
        }
    }
    if (inst == 'A' || inst == 'C') {
        d.ponArista(L - 1, L); //Arista extra que debe de ser visitada para que se de por terminado
    }
    //Resolucion del problema
    CicloDirigido c(d);
    c.termina();
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
