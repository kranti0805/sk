#include <iostream>
using namespace std;

struct Node { int data; Node *next; };

class QueueLL {
    Node *front, *rear;
public:
    QueueLL() { front = rear = NULL; }
    
    void enqueue(int val) {
        Node *n = new Node(); 
        n->data = val; 
        n->next = NULL;
        if (!rear) { 
            front = rear = n; 
            cout << "Enqueued: " << val << "\n";
            return; 
        }
        rear->next = n;
        rear = n;
        cout << "Enqueued: " << val << "\n";
    }
    
    void dequeue() {
        if (!front) { 
            cout << "Underflow\n"; 
            return; 
        }
        cout << "Dequeued: " << front->data << "\n";
        front = front->next;
        if (!front) rear = NULL;
    }
    
    void display() {
        if (!front) { 
            cout << "Queue is empty\n"; 
            return; 
        }
        Node *temp = front;
        cout << "Queue: ";
        while (temp) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        }
        cout << "\n";
    }
};

int main() {
    QueueLL q;
    int choice, val;
    
    while (true) {
        cout << "\n===== QUEUE (LINKED LIST) =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 4) break;
        
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.display();
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    cout << "Program ended.\n";
    return 0;
}