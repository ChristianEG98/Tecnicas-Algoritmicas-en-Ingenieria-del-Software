
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
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

struct tComic {
    int id;
    int pila;
};

bool operator<(tComic const& a, tComic const& b) {
    return a.id > b.id;
}

int posicion(vector<stack<tComic>>& comics, int const idMinimo) {
    int pos = 0, idActual;
    priority_queue<tComic> pq;
    for (int i = 0; i < comics.size(); i++) {
        pq.push(comics[i].top());
        comics[i].pop();
    }
    do {
        tComic aux = pq.top(); pq.pop();
        idActual = aux.id;
        if (!comics[aux.pila].empty()) {
            pq.push(comics[aux.pila].top());
            comics[aux.pila].pop();
        }
        pos++;
    } while (idActual != idMinimo);

    return pos;
}

bool resuelveCaso() {
    //Lectura de datos
    int N;
    cin >> N;
    if (!cin) return false;
    vector<stack<tComic>> comics(N);
    int idMinimo = 100000000;
    for (int i = 0; i < N; i++) {
        int T; cin >> T;
        for (int j = 0; j < T; j++) {
            int id; cin >> id;
            if (id < idMinimo) idMinimo = id;
            comics[i].push({ id, i });
        }
    }
    //Resolucion del problema
    cout << posicion(comics, idMinimo) << "\n";
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
