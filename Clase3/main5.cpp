#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
    string nombre;
    string apellido;
    int edad;
} t_persona;


int main() {
    ifstream lectura;
    int cant_datos;

    lectura.open("Clase3/testagenda.txt");

    if (lectura.fail()) {
        cout << "No pude abrir el archivo" << endl;
        return 1;
    }

    lectura >> cant_datos;
    cout << "Cant Datos: " << cant_datos << endl<< endl;

    t_persona arreglo[cant_datos];

    for (int i = 0; i < cant_datos; ++i) {
        lectura >> arreglo[i].nombre;
        lectura >> arreglo[i].apellido;
        lectura >> arreglo[i].edad;
    }
    lectura.close();

    for (int i = 0; i < cant_datos; ++i) {
        cout << "nombre: " << arreglo[i].nombre << endl;
        cout << "apellido: " << arreglo[i].apellido << endl;
        cout << "edad: " << arreglo[i].edad << endl << endl;
    }
    return 0;
}

