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
using namespace std;


/*@ <answer>

 Resolvemos el problema por programación dinámica basándonos en la siguiente recurrencia:

 numGrupos(i, j) = numero maximo de grupos que podemos escuchar con un presupuesto P si podemos
                   asistir a los festivales del 1 al i.

 Un caso básico seria que nuestro presupuesto es 0, en ese caso no podemos escuchar ningun artista

 numGrupos[0] = 0

 Otro caso básico es que no haya festivales de cualquier presupuesto que podamos utilizar. 
 En ese caso no hay solución, lo que representamos con 0:

 numGrupos[j] = 0 si j > 0

 En cuanto a los casos recursivos distinguimos:

 numGrupos[j] = numGrupos[j] si el precio del festival i > j
 numGrupos[j] = std::max(numGrupos[j] , numGrupos[j - festivales[i].precio] + festivales[i].grupos) si el precio del gestival i >= j nos quedamos con la mayor de las dos.

 La complejidad está en O(P*N) en tiempo y O(P) en espacio, ya que utilizamos un vector de ese tamaño
 que se recorre completamente N veces.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

struct tFestival {
    int grupos;
    int precio;
};

int gruposMax(vector<tFestival> const& F, int const& P) {
    vector<int> numGrupos(P + 1, 0);
    numGrupos[0] = 0;
    for (int i = 1; i <= F.size(); i++) {
        for (int j = P; j >= 1; j--) {
            if (F[i - 1].precio <= j)
                numGrupos[j] = std::max(numGrupos[j], numGrupos[j - F[i - 1].precio] + F[i - 1].grupos);
        }
    }
    return numGrupos[P];
}

bool resuelveCaso() {

    int P, N;
    cin >> P >> N;  // presupuesto y número de festivales

    if (!cin)
        return false;
    vector<tFestival> festivales(N);
    // leer el resto del caso y resolverlo
    for (int i = 0; i < festivales.size(); i++) {
        cin >> festivales[i].grupos >> festivales[i].precio;
    }

    cout << gruposMax(festivales, P) << "\n";

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
