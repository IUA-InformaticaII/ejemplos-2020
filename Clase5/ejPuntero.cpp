#include <iostream>

using namespace std;

void sumarYMult(int a, int b, int *suma, int *mul) {
    *suma = a + b;
    *mul = a * b;
}

void sumarYMultr(int a, int b, int &suma, int &mul) {
    suma = a + b;
    mul = a * b;
}

int main() {
    int res1, res2;

    int miMatriz[50][50];

    cout << miMatriz[5][25];


    sumarYMult(3, 5, &res1, &res2);
    sumarYMultr(3, 5, res1, res2);
    cout << res1 << endl;
    cout << res2 << endl;
}