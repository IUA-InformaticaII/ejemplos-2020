#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream lectura;
    int tmp, i = 0;

    lectura.open("Clase3/test3.txt");
    while (!lectura.eof()) {
        lectura >> tmp;
        cout << "Dato Leido N" << i << ": " << tmp << endl;
        i++;
    }
    lectura.close();
    return 0;
}

