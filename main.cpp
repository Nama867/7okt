#include "list.h"

int main() {

    Node* nodeA = new Node{"A", nullptr, nullptr};
    Node* nodeB = new Node{"B", nullptr, nullptr};
    Node* nodeC = new Node{"C", nullptr, nullptr};
    Node* nodeD = new Node{"D", nullptr, nullptr};
    Node* nodeE = new Node{"E", nullptr, nullptr};

    nodeA->next = nodeB;
    
    nodeB->prev = nodeA;
    nodeB->next = nodeC;
    
    nodeC->prev = nodeB;
    nodeC->next = nodeD;
    
    nodeD->prev = nodeC;
    nodeD->next = nodeE;
    
    nodeE->prev = nodeD;

    Node* head = nodeA;

    cout << "Before: ";
    displayList(head);

    Node* nodeX = new Node{"X", nullptr, nullptr};

    nodeB->next = nodeX;
    nodeX->prev = nodeB;
    nodeX->next = nodeC;
    nodeC->prev = nodeX;

    cout << "After : ";
    displayList(head);

    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    cout << "\nForward:" << endl;
    forwardTraversal(node1);

    cout << "\nBackward:" << endl;
    backwardTraversal(node5);

    return 0;
}
