#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
};

void displayList(Node* head);
void forwardTraversal(Node* head);
void backwardTraversal(Node* tail);

#endif
