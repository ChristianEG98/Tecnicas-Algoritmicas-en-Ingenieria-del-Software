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
* 
 peliculas(i, j) = máximo de minutos para ver las peliculas de i ... N sin solaparse.

 Caso base: peliculas(0, j) = 0 si no hay películas
 Caso recursivo: peliculas(i, j) = max(peliculas(i - 1, j), peliculas(i - 1, j - pelicula[i].fin) + pelicula[i].duracion)

 Llamada inicial: f(0)

 Coste O(N * M) en tiempo y O(M) en espacio

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tPelicula {
    int ini;
    int fin;
    int duracion;
};

bool operator <(tPelicula const& a, tPelicula const& b) {
    return a.ini < b.ini;
}

int tiempoMaximo(vector<tPelicula> const& peliculas) {
    int n = peliculas.size(), m = (24 * 60) + 10;
    vector<int> tiempo(m + 1, 0);

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m - 10; j++) {
            if (peliculas[i - 1].ini >= j && peliculas[i - 1].fin <= m)
                tiempo[j] = std::max(tiempo[j], tiempo[peliculas[i - 1].fin] + peliculas[i - 1].duracion);
        }
    }
    return tiempo[0];
}

bool resuelveCaso() {
    // leemos la entrada
    int N;
    cin >> N;
    if (N == 0) return false;
    vector<tPelicula> peliculas(N);
    for (int i = 0; i < N; i++) {
        int h, m, fin, duracion;
        cin >> h; cin.ignore(); cin >> m; h *= 60; peliculas[i].ini = h + m;
        cin >> duracion; peliculas[i].duracion = duracion;
        fin = h + m + duracion + 10; peliculas[i].fin = fin;
    }
    std::sort(peliculas.begin(), peliculas.end());
    // resolver el caso
    cout << tiempoMaximo(peliculas);
    cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
