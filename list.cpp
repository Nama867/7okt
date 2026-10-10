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
}
};
