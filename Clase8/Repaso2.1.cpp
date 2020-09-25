#include  <iostream>
#include <fstream>
#include <time.h>


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
    int fecha[3];
    int total;
} t_factura;


int cargar_ventas_diarias(t_factura *arreglo) {
    int monto = 1;
    int idx;
    time_t times = time(0);
    struct tm *fecha = localtime(&times);

    for (idx = 0; idx < 3; idx++) {
        cout << "Ingrese el monto de la venta" << endl;
        cin >> monto;
        if (monto == 0)
            break;
        arreglo->numero = idx;
        arreglo->total = monto;
        arreglo->fecha[0] = fecha->tm_mday;
        arreglo->fecha[1] = fecha->tm_mon + 1;
        arreglo->fecha[2] = fecha->tm_year + 1900;
        arreglo++;
    }
    return idx;
}

int calcularRecaudacion(t_factura *arr, int tam) {
    if (tam == 0)
        return 0;
    return calcularRecaudacion(arr, tam - 1) + arr[tam - 1].total;
}

void guardarDatos(t_factura *arr, int tam) {
    ofstream salida;
    salida.open("ventas.txt", ios::app);

    if (!salida.is_open()) {
        cout << "No se pudo abrir el archivo";
        return;
    }

    for (int i = 0; i < tam; i++) {
        salida << arr[i].numero << "\t";
        salida << arr[i].fecha[0] << "/" << arr[i].fecha[1] << "/" << arr[i].fecha[2] << "\t";
        salida << arr[i].total << endl;
    }

    salida.close();
}

int main() {
    t_factura ventas[3];
    int cant_ventas;

    cant_ventas = cargar_ventas_diarias(ventas);

    cout << "Ingresadas " << cant_ventas << " de ventas" << endl;

    cout << "La recaudación es: " << calcularRecaudacion(ventas, cant_ventas) << endl;

    guardarDatos(ventas, cant_ventas);

    return 0;
}

