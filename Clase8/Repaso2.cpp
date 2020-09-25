#include  <iostream>
#include <fstream>

int cargar_ventas_diarias(int *pInt);

using namespace std;

/**
 * 2. Escribir un programa utilizando punteros y funciones en la cual
 * se desea cargar en un vector con las ventas diarias de un negocio,
 * 3 como máximo. La carga finaliza cuando el monto igual a cero.
 * Crear una estructura Factura, en donde tenga los siguientes atributos:
 * numero, fecha y monto total.
 * Además, se pide:
                - Cantidad de ventas cargadas.
                - Calcular la recaudación del día de manera recursiva.
                - Guardar los datos en un archivo.
 */

typedef struct {
    int numero;
    int fecha[6];
    int total;
} t_factura;


int calcularRecaudacion(int *arr, int tam) {
    if (tam == 0)
        return 0;
    return calcularRecaudacion(arr, tam - 1) + arr[tam - 1];
}

void guardarDatos(int *arr, int tam) {
    ofstream salida;
    salida.open("ventas.txt", ios::app );

    if (!salida.is_open()) {
        cout << "No se pudo abrir el archivo";
        return;
    }

    for (int i = 0; i < tam; i++) {
        salida << arr[i] << endl;
    }

    salida.close();
}

int main() {
    int ventas[3];
    int cant_ventas;

    cant_ventas = cargar_ventas_diarias(ventas);

    cout << "Ingresadas " << cant_ventas << " de ventas" << endl;

    cout << "La recaudación es: " << calcularRecaudacion(ventas, cant_ventas) << endl;

    guardarDatos(ventas, cant_ventas);

    return 0;
}

int cargar_ventas_diarias1(int *arreglo) {
    int monto;
    int idx = 0;
    do {
        cout << "Ingrese el monto de la venta" << endl;
        cin >> monto;
        *arreglo = monto;
        arreglo++;
        idx++;
    } while (monto != 0 && idx < 3);
    return idx - 1;
}

void cargar_ventas_diarias2(int *arreglo) {
    int monto = 1;
    for (int idx = 0; idx < 3 && monto != 0; idx++) {
        cout << "Ingrese el monto de la venta" << endl;
        cin >> monto;
        *arreglo = monto;
        arreglo++;
    }
}

int cargar_ventas_diarias(int *arreglo) {
    int monto = 1;
    int idx;
    for (idx = 0; idx < 3; idx++) {
        cout << "Ingrese el monto de la venta" << endl;
        cin >> monto;
        if (monto == 0)
            break;
        *arreglo = monto;
        arreglo++;
    }
    return idx;
}

void cargar_ventas_diarias4(int *arreglo) {
    int monto = 1;
    for (int idx = 0; idx < 3; idx++) {
        cout << "Ingrese el monto de la venta" << endl;
        cin >> monto;
        if (monto == 0)
            break;
        *(arreglo + idx) = monto; // arreglo[idx]
    }
}