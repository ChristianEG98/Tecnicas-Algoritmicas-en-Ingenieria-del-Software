/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Christian Esteban
  * Estudiante 2:
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "Matriz.h"
using namespace std;


/*@ <answer>

 Resolvemos el problema mediante programación dinámica:

 subsecuencia(i, j) = tamaño de la subsecuencia de mayor longitud entre X e Y

 - Casos base:
 subsecuencia(i, j) = 0 si j = 0
 subsecuencia(i, j) = 0 si i = 0

 - Casos recursivos:
 subsecuencia(i, j) = subsecuencia(i - 1, j - 1) + 1 si coincide el mismo caracter en X[i - 1] e Y[j - 1]
 subsecuencia(i, j) = max(subsecuencia(i - 1, j), subsecuencia(i, j - 1)) si el caracter en X[i - 1] e Y[j - 1] son distintos

 La llamada inicial se hara con subsecuencia(n1, n2) siendo n1 = X.size() y n2 = Y.size()

 El coste es O(n1 * n2) en tiempo y espacio

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

int subsecuencia(string const& X, string const& Y, Matriz<int>& sol) {
    int n1 = X.size();
    int n2 = Y.size();
    sol = Matriz<int> (n1 + 1, n2 + 1, 0);

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (X[i - 1] == Y[j - 1]) {
                sol[i][j] = sol[i - 1][j - 1] + 1;
            }
            else {
                sol[i][j] = std::max(sol[i - 1][j], sol[i][j - 1]);
            }
        }
    }
    return sol[n1][n2];
}

string reconstuir(string const& X, string const& Y, Matriz<int> const& sol) {
    int n1 = X.size(); int n2 = Y.size();
    int tam = sol[n1][n2];
    string subcadena_inv = "", subcadena = "";
    int i = n1; int j = n2;
    //Reconstruimos la solucion
    while (tam > 0) {
        if (X[i - 1] == Y[j - 1]) { //Si coindice el caracter lo añadimos a la solucion
            subcadena_inv += X[i - 1];
            tam--; i--; j--;
        }
        else {
            if (sol[i][j] == sol[i - 1][j]) i--;
            else j--;
        }
    }
    //Invertimos la subcadena
    for (int i = subcadena_inv.size(); i > 0; i--) {
        subcadena += subcadena_inv[i - 1];
    }
    return subcadena;
}

bool resuelveCaso() {
    // leemos la entrada
    string X, Y;
    cin >> X >> Y;
    if (!cin)
        return false;
    // resolver el caso
    Matriz<int> sol;
    int tam = subsecuencia(X, Y, sol);
    if (tam > 0) {
        cout << reconstuir(X, Y, sol);
    }
    cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
