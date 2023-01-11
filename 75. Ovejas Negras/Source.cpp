
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include "ConjuntosDisjuntos.h"

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

class Ovejas {
private:
    int F, C;
    Matriz<bool> visit;
    int num;

    const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };

    bool correcta(int i, int j) const {
        return 0 <= i && i < F && 0 <= j && j < C;
    }

    void dfs(Matriz<char> const& M, int i, int j) {
        visit[i][j] = true;
        for (auto d : dirs) {
            int ni = i + d.first, nj = j + d.second;
            if (correcta(ni, nj) && M[ni][nj] == '.' && !visit[ni][nj]) {
                dfs(M, ni, nj);
            }
        }
    }

public:
    Ovejas(Matriz<char> const& M) : F(M.numfils()), C(M.numcols()), visit(F, C, false), num(0) {
        for(int i = 0; i < F; i++)
            for (int j = 0; j < C; j++) {
                if (!visit[i][j] && M[i][j] == '.') {
                    num++;
                    dfs(M, i, j);
                }
            }
    }

    int numero() const {
        return num - 1;
    }
};

bool resuelveCaso() {
    //Lectura de datos
    int ancho, alto;
    cin >> ancho >> alto;
    if (!cin) return false;
    Matriz<char> imagen(alto, ancho);
    for(int i = 0; i < alto; i++)
        for (int j = 0; j < ancho; j++) {
            cin >> imagen[i][j];
        }
    //Resolucion del problema
    Ovejas ov(imagen);
    cout << ov.numero();
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
