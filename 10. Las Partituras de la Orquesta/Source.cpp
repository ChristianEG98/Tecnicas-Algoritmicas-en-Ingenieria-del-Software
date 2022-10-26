
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

struct musicos {
    int musicos;
    int partituras;

};

bool operator <(const musicos& a, const musicos& b) {
    int ratioA, ratioB;
    ratioA = a.musicos / a.partituras;
    ratioB = b.musicos / b.partituras;

    if (a.musicos % a.partituras != 0) ratioA++;
    if (b.musicos % b.partituras != 0) ratioB++;

    return ratioA < ratioB;
}

//Coste O(numPartituras * log numInstrumentos)
bool resuelveCaso() {
    //Lectura de datos
    int numPartituras, numInstrumentos;
    cin >> numPartituras >> numInstrumentos;
    if (!cin)
        return false;
    priority_queue<musicos> orquesta;
    for (int i = 0; i < numInstrumentos; i++) {
        int musicos; cin >> musicos;
        orquesta.push({ musicos, 1 });
    }
    //Resolucion del problema
    numPartituras -= numInstrumentos;
    while (numPartituras > 0) {
        musicos aux = orquesta.top(); orquesta.pop();
        aux.partituras++;
        orquesta.push(aux);
        numPartituras--;
    }
    int sol = orquesta.top().musicos / orquesta.top().partituras;
    if (orquesta.top().musicos % orquesta.top().partituras != 0) sol++;
    cout << sol << "\n";
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
