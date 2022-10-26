
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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

long long int resolver(priority_queue<long long int, vector<long long int>, greater<long long int>> sumandos) {
    long long int costo = 0, suma = 0, prim, seg;
    if (sumandos.size() > 1) {
        while (sumandos.size() > 1) {
            prim = sumandos.top();
            sumandos.pop();
            seg = sumandos.top();
            sumandos.pop();
            suma = prim + seg;
            costo += suma;
            sumandos.push(suma);
        }
    }
    return costo;
}

bool resuelveCaso() {
    int num;
    cin >> num;
    // leer los datos de la entrada
    if (num == 0)
       return false;
    priority_queue<long long int, vector<long long int>, greater<long long int>> sumandos;
    for (int i = 0; i < num; i++) {
        int n; cin >> n;
        sumandos.push(n);
    }
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
    cout << resolver(sumandos) << "\n";

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
