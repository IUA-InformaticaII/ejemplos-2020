#ifndef INFO2_2020_STACK_H
#define INFO2_2020_STACK_H

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node *next;
    };
    Node *top;

public:
    Stack();

    ~Stack();

    void push(T data);

    T pop();

    T peek();

    bool isEmpty();
};

template<typename T>
Stack<T>::Stack() {
    top = nullptr;
}

template<typename T>
void Stack<T>::push(T data) {
    Node *aux = new Node;
    aux->data = data;
    aux->next = top;

    top = aux;
}

template<typename T>
T Stack<T>::peek() {
    if (top == nullptr)
        throw 404;

    return top->data;
}

template<typename T>
T Stack<T>::pop() {
    if (top == nullptr)
        throw 404;

    T data = top->data;
    Node *toDelete = top;
    top = top->next;
    delete toDelete;

    return data;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

template<typename T>
Stack<T>::~Stack() {
    while(!isEmpty()){
        pop();
    }
}


#endif //INFO2_2020_STACK_H
