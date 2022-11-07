
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

int numeroCoches(vector<int> const& pilas, const int V) { //Coste O(n) siendo n pilas.size()
    int coches = 0, i = 0, f = pilas.size() - 1;
    while (i < f) {
        if (pilas[i] + pilas[f] >= V) {
            coches++; i++; f--;
        }
        else f--;
    }
    return coches;
}

void resuelveCaso() { //Coste O(n log n) por haber ordenado los vectores
    //Lectura de datos
    int N, V; //N = Numero de pilas / V = Voltaje de cada coche
    cin >> N >> V;
    vector<int> pilas(N);
    for (int i = 0; i < N; i++) cin >> pilas[i];
    sort(pilas.begin(), pilas.end(), greater<int>());
    //Resolucion del problema
    cout << numeroCoches(pilas, V);
    cout << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
