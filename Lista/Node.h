#ifndef INFO2_2020_NODE_H
#define INFO2_2020_NODE_H


class Node {
private:
    int data;
    Node *next;
public:
    int getData() {
        return data;
    }

    void setData(int d) {
        data = d;
    }

    Node *getNext() {
        return next;
    }

    void setNext(Node *n) {
        next = n;
    }
};


#endif //INFO2_2020_NODE_H
