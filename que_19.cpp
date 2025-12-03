#include <iostream>
using namespace std;

struct Node { int data; Node *prev, *next; };

Node *head = NULL;

void insertBegin(int val) {
    Node *n = new Node(); n->data = val; n->prev = NULL;
    n->next = head;
    if (head) head->prev = n;
    head = n;
}

void insertEnd(int val) {
    Node *n = new Node(); n->data = val; n->next = NULL;
    if (!head) { n->prev = NULL; head = n; return; }
    Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n; n->prev = temp;
}

void insertPos(int val, int pos) {
    if (pos == 0) { insertBegin(val); return; }
    Node *temp = head;
    for (int i = 0; i < pos-1 && temp; ++i) temp = temp->next;
    if (!temp) { cout << "Invalid position\n"; return; }
    Node *n = new Node(); n->data = val;
    n->next = temp->next;
    n->prev = temp;
    if (temp->next) temp->next->prev = n;
    temp->next = n;
}

void deleteBegin() {
    if (!head) { cout << "List is empty\n"; return; }
    head = head->next;
    if (head) head->prev = NULL;
}

void deleteEnd() {
    if (!head) { cout << "List is empty\n"; return; }
    Node *temp = head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else head = NULL;
}

void deletePos(int pos) {
    if (!head) { cout << "List is empty\n"; return; }
    if (pos == 0) { deleteBegin(); return; }
    Node *temp = head;
    for (int i = 0; i < pos-1 && temp; ++i) temp = temp->next;
    if (!temp || !temp->next) { cout << "Invalid position\n"; return; }
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next) nodeToDelete->next->prev = temp;
}

void search(int val) {
    Node *temp = head;
    int pos = 0;
    while (temp) {
        if (temp->data == val) { cout << "Found " << val << " at position " << pos << "\n"; return; }
        temp = temp->next; ++pos;
    }
    cout << val << " not found\n";
}

void displayForward() {
    if (!head) { cout << "List is empty\n"; return; }
    Node *temp = head;
    cout << "Forward: ";
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << "\n";
}

void displayBackward() {
    if (!head) { cout << "List is empty\n"; return; }
    Node *temp = head;
    while (temp->next) temp = temp->next;
    cout << "Backward: ";
    while (temp) { cout << temp->data << " "; temp = temp->prev; }
    cout << "\n";
}

int main() {
    int choice, val, pos;
    
    while (true) {
        cout << "\n===== DOUBLY LINKED LIST =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from position\n";
        cout << "7. Search\n";
        cout << "8. Display forward\n";
        cout << "9. Display backward\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 10) break;
        
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertBegin(val);
            cout << "Inserted at beginning\n";
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
            cout << "Inserted at end\n";
        }
        else if (choice == 3) {
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter position: ";
            cin >> pos;
            insertPos(val, pos);
            cout << "Inserted at position " << pos << "\n";
        }
        else if (choice == 4) {
            deleteBegin();
            cout << "Deleted from beginning\n";
        }
        else if (choice == 5) {
            deleteEnd();
            cout << "Deleted from end\n";
        }
        else if (choice == 6) {
            cout << "Enter position: ";
            cin >> pos;
            deletePos(pos);
            cout << "Deleted from position " << pos << "\n";
        }
        else if (choice == 7) {
            cout << "Enter value to search: ";
            cin >> val;
            search(val);
        }
        else if (choice == 8) {
            displayForward();
        }
        else if (choice == 9) {
            displayBackward();
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    cout << "Program ended.\n";
    return 0;
}