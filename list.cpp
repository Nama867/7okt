#include "list.h"

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
};

void forwardTraversal(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
};

void backwardTraversal(Node* tail) {
    Node* temp = tail;
    
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->prev;
    }
};



void insertMiddle(Node* prevNode, string newData) {
    if (prevNode == nullptr) {
        cout << "Node sebelumnya tidak boleh null." << endl;
        return;
    }

    Node* newNode = new Node{newData, nullptr, nullptr};

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;

};

void deleteNode(Node* delNode) {
    if (delNode == nullptr) {
        cout << "Node tidak boleh null." << endl;
        return;
    }

    if (delNode->prev != nullptr) {
        delNode->prev->next = delNode->next;
    }

    if (delNode->next != nullptr) {
        delNode->next->prev = delNode->prev;
    }

    cout << "Node \"" << delNode->data << "\" berhasil dihapus." << endl;
    delete delNode;
};

