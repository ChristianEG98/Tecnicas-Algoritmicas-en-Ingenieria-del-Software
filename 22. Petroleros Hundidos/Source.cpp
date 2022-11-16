
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

using Mapa = vector<string>;

class Petroleros {
private:
    vector<vector<bool>> visitados;
    vector<vector<bool>> matriz; //Matriz booleana que almacena las posiciones de las manchas
    int F, C, maximo;
    ConjuntosDisjuntos cj;

    const vector<pair<int, int>> dirs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1},{-1, 1},{1, -1},{1, 1} };

    bool correcta(int i, int j) const { //Si esta dentro de los limites de la matriz
        return (0 <= i && i < F) && (0 <= j && j < C);
    }

    void dfs(Mapa const& mapa, int i, int j, int & tam) {
        visitados[i][j] = true;
        tam++;
        for (auto d : dirs) {
            int v = i * C + j;
            int ni = i + d.first, nj = j + d.second;
            if (correcta(ni, nj) && mapa[ni][nj] == '#' && !visitados[ni][nj]) {
                int w = ni * C + nj;
                cj.unir(i * C + j, ni * C + nj);
                dfs(mapa, ni, nj, tam);
            }
        }
    }

public:
    Petroleros(Mapa const& mapa) : F(mapa.size()), C(mapa[0].size()), visitados(mapa.size(), vector<bool>(mapa[0].size(), false)),
        cj(mapa.size()* mapa[0].size()), maximo(0) {
        for (int i = 0; i < F; ++i) {
            for (int j = 0; j < C; ++j) {
                if (!visitados[i][j] && mapa[i][j] == '#') { //Nueva componente conexa
                    int tam = 0;
                    dfs(mapa, i, j, tam);
                    maximo = std::max(maximo, tam);
                }
            }
        }
    }

    void dfsNuevos(Mapa const& mapa, int i, int j) {
        bool nuevo = true;
        int v = i * C + j;
        for (auto d : dirs) {
            int ni = i + d.first, nj = j + d.second;
            int w = ni * C + nj;
            if (correcta(ni, nj) && mapa[ni][nj] == '#') {
                cj.unir(v, w);
                maximo = std::max(maximo, cj.cardinal(v));
                nuevo = false;
            }
        }
        if (nuevo) maximo = std::max(maximo, cj.cardinal(v));
    }

    int maxSol() const {
        return maximo;
    }
};

bool resuelveCaso() {
    //Lectura de datos
    int F, C;
    cin >> F >> C;
    if (!cin) return false;
    Mapa mapa(F);
    cin.get(); //cin.ignore();
    for (int i = 0; i < F; i++) getline(cin, mapa[i]);
    //Resolucion del problema
    Petroleros p(mapa);
    cout << p.maxSol() << " ";
    int adicionales; cin >> adicionales;
    for (int a = 0; a < adicionales; a++) {
        int i, j; cin >> i >> j;
        mapa[i - 1][j - 1] = '#';
        p.dfsNuevos(mapa, i - 1, j - 1);
        cout << p.maxSol() << " ";
    }
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
