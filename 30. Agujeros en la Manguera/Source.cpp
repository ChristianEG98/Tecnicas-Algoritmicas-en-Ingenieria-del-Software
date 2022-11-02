
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

int parches(vector<int> const& agujeros, int L) { //Coste O(agujeros.size())
    int parches = 1;
    int distancia = L;
    for (int i = 0; i < agujeros.size() - 1; i++) {
        if (agujeros[i] != agujeros[i + 1]) { //Si no hay un mismo agujero en posiciones consecutivas
            if (agujeros[i + 1] - agujeros[i] <= distancia) { //Si hay la distancia necesaria entre el siguiente y el actual
                distancia -= (agujeros[i + 1] - agujeros[i]);
            }
            else { //Si no hay distancia necesaria entre el siguiente y el actual
                parches++;
                distancia = L;
            }
        }
    }
    return parches;
}

bool resuelveCaso() {
    //Lectura de datos
    int N, L; //N = Numero de agujeros / L = Longitud de los parches
    cin >> N >> L;
    if (!cin) return false;
    vector<int> agujeros(N);
    for (int i = 0; i < agujeros.size(); i++) {
        cin >> agujeros[i];
    }
    //Resolucion del problema
    cout << parches(agujeros, L);
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
