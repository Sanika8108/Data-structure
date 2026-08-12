#include <iostream>
using namespace std;

struct Node {
    string song;
    Node *prev, *next;
};

int main() {
    Node *a = new Node{"Song A", NULL, NULL};
    Node *b = new Node{"Song B", a, NULL};
    Node *c = new Node{"Song C", b, NULL};

    a->next = b;
    b->next = c;

    
    Node *current = a;
    cout << "Forward: ";
    while (current != NULL) {
        cout << current->song << " ";
        current = current->next;
    }

    
    current = c;
    cout << "\nBackward: ";
    while (current != NULL) {
        cout << current->song << " ";
        current = current->prev;
    }

    return 0;
}
