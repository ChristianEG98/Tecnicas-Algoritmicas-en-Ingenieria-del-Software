
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

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

const int INF = 1e9;

vector<int> minimoTiradas(vector<int> const& P, int const& T) {
    int n = P.size() - 1;
    Matriz<int> sol(n + 1, T + 1, INF);
    sol[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        sol[i][0] = 0;
        for (int j = 1; j <= T; j++) {
            if (P[i] > j)
                sol[i][j] = sol[i - 1][j];
            else
                sol[i][j] = std::min(sol[i - 1][j], sol[i][j - P[i]] + 1);
        }
    }
    //Reconstruccion de la solucion
    vector<int> tiradas;
    if (sol[n][T] != INF) {
        int i = n, j = T;
        while (j > 0) {
            if (j >= P[i] && sol[i][j] == sol[i][j - P[i]] + 1) {
                tiradas.push_back(P[i]);
                j -= P[i];
            }
            else i--;
        }
    }
    return tiradas;
}

bool resuelveCaso() { //Coste O(Puntos*Sectores) en tiempo y en espacio
    //Lectura de datos
    int puntos, sectores;
    cin >> puntos >> sectores;
    if (!cin) return false;
    vector<int> puntuaciones(sectores + 1);
    for (int i = 1; i < puntuaciones.size(); i++) cin >> puntuaciones[i];
    vector<int> tiradas = minimoTiradas(puntuaciones, puntos);
    if (tiradas.size() > 0) {
        cout << tiradas.size() << ": ";
        for (int i = 0; i < tiradas.size(); i++) cout << tiradas[i] << " ";
    }
    else cout << "Imposible";
    //Resolucion del problema
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
