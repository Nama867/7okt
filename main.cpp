#include "list.h"

int main() {
    Node* node1 = new Node{"Song A", nullptr, nullptr};
    Node* node2 = new Node{"Song B", nullptr, nullptr};
    Node* node3 = new Node{"Song C", nullptr, nullptr};
    Node* node4 = new Node{"Song D", nullptr, nullptr};
    Node* node5 = new Node{"Song E", nullptr, nullptr};

    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = node4;

    node4->prev = node3;
    node4->next = node5;

    node5->prev = node4;

    cout << "Isi List: ";
    displayList(node1);

    cout << "\nForward:" << endl;
    forwardTraversal(node1);

    return 0;
}
