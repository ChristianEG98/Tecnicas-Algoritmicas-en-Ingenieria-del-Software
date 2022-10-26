
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "bintree.h"
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

bool esEquilibrado(const BinTree<int>& i, int& h) {
    if (i.empty()) {
        h = 0;
        return true;
    }
    else {
        int hIzq, hDer;

        bool eqIzq = esEquilibrado(i.left(), hIzq);
        bool eqDer = esEquilibrado(i.right(), hDer);

        h = max(hIzq, hDer) + 1;

        if (abs(hIzq - hDer) <= 1 && eqIzq&& eqDer) return true;
        else return false;
    }
}

bool esAVL(const BinTree<int>& i, bool& avl, int& min, int& max) {
    if (!i.empty() && avl) {
        if (i.left().empty() && i.right().empty()) {
            min = i.root();
            max = i.root();
        }
        else {
            int aux = -1;
            if (!i.left().empty()) {
                esAVL(i.left(), avl, min, max);
                if (max >= i.root()) {
                    avl = false;
                }
                else max = i.root();
                aux = min;
            }
            if (!i.right().empty()) {
                esAVL(i.right(), avl, min, max);
                if (min <= i.root()) {
                    avl = false;
                }
                else if (aux != -1) min = aux;
                else min = i.root();
            }
        }
    }
    return avl;
}

void resuelveCaso() {
    int h = 0;
    int max = INT32_MIN, min = INT32_MAX;
    bool equilibrado, avl = true;
    // leer los datos de la entrada
    auto i = read_tree<int>(cin);
    // resolver el caso posiblemente llamando a otras funciones
    equilibrado = esEquilibrado(i, h);
    avl = esAVL(i, avl, min, max);
    // escribir la solución
    if (equilibrado && avl) cout << "SI";
    else cout << "NO";
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
