
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "Matriz.h"

using namespace std;

/*@ <answer>
 aibofobia(i, j) = numero minimo de letras a añadir para que una palabra sea palindromo

 Casos base:
 aibofobia(i, i) = 0  si i == j
 aibofobia(i, j) = 0  si i > j

 Casos recursivos:
 aibofobia(i, i) = aibofobia(i + 1, j - 1) si palabra[i] == palabra[j]
 aibofobia(i, i) = min(aibofobia(i + 1, j) + 1, aibofobia(i, j - 1) + 1) si palabra[i] != palabra[j]

 Llamada inicial = aibofobia(0, palabra.size() - 1)

 El coste de esta funcion es O(n^2) siendo n = palabra.size()
 - - - - - - - - - - -
 solAibofobia(i, j) = reconstruccion de la palabra que buscamos para formar el palindromo

 Casos base:
 solAibofobia(i, j) = {}  si i > j
 solAibofobia(i, j) = { palabra[i] }  si i == j

 Casos recursivos:
 solAibofobia(i, j) = palabra[i] + solAibofobia(i + 1, j - 1) + palabra[j] si palabra[i] == palabra[j]
 solAibofobia(i, j) = palabra[i] + solAibofobia(i, j - 1) + palabra[i] si sol[i][j] == sol[i][j - 1] + 1
 solAibofobia(i, j) = palabra[j] + solAibofobia(i + 1, j) + palabra[j] en caso contrario

 Llamada inicial = solAibofobia(0, palabra.size() - 1)

 El coste de esta funcion es O(n^2) siendo n = palabra.size()

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int aibofobia(string const& palabra, int i, int j, Matriz<int>& sol) {
    int& res = sol[i][j];
    if (res == -1) {
        if (i >= j) res = 0;
        else if (palabra[i] == palabra[j])
            res = aibofobia(palabra, i + 1, j - 1, sol);
        else
            res = std::min(aibofobia(palabra, i + 1, j, sol) + 1, aibofobia(palabra, i, j - 1, sol) + 1);
    }
    return res;
}

string solAibofobia(string const& palabra, int i, int j, Matriz<int> const& sol) {
    if (i > j) return {};
    if (i == j) return { palabra[i] };
    if (palabra[i] == palabra[j])
        return palabra[i] + solAibofobia(palabra, i + 1, j - 1, sol) + palabra[j];
    else if (sol[i][j] == sol[i][j - 1] + 1)
        return palabra[j] + solAibofobia(palabra, i, j - 1, sol) + palabra[j];
    else
        return palabra[i] + solAibofobia(palabra, i + 1, j, sol) + palabra[i];
}

bool resuelveCaso() {
    //Lectura de datos
    string palabra;
    cin >> palabra;
    if (!cin) return false;
    //Resolucion del problema
    int n = palabra.size();
    Matriz<int> sol(n, n, -1);
    cout << aibofobia(palabra, 0, n - 1, sol) << " ";
    cout << solAibofobia(palabra, 0, n - 1, sol);
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
