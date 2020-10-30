#include "LinkedList.h"
#include <iostream>

using namespace std;

class Car {

};


int main() {
    LinkedList<float> ll;

    // 7 5 30 4
    // 0 1 2  3

    ll.insert(0, 5);
    ll.insert(1, 4);
    ll.insert(1, 30.300);
    ll.insert(0, 7);

    LinkedList<float> ll2 = ll;

    try {
        cout << ll.get(2) << endl;
        cout << ll2.get(2) << endl;
    } catch (...) {
        cout << "no andó" << endl;
    }

    return 0;
}