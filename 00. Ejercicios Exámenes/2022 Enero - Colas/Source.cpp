
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"

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

struct tActividad{
    int inicio;
    int fin;
};

bool operator<(tActividad const& a, tActividad const& b) {
    return a.inicio < b.inicio || (a.inicio == b.inicio && a.fin < b.fin);
}

int minimoCompas(vector<tActividad> const& actividades) { //O(N log N)
    int compas = 0;
    PriorityQueue<int> pq; //Finales
    pq.push(actividades[0].fin);
    for (int i = 1; i < actividades.size(); i++) {
        if (actividades[i].inicio >= pq.top()) { 
            pq.pop(); pq.push(actividades[i].fin);
        }
        else {
            compas++;
            pq.push(actividades[i].fin);
        }
    }
    return compas;
}

bool resuelveCaso() {
    //Lectura de datos
    int N;
    cin >> N;
    if (N == 0) return false;
    vector<tActividad> actividades(N);
    for (int i = 0; i < N; i++) {
        cin >> actividades[i].inicio >> actividades[i].fin;
    }
    sort(actividades.begin(), actividades.end()); //O(N log N)
    //Resolucion del problema
    cout << minimoCompas(actividades) << "\n";
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
