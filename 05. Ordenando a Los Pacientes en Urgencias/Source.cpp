
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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

struct paciente {
    int llegada;
    string nombre;
    int gravedad;
};

bool operator<(paciente const& a, paciente const& b) {
    return a.gravedad < b.gravedad || (a.gravedad == b.gravedad && a.llegada > b.llegada);
}

bool resuelveCaso() {
    int num;
    cin >> num;
    // leer los datos de la entrada
    if (num == 0)
       return false;
    priority_queue<paciente> cola;
    char accion; string nomb; int grav;
    for (int i = 0; i < num; i++) {
        cin >> accion;
        if (accion == 'I') {
            cin >> nomb >> grav;
            cola.push({ i, nomb, grav });
        }
        else {
            paciente p = cola.top();
            cout << p.nombre << "\n";
            cola.pop();
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
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
