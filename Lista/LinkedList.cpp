//
// Created by martin on 2/10/20.
//
#include <iostream>
#include "LinkedList.h"

using namespace std;


LinkedList::LinkedList() {
    head = nullptr;
}


void LinkedList::insert(int pos, int dato) {
    Node *aux;

    if (pos == 0) { // caso especial para pos = 0
        aux = new Node;
        aux->setNext(head);
        aux->setData(dato);
        head = aux;
        return;
    }

    aux = getNode(pos - 1);

    Node *newNode = new Node;
    newNode->setNext(aux->getNext());
    aux->setNext(newNode);
    newNode->setData(dato);

}

int LinkedList::get(int pos) {
    Node *aux = getNode(pos);
    return aux->getData();
}

Node *LinkedList::getNode(int pos) {
    Node *aux = head;
    int p = 0;

    while (p != pos && aux != nullptr) {
        aux = aux->getNext();
        p++;
    }

    if (aux == nullptr) {
        throw 404;
    }

    return aux;
}


void LinkedList::replace(int pos, int dato) {
    Node *aux = getNode(pos);
    aux->setData(dato);
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}

void LinkedList::remove(int pos) {

    if (head == nullptr)
        throw 404;

    if (pos == 0) {
        Node *toDelete = head;
        head = head->getNext();
        delete toDelete;
        return;
    }

    Node *aux = getNode(pos - 1);
    Node *toDelete = aux->getNext();

    if (toDelete == nullptr) {
        throw 404;
    }

    aux->setNext(toDelete->getNext());
    delete toDelete;
}

