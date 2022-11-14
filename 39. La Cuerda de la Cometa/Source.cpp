
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

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

struct tCordel {
    int longitud;
    int coste;
};

bool esPosible(vector<tCordel> const& C, int const& L) {
    int n = C.size() - 1;
    Matriz<bool> sol(n + 1, L + 1, false);
    sol[0][0] = true;
    for (int i = 1; i <= n; i++) {
        sol[i][0] = true;
        for (int j = 1; j <= L; j++) {
            if (C[i].longitud > j)
                sol[i][j] = sol[i - 1][j];
            else
                sol[i][j] = (sol[i - 1][j] || sol[i - 1][j - C[i].longitud]);
        }
    }
    return sol[n][L];
}

long long int formasPosibles(vector<tCordel> const& C, int const& L) {
    int n = C.size() - 1;
    Matriz<long long int> sol(n + 1, L + 1, 0);
    sol[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        sol[i][0] = 1;
        for (int j = 1; j <= L; j++) {
            if (C[i].longitud > j)
                sol[i][j] = sol[i - 1][j];
            else
                sol[i][j] = sol[i - 1][j] + sol[i - 1][j - C[i].longitud];
        }
    }
    return sol[n][L];
}

long long int minimoCuerdas(vector<tCordel> const& C, int const& L) {
    int n = C.size() - 1;
    Matriz<long long int> sol(n + 1, L + 1, (long long int) 1e18);
    sol[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        sol[i][0] = 0;
        for (int j = 1; j <= L; j++) {
            if (C[i].longitud > j)
                sol[i][j] = sol[i - 1][j];
            else
                sol[i][j] = std::min(sol[i - 1][j], sol[i - 1][j - C[i].longitud] + 1);
        }
    }
    return sol[n][L];
}

long long int minimoCoste(vector<tCordel> const& C, int const& L) {
    int n = C.size() - 1;
    Matriz<long long int> sol(n + 1, L + 1, (long long int) 1e18);
    sol[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        sol[i][0] = 0;
        for (int j = 1; j <= L; j++) {
            if (C[i].longitud > j)
                sol[i][j] = sol[i - 1][j];
            else
                sol[i][j] = std::min(sol[i - 1][j], sol[i - 1][j - C[i].longitud] + C[i].coste);
        }
    }
    return sol[n][L];
}

bool resuelveCaso() { //Coste O(N*L) en espacio y tiempo
    //Lectura de datos
    int N, L;
    cin >> N >> L;
    if (!cin) return false;
    vector<tCordel> cordeles(N + 1, { 0, 0 });
    for (int i = 1; i < cordeles.size(); i++)
        cin >> cordeles[i].longitud >> cordeles[i].coste;
    if (esPosible(cordeles, L)) {
        cout << "SI" << " " << formasPosibles(cordeles, L) << " " << minimoCuerdas(cordeles, L);
        cout << " " << minimoCoste(cordeles, L);
    }
    else cout << "NO";
    //Resolucion del problema
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
