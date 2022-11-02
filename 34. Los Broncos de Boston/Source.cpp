
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

 Como sabemos la secuencia exacta de puntos de los rivales y de los broncos, para maximizar el resultado
 ordenamos el vector de puntos de los rivales de menor a mayor y el de los broncos de mayor a menor.
 Recorremos ambos vectores al mismo tiempo y comparamos las mismas posiciones, si los puntos de los broncos
 es mayor al de los rivales, se añade la diferencia a una variable que lleva la suma del maximo de puntos
 alcanzables. El recorrido del vector termina cuando se recorre entero o bien, cuando encuentra que los puntos
 de los rivales son mayores a los de los broncos, ya que, por la ordenacion realizada, los broncos ya no obtendran
 mas victorias a partir de ahi.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int exitoMaximo(vector<int> const& rivales, vector<int> const& broncos) { //Coste O(n) siendo n rivales.size() = broncos.size()
    int puntos = 0, i = 0;
    while(i < rivales.size()) {
        if (rivales[i] < broncos[i]) {
            puntos += broncos[i] - rivales[i];
            i++;
        }
        else i = rivales.size();
    }
    return puntos;
}

bool resuelveCaso() { //Coste O(n log n) por haber ordenado los vectores
    //Lectura de datos
    int N; //N = Numero de partidos
    cin >> N;
    if (N == 0) return false;
    vector<int> rivales(N);
    for (int i = 0; i < N; i++) cin >> rivales[i];
    sort(rivales.begin(), rivales.end());
    vector<int> broncos(N);
    for (int i = 0; i < N; i++) cin >> broncos[i];
    sort(broncos.begin(), broncos.end(), greater<int>());
    //Resolucion del problema
    cout << exitoMaximo(rivales, broncos);
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
