
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

struct comic {
    int id;
    int pila;
};

bool operator<(comic const& a, comic const& b) {
    return a.id > b.id;
}

int posicionCola(vector<stack<comic>>& pilas, const int idMinimo) {
    int posicion = 0;
    priority_queue<comic> cimas;
    for (int i = 0; i < pilas.size(); i++) {
        cimas.push(pilas[i].top()); //Coste O(log N)
        pilas[i].pop();
    }
    int id, cima;
    do {
        id = cimas.top().id;
        cima = cimas.top().pila;
        cimas.pop(); //Coste O(log N)
        posicion++;
        if (!pilas[cima].empty()) {
            cimas.push(pilas[cima].top()); //Coste O(log N)
            pilas[cima].pop();
        }
    } while (id != idMinimo);
    return posicion;
}

bool resuelveCaso() { 
    //Lectura de datos
    int nPilas, idMinimo = 100000000;
    cin >> nPilas;
    if (!cin) return false;
    vector<stack<comic>> pilas(nPilas);
    for (int i = 0; i < nPilas; i++) {
        int tam, id; cin >> tam;
        for (int j = 0; j < tam; j++) {
            cin >> id;
            pilas[i].push({ id, i });
            if (id < idMinimo) idMinimo = id;
        }
    }
    //Resolucion del problema
    cout << posicionCola(pilas, idMinimo);
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
