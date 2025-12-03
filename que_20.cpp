#include <iostream>
using namespace std;

struct Node { int data; Node *next; };

Node *head = NULL;

void insertBegin(int val) {
    Node *n = new Node(); n->data = val;
    if (!head) { head = n; n->next = head; return; }
    n->next = head->next;
    head->next = n;
}

void insertEnd(int val) {
    Node *n = new Node(); n->data = val;
    if (!head) { head = n; n->next = head; return; }
    Node *temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = n; n->next = head;
}

void deleteBegin() {
    if (!head) return;
    if (head->next == head) { head = NULL; return; }
    head->next = head->next->next;
}

void deleteEnd() {
    if (!head) return;
    if (head->next == head) { head = NULL; return; }
    Node *temp = head;
    while (temp->next->next != head) temp = temp->next;
    temp->next = head;
}

void display() {
    if (!head) { cout << "List is empty\n"; return; }
    Node *temp = head;
    cout << "List: ";
    do { cout << temp->data << " "; temp = temp->next; } while (temp != head);
    cout << "\n";
}

void search(int val) {
    if (!head) { cout << "List is empty\n"; return; }
    Node *temp = head;
    do {
        if (temp->data == val) { cout << "Found " << val << "\n"; return; }
        temp = temp->next;
    } while (temp != head);
    cout << val << " not found\n";
}

int main() {
    int choice, val;
    
    while (true) {
        cout << "\n===== CIRCULAR LINKED LIST =====\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete from beginning\n";
        cout << "4. Delete from end\n";
        cout << "5. Search\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 7) break;
        
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
            deleteBegin();
            cout << "Deleted from beginning\n";
        }
        else if (choice == 4) {
            deleteEnd();
            cout << "Deleted from end\n";
        }
        else if (choice == 5) {
            cout << "Enter value to search: ";
            cin >> val;
            search(val);
        }
        else if (choice == 6) {
            display();
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    cout << "Program ended.\n";
    return 0;
}