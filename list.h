#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <string>

using namespace std;

// Task 1 - Create the Node
struct Node {
    string data;
    Node* prev;
    Node* next;
};

// Deklarasi fungsi untuk menampilkan list
void displayList(Node* head);

#endif