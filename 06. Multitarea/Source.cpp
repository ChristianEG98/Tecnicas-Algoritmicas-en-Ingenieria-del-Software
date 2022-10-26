
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

struct tarea {
    int inicio;
    int fin;
    int repeticion;
};

bool operator<(tarea const& a, tarea const& b) {
    return a.inicio > b.inicio;
}

bool resuelveCaso() {
    int tUnicas, tPeriodicas, minutos;
    
    // leer los datos de la entrada
    cin >> tUnicas >> tPeriodicas >> minutos;
    if (!std::cin)
        return false;
    priority_queue<tarea> cola;
    int ini, fin, rep;
    for (int i = 0; i < tUnicas; i++) {
        cin >> ini >> fin;
        cola.push({ ini, fin, 0 });
    }
    for (int i = 0; i < tPeriodicas; i++) {
        cin >> ini >> fin >> rep;
        cola.push({ ini, fin, rep });
    }
    // resolver el caso posiblemente llamando a otras funciones
    bool solapa = false;
    int aux = 0;
    while (!cola.empty() && !solapa && cola.top().inicio < minutos) {
        auto a = cola.top(); cola.pop();
        if (a.inicio < aux) {
            solapa = true;
        }
        else {
            aux = a.fin;
            if (a.repeticion > 0) cola.push({ a.inicio + a.repeticion, a.fin + a.repeticion, a.repeticion });
        }
    }
    if (solapa) cout << "SI";
    else cout << "NO";
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
