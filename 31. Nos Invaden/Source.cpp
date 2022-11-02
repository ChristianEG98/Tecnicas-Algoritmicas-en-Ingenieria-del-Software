
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

int victoria(vector<int> const& enemigos, vector<int> const& defensa) {
    int victorias = 0;
    int e = 0, d = 0;
    while (e < enemigos.size() && d < defensa.size()) { //Coste O(n) siendo n enemigos.size() = defensa.size()
        if (defensa[d] >= enemigos[e]) {
            victorias++;
            e++; d++;
        }
        else {
            d++;
        }
    }
    return victorias;
}

bool resuelveCaso() { //Coste O(n log n) por haber ordenado los vectores
    //Lectura de datos
    int N; //N = Numero de ciudades invadidas y equipos de defensa
    cin >> N;
    if (!cin) return false;
    vector<int> enemigos(N), defensa(N);
    for (int i = 0; i < enemigos.size(); i++) cin >> enemigos[i];
    sort(enemigos.begin(), enemigos.end());
    for (int i = 0; i < defensa.size(); i++) cin >> defensa[i];
    sort(defensa.begin(), defensa.end());
    //Resolucion del problema
    cout << victoria(enemigos, defensa);
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
