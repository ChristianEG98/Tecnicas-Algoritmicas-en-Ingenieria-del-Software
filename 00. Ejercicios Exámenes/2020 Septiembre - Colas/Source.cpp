
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

int numGorras(priority_queue<int, vector<int>, greater<int>>& pq) {
    int minGorras = 0;
    int e1, e2;
    if (pq.size() > 1) {
        while (pq.size() > 1) {
            e1 = pq.top(); pq.pop();
            e2 = pq.top(); pq.pop();
            minGorras += e1 + e2;
            pq.push(e1 + e2);
        }
    }
    return minGorras;
}

bool resuelveCaso() {
    //Lectura de datos
    int N;
    cin >> N;
    if (N == 0) return false;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        pq.push(n);
    }
    //Resolucion del problema
    cout << numGorras(pq) << "\n";
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
