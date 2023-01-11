
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

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

struct tBateria {
    int tiempo;
    int capacidad;
    int id;
};

bool operator<(tBateria const& a, tBateria const& b) {
    return a.tiempo < b.tiempo || ((a.tiempo == b.tiempo) && a.id < b.id);
}

void estadoBaterias(PriorityQueue<tBateria>& baterias, vector<tBateria>& reservas, const int degradacion,
    const int tiempo, const int nBaterias) {
    int t = 0; int r = 0;
    tBateria aux;
    if (!baterias.empty()) {
        aux = baterias.top();
    }
    while (!baterias.empty() && aux.tiempo <= tiempo) {
        baterias.pop();
        if (aux.capacidad - degradacion > 0) { //Si aun tiene carga
            aux.capacidad -= degradacion;
            aux.tiempo += aux.capacidad;
            baterias.push(aux);
        }
        else { //Si ya no puede recargarse mas
            if (r < reservas.size()) {
                tBateria res = reservas[r];
                res.tiempo += aux.tiempo;
                baterias.push(res);
                r++;
            }
        }
        if (!baterias.empty()) {
            aux = baterias.top();
        }
    }
    if (baterias.size() == nBaterias) {
        cout << "CORRECTO" << '\n';
    }
    else if (baterias.empty()) cout << "ABANDONEN INMEDIATAMENTE LA BASE" << '\n';
    else {
        cout << "FALLO EN EL SISTEMA" << '\n';
    }
    while (!baterias.empty()) {
        cout << baterias.top().id << " " << baterias.top().tiempo << '\n';
        baterias.pop();
    }
    cout << "---" << '\n';
}

bool resuelveCaso() { 
    //Lectura de datos
    int nBaterias; cin >> nBaterias;
    if (!cin) return false;
    PriorityQueue<tBateria> baterias;
    for (int i = 0; i < nBaterias; i++) {
        int c; cin >> c;
        baterias.push({ c, c, i + 1 });
    }
    int nReserva; cin >> nReserva;
    vector<tBateria> reservas(nReserva);
    for (int i = 0; i < nReserva; i++) {
        int c; cin >> c;
        reservas[i] = { c, c, i + 1 + nBaterias };
    }
    int degradacion; cin >> degradacion;
    int tiempo; cin >> tiempo;
    //Resolucion del problema
    estadoBaterias(baterias, reservas, degradacion, tiempo, nBaterias);
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
