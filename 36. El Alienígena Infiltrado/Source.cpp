
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

struct intervalo {
    int ini;
    int fin;
};

bool ordInterv(intervalo const& a, intervalo const& b) {
    if (a.ini != b.ini) return a.ini < b.ini;
    else return a.fin < b.fin;
}

int minTrabajos(vector<intervalo> tareas, int ini, int fin) {
    int trabajos = 0, i = 0, ultimoFin;
    bool hayHueco = false;
    if (tareas.size() != 0 && tareas[0].ini <= ini)
        while (!hayHueco && ini < fin) {
            ultimoFin = -1;
            while (i < tareas.size() && tareas[i].ini <= ini) {
                if (tareas[i].fin > ultimoFin)
                    ultimoFin = tareas[i].fin;
                i++;
            }
            if (ultimoFin == -1) hayHueco = true;

            trabajos++;
            ini = ultimoFin;
        }
    if (hayHueco) trabajos = 0;
    return trabajos;
}

bool resuelveCaso() { //Coste O(n log n) por haber ordenado el vector
    //Lectura de datos
    int C, F, N; // C = Comienzo intervalo / F = Fin intervalo / N = Numero de trabajos
    cin >> C >> F >> N;
    if (C == 0 && F == 0 && N == 0) return false;
    vector<intervalo> tareas(N);
    for (int i = 0; i < N; i++) {
        cin >> tareas[i].ini >> tareas[i].fin;
    }
    sort(tareas.begin(), tareas.end(), ordInterv);
    //Resolucion del problema
    int sol = minTrabajos(tareas, C, F);
    if (sol != 0) cout << sol;
    else cout << "Imposible";
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

    while(resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
