
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

struct cliente {
    int segundos;
    int caja;
};

bool operator<(cliente const& a, cliente const& b) {
    if (a.segundos > b.segundos) return true;
    else if (a.segundos == b.segundos && a.caja > b.caja) return true;
    else return false;
}

//Coste O(ca log(cl)) siendo ca = cajas y cl = clientes
bool resuelveCaso() {
    int cajas, clientes;
    // leer los datos de la entrada
    cin >> cajas >> clientes;
    if (cajas == 0 && clientes == 0)
        return false;
    else {
        priority_queue<cliente> cola;
        // resolver el caso posiblemente llamando a otras funciones
        int cajaAsignada = 1, tiempo = 0, segundos;
        while (clientes > 0) {
            int tarda; cin >> tarda;
            segundos = tiempo + tarda;

            if (cajas > 0) {
                cola.push({ segundos, cajaAsignada });
                cajaAsignada++;
                cajas--;
            }

            if (cajas == 0) {
                cajaAsignada = cola.top().caja;
                tiempo = cola.top().segundos;
                cola.pop();
                cajas++;
            }
            clientes--;
        }
        cout << cajaAsignada << "\n";
    }
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
