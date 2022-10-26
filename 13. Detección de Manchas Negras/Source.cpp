
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

using Mapa = vector<string>;

class Manchas { 
private:
    vector<vector<bool>> visitados;
    int F, C, manchas, maxim;

    const vector<pair<int, int>> dirs = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    bool correcta(int i, int j) const { //Si esta dentro de los limites de la matriz
        return (0 <= i && i < F) && (0 <= j && j < C);
    }

    int dfs(vector<string> const& mapa, int i, int j) {
        visitados[i][j] = true;
        int tam = 1;
        for (auto d: dirs) {
            int ni = i + d.first, nj = j + d.second;
            if (correcta(ni, nj) && mapa[ni][nj] == '#' && !visitados[ni][nj]) {
                tam += dfs(mapa, ni, nj);
            }
        }
        return tam;
    }


public:
    Manchas(Mapa const& mapa) : F(mapa.size()), C(mapa[0].size()), manchas(0),
    maxim(0), visitados(mapa.size(), vector<bool>(mapa[0].size(), false)) {
        for (int i = 0; i < F; ++i) {
            for (int j = 0; j < C; ++j) {
                if (!visitados[i][j] && mapa[i][j] == '#') { //Nueva componente conexa
                    ++manchas;
                    int nuevotam = dfs(mapa, i, j);
                    maxim = max(nuevotam, maxim);
                }
            }
        }
    }
    int mancha() const {
        return manchas;
    }
    int maximo() const {
        return maxim;
    }
};

//Coste O(F*C)
bool resuelveCaso() {
    //Lectura de datos
    int F, C;
    cin >> F >> C;
    if (!cin) return false;
    Mapa mapa(F);
    for (string& linea : mapa) cin >> linea;
    //Resolucion del problema
    Manchas manchas(mapa);
    cout << manchas.mancha() << " " << manchas.maximo();
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
