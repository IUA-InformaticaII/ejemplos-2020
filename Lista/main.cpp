#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList ll;

    // 7 5 30 4
    // 0 1 2  3

    ll.insert(0, 5);
    ll.insert(1, 4);
    ll.insert(1, 30);
    ll.insert(0, 7);

    try {
        cout << ll.get(2) << endl;
    } catch (...) {
        cout << "no andó" << endl;
    }

    return 0;
}