#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream lectura;
    int arreglo[10];

    lectura.open("Clase3/test2.txt");
    for (int i = 0; i < 10; ++i) {
        if (lectura.eof()) {
            arreglo[i] = 0;
        } else
            lectura >> arreglo[i];
    }
    lectura.close();

    for (int i = 0; i < 10; ++i) {
        cout << arreglo[i] << endl;
    }
    return 0;
}

