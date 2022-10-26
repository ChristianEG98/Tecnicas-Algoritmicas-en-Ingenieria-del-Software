
/*@ <answer>
 *
 * Nombre y Apellidos: Christian Esteban 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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


bool resuelveCaso() {
    //Lectura de datos
    int drones, vNueve, vUnoCinco;
    cin >> drones >> vNueve >> vUnoCinco;
    if (!cin)
        return false;
    priority_queue<int, vector<int>> pilasNueve, pilasUnoCinco;
    for (int i = 0; i < vNueve; i++) {
        int horas; cin >> horas;
        pilasNueve.push(horas);
    }
    for (int i = 0; i < vUnoCinco; i++) {
        int horas; cin >> horas;
        pilasUnoCinco.push(horas);
    }
    //Resolucion del problema
    int pNueve, pUnoCinco, tiempo = 0, contDrones = drones;
    vector<int> sobrantesNueve, sobrantesUnoCinco;
    while (pilasNueve.size() != 0 && pilasUnoCinco.size() != 0) {
        pNueve = pilasNueve.top(); pilasNueve.pop();
        pUnoCinco = pilasUnoCinco.top(); pilasUnoCinco.pop();
        if (pNueve > pUnoCinco) {
            tiempo += pUnoCinco;
            pNueve -= pUnoCinco;
            sobrantesNueve.push_back(pNueve); //Las pilas usadas las guardamos en otro vector para que no se usen ese mismo dia
        }
        else if (pNueve < pUnoCinco) {
            tiempo += pNueve;
            pUnoCinco -= pNueve;
            sobrantesUnoCinco.push_back(pUnoCinco); //Las pilas usadas las guardamos en otro vector para que no se usen ese mismo dia
        }
        else {
            tiempo += pNueve;
        }
        contDrones--;
        if (contDrones == 0 || pilasNueve.size() == 0 || pilasUnoCinco.size() == 0) { //Cada sabado
            std::cout << tiempo << " ";
            tiempo = 0;
            contDrones = drones;
            for (int i = 0; i < sobrantesNueve.size(); i++) pilasNueve.push(sobrantesNueve[i]);
            for (int i = 0; i < sobrantesUnoCinco.size(); i++) pilasUnoCinco.push(sobrantesUnoCinco[i]);
            sobrantesNueve.clear(); sobrantesUnoCinco.clear();
        }
    }
    std::cout << "\n";
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
