#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *down;
};

Node* create(int val) {
    Node *n = new Node();
    n->data = val; n->next = NULL; n->down = NULL;
    return n;
}

void insertHorizontal(Node *head, int val) {
    while (head->next) head = head->next;
    head->next = create(val);
}

void insertVertical(Node *head, int val) {
    while (head->down) head = head->down;
    head->down = create(val);
}

void displayRecursive(Node *head) {
    if (!head) return;
    cout << head->data;
    if (head->down) {
        cout << "-> ";
        displayRecursive(head->down);
    }
    if (head->next) {
        cout << ", ";
        displayRecursive(head->next);
    }
}

void displayIterative(Node *head) {
    while (head) {
        cout << head->data;
        Node *temp = head->down;
        while (temp) {
            cout << "-> " << temp->data;
            temp = temp->down;
        }
        head = head->next;
        if (head) cout << ", ";
    }
    cout << "\n";
}

int main() {
    cout << "===== GENERALIZED LINKED LIST =====\n\n";
    
    // Create first node
    Node *head = create(1);
    
    // Add horizontal nodes
    insertHorizontal(head, 2);
    insertHorizontal(head, 3);
    
    // Add vertical nodes to first node
    insertVertical(head, 10);
    insertVertical(head, 20);
    
    // Add vertical nodes to second node
    Node *second = head->next;
    insertVertical(second, 30);
    insertVertical(second, 40);
    
    // Add vertical nodes to third node
    Node *third = head->next->next;
    insertVertical(third, 50);
    
    cout << "GLL (Iterative Display): ";
    displayIterative(head);
    
    cout << "GLL (Recursive Display): ";
    displayRecursive(head);
    cout << "\n";
    
    return 0;
}