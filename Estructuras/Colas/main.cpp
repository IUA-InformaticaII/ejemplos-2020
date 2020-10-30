//
// Created by martin on 30/10/20.
//
#include <iostream>
#include "Queue.h"

using namespace std;


int main() {
    Queue<string> qq;

    qq.enqueue("primero");
    qq.enqueue("segundo");
    qq.enqueue("tercero");
    qq.enqueue("cuarto");


    while (!qq.isEmpty()) {
        cout << qq.dequeue() << endl;
    }


    return 0;
}