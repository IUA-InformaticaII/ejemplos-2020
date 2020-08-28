#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct {
    string nombre;
    string apellido;
    int edad;
} t_persona;


int main() {
    ifstream lectura;
    vector<t_persona> vect;
    t_persona tmp;

    lectura.open("Clase3/testagenda2.txt");

    if (lectura.fail()) {
        cout << "No pude abrir el archivo" << endl;
        return 1;
    }


    while (!lectura.eof()) {
        lectura >> tmp.nombre;
        lectura >> tmp.apellido;
        lectura >> tmp.edad;
        vect.push_back(tmp);
    }
    lectura.close();

    for (int i = 0; i < vect.size(); ++i) {
        cout << "nombre: " << vect[i].nombre << endl;
        cout << "apellido: " << vect[i].apellido << endl;
        cout << "edad: " << vect[i].edad << endl << endl;
    }
    return 0;
}

