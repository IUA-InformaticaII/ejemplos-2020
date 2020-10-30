//
// Created by martin on 30/10/20.
//

#ifndef INFO2_2020_QUEUE_H
#define INFO2_2020_QUEUE_H

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;
    };
    Node *front;
    Node *back;

public:
    Queue();
    ~Queue();

    // encolar
    void enqueue(T data);

    // desencolar
    T dequeue();

    // esVacia
    bool isEmpty();
};

template<typename T>
Queue<T>::Queue() {
    front = back = nullptr;
}

template<typename T>
void Queue<T>::enqueue(T data) {
    Node *aux = new Node;
    aux->data = data;
    aux->next = nullptr;

    if (back != nullptr)
        back->next = aux;
    else
        front = aux;

    back = aux;
}

template<typename T>
Queue<T>::~Queue() {
    while (!isEmpty())
        dequeue();
}

template<typename T>
T Queue<T>::dequeue() {
    if (front == nullptr)
        throw 404;

    T data = front->data;
    Node *toDelete = front;
    front = front->next;
    delete toDelete;

    if (front == nullptr)
        back = front;

    return data;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return front == nullptr;
}


#endif //INFO2_2020_QUEUE_H
