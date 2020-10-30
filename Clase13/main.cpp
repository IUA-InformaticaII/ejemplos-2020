/* 3. Elaborar un sistema de stock, en la cual posee una lista de productos con
 los siguientes atributos: codigo, nombre, cantidad, precio lista.
 Desarrollar las siguientes funciones:
	a. Mostrar el stock. (lista de productos)
	b. Descontar stock.
	c. Reponer stock.
	(hacer con estructura - clases y objetos)
*/

#include <iostream>
#include "../Estructuras/Lista/LinkedList.h"
#include "stock.h"

using namespace std;

void mostrar(LinkedList<stock> &lista);

void descontar(LinkedList<stock> &lista);

void reponer(LinkedList<stock> &lista);

int main(int argc, char *argv[]) {

    LinkedList<stock> lista;
    stock a;
    char opc, fin;

    a.codigo = 1;
    a.nombre = "azul";
    a.cantidad = 5;
    a.precio = 100;
    lista.insert(0, a);

    a.codigo = 2;
    a.nombre = "rojo";
    a.cantidad = 10;
    a.precio = 150;
    lista.insert(1, a);

    a.codigo = 3;
    a.nombre = "verde";
    a.cantidad = 15;
    a.precio = 200;
    lista.insert(2, a);

    cout << "Selecciona una opcion del menu: " << endl;
    do {
        cout << "a. Mostrar el stock.\nb. Descontar stock.\nc. Reponer stock." << endl;
        cin >> opc;
        switch (opc) {
            case 'a':
                mostrar(lista);
                break;
            case 'b':
                descontar(lista);
                mostrar(lista);
                break;
            case 'c':
                reponer(lista);
                mostrar(lista);
                break;
            default:
                cout << "Selecciono una opcion invalida." << endl;
        }
        cout << "\n¿Realizar otra opcion? (S/N)" << endl;
        cin >> fin;
    } while (fin == 'S' || fin == 's');

    return 0;
}

void mostrar(LinkedList<stock> &lista) {

    stock a;
    cout << "\nLista de tarros de pintura: " << endl;
    cout << "Cod. \tNomb.\tCant.\tPrecio" << endl;
    for (int i = 0; i < 3; i++) {
        a = lista.get(i);
        cout << a.codigo << "\t" << a.nombre << "\t" << a.cantidad << "\t" << a.precio << endl;
    }
}

void descontar(LinkedList<stock> &lista) {

    stock a;
    int cod = 0, quitar = 0;

    cout << "\nCodigo del articulo: ";
    cin >> cod;
    cout << "Cantidad a descontar: ";
    cin >> quitar;

    for (int i = 0; i < 3; i++) {
        a = lista.get(i);
        if (a.codigo == cod) {
            a.cantidad = a.cantidad - quitar;
            lista.replace(i, a);
        }
    }
}

void reponer(LinkedList<stock> &lista) {

    stock a;
    int cod = 0, agregar = 0;

    cout << "\nCodigo del articulo: ";
    cin >> cod;
    cout << "Cantidad a agregar: ";
    cin >> agregar;

    for (int i = 0; i < 3; i++) {
        a = lista.get(i);
        if (a.codigo == cod) {
            a.cantidad = a.cantidad + agregar;
            lista.replace(i, a);
        }
    }
}