
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

struct tEdificio {
    int ini;
    int fin;
    bool tienePasadizo;
};

bool ordenar(tEdificio const& a, tEdificio const& b) {
    if (a.ini < b.ini) return true;
    else if (a.ini == b.ini) return a.fin < b.fin;
    else return false;
}

int numPasadizos(vector<tEdificio> const& edificios) {
    int num = 1;
    int finLimite = edificios[0].fin;
    for (int i = 1; i < edificios.size(); i++) {
        if (edificios[i].ini >= finLimite) {
            num++;
            finLimite = edificios[i].fin;
        }
        else {
            //Si encontramos un edificio con un este menor al actual
            if (edificios[i].fin < finLimite) finLimite = edificios[i].fin;
        }
    }
    return num;

}

bool resuelveCaso() { //Coste O(n log n) por haber ordenado el vector
    //Lectura de datos
    int N; //N = Numero de edificios
    cin >> N;
    if (N == 0) return false;
    vector<tEdificio> edificios(N);
    for (int i = 0; i < N; i++) {
        cin >> edificios[i].ini >> edificios[i].fin;
        edificios[i].tienePasadizo = false;
    }
    sort(edificios.begin(), edificios.end(), ordenar);
    //Resolucion del problema
    cout << numPasadizos(edificios);
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
