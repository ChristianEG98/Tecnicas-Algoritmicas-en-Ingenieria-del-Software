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
using namespace std;


//  IMPORTANTE: NO se admiten soluciones basadas en el algoritmo (y recurrencia)
//  de Floyd. Hay que pensar una recurrencia específica para este problema
//  que intente sacar partido de que el río solamente se puede recorrer en un
//  sentido.


/*@ <answer>

 costes(i, j) = coste minimo para llegar desde el poblado i hasta el j

 - Casos base:
 costes(i, i) = 0 
 costes(i - 1, i) = 0
 - Casos recursivo:
 costes(i, j) = min(costes(i - 1, j), costes(i - 1, i) + alquiler[i - 1][j - 1]) si i < j
 costes(i, j) = costes(i - 1, j) si i >= j

 Coste O(n ^ 2) en espacio y O(n ^ 3) en tiempo siendo n = alquiler.size()

 Llamada inicial: costes(n - 1, j)

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

const int INF = 1000000000;

void costeMinimo(vector<vector<int>> const& alquiler, int iPoblado) { //O(n ^ 2) en tiempo y espacio
    int n = alquiler.size();
    vector<vector<int>> costes(n, vector<int>(n + 1, INF));
    costes[iPoblado - 1][iPoblado - 1] = 0;
    for (int i = iPoblado; i < n; i++) {
        costes[iPoblado - 1][i] = 0;
        for (int j = iPoblado; j <= n; j++) {
            if (i >= j)
                costes[i][j] = costes[i - 1][j];
            else
                costes[i][j] = std::min(costes[i - 1][j], costes[i - 1][i] + alquiler[i - 1][j - 1]);
        }
    }

    for (int j = iPoblado + 1; j <= n; j++) {
        cout << costes[n - 1][j] << " ";
    }
}

bool resuelveCaso() {

    // leemos la entrada
    int N;
    cin >> N;

    if (!cin)
        return false;

    // leemos los alquileres
    vector<vector<int>> alquiler(N, vector<int>(N, 0));
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cin >> alquiler[i][j];
        }
    }

    // resolver el caso
    for (int i = 1; i <= N - 1; i++) {
        costeMinimo(alquiler, i);
        cout << "\n";
    }

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
