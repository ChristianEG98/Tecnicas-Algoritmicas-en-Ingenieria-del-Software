
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

//Coste O(N log N)

int descuento(vector<int> const& libros) {
    int dto = 0;
    if (libros.size() > 2) {
        for (int i = 2; i < libros.size(); i += 3)
            dto += libros[i];
    }
    return dto;
}

bool resuelveCaso() {
    //Lectura de datos
    int nLibros;
    cin >> nLibros;
    if (!cin) return false;
    vector<int> libros(nLibros);
    for (int i = 0; i < libros.size(); i++) cin >> libros[i];
    sort(libros.begin(), libros.end(), greater<int>());
    //Resolucion del problema
    cout << descuento(libros);
    cout << '\n';
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
