
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

struct tPelicula {
    int hora;
    int minutos;
    int duracion;
    int horaFin;
    int minutosFin;
};

bool ordenarPeliculas(tPelicula const& a, tPelicula const& b) {
    if (a.horaFin != b.horaFin) return a.horaFin < b.horaFin;
    else return a.minutosFin < b.minutosFin;
}

void calcularHoraFin(tPelicula& p) {
    int min = 10 + p.duracion + p.minutos + p.hora * 60;
    p.minutosFin = min % 60;
    p.horaFin = min / 60;
}

bool daTiempo(tPelicula const& p1, tPelicula const& p2) {
    if (p1.horaFin < p2.hora) return true;
    else if (p1.horaFin == p2.hora && p1.minutosFin <= p2.minutos) return true;
    else return false;
}

int maxPeliculas(vector<tPelicula> const& peliculas) {
    int numPeliculas = 1;
    tPelicula p = peliculas[0];
    for (int i = 1; i < peliculas.size(); i++) {
        if (daTiempo(p, peliculas[i])) {
            numPeliculas++;
            p = peliculas[i];
        }
    }
    return numPeliculas;
}

bool resuelveCaso() { //Coste O(n log n) por haber ordenado el vector
    //Lectura de datos
    int N; //N = Numero de peliculas
    cin >> N;
    if (N == 0) return false;
    vector<tPelicula> peliculas(N);
    for (int i = 0; i < peliculas.size(); i++) {
        cin >> peliculas[i].hora;
        cin.ignore(1);
        cin >> peliculas[i].minutos;
        cin >> peliculas[i].duracion;
        calcularHoraFin(peliculas[i]);
    }
    sort(peliculas.begin(), peliculas.end(), ordenarPeliculas);
    //Resolucion del problema
    cout << maxPeliculas(peliculas);
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
