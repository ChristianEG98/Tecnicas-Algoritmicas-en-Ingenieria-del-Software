
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

 Casos base:
 cofres[0][j] = 0  0 <= j <= T
 cofres[i][0] = 0  0 <= i <= N

 Casos recursivos:
 cofres[i][j] = cofres[i - 1][j] si prof_i - 1 > j
 cofres[i][j] = max(cofres[i - 1][j], cofres[i - 1][j - prof_i - 1] + oro_i - 1) si prof_i - 1 <= j

 Llamada inicial = cofres[N, T]

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tCofre {
    int prof;
    int oro;
};

int cofres_rec(vector<tCofre> const& C, int i, int j, Matriz<int>& cofres) {
    if (cofres[i][j] != -1) return cofres[i][j];
    if (i == 0 || j == 0) cofres[i][j] = 0;
    else if (C[i - 1].prof > j)
        cofres[i][j] = cofres_rec(C, i - 1, j, cofres);
    else
        cofres[i][j] = std::max(cofres_rec(C, i - 1, j, cofres), cofres_rec(C, i - 1, j - C[i - 1].prof, cofres) + C[i - 1].oro);
    
    return cofres[i][j];
}

int cofres_sol(vector<tCofre> const& C, int T, vector<bool> & sol) {
    int n = C.size();
    Matriz<int> cofres(n + 1, T + 1, -1);
    int oro = cofres_rec(C, n, T, cofres); //Coste O(N * T)
    //Calculo de los cofres
    int i = n, j = T;
    sol = vector<bool>(n, false);
    while (i > 0 && j > 0) { //Coste O(N)
        if (cofres[i][j] != cofres[i - 1][j]) {
            sol[i - 1] = true;
            j = j - C[i - 1].prof;
        }
        i--;
    }
    return oro;
}

bool resuelveCaso() { //Coste O(N * T) en tiempo y espacio
    //Lectura de datos
    int T, N; //T = Segundos botella / N = Numero cofres
    cin >> T >> N;
    if (!cin) return false;
    vector<tCofre> cofres(N);
    for (int i = 0; i < N; i++) {
        int p; cin >> p; p = p + 2 * p;
        cofres[i].prof = p;
        cin >> cofres[i].oro;
    }
    //Resolucion del problema
    vector<bool> sol; int numCofres = 0;
    cout << cofres_sol(cofres, T, sol) << "\n";
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i]) numCofres++;
    }
    cout << numCofres << "\n";
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i]) {
            int p = cofres[i].prof;
            p = p / 3;
            cout << p << " " << cofres[i].oro << "\n";
        }
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
