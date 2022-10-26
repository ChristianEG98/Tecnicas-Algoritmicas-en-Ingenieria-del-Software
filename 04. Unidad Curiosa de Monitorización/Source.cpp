
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

struct registro {
    int momento;
    int id;
    int periodo;
};

bool operator<(registro const& a, registro const& b) {
    return b.momento < a.momento || (a.momento == b.momento && b.id < a.id);
}

bool resuelveCaso() {
    int num, envios;
    cin >> num;
    // leer los datos de la entrada
    if (num == 0)
       return false;
    priority_queue<registro> cola;
    for (int i = 0; i < num; i++) {
        int id, periodo;
        cin >> id >> periodo;
        cola.push({ periodo, id, periodo });
    }
    cin >> envios;
    // resolver el caso posiblemente llamando a otras funciones
    while (envios--) {
        auto e = cola.top();
        cola.pop();
        // escribir la solución
        cout << e.id << "\n";
        e.momento += e.periodo;
        cola.push(e);
    }
    cout << "---\n";
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
