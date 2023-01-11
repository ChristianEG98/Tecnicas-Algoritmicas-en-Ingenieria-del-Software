
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

//Coste O(N log N + N log N)

long int gorras(PriorityQueue<long int>& equipos) {
    long int numGorras = 0;
    if (equipos.size() > 1) {
        long int equipoA, equipoB;
        while (!equipos.empty()) {
            equipoA = equipos.top(); equipos.pop();
            if (!equipos.empty()) {
                equipoB = equipos.top(); equipos.pop();
                numGorras += equipoB + equipoA;
                equipos.push(equipoB + equipoA);
            }
        }
    }
    return numGorras;
}

bool resuelveCaso() {
    //Lectura de datos
    int nEquipos;
    cin >> nEquipos;
    if (nEquipos == 0) return false;
    PriorityQueue<long int> equipos;
    for (int i = 0; i < nEquipos; i++) {
        int seg; cin >> seg;
        equipos.push(seg);
    }
    //Resolucion del problema
    cout << gorras(equipos) << "\n";
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
