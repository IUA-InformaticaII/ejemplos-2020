#include <iostream>

using namespace std;

typedef struct {
    string nombre;
    int edad;
    int curso;
    int nota;
} alumno;

void mostrar_alumno(alumno a);


void cargar_dato(alumno curso[10]);

int main() {
    alumno curso[10];

    cargar_dato(curso);

    curso[0].edad = 3;
    curso[0].curso = 1;

    mostrar_alumno(curso[0]);

    return 0;
}

void cargar_dato(alumno curso[10]) {
    for (int i = 0; i < 10; i++) {
        cout << "ingrese nombre: ";
        cin >> curso[i].nombre;
        cout << "ingrese edad: ";
        cin >> curso[i].edad;
        cout << "ingrese curso: ";
        cin >> curso[i].curso;
    }
}

void mostrar_alumno(alumno a) {
    cout << "nombre: " << a.nombre << endl;
    cout << "edad: " << a.edad << endl;
    cout << "curso: " << a.curso << endl;
}
