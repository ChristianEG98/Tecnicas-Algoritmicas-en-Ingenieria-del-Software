
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

class Trampas {
private:
    Digrafo d;
    int K;

    int bfs(int origen, int destino) { //O(V + A)
        if (origen == destino) return 0;
        vector<int> distancia(destino, -1);
        distancia[origen] = 0;
        vector<bool> visit(destino, false);
        visit[origen] = false;
        queue<int> cola; cola.push(origen);
        while (!cola.empty()) {
            int v = cola.front(); cola.pop();
            for (int i = 1; i <= K; i++) { //Para todas las k posibles caras del dado
                int w = v + i; //Nueva arista = casilla actual + tirada del dado
                if (w >= destino) w = destino - 1; //Por si con la tirada nos pasamos del final
                if (!d.ady(w).empty()) w = d.ady(w).front(); //Si tiene una ady (escalera o serpiente)
                if (!visit[w]) {
                    visit[w] = true;
                    distancia[w] = distancia[v] + 1;
                    if (w == destino - 1) return distancia[w];
                    else cola.push(w);
                }
            }
        }
    }

public:
    Trampas(Digrafo const& _d, int const _K): d(_d), K(_K) {
        cout << bfs(0, d.V());
    }

};

bool resuelveCaso() {
    //Lectura de datos
    int N, K, S, E; //N = Dimension/ K = Caras dado / S = Num serpientes / E = Num escaleras
    cin >> N >> K >> S >> E;
    if (N == 0 && K == 0 && S == 0 && E == 0) return false;
    int numCasillas = N * N;
    Digrafo d(numCasillas);
    for (int i = 0; i < S; i++) { //Aristas de las serpientes
        int a1, a2; cin >> a1 >> a2;
        d.ponArista(a1 - 1, a2 - 1);
    }
    for (int i = 0; i < E; i++) { //Aristas de las escaleras
        int a1, a2; cin >> a1 >> a2;
        d.ponArista(a1 - 1, a2 - 1);
    }
    //Resolucion del problema
    Trampas t(d, K);
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
