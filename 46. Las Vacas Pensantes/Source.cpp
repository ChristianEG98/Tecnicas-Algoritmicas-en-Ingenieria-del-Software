
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

 maximaComida(i, j) = maximo de comida a elegir del cubo i al j

 Casos base:
 maximaComida(i, i) = cubos[i] //Si queda un cubo
 maximaComida(i, i + 1) = max(cubos[i], cubos[i + 1]) //Si quedan dos cubos, el que mas comida tenga

 Casos recursivos:
 maximaComida(i, j) = max(elegirDe, elegirIz)

 elegirDe = maximaComida(i + 1, j - 1) + cubos[i] si cubos[j] > cubos[i + 1]
            maximaComida(i + 1, j) + cubos[i] en caso contrario

 elegirIz = maximaComida(i + 1, j - 1) + cubos[j] si cubos[j - 1] > cubos[i]
            maximaComida(i, j - 2) + cubos[j] en caso contrario

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int maximaComida(vector<int> & cubos) {
    int n = cubos.size();
    Matriz<int> sol(n, n, 0);

    if (n == 1) return cubos[1];
    else if (n == 2) return std::max(cubos[1], cubos[2]);
    else {
        for (int i = 1; i < n - 1; i++) {
            sol[i][i + 1] = std::max(cubos[i], cubos[i + 1]);
        }
        for (int i = 1; i < n; i++) {
            sol[i][i] = cubos[i];
        }
        for (int v = 2; v < n - 1; v++) {
            for (int i = 1; i < n - v; i++) {
                int iz, de, j = i + v;
                //Derecha
                if (cubos[j - 1] > cubos[i]) {
                    de = sol[i][j - 2] + cubos[j];
                }
                else {
                    de = sol[i + 1][j - 1] + cubos[j];
                }
                //Izquierda
                if (cubos[j] > cubos[i + 1]) {
                    iz = sol[i + 1][j - 1] + cubos[i];
                }
                else {
                    iz = sol[i + 2][j] + cubos[i];
                }
                sol[i][j] = std::max(iz, de);
            }
        }
        return sol[1][n - 1];
    }
}

bool resuelveCaso() { //Coste O(N * N) en tiempo y espacio
    //Lectura de datos
    int N; //N = Numero cubos
    cin >> N;
    if (N == 0) return false;
    vector<int> cubos(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> cubos[i];
    }
    //Resolucion del problema
    cout << maximaComida(cubos) << "\n";

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
