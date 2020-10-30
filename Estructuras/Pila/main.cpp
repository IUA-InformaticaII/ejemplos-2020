//
// Created by martin on 30/10/20.
//
#include "Stack.h"
#include <iostream>

#include <stack>
#include <queue>
#include <list>

using namespace std;

int main() {
    Stack<string> ss;
    ss.push("primero");
    ss.push("segundo");
    ss.push("tercero");
    ss.push("cuarto");

    while (!ss.isEmpty()) {
        cout << ss.pop() << endl;
    }

    try {
        ss.pop();
    } catch (...) {
        cout << "estaba vacía" << endl;
    }


    return 0;
}