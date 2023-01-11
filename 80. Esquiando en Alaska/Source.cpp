
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

//Coste O(N log N)

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int minimo(vector<int> const& esquiadores, vector<int> const& esquis) {
    int longitud = 0;
    for (int i = 0; i < esquis.size(); i++) {
        longitud += abs(esquiadores[i] - esquis[i]);
    }
    return longitud;
}

bool resuelveCaso() {
    //Lectura de datos
    int num;
    cin >> num;
    if (num == 0) return false;
    vector<int> esquiadores(num);
    for (int i = 0; i < num; i++) cin >> esquiadores[i];
    sort(esquiadores.begin(), esquiadores.end());
    vector<int> esquis(num);
    for (int i = 0; i < num; i++) cin >> esquis[i];
    sort(esquis.begin(), esquis.end());
    //Resolucion del problema
    cout << minimo(esquiadores, esquis);
    cout << '\n';
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
