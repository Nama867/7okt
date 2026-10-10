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

void displayBackward(Node* tail) {
    Node* temp = tail;
    cout << "Backward:" << endl;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->prev; // Bergerak mundur menggunakan pointer prev
    }
};
