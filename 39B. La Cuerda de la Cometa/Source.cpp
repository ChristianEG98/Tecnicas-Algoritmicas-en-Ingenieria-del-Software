
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

struct tCordel {
    int longitud;
    int coste;
};

bool esPosible(vector<tCordel> const& C, int const& L) {
    vector<bool> sol(L + 1, false);
    sol[0] = true;
    for (int i = 1; i <= C.size(); i++) {
        for (int j = L; j >= 1; j--) {
            if (C[i - 1].longitud <= j)
                sol[j] = (sol[j] || sol[j - C[i - 1].longitud]);
        }
    }
    return sol[L];
}

long long int formasPosibles(vector<tCordel> const& C, int const& L) {
    vector<long long int> sol(L + 1, 0);
    sol[0] = 1;
    for (int i = 1; i <= C.size(); i++) {
        for (int j = L; j >= 1; j--) {
            if (C[i - 1].longitud <= j)
                sol[j] = sol[j] + sol[j - C[i - 1].longitud];
        }
    }
    return sol[L];
}

long long int minimoCuerdas(vector<tCordel> const& C, int const& L) {
    vector<long long int> sol(L + 1, (long long int) 1e18);
    sol[0] = 0;
    for (int i = 1; i <= C.size(); i++) {
        for (int j = L; j >= 1; j--) {
            if (C[i - 1].longitud <= j)
                sol[j] = std::min(sol[j], sol[j - C[i - 1].longitud] + 1);
        }
    }
    return sol[L];
}

long long int minimoCoste(vector<tCordel> const& C, int const& L) {
    vector<long long int> sol(L + 1, (long long int) 1e18);
    sol[0] = 0;
    for (int i = 1; i <= C.size(); i++) {
        for (int j = L; j >= 1; j--) {
            if (C[i - 1].longitud <= j)
                sol[j] = std::min(sol[j], sol[j - C[i - 1].longitud] + C[i - 1].coste);
        }
    }
    return sol[L];
}

bool resuelveCaso() { //Coste O(N*L) en tiempo y O(L) en espacio 
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
