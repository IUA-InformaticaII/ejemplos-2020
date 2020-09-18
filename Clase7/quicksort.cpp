#include  <iostream>

using namespace std;
#define TAM 6

void quicksort(int a[], int primero, int ultimo) {
    int i, d, pivote, tmp;
    //pivote = a[primero];
    pivote = a[(primero + ultimo) / 2];
    i = primero;
    d = ultimo;

    // para mostrar
    for (int i = 0; i < TAM; i++)
        cout << a[i] << " ";
    cout << " - " << primero << " " << pivote << " " << ultimo << endl;

    do {
        while (a[i] < pivote)
            i++;
        while (a[d] > pivote)
            d--;

        if (i <= d) {
            tmp = a[i];  // Swapping
            a[i] = a[d];
            a[d] = tmp;
            i++;
            d--;
        }
    } while (i <= d);

    if (primero < d)
        quicksort(a, primero, d); // Llamada recursiva
    if (i < ultimo)
        quicksort(a, i, ultimo); // Llamada recursiva
}

int main() {
    int arreglo[TAM] = {4, 5, 2, 3, 6, 1};
    quicksort(arreglo, 0, TAM - 1);

    for (int i = 0; i < TAM; i++)
        cout << arreglo[i] << endl;
    return 0;
}
