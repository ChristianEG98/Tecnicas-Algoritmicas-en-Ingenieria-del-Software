
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

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

class Calculadora {
public:
    int bfs(int origen, int destino) { //Coste O(V + A) = O(10.000 + 30.000)
        if (origen == destino) return 0;
        vector<int> distancia(MAX, INF);
        distancia[origen] = 0;
        queue<int> cola; cola.push(origen);
        while (!cola.empty()) {
            int v = cola.front(); cola.pop();
            for (int i = 0; i < 3; ++i) {
                int w = adyacente(v, i);
                if (distancia[w] == INF) { //Si aun no ha sido visitado
                    distancia[w] = distancia[v] + 1;
                    if (w == destino) return distancia[w];
                    else cola.push(w);
                }
            }
        }
    }

private:
    const int MAX = 10000;
    const int INF = 1000000000;

    int adyacente(int v, int i) {
        switch (i) {
            case 0: return (v + 1) % MAX;
            case 1: return (v * 2) % MAX;
            case 2: return v / 3;
        }
    }
};

bool resuelveCaso() {
    //Lectura de datos
    int ini, fin;
    cin >> ini >> fin;
    if (!cin) return false;

    //Resolucion del problema
    Calculadora p;
    cout << p.bfs(ini, fin);
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
