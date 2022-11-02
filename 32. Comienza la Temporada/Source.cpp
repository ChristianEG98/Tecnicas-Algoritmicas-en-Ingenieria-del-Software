
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

int equipo(vector<int> const& jugadores, vector<int> const& equipaciones) {
    int jugadoresConEquip = 0;
    int j = 0, e = 0;
    while (j < jugadores.size() && e < equipaciones.size()) {
        if (equipaciones[e] == jugadores[j] || equipaciones[e] - 1 == jugadores[j]) {
            j++; e++; jugadoresConEquip++;
        }
        else {
            if (equipaciones[e] < jugadores[j]) e++;
            else j++;
        }
    }
    if (jugadoresConEquip < jugadores.size()) return jugadores.size() - jugadoresConEquip;
    else return 0;
}

bool resuelveCaso() { //Coste O(n log n) por haber ordenado los vectores
    //Lectura de datos
    int N, M; //N = Numero de jugadores / M = Numero de equipaciones disponibles
    cin >> N >> M;
    if (!cin) return false;
    vector<int> jugadores(N), equipaciones(M);
    for (int i = 0; i < jugadores.size(); i++) cin >> jugadores[i];
    sort(jugadores.begin(), jugadores.end());
    for (int i = 0; i < equipaciones.size(); i++) cin >> equipaciones[i];
    sort(equipaciones.begin(), equipaciones.end());
    //Resolucion del problema
    cout << equipo(jugadores, equipaciones);
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
