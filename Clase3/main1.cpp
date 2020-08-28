#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream archivoSalida;

    // Escribo 10 veces en el archivo test.txt
    archivoSalida.open("Clase3/test1.txt");
    for (int i = 0; i < 10; ++i) {
        archivoSalida << "i: " << i << endl;
    }
    archivoSalida.close();

    return 0;
}

