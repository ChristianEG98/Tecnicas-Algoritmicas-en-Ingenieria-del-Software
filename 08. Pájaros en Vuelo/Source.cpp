
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

//Coste O(log 1+numParejas*2)*(izq.size + der.size)
bool resuelveCaso() {
    int primer, numParejas;
    // leer los datos de la entrada
    cin >> primer >> numParejas;
    if (primer == 0 && numParejas == 0)
        return false;
    else {
        vector<int> edades(numParejas * 2 + 1);
        priority_queue<int, vector<int>> izq; //En top() el mayor
        priority_queue<int, vector<int>, greater<int>> der; //En top() el menor
        // resolver el caso
        der.push(primer);
        while (numParejas > 0) {
            int edadPrim, edadSeg, aux; 
            cin >> edadPrim;
            cin >> edadSeg;
            if (edadPrim > primer && edadSeg > primer) {
                der.push(edadPrim); der.push(edadSeg);
                aux = der.top(); der.pop();
                izq.push(aux);
            }
            else if (edadPrim < primer && edadSeg < primer) {
                izq.push(edadPrim); izq.push(edadSeg);
                aux = izq.top(); izq.pop();
                der.push(aux);
            }
            else if (edadPrim > primer && edadSeg < primer) {
                der.push(edadPrim); izq.push(edadSeg);
            }
            else {
                izq.push(edadPrim); der.push(edadSeg);
            }
            cout << der.top() << " ";
            primer = der.top();
            numParejas--;
        }
        cout << "\n";
    }
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
