#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream lectura;
    int cant_datos;

    lectura.open("Clase3/test4.martin");

    if(lectura.fail()){
        cout << "no pude abrir el archivo" << endl;
        return 1;
    }

    lectura >> cant_datos;
    cout << "Cant Datos: " << cant_datos << endl;

    int arreglo[cant_datos];

    for (int i = 0; i < cant_datos; ++i) {
        if (lectura.eof()) {
            arreglo[i] = 0;
        } else
            lectura >> arreglo[i];
    }
    lectura.close();

    for (int i = 0; i < cant_datos; ++i) {
        cout << "Dato: " << arreglo[i] << endl;
    }
    return 0;
}

