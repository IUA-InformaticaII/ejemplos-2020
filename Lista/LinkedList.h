#ifndef INFO2_2020_LINKEDLIST_H
#define INFO2_2020_LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    Node *head;
    Node *getNode(int pos);
public:
    LinkedList();
    void insert(int pos, int dato);
    int get(int pos);
    void replace(int pos, int dato);
    bool isEmpty();
    void remove(int pos);
    int find(int dato);
};


#endif //INFO2_2020_LINKEDLIST_H
