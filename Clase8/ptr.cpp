
#include <iostream>

using namespace std;

typedef struct miEstructra{
    string nombre;
    string apellido;
    int edad;
    int *edadptpap;
} t_persona;

int main() {
    int conta = 5;
    int arrint[10];

    t_persona juan = {"juan", "perez", 25};
    t_persona personas[10];
    juan.edad = 7;


    // Una sola variable
    int *ptr;
    ptr = &conta;
    *ptr = 45;

    // Una sola estructura
    t_persona *pp;
    pp = &juan;
    (*pp).edad = 45;
    pp->edad = 32;

    // Arreglo de int
    arrint[0] = 3;
    *arrint = 64;

    // Arreglo de personas
    personas[0].edad = 3;
    (*personas).edad = 3;
    personas->edad = 5;

    cout << "Holamundo";
}

typedef struct Articulo {
    int nombre;
    int precio;
} t_articulo;


void mostrarLista(t_articulo *p_articulos) {
    cout << "lista de Articulos" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Nombre: " << p_articulos->nombre << endl;
        cout << "Precio: $" << p_articulos->precio << endl;
        p_articulos++;
        cout << endl;
    }
}