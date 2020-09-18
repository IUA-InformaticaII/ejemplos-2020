#include <iostream>

using namespace std;

unsigned long fibonacci(unsigned n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "fib: 3  " << fibonacci(3) << endl;
    cout << "fib: 5  " << fibonacci(5) << endl;
    cout << "fib: 10  " << fibonacci(10) << endl;
    cout << "fib: 15  " << fibonacci(15) << endl;
    return 0;
}