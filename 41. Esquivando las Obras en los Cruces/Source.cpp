
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

Resolvemos el problema por programacion dinamica basandonos en la siguiente recurrencia:
    - numCaminos[i][j] = numero de caminos que llegan a la interseccion i, j desde arriba o desde la izquierda
    
    - numCaminos[0][0] = 1 caso basico ya que en la interseccion de inicio nunca hay obra
    - numCaminos[0][j] = 1 si no hay una obra en esa interseccion y si en la interseccion a su izquierda tampoco hay obra
    - numCaminos[i][0] = 1 si no hay una obra en esa interseccion y si en la interseccion de arriba tampoco hay obra

    - numCaminos[i][j] con i > 0 y j > 0 = numCaminos[i - 1][j] + numCaminos[i][j - 1] si no hay una obra en esa interseccion

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int numCaminos(Matriz<char> const& calles) {
    int f = calles.numfils();
    int c = calles.numcols();
    Matriz<int> sol(f, c, 0);
    sol[0][0] = 1;
    for (int j = 1; j < c; j++) {
        if (calles[0][j] == '.' && sol[0][j - 1] == 1) sol[0][j] = 1;
    }
    for (int i = 1; i < f; i++) {
        if (calles[i][0] == '.' && sol[i - 1][0] == 1) sol[i][0] = 1;
        for (int j = 1; j < c; j++) {
            if (calles[i][j] != 'X' && sol[i - 1][j] + sol[i][j - 1])
                sol[i][j] = sol[i - 1][j] + sol[i][j - 1];
        }
    }
    return sol[f - 1][c - 1];
}

bool resuelveCaso() { //Coste O(N*M) en tiempo y en espacio
    //Lectura de datos
    int N, M;
    cin >> N >> M;
    if (!cin) return false;
    Matriz<char> calles(N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> calles[i][j];
        }
    }
    //Resolucion del problema
    cout << numCaminos(calles) << "\n";
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
