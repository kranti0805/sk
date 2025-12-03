#include <iostream>
using namespace std;

struct Node { int data; Node *next; };

Node *head = NULL;

void insertBegin(int val) {
    Node *n = new Node(); n->data = val;
    n->next = head; head = n;
    cout << "Inserted at beginning: " << val << "\n";
}

void insertEnd(int val) {
    Node *n = new Node(); n->data = val; n->next = NULL;
    if (!head) { head = n; cout << "Inserted at end: " << val << "\n"; return; }
    Node *temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    cout << "Inserted at end: " << val << "\n";
}

void insertPos(int val, int pos) {
    Node *n = new Node(); n->data = val;
    if (pos == 0) { n->next = head; head = n; cout << "Inserted at position " << pos << "\n"; return; }
    Node *temp = head;
    for (int i = 0; i < pos-1 && temp; ++i) temp = temp->next;
    if (temp) { n->next = temp->next; temp->next = n; cout << "Inserted at position " << pos << "\n"; }
    else cout << "Invalid position\n";
}

void deleteBegin() {
    if (!head) { cout << "List is empty\n"; return; }
    cout << "Deleted: " << head->data << "\n";
    head = head->next;
}

void deleteEnd() {
    if (!head) { cout << "List is empty\n"; return; }
    if (!head->next) { cout << "Deleted: " << head->data << "\n"; head = NULL; return; }
    Node *temp = head;
    while (temp->next->next) temp = temp->next;
    cout << "Deleted: " << temp->next->data << "\n";
    temp->next = NULL;
}

void deletePos(int pos) {
    if (!head) { cout << "List is empty\n"; return; }
    if (pos == 0) { deleteBegin(); return; }
    Node *temp = head;
    for (int i = 0; i < pos-1 && temp; ++i) temp = temp->next;
    if (temp && temp->next) { cout << "Deleted: " << temp->next->data << "\n"; temp->next = temp->next->next; }
    else cout << "Invalid position\n";
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

void display() {
    if (!head) { cout << "List is empty\n"; return; }
    Node *temp = head;
    cout << "List: ";
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << "\n";
}

int main() {
    int choice, val, pos;
    
    while (true) {
        cout << "\n===== SINGLY LINKED LIST =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 9) break;
        
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertBegin(val);
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
        }
        else if (choice == 3) {
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter position: ";
            cin >> pos;
            insertPos(val, pos);
        }
        else if (choice == 4) {
            deleteBegin();
        }
        else if (choice == 5) {
            deleteEnd();
        }
        else if (choice == 6) {
            cout << "Enter position: ";
            cin >> pos;
            deletePos(pos);
        }
        else if (choice == 7) {
            cout << "Enter value to search: ";
            cin >> val;
            search(val);
        }
        else if (choice == 8) {
            display();
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    return 0;
}