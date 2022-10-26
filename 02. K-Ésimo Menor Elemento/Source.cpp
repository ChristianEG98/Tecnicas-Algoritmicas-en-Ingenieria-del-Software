
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "TreeSet_AVL.h"
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

bool resuelveCaso() {
    int tam_conjunto, tam_consulta, num, sol;
    Set<int> conjunto;
    // leer los datos de la entrada
    cin >> tam_conjunto;
    if (tam_conjunto == 0)
       return false;
    for (int i = 0; i < tam_conjunto; i++) {
        cin >> num;
        conjunto.insert(num);
    }
    cin >> tam_consulta;
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < tam_consulta; i++) {
        cin >> num;
        sol = conjunto.kesimo(num);
        if (sol != -1) cout << sol;
        else cout << "??";
        cout << "\n";
    }
    // escribir la solución
    cout << "---" << "\n";
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
