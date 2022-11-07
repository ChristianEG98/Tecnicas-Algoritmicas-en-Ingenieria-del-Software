
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

int numeroViajes(vector<int> const& pesos, const int P) { //Coste O(n) siendo n pesos.size()
    int viajes = 0, i = 0, f = pesos.size() - 1;
    while (i < f) {
        if (pesos[i] + pesos[f] <= P) {
            i++; f--;
        }
        else i++;
        viajes++;
        if (i == f) viajes++;
    }
    return viajes;
}

bool resuelveCaso() { //Coste O(n log n) por haber ordenado el vector
    //Lectura de datos
    int P, N;
    cin >> P >> N;
    if (!cin) return false;
    vector<int> pesos(N);
    for (int i = 0; i < N; i++) cin >> pesos[i];
    sort(pesos.begin(), pesos.end(), greater<int>());
    //Resolucion del problema
    if (N == 1) cout << 1;
    else cout << numeroViajes(pesos, P);
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

    while(resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
