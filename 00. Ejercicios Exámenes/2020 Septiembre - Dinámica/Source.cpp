
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
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

#define INF 100000000

void Floyd(Matriz<int>& costes) {
    int v = costes.numfils();
    //actualizacion matrices
    for (int k = 0; k < v; k++)
        for(int i = 0; i < v; i++)
            for (int j = 0; j < v; j++) {
                auto temp = costes[i][k] + costes[k][j];
                if (temp < costes[i][j]) { //es mejor parar en el poblado k
                    costes[i][j] = temp;
                }
            }
}

bool resuelveCaso() {
    //Lectura de datos
    int N;
    cin >> N;
    if (!cin) return false;
    Matriz<int> costes(N, N, INF);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> costes[i][j];
        }
    }
    //Resolucion del problema
    Floyd(costes);
    //Escribir solucion
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++)
            cout << costes[i][j] << " ";
        cout << "\n";
    }
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
